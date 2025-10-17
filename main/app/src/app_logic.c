#include "app_logic.h"
#include "app_ui.h"
#include "app_motion.h"
#include "app_statemachine.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "freertos/queue.h"
#include "esp_log.h"
//引用二值信号量头文件
#include "freertos/semphr.h"

static const char *TAG = "app_logic";

// 用于接收事件的FreeRTOS队列
static QueueHandle_t app_event_queue;
// 状态机信号量，用于同步状态机和主逻辑任务
SemaphoreHandle_t app_statemachine_semaphore;

// 主逻辑任务
static void app_logic_task(void *pvParameters)
{
    ESP_LOGI(TAG, "应用逻辑任务已启动");

    // 初始化状态机，设定初始状态为“匀速”
    app_statemachine_init(APP_STATE_UNIFORM_SPEED);

    while (1) {
        app_event_t event;
        if(xSemaphoreTake(app_statemachine_semaphore, portMAX_DELAY) == pdPASS) {
            // 等待事件队列中的新事件
            if (xQueueReceive(app_event_queue, &event, portMAX_DELAY) == pdPASS) {
                ESP_LOGI(TAG, "接收到事件: %d", event);
                // 将事件交由状态机处理
                app_statemachine_handle_event(event);
                //释放二值信号量，通知IMU任务运行
                xSemaphoreGive(app_statemachine_semaphore);
            }
        }
    }
}

esp_err_t app_logic_init(void)
{
    // ESP_LOGE(TAG, "========= NEW FIRMWARE IS RUNNING! app_logic_init() IS CALLED! =========");
    ESP_LOGI(TAG, "应用逻辑核心初始化");

    // 创建事件队列，用于任务间通信
    app_event_queue = xQueueCreate(1, sizeof(app_event_t));
    if (app_event_queue == NULL) {
        ESP_LOGE(TAG, "事件队列创建失败");
        return ESP_FAIL;
    }
    //创建二值信号量，用于同步IMU和主逻辑任务
    app_statemachine_semaphore = xSemaphoreCreateBinary();
    if (app_statemachine_semaphore == NULL) {
        ESP_LOGE(TAG, "二值信号量创建失败");
        return ESP_FAIL;
    }
    //释放信号量，允许逻辑任务运行
    xSemaphoreGive(app_statemachine_semaphore);

    // 初始化UI模块
    app_ui_init();
    // 初始化运动检测模块
    app_motion_init();

    // 创建并启动主逻辑任务
    xTaskCreate(app_logic_task, "app_logic_task", 4096, NULL, 4, NULL);

    return ESP_OK;
}

BaseType_t app_logic_post_event(app_event_t event)
{
    // 线程安全地将事件发送到队列末尾
    return xQueueSend(app_event_queue, &event, 0);
}
#include "app_motion.h"
#include "service_imu.h"
#include "esp_log.h"
#include "app_logic.h" // 改为包含 app_logic.h
#include "app_statemachine.h"
#include <math.h>

static const char *TAG = "app_motion"; // 日志标签

// 动作识别状态定义
typedef enum {
    ACTION_STATE_STRAIGHT, // 直
    ACTION_STATE_TURN_LEFT,  // 左转
    ACTION_STATE_TURN_RIGHT, // 右转
} action_state_t;

//定义枚举
typedef enum {
    MOTION_STATE_STILL, // 静止
    MOTION_STATE_MOVE, // 动
} motion_state_t;
static motion_state_t s_current_motion_state = MOTION_STATE_STILL;
// 用于状态机和阈值判断的宏定义
#define TURN_START_THRESHOLD    30.0f // 进入“转向”状态的角度阈值
#define TURN_STOP_THRESHOLD     15.0f // 从“转向”返回“直行”状态的角度阈值
#define ACCELERATE_THRESHOLD_G  -0.12f  // 判定为“加速”的y轴加速度阈值 (单位: g)
#define DECELERATE_THRESHOLD_G  0.1f  // 判定为“减速”的y轴加速度阈值 (单位: g)
#define TURN_HARD_GYRO_THRESHOLD  100.0f // 判定为“大力转向”的角速度阈值 (dps)

//左转阈值
#define TURN_LEFT_THRESHOLD  8.0f // 判定为“左转”的角度阈值
//右转阈值
#define TURN_RIGHT_THRESHOLD  -7.5f // 判定为“右转”的角度阈值
//大力左转阈值
#define TURN_LEFT_HARD_THRESHOLD  25.0f
//大力右转阈值
#define TURN_RIGHT_HARD_THRESHOLD  -25.0f
//从“右转向”返回“直行”状态的角度阈值
#define TURN_RIGHT_STOP_THRESHOLD  -3.0f
//从“左转”返回“直行”状态的角度阈值
#define TURN_LEFT_STOP_THRESHOLD  3.0f

//是否校准完成的标志位
static bool is_calibrated = false;
//校准停止时Y轴加速度值
static float acce_y_offset;
static int num = 0;//记录校准次数
//向前移动的Y轴加速度阈值
static float MOVE_THRESHOLD_G; // 判定为“向前移动”的y轴加速度阈值-g (单位: g)
//向后移动的Y轴加速度阈值
static float MOVE_BACK_THRESHOLD_G ;// 判定为“向后移动”的y轴加速度阈值 +g(单位: g)
//动到停止检测次数
static int stop_count = 0;
//动到停止标志位
static bool is_stopped = false;
//静止检测次数
static int still_count = 0;
// 保存当前动作状态的静态变量
static action_state_t s_current_action_state = ACTION_STATE_STRAIGHT;



//取5次y轴加速度值的平均值作为校准值
static void calibrate_acce_y(imu_data_t data)
{
    num++;
    acce_y_offset += data.acce_y;
    if(num==5)
    {
        num = 0;
        acce_y_offset /= 5.0f;
        //向前移动的Y轴加速度阈值
        MOVE_THRESHOLD_G  = acce_y_offset-0.02f; // 判定为“向前移动”的y轴加速度阈值 (单位: g)
        //向后移动的Y轴加速度阈值
        MOVE_BACK_THRESHOLD_G  = acce_y_offset+0.02f; // 判定为“向后移动”的y轴加速度阈值 (单位: g)
        is_calibrated = true;
    }
}
static void imu_data_cb(imu_data_t data)
{
    action_state_t last_state = s_current_action_state;

    // //打印data.angle.roll
    // ESP_LOGI(TAG, "roll: %f", data.angle.roll);
    // //打印data.angle.pitch
    // ESP_LOGI(TAG, "pitch: %f", data.angle.pitch);
    // //打印data.angle.yaw
    ESP_LOGI(TAG, "yaw: %f", data.angle.yaw);
  
    //前五次数据用作校准，不会进入判断
    if (!is_calibrated) {
        calibrate_acce_y(data);
    }
    else
    {
        //打印校准Y轴加速度值
        ESP_LOGI(TAG, "校准加速度值: %f", acce_y_offset); 
        // 汽车状态逻辑判断
        if (data.angle.yaw < TURN_RIGHT_THRESHOLD) {
                    s_current_action_state = ACTION_STATE_TURN_RIGHT;
                    s_current_motion_state = MOTION_STATE_MOVE;
        } else if (data.angle.yaw > TURN_LEFT_THRESHOLD) {
                    s_current_action_state = ACTION_STATE_TURN_LEFT;
                    s_current_motion_state = MOTION_STATE_MOVE;
        }
        if ((data.angle.yaw < TURN_LEFT_STOP_THRESHOLD) && (data.angle.yaw > TURN_RIGHT_STOP_THRESHOLD)) {
                    s_current_action_state = ACTION_STATE_STRAIGHT;
        }

        //打印data.gyro.gyro_y
        // ESP_LOGI(TAG, "gyro_y: %f", data.gyro.gyro_y);
        // --- 事件发送逻辑 (简化版) ---
        if (s_current_action_state == ACTION_STATE_TURN_LEFT) {
            // 检查进入左转时的角速度
            if (fabsf(data.angle.yaw) > TURN_LEFT_HARD_THRESHOLD) {
                app_logic_post_event(APP_EVENT_MOTION_TURN_LEFT_HARD);
            } else {
                app_logic_post_event(APP_EVENT_MOTION_TURN_LEFT_NORMAL);
            }
        }  
        if (s_current_action_state == ACTION_STATE_TURN_RIGHT) {
            // 检查进入右转时的角速度
            if (fabsf(data.angle.yaw) < TURN_RIGHT_HARD_THRESHOLD) {
                app_logic_post_event(APP_EVENT_MOTION_TURN_RIGHT_HARD);
            } else {
                app_logic_post_event(APP_EVENT_MOTION_TURN_RIGHT_NORMAL);
            }
        }
        if(s_current_action_state==ACTION_STATE_STRAIGHT)
        {
            // 打印data.acce_z
            // ESP_LOGI(TAG, "acce_z: %f", data.acce_z);
            if (data.acce_y < MOVE_THRESHOLD_G) {
                s_current_motion_state = MOTION_STATE_MOVE;
            } 
            else if (data.acce_y > MOVE_BACK_THRESHOLD_G && s_current_motion_state==MOTION_STATE_MOVE) {
                s_current_motion_state = MOTION_STATE_MOVE;
                is_stopped = true;
                still_count=0;
                stop_count=0;
            }
            else if (data.acce_y > MOVE_THRESHOLD_G && data.acce_y < MOVE_BACK_THRESHOLD_G && s_current_motion_state==MOTION_STATE_MOVE) {
                s_current_motion_state = MOTION_STATE_MOVE;

            }    
        }

        if(is_stopped)
        {
            still_count++;
            if(still_count >= 17)
            {
                is_stopped = false;
                still_count=0;
            }
            // 停止检测, 检测次数达到阈值时, 判定为停止
            if (data.acce_y > MOVE_THRESHOLD_G && data.acce_y < MOVE_BACK_THRESHOLD_G &&((data.angle.yaw < TURN_LEFT_STOP_THRESHOLD) && (data.angle.yaw > TURN_RIGHT_STOP_THRESHOLD))&&still_count>=4) {
                stop_count++;
                if(stop_count >= 6)
                {
                    is_stopped = false;
                    stop_count=0;
                    still_count=0;
                    s_current_motion_state = MOTION_STATE_STILL;
                }
            }
        }
    }
    
    // 状态机根据当前状态发送事件
    if(s_current_motion_state == MOTION_STATE_STILL)
    {
        app_logic_post_event(APP_EVENT_MOTION_DECELERATE);
    }
    else if(s_current_motion_state == MOTION_STATE_MOVE)
    {
        app_logic_post_event(APP_EVENT_MOTION_ACCELERATE);
    }
    
}
/**
 * @brief 初始化动作识别应用
 * @details
 *   这是动作识别相关应用逻辑的入口。
 *   它负责初始化底层的服务，并设置好数据回调。
 *
 * @return esp_err_t 错误码
 */
esp_err_t app_motion_init(void)
{
    ESP_LOGI(TAG, "动作识别应用初始化");

    // 初始化IMU服务层
    esp_err_t ret = service_imu_init();
    if (ret != ESP_OK) {
        ESP_LOGE(TAG, "IMU 服务初始化失败");
        return ret;
    }

    // 注册回调函数，以便在获取到新数据时被调用
    service_imu_register_callback(imu_data_cb);

    // 启动IMU服务，开始后台数据采集和处理
    ret = service_imu_start();
    if (ret != ESP_OK) {
        ESP_LOGE(TAG, "IMU 服务启动失败");
        return ret;
    }

    ESP_LOGI(TAG, "动作识别应用启动成功");

    // 移除旧的初始事件发送，状态机有自己的初始化逻辑
    return ESP_OK;
}
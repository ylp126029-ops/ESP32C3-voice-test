#include "app_ui.h"
#include "esp_log.h"
#include "esp_system.h"
#include "lvgl.h"
#include "esp_lvgl_port.h"
#include "esp_random.h"

#include "ui_custom/gui_guider.h"
#include "ui_custom/events_init.h"
#include "ui_custom/custom.h"

#include <stdio.h>

static const char *TAG = "app_ui";

static screen_id_t g_current_screen = SCREEN_ID_NONE; // Default screen set by setup_ui
// 返回当前屏幕id
screen_id_t app_ui_get_current_screen(void)
{
    return g_current_screen;
}

// Helper to get the delete flag pointer for the current screen
static bool *get_current_screen_del_flag(void)
{
    switch (g_current_screen)
    {
    case SCREEN_ID_E2:
        return &guider_ui.E_2_del;
    case SCREEN_ID_E5:
        return &guider_ui.E_5_del;
    case SCREEN_ID_E7:
        return &guider_ui.E_7_del;
    case SCREEN_ID_E8:
        return &guider_ui.E_8_del;
    case SCREEN_ID_E10:
        return &guider_ui.E_10_del;
    case SCREEN_ID_E13:
        return &guider_ui.E_13_del;
    case SCREEN_ID_E14:
        return &guider_ui.E_14_del;
    case SCREEN_ID_E15:
        return &guider_ui.E_15_del;
    case SCREEN_ID_E16:
        return &guider_ui.E_16_del;
    case SCREEN_ID_E17:
        return &guider_ui.E_17_del;
    default:
        static bool first_time_del = true;
        return &first_time_del;
    }
}

// Generic screen switching function
static void switch_to_screen(screen_id_t screen_id)
{
    if (lvgl_port_lock(0))
    {
        if (g_current_screen == screen_id)
        {
            ESP_LOGI(TAG, "Already on the target screen, skipping switch.");
            lvgl_port_unlock();
            return;
        }

        ESP_LOGI(TAG, "Memory before switch: %zu bytes", (size_t)esp_get_free_heap_size());

        bool *old_scr_del = get_current_screen_del_flag();
        lv_obj_t **new_scr = NULL;
        ui_setup_scr_t setup_scr = NULL;
        const char *scr_name = "UNKNOWN";
        bool new_scr_del_val = false;

        switch (screen_id)
        {
        case SCREEN_ID_E2:
            new_scr = &guider_ui.E_2;
            setup_scr = setup_scr_E_2;
            new_scr_del_val = guider_ui.E_2_del;
            scr_name = "E2";
            break;
        case SCREEN_ID_E5:
            new_scr = &guider_ui.E_5;
            setup_scr = setup_scr_E_5;
            new_scr_del_val = guider_ui.E_5_del;
            scr_name = "E5";
            break;
        case SCREEN_ID_E7:
            new_scr = &guider_ui.E_7;
            setup_scr = setup_scr_E_7;
            new_scr_del_val = guider_ui.E_7_del;
            scr_name = "E7";
            break;
        case SCREEN_ID_E8:
            new_scr = &guider_ui.E_8;
            setup_scr = setup_scr_E_8;
            new_scr_del_val = guider_ui.E_8_del;
            scr_name = "E8";
            break;
        case SCREEN_ID_E10:
            new_scr = &guider_ui.E_10;
            setup_scr = setup_scr_E_10;
            new_scr_del_val = guider_ui.E_10_del;
            scr_name = "E10";
            break;
        case SCREEN_ID_E13:
            new_scr = &guider_ui.E_13;
            setup_scr = setup_scr_E_13;
            new_scr_del_val = guider_ui.E_13_del;
            scr_name = "E13";
            break;
        case SCREEN_ID_E14:
            new_scr = &guider_ui.E_14;
            setup_scr = setup_scr_E_14;
            new_scr_del_val = guider_ui.E_14_del;
            scr_name = "E14";
            break;
        case SCREEN_ID_E15:
            new_scr = &guider_ui.E_15;
            setup_scr = setup_scr_E_15;
            new_scr_del_val = guider_ui.E_15_del;
            scr_name = "E15";
            break;
        case SCREEN_ID_E16:
            new_scr = &guider_ui.E_16;
            setup_scr = setup_scr_E_16;
            new_scr_del_val = guider_ui.E_16_del;
            scr_name = "E16";
            break;
        case SCREEN_ID_E17:
            new_scr = &guider_ui.E_17;
            setup_scr = setup_scr_E_17;
            new_scr_del_val = guider_ui.E_17_del;
            scr_name = "E17";
            break;
        default:
            ESP_LOGE(TAG, "Invalid screen ID: %d", screen_id);
            ESP_LOGI(TAG, "Memory after failed switch attempt: %zu bytes", (size_t)esp_get_free_heap_size());
            lvgl_port_unlock();
            return;
        }

        ESP_LOGI(TAG, "Switching from screen %d to %s screen", g_current_screen, scr_name);

        ui_load_scr_animation(&guider_ui, new_scr, new_scr_del_val, old_scr_del, setup_scr, LV_SCR_LOAD_ANIM_FADE_ON, 200, 0, true, true);

        g_current_screen = screen_id;

        ESP_LOGI(TAG, "Memory after switch: %zu bytes", (size_t)esp_get_free_heap_size());

        lvgl_port_unlock();
    }
}

esp_err_t app_ui_init(void)
{
    ESP_LOGI(TAG, "UI Application Init");
    Gif_Ui_Init(); // 初始化gif UI
    // setup_ui(&guider_ui);//Gui guider实现的程序
    // events_init(&guider_ui);//Gui guider实现的程序
    srand(xTaskGetTickCount()); // 基于系统滴答计数初始化随机种子
    // g_current_screen = SCREEN_ID_E14; // Change default to E14

    // ESP_LOGI(TAG, "UI Init Finished, default screen is E14.");
    ESP_LOGI(TAG, "Initial memory: %d bytes", (size_t)esp_get_free_heap_size());

    return ESP_OK;
}

void app_ui_show_uniform_speed(int index)
{
    ESP_LOGI(TAG, "UI Update: Uniform Speed -> E14");
    switch_to_screen(SCREEN_ID_E14); // Change to E14
}

void app_ui_show_accelerate_start(void)
{
    // With E5 and E7 gone, only E10 is left. No need for random.
    ESP_LOGI(TAG, "UI Update: Accelerate Start -> E10");
    switch_to_screen(SCREEN_ID_E10);
}

void app_ui_show_accelerate_end(void)
{
    ESP_LOGI(TAG, "UI Update: Accelerate End -> E14");
    switch_to_screen(SCREEN_ID_E14);
}

void app_ui_show_decelerate_start(void)
{
    ESP_LOGI(TAG, "UI Update: Decelerate Start -> E8");
    switch_to_screen(SCREEN_ID_E8);
}

void app_ui_show_decelerate_end(void)
{
    ESP_LOGI(TAG, "UI Update: Decelerate End -> E14");
    switch_to_screen(SCREEN_ID_E14);
}

void app_ui_show_turn_left_start(void)
{
    ESP_LOGI(TAG, "UI Update: Turn Left Start -> E13");
    switch_to_screen(SCREEN_ID_E13);
}

void app_ui_show_turn_left_end(void)
{
    ESP_LOGI(TAG, "UI Update: Turn Left End -> E14");
    switch_to_screen(SCREEN_ID_E14);
}

void app_ui_show_turn_right_start(void)
{
    ESP_LOGI(TAG, "UI Update: Turn Right Start -> E17");
    // switch_to_screen(SCREEN_ID_E17);
}

void app_ui_show_turn_right_end(void)
{
    ESP_LOGI(TAG, "UI Update: Turn Right End -> E14");
    switch_to_screen(SCREEN_ID_E14);
}

void app_ui_test(void)
{
    app_ui_show_decelerate_end();
}

static straight_express_t s_current_straight_express = STRAIGHT_EXPRESS_0;
// 设置当前直行表情
void app_ui_set_straight_express(straight_express_t express)
{
    s_current_straight_express = express;
}

// 显示直行表情
void app_ui_show_straight(void)
{
    // 获取当前直行表情
    straight_express_t express = s_current_straight_express;
    switch (express)
    {
    case STRAIGHT_EXPRESS_0:
        switch_to_screen(SCREEN_ID_E14);
        // 显示直行表情0
        break;
    case STRAIGHT_EXPRESS_1:
        switch_to_screen(SCREEN_ID_E5);
        // 显示直行表情1
        break;
    case STRAIGHT_EXPRESS_2:
        switch_to_screen(SCREEN_ID_E7);
        // 显示直行表情2
        break;
    case STRAIGHT_EXPRESS_3:
        switch_to_screen(SCREEN_ID_E10);
        // 显示直行表情3
        break;
    case STRAIGHT_EXPRESS_4:
        switch_to_screen(SCREEN_ID_E13);
        // 显示直行表情4
        break;
    default:
        switch_to_screen(SCREEN_ID_E14);
        break;
    }
    // 打印当前直行表情
    ESP_LOGI(TAG, "UI Update: Straight Express -> %d", express);
}

// 显示左转表情
void app_ui_show_left(void)
{
    // 生成随机数1-3
    int express = random_express_left();
    switch (express)
    {
    case 1:
        switch_to_screen(SCREEN_ID_E16);           // 显示左转专属表情
        vTaskDelay(3 * 1000 / portTICK_PERIOD_MS); // 延时3S
        switch_to_screen(SCREEN_ID_E15);           // 显示左转结束表情
        vTaskDelay(30 * 1000 / portTICK_PERIOD_MS);
        // 显示左转表情0
        break;
    case 2:
        switch_to_screen(SCREEN_ID_E16);           // 显示左转专属表情
        vTaskDelay(3 * 1000 / portTICK_PERIOD_MS); // 延时3S
        switch_to_screen(SCREEN_ID_E2);            // 显示左转结束表情
        vTaskDelay(30 * 1000 / portTICK_PERIOD_MS);
        break;
    case 3:
        switch_to_screen(SCREEN_ID_E16);           // 显示左转专属表情
        vTaskDelay(3 * 1000 / portTICK_PERIOD_MS); // 延时3S
        switch_to_screen(SCREEN_ID_E8);            // 显示左转结束表情
        vTaskDelay(30 * 1000 / portTICK_PERIOD_MS);
        break;
    default:
        switch_to_screen(SCREEN_ID_E16);
        vTaskDelay(3 * 1000 / portTICK_PERIOD_MS); // 延时3S
        switch_to_screen(SCREEN_ID_E15);           // 显示左转结束表情
        vTaskDelay(30 * 1000 / portTICK_PERIOD_MS);
        break;
    }
    // 打印当前左转表情
    ESP_LOGI(TAG, "UI Update: Left Express -> %d", express);
}

// 显示右转表情
void app_ui_show_right(void)
{
    // 生成随机数1-3
    int express = random_express_right();
    switch (express)
    {
    case 1:
        switch_to_screen(SCREEN_ID_E17);           // 显示右转专属表情
        vTaskDelay(3 * 1000 / portTICK_PERIOD_MS); // 延时3S
        switch_to_screen(SCREEN_ID_E2);            // 显示右转结束表情
        vTaskDelay(30 * 1000 / portTICK_PERIOD_MS);
        // 显示右转表情0
        break;
    case 2:
        switch_to_screen(SCREEN_ID_E17);           // 显示右转专属表情
        vTaskDelay(3 * 1000 / portTICK_PERIOD_MS); // 延时3S
        switch_to_screen(SCREEN_ID_E8);            // 显示右转结束表情
        vTaskDelay(30 * 1000 / portTICK_PERIOD_MS);
        break;
    case 3:
        switch_to_screen(SCREEN_ID_E17);           // 显示右转专属表情
        vTaskDelay(3 * 1000 / portTICK_PERIOD_MS); // 延时3S
        switch_to_screen(SCREEN_ID_E15);           // 显示右转结束表情
        vTaskDelay(30 * 1000 / portTICK_PERIOD_MS);
        break;
    default:
        switch_to_screen(SCREEN_ID_E17);
        vTaskDelay(3 * 1000 / portTICK_PERIOD_MS); // 延时3S
        switch_to_screen(SCREEN_ID_E15);           // 显示右转结束表情
        vTaskDelay(30 * 1000 / portTICK_PERIOD_MS);
        break;
    }
    // 打印当前右转表情
    ESP_LOGI(TAG, "UI Update: Right Express -> %d", express);
}

// 显示停止表情，，，目前和直行用同一套表情
void app_ui_show_stop(void)
{
    // 获取当前停止表情
    straight_express_t express = s_current_straight_express;
    switch (express)
    {
    case STRAIGHT_EXPRESS_0:
        switch_to_screen(SCREEN_ID_E13);
        // 显示停止表情0
        break;
    case STRAIGHT_EXPRESS_1:
        switch_to_screen(SCREEN_ID_E14);
        // 显示停止表情1
        break;
    case STRAIGHT_EXPRESS_2:
        switch_to_screen(SCREEN_ID_E10);
        // 显示停止表情2
        break;
    case STRAIGHT_EXPRESS_3:
        switch_to_screen(SCREEN_ID_E7);
        // 显示停止表情3
        break;
    case STRAIGHT_EXPRESS_4:
        switch_to_screen(SCREEN_ID_E5);
        // 显示停止表情4
        break;
    default:
        switch_to_screen(SCREEN_ID_E13);
        break;
    }
    ESP_LOGI(TAG, "UI Update: Stop Express -> %d", express);
}

// 编写一个随机函数，要求随机返回1-4，第一次的时候将1-4随机排好序，每调用4次后又重新排序
int random_express(void)
{
    static int express[4] = {1, 2, 3, 4};
    static int index = 0;
    if (index % 4 == 0)
    {
        // 每四次调用，随机排序
        for (int i = 0; i < 4; i++)
        {
            int j = rand() % 4;
            int temp = express[i];
            express[i] = express[j];
            express[j] = temp;
        }
    }
    return express[index++ % 4];
}

// 编写一个随机函数，要求随机返回1-3，第一次的时候将1-3随机排好序，每调用3次后又重新排序
int random_express_left(void)
{
    static int express[3] = {1, 2, 3};
    static int index = 0;
    if (index % 3 == 0)
    {
        // 每三次调用，随机排序
        for (int i = 0; i < 3; i++)
        {
            int j = rand() % 3;
            int temp = express[i];
            express[i] = express[j];
            express[j] = temp;
        }
    }
    return express[index++ % 3];
}

int random_express_right(void)
{
    static int express[3] = {1, 2, 3};
    static int index = 0;
    if (index % 3 == 0)
    {
        // 每三次调用，随机排序
        for (int i = 0; i < 3; i++)
        {
            int j = rand() % 3;
            int temp = express[i];
            express[i] = express[j];
            express[j] = temp;
        }
    }
    return express[index++ % 3];
}

/***************************************
****************************************
以下代码是基于播放Gif图素材实现的UI显示功能
***************************************
***************************************/

static lv_obj_t *Gif = NULL; // 只创建一次
void Gif_Ui_Init(void)
{
    lv_obj_t *scr = lv_scr_act();
    lv_obj_set_style_bg_color(scr, lv_color_black(), 0); // 设置背景颜色为黑色

    // 如果 gif 对象还没创建，先创建gif对象
    if (Gif == NULL)
    {
        Gif = lv_gif_create(scr);
        lv_obj_center(Gif);
    }
}

static Gif_Straight_Num_t Current_Gif_Straight_Num = Gif_Straight_1; // 当前要显示的直行Gif图编号
static Gif_Straight_Num_t Last_Gif_Straight_Num = Gif_Straight_NULL; // 上一次显示的直行Gif图编号
void Gif_Shou_straight(void)
{
    if (Current_Gif_Straight_Num == Last_Gif_Straight_Num)
    {
        return; // 如果当前要显示的直行Gif图编号和上一次显示的直行Gif图编号相同，则直接返回
    }
    lvgl_port_lock(0);
    // 直行gif 资源数组
    const lv_img_dsc_t *gif_array[] = {&straight1, &straight2, &straight3, &straight4, &straight5, &straight6, &straight7, &straight8, &straight9};

    if (Current_Gif_Straight_Num >= 1 && Current_Gif_Straight_Num <= Gif_Straight_Num_MAX)
    {
        lv_gif_set_src(Gif, gif_array[Current_Gif_Straight_Num - 1]); // 设置当前要显示的直行Gif图
    }
    else
    {
        // 超出范围，设置为默认的straight1
        lv_gif_set_src(Gif, &straight1);
    }
    lvgl_port_unlock();
    Last_Gif_Straight_Num = Current_Gif_Straight_Num; // 更新上一次显示的直行Gif图编号
}

// 编写一个直行随机函数，要求随机返回Gif_Straight_Num_t里的枚举，第一次的时候将全部随机排好序，每调用Gif_Straight_Num_MAX次后又重新排序,并更新当前要显示的直行Gif图编号
Gif_Straight_Num_t random_express_straight(void)
{
    static Gif_Straight_Num_t express[Gif_Straight_Num_MAX] = {
        Gif_Straight_1, Gif_Straight_2, Gif_Straight_3, Gif_Straight_4,
        Gif_Straight_5, Gif_Straight_6, Gif_Straight_7, Gif_Straight_8, Gif_Straight_9};
    static int index = 0;
    if (index % Gif_Straight_Num_MAX == 0)
    {
        // 标准 Fisher-Yates 洗牌
        for (int i = Gif_Straight_Num_MAX - 1; i > 0; i--)
        {
            int j = rand() % (i + 1); // j 范围是 0~i
            Gif_Straight_Num_t temp = express[i];
            express[i] = express[j];
            express[j] = temp;
        }
        index = 0; // 新一轮归零
        // 打印新生成的随机序列（调试用）
        ESP_LOGI("straight", "生成新的直行随机场景序列!");
        for (int i = 0; i < Gif_Straight_Num_MAX; i++)
        {
            ESP_LOGI("straight", " 直行随机场景序列[%d] = Gif_Straight_%d", i, express[i]);
        }
    }
    Current_Gif_Straight_Num = express[index]; // 更新当前要显示的直行Gif图编号
    return express[index++];
}

static Gif_Stop_Num_t Current_Gif_Stop_Num = Gif_Stop_1; // 当前要显示的停止Gif图编号
static Gif_Stop_Num_t Last_Gif_Stop_Num = Gif_Stop_NULL; // 上一次显示的停止Gif图编号
void Gif_Shou_Stop(void)
{
    if (Current_Gif_Stop_Num == Last_Gif_Stop_Num)
    {
        return; // 如果当前要显示的停止Gif图编号和上一次显示的停止Gif图编号相同，则直接返回
    }

    lvgl_port_lock(0);
    // 停止gif 资源数组
    const lv_img_dsc_t *gif_array[] = {&gif1, &gif2, &gif3, &gif4, &gif5, &gif6, &gif7, &gif8, &gif9};
    if (Current_Gif_Stop_Num >= 1 && Current_Gif_Stop_Num <= Gif_Stop_Num_MAX)
    {
        lv_gif_set_src(Gif, gif_array[Current_Gif_Stop_Num - 1]);
    }
    else
    {
        // 超出范围，设置为空
        lv_gif_set_src(Gif, &gif1);
    }
    lvgl_port_unlock();
    Last_Gif_Stop_Num = Current_Gif_Stop_Num; // 更新上一次显示的停止Gif图编号
}

// 编写一个停止随机函数，要求随机返回Gif_Stop_Num_t里的枚举，第一次的时候将全部随机排好序，每调用Gif_Stop_Num_MAX次后又重新排序,并更新当前要显示的停止Gif图编号
Gif_Stop_Num_t random_express_stop(void)
{
    static Gif_Stop_Num_t express[Gif_Stop_Num_MAX] = {
        Gif_Stop_1, Gif_Stop_2, Gif_Stop_3, Gif_Stop_4,
        Gif_Stop_5, Gif_Stop_6, Gif_Stop_7, Gif_Stop_8, Gif_Stop_9};
    static int index = 0;
    if (index % Gif_Stop_Num_MAX == 0)
    {
        // 标准 Fisher-Yates 洗牌
        for (int i = Gif_Stop_Num_MAX - 1; i > 0; i--)
        {
            int j = rand() % (i + 1); // j 范围是 0~i
            Gif_Stop_Num_t temp = express[i];
            express[i] = express[j];
            express[j] = temp;
        }
        index = 0; // 新一轮归零
        // 打印新生成的随机序列（调试用）
        ESP_LOGI("STOP", "生成新的停止随机场景序列!");
        for (int i = 0; i < Gif_Stop_Num_MAX; i++)
        {
            ESP_LOGI("STOP", " 停止随机场景序列[%d] = Gif_Stop_%d", i, express[i]);
        }
    }
    Current_Gif_Stop_Num = express[index]; // 更新当前要显示的停止Gif图编号
    return express[index++];
}

void Gif_Shou_Right(void)
{
    lvgl_port_lock(0);
    // 显示右转专属GIF图
    lv_gif_set_src(Gif, &gif2);
    lvgl_port_unlock();

    // 延时3S
    vTaskDelay(3 * 1000 / portTICK_PERIOD_MS);

    lvgl_port_lock(0);
    // 显示右转完成GIF图
    random_right_Pass(); // 随机返回一个右转Gif图编号,并更新当前要显示的右转Gif图编号
    lvgl_port_unlock();

    // 保持30S，防止其他状态打断
    vTaskDelay(8 * 1000 / portTICK_PERIOD_MS);
    Current_Gif_Straight_Num = Gif_Straight_1; // 播放完后设置好切回直行的默认Gif图
    Current_Gif_Stop_Num = Gif_Stop_1;         // 播放完后设置好切回停止的默认Gif图
}

// 设置当前要显示的右转完成Gif图，随机返回Gif_Right_Num_t里的枚举，第一次的时候将全部随机排好序，每调用Gif_Right_Num_MAX次后又重新排序,并更新显示当前要显示的右转完成Gif图
Gif_Right_Num_t random_right_Pass(void)
{
    static Gif_Right_Num_t express[Gif_Right_Num_MAX] = {
        Gif_Right_1, Gif_Right_2, Gif_Right_3, Gif_Right_4,
        Gif_Right_5, Gif_Right_6, Gif_Right_7, Gif_Right_8, Gif_Right_9};
    static int index = 0;
    if (index % Gif_Right_Num_MAX == 0)
    {
        // 标准 Fisher-Yates 洗牌
        for (int i = Gif_Right_Num_MAX - 1; i > 0; i--)
        {
            int j = rand() % (i + 1); // j 范围是 0~i
            Gif_Right_Num_t temp = express[i];
            express[i] = express[j];
            express[j] = temp;
        }
        index = 0; // 新一轮归零
        // 打印新生成的随机序列（调试用）
        ESP_LOGI("right", "生成新的右转完成随机场景序列!");
        for (int i = 0; i < Gif_Right_Num_MAX; i++)
        {
            ESP_LOGI("right", " 右转完成随机场景序列[%d] = Gif_Right_%d", i, express[i]);
        }
    }
    Gif_Right_Num_t Current_Gif_Right_Num = express[index];

    lvgl_port_lock(0);
    // 右转完成gif 资源数组
    const lv_img_dsc_t *gif_array[] = {&gif1, &gif2, &gif3, &gif4, &gif5, &gif6, &gif7, &gif8, &gif9};

    if (Current_Gif_Right_Num >= 1 && Current_Gif_Right_Num <= Gif_Right_Num_MAX)
    {
        lv_gif_set_src(Gif, gif_array[Current_Gif_Right_Num - 1]);
    }
    else
    {
        // 超出范围，设置为默认的gif1
        lv_gif_set_src(Gif, &gif1);
    }
    lvgl_port_unlock();
    return express[index++];
}

// 左转表情显示函数
void Gif_Shou_Left(void)
{
    lvgl_port_lock(0);
    lv_gif_set_src(Gif, &gif2); // 显示左转专属GIF图
    lvgl_port_unlock();
    vTaskDelay(3 * 1000 / portTICK_PERIOD_MS); // 延时3S
    lvgl_port_lock(0);
    random_left_Pass(); // 随机返回一个左转Gif图编号,并更新当前要显示的左转Gif图编号,//显示左转完成GIF图
    lvgl_port_unlock();
    // 保持30S，防止其他状态打断
    vTaskDelay(8 * 1000 / portTICK_PERIOD_MS);
    Current_Gif_Straight_Num = Gif_Straight_1; // 播放完后设置好切回直行的默认Gif图
    Current_Gif_Stop_Num = Gif_Stop_1;         // 播放完后设置好切回停止的默认Gif图
}

/*设置当前要显示的左转完成Gif图，随机返回Gif_Left_Num_t里的枚举，
第一次的时候将全部随机排好序，每调用Gif_Left_Num_MAX次后又重新排序,
并更新显示当前要显示的左转完成Gif图*/
Gif_Left_Num_t random_left_Pass(void)
{
    static Gif_Left_Num_t express[Gif_Left_Num_MAX] = {
        Gif_Left_1, Gif_Left_2, Gif_Left_3, Gif_Left_4,
        Gif_Left_5, Gif_Left_6, Gif_Left_7, Gif_Left_8, Gif_Left_9};
    static int index = 0;
    if (index % Gif_Left_Num_MAX == 0)
    {
        // 标准 Fisher-Yates 洗牌
        for (int i = Gif_Left_Num_MAX - 1; i > 0; i--)
        {
            int j = rand() % (i + 1); // j 范围是 0~i
            Gif_Left_Num_t temp = express[i];
            express[i] = express[j];
            express[j] = temp;
        }
        index = 0; // 新一轮归零
        // 打印新生成的随机序列（调试用）
        ESP_LOGI("left", "生成新的左转完成随机场景序列!");
        for (int i = 0; i < Gif_Left_Num_MAX; i++)
        {
            ESP_LOGI("left", " 左转随机场景序列[%d] = Gif_Left_%d", i, express[i]);
        }
    }
    Gif_Left_Num_t Current_Gif_Left_Num = express[index]; // 获取当前要显示的左转完成Gif图编号

    lvgl_port_lock(0);
    // 左转完成gif 资源数组,每个元素对应一个左转完成gif图,根据实际素材在这添加
    const lv_img_dsc_t *gif_array[] = {&gif1, &gif2, &gif3, &gif4, &gif5, &gif6, &gif7, &gif8, &gif9};

    if (Current_Gif_Left_Num >= 1 && Current_Gif_Left_Num <= Gif_Left_Num_MAX)
    {
        lv_gif_set_src(Gif, gif_array[Current_Gif_Left_Num - 1]); // 显示左转完成GIF图
    }
    else
    {
        // 超出范围，设置为默认的gif1
        lv_gif_set_src(Gif, &gif1);
    }
    lvgl_port_unlock();
    return express[index++];
}

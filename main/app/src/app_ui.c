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
//返回当前屏幕id
screen_id_t app_ui_get_current_screen(void)
{
    return g_current_screen;
}

// Helper to get the delete flag pointer for the current screen
static bool* get_current_screen_del_flag(void)
{
    switch (g_current_screen) {
        case SCREEN_ID_E2: return &guider_ui.E_2_del;
        case SCREEN_ID_E5: return &guider_ui.E_5_del;
        case SCREEN_ID_E7: return &guider_ui.E_7_del;
        case SCREEN_ID_E8: return &guider_ui.E_8_del;
        case SCREEN_ID_E10: return &guider_ui.E_10_del;
        case SCREEN_ID_E13: return &guider_ui.E_13_del;
        case SCREEN_ID_E14: return &guider_ui.E_14_del;
        case SCREEN_ID_E15: return &guider_ui.E_15_del;
        case SCREEN_ID_E16: return &guider_ui.E_16_del;
        case SCREEN_ID_E17: return &guider_ui.E_17_del;
        default:
            static bool first_time_del = true;
            return &first_time_del;
    }
}

// Generic screen switching function
static void switch_to_screen(screen_id_t screen_id)
{
    if (lvgl_port_lock(0)) {
        if (g_current_screen == screen_id) {
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

        switch (screen_id) {
            case SCREEN_ID_E2: new_scr = &guider_ui.E_2; setup_scr = setup_scr_E_2; new_scr_del_val = guider_ui.E_2_del; scr_name = "E2"; break;
            case SCREEN_ID_E5: new_scr = &guider_ui.E_5; setup_scr = setup_scr_E_5; new_scr_del_val = guider_ui.E_5_del; scr_name = "E5"; break;
            case SCREEN_ID_E7: new_scr = &guider_ui.E_7; setup_scr = setup_scr_E_7; new_scr_del_val = guider_ui.E_7_del; scr_name = "E7"; break;
            case SCREEN_ID_E8: new_scr = &guider_ui.E_8; setup_scr = setup_scr_E_8; new_scr_del_val = guider_ui.E_8_del; scr_name = "E8"; break;
            case SCREEN_ID_E10: new_scr = &guider_ui.E_10; setup_scr = setup_scr_E_10; new_scr_del_val = guider_ui.E_10_del; scr_name = "E10"; break;
            case SCREEN_ID_E13: new_scr = &guider_ui.E_13; setup_scr = setup_scr_E_13; new_scr_del_val = guider_ui.E_13_del; scr_name = "E13"; break;
            case SCREEN_ID_E14: new_scr = &guider_ui.E_14; setup_scr = setup_scr_E_14; new_scr_del_val = guider_ui.E_14_del; scr_name = "E14"; break;
            case SCREEN_ID_E15: new_scr = &guider_ui.E_15; setup_scr = setup_scr_E_15; new_scr_del_val = guider_ui.E_15_del; scr_name = "E15"; break;
            case SCREEN_ID_E16: new_scr = &guider_ui.E_16; setup_scr = setup_scr_E_16; new_scr_del_val = guider_ui.E_16_del; scr_name = "E16"; break;
            case SCREEN_ID_E17: new_scr = &guider_ui.E_17; setup_scr = setup_scr_E_17; new_scr_del_val = guider_ui.E_17_del; scr_name = "E17"; break;
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

    setup_ui(&guider_ui);
    events_init(&guider_ui);

    // g_current_screen = SCREEN_ID_E14; // Change default to E14

    ESP_LOGI(TAG, "UI Init Finished, default screen is E14.");
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
//设置当前直行表情
void app_ui_set_straight_express(straight_express_t express)
{
    s_current_straight_express = express;
}

//显示直行表情
void app_ui_show_straight(void)
{
    //获取当前直行表情
    straight_express_t express = s_current_straight_express;
    switch (express) { 
    case STRAIGHT_EXPRESS_0:
        switch_to_screen(SCREEN_ID_E14);
        //显示直行表情0
        break;
    case STRAIGHT_EXPRESS_1:
        switch_to_screen(SCREEN_ID_E5);
        //显示直行表情1
        break;
    case STRAIGHT_EXPRESS_2:
        switch_to_screen(SCREEN_ID_E7);
        //显示直行表情2
        break;
    case STRAIGHT_EXPRESS_3:
        switch_to_screen(SCREEN_ID_E10);
        //显示直行表情3
        break;
    case STRAIGHT_EXPRESS_4:
        switch_to_screen(SCREEN_ID_E13);
        //显示直行表情4
        break;
    default:
        switch_to_screen(SCREEN_ID_E14);
        break;
    }
    //打印当前直行表情
    ESP_LOGI(TAG, "UI Update: Straight Express -> %d", express);
}

//显示左转表情
void app_ui_show_left(void)
{
    //生成随机数1-3
    int express = rand() % 3 + 1;
    switch (express) { 
    case 1:
        switch_to_screen(SCREEN_ID_E16);//显示左转专属表情
        vTaskDelay(2*1000 / portTICK_PERIOD_MS);//延时2S
        switch_to_screen(SCREEN_ID_E15);//显示左转结束表情
        vTaskDelay(30*1000 / portTICK_PERIOD_MS);
        //显示左转表情0
        break;
    case 2:
        switch_to_screen(SCREEN_ID_E16);//显示左转专属表情
        vTaskDelay(2*1000 / portTICK_PERIOD_MS);//延时2S
        switch_to_screen(SCREEN_ID_E2);//显示左转结束表情
        vTaskDelay(30*1000 / portTICK_PERIOD_MS);        
        break;
    case 3:
        switch_to_screen(SCREEN_ID_E16);//显示左转专属表情
        vTaskDelay(2*1000 / portTICK_PERIOD_MS);//延时2S
        switch_to_screen(SCREEN_ID_E8);//显示左转结束表情
        vTaskDelay(30*1000 / portTICK_PERIOD_MS);
        break;
    default:
        switch_to_screen(SCREEN_ID_E16);
        vTaskDelay(2*1000 / portTICK_PERIOD_MS);//延时2S
        switch_to_screen(SCREEN_ID_E15);//显示左转结束表情
        vTaskDelay(30*1000 / portTICK_PERIOD_MS);
        break;
    }
    //打印当前左转表情
    ESP_LOGI(TAG, "UI Update: Left Express -> %d", express);
}

//显示右转表情
void app_ui_show_right(void)
{
    //生成随机数1-3
    int express = rand() % 3 + 1;
    switch (express) { 
    case 1:
        switch_to_screen(SCREEN_ID_E17);//显示右转专属表情
        vTaskDelay(2*1000 / portTICK_PERIOD_MS);//延时2S
        switch_to_screen(SCREEN_ID_E2);//显示右转结束表情
        vTaskDelay(30*1000 / portTICK_PERIOD_MS);
        //显示右转表情0
        break;
    case 2:
        switch_to_screen(SCREEN_ID_E17);//显示右转专属表情
        vTaskDelay(2*1000 / portTICK_PERIOD_MS);//延时2S
        switch_to_screen(SCREEN_ID_E8);//显示右转结束表情
        vTaskDelay(30*1000 / portTICK_PERIOD_MS);
        break;
    case 3:
        switch_to_screen(SCREEN_ID_E17);//显示右转专属表情
        vTaskDelay(2*1000 / portTICK_PERIOD_MS);//延时2S
        switch_to_screen(SCREEN_ID_E15);//显示右转结束表情
        vTaskDelay(30*1000 / portTICK_PERIOD_MS);
        break;
    default:
        switch_to_screen(SCREEN_ID_E17);
        vTaskDelay(2*1000 / portTICK_PERIOD_MS);//延时2S
        switch_to_screen(SCREEN_ID_E15);//显示右转结束表情
        vTaskDelay(30*1000 / portTICK_PERIOD_MS);
        break;
    }
}

//显示停止表情，，，目前和直行用同一套表情
void app_ui_show_stop(void)
{
    //获取当前停止表情
    straight_express_t express = s_current_straight_express;
    switch (express) { 
        case STRAIGHT_EXPRESS_0:
            switch_to_screen(SCREEN_ID_E13);
            //显示停止表情0
            break;
        case STRAIGHT_EXPRESS_1:
            switch_to_screen(SCREEN_ID_E14);
            //显示停止表情1
            break;
        case STRAIGHT_EXPRESS_2:
            switch_to_screen(SCREEN_ID_E10);
            //显示停止表情2
            break;
        case STRAIGHT_EXPRESS_3:
            switch_to_screen(SCREEN_ID_E7);
            //显示停止表情3 
            break;
        case STRAIGHT_EXPRESS_4:
            switch_to_screen(SCREEN_ID_E5);
            //显示停止表情4
            break;
        default:
            switch_to_screen(SCREEN_ID_E13);
            break;
    }
    
}

//编写一个随机函数，要求随机返回1-4，第一次的时候将1-4随机排好序，每调用4次后又重新排序
int random_express(void)
{
    static int express[4] = {1, 2, 3, 4};
    static int index = 0;
    if (index % 4 == 0) {
        // 每四次调用，随机排序
        for (int i = 0; i < 4; i++) {
            int j = rand() % 4;
            int temp = express[i];
            express[i] = express[j];
            express[j] = temp;
        }
    }
    return express[index++ % 4];
}
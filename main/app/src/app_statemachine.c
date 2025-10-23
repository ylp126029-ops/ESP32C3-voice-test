#include "app_statemachine.h"
#include "app_logic.h"
#include "app_ui.h"
#include "esp_log.h"
#include "freertos/FreeRTOS.h"
#include "freertos/timers.h"
#include "freertos/task.h"
#include <stdlib.h>
#include "ui_custom/gui_guider.h"
#include "esp_lvgl_port.h"

static const char *TAG = "app_sm";
static app_state_t current_state;
static TimerHandle_t ui_dynamic_timer;//表情由静态切换为动态定时器
static TimerHandle_t ui_Change_timer;//直行表情切换定时器
static TimerHandle_t ui_back_timer;//切回直行默认表情定时器

static screen_id_t current_screen;
//表情由静态切换为动态定时器回调函数
static void ui_dynamic_timer_callback(TimerHandle_t xTimer) {
    current_screen = app_ui_get_current_screen();//获取当前屏幕ID
    if(current_screen == SCREEN_ID_E2)
    {
        lvgl_port_lock(0);
        lv_animimg_set_src(guider_ui.E_2_animimg_1, (const void **) E_2_animimg_1_imgs, 30);
        lv_animimg_set_duration(guider_ui.E_2_animimg_1, 60*30);
        lv_animimg_set_repeat_count(guider_ui.E_2_animimg_1, 1);
        lv_animimg_start(guider_ui.E_2_animimg_1);
        lvgl_port_unlock();
    }
    else if(current_screen == SCREEN_ID_E5)
    {
        lvgl_port_lock(0);
        lv_animimg_set_src(guider_ui.E_5_animimg_1, (const void **) E_5_animimg_1_imgs, 30);
        lv_animimg_set_duration(guider_ui.E_5_animimg_1, 60*30);
        lv_animimg_set_repeat_count(guider_ui.E_5_animimg_1, 1);
        lv_animimg_start(guider_ui.E_5_animimg_1);
        lvgl_port_unlock();
    }
    else if(current_screen == SCREEN_ID_E7)
    {
        lvgl_port_lock(0);
        lv_animimg_set_src(guider_ui.E_7_animimg_1, (const void **) E_7_animimg_1_imgs, 30);
        lv_animimg_set_duration(guider_ui.E_7_animimg_1, 60*30);
        lv_animimg_set_repeat_count(guider_ui.E_7_animimg_1, 1);
        lv_animimg_start(guider_ui.E_7_animimg_1);
        lvgl_port_unlock();
    }
    else if(current_screen == SCREEN_ID_E8)
    {
        lvgl_port_lock(0);
        lv_animimg_set_src(guider_ui.E_8_animimg_1, (const void **) E_8_animimg_1_imgs, 30);
        lv_animimg_set_duration(guider_ui.E_8_animimg_1, 60*30);
        lv_animimg_set_repeat_count(guider_ui.E_8_animimg_1, 2);
        lv_animimg_start(guider_ui.E_8_animimg_1);
        lvgl_port_unlock();
    }
    else if(current_screen == SCREEN_ID_E10)
    {
        lvgl_port_lock(0);
        lv_animimg_set_src(guider_ui.E_10_animimg_1, (const void **) E_10_animimg_1_imgs, 30);
        lv_animimg_set_duration(guider_ui.E_10_animimg_1, 60*30);
        lv_animimg_set_repeat_count(guider_ui.E_10_animimg_1, 1);
        lv_animimg_start(guider_ui.E_10_animimg_1);
        lvgl_port_unlock();
    }
    else if(current_screen == SCREEN_ID_E13)
    {
        lvgl_port_lock(0);
        lv_animimg_set_src(guider_ui.E_13_animimg_1, (const void **) E_13_animimg_1_imgs, 30);
        lv_animimg_set_duration(guider_ui.E_13_animimg_1, 60*30);
        lv_animimg_set_repeat_count(guider_ui.E_13_animimg_1, 1);
        lv_animimg_start(guider_ui.E_13_animimg_1);
        lvgl_port_unlock();
    }
    else if(current_screen == SCREEN_ID_E14)
    {
        lvgl_port_lock(0);
        lv_animimg_set_src(guider_ui.E_14_animimg_1, (const void **) E_14_animimg_1_imgs, 30);
        lv_animimg_set_duration(guider_ui.E_14_animimg_1, 60*30);
        lv_animimg_set_repeat_count(guider_ui.E_14_animimg_1, 1);
        lv_animimg_start(guider_ui.E_14_animimg_1);
        lvgl_port_unlock();
    }
    else if(current_screen == SCREEN_ID_E15)
    {
        lvgl_port_lock(0);
        lv_animimg_set_src(guider_ui.E_15_animimg_1, (const void **) E_15_animimg_1_imgs, 30);
        lv_animimg_set_duration(guider_ui.E_15_animimg_1, 60*30);
        lv_animimg_set_repeat_count(guider_ui.E_15_animimg_1, 1);
        lv_animimg_start(guider_ui.E_15_animimg_1);
        lvgl_port_unlock();
    }

}

//表情切换定时器回调函数
static void ui_Change_timer_callback(TimerHandle_t xTimer) {
    //生成1-4之间的随机数
    int express = random_express();
    //根据随机数切换不同表情
    switch (express) {
        case 1:
            app_ui_set_straight_express(STRAIGHT_EXPRESS_1);
            break;
        case 2:
            app_ui_set_straight_express(STRAIGHT_EXPRESS_2);
            break;
        case 3:
            app_ui_set_straight_express(STRAIGHT_EXPRESS_3);
            break;
        case 4:
            app_ui_set_straight_express(STRAIGHT_EXPRESS_4);
            break;
        default:
    }
    //停止当前动态表情切换定时器
    xTimerStop(ui_Change_timer, portMAX_DELAY);
    //启动切回默认表情定时器回调函数
    xTimerStart(ui_back_timer, portMAX_DELAY);
}

//切回默认表情定时器回调函数
static void ui_back_timer_callback(TimerHandle_t xTimer) {
    //停止当前表情切换定时器
    xTimerStop(ui_back_timer, portMAX_DELAY);
    //切换回默认表情
    app_ui_set_straight_express(STRAIGHT_EXPRESS_0);
    //启动动态表情切换定时器
    xTimerStart(ui_Change_timer, portMAX_DELAY);
}
void app_time_init(void) {
    // 创建8S周期的软件定时器，用于切换启动表情动态
    ui_dynamic_timer = xTimerCreate(
        "ui_dynamic_timer",         // 定时器名称
        pdMS_TO_TICKS(8 * 1000),   // 定时周期 (8S)
        pdTRUE,                     // 自动重载
        (void *)0,                  // 定时器ID
        ui_dynamic_timer_callback // 回调函数
    );
    //启动定时器
    xTimerStart(ui_dynamic_timer, portMAX_DELAY);

    //创建1分钟周期的软件定时器，用于切换直行不同表情
    ui_Change_timer = xTimerCreate(
        "ui_Change_timer",         // 定时器名称
        pdMS_TO_TICKS(60 * 1000),   // 定时周期 (1分钟)
        pdTRUE,                     // 自动重载
        (void *)0,                  // 定时器ID
        ui_Change_timer_callback // 回调函数
    );
    //启动定时器
    xTimerStart(ui_Change_timer, portMAX_DELAY);
    //创建45S周期的软件定时器，用于切换回直行默认表情
    ui_back_timer = xTimerCreate(
        "ui_back_timer",         // 定时器名称
        pdMS_TO_TICKS(45 * 1000),   // 定时周期 (45S)
        pdTRUE,                     // 自动重载
        (void *)0,                  // 定时器ID
        ui_back_timer_callback // 回调函数
    );
 
}

void app_statemachine_handle_event(app_event_t event) {

    app_event_t current_event = event;
    switch (current_event) {
        case APP_EVENT_MOTION_TURN_LEFT_NORMAL://左
            // 进入左转状态，显示左转开始UI
            app_ui_show_left();
            break;
        case APP_EVENT_MOTION_TURN_LEFT_HARD://左
            app_ui_show_left();
            break;
        case APP_EVENT_MOTION_TURN_RIGHT_NORMAL://右
            // 进入右转状态，显示右转开始UI
            app_ui_show_right();
            break;
        case APP_EVENT_MOTION_TURN_RIGHT_HARD://右
            app_ui_show_right();
            break;
        case APP_EVENT_MOTION_ACCELERATE://直行
            // 进入直行状态，显示UI
            // app_ui_test();
            app_ui_show_straight();
            break;
        case APP_EVENT_MOTION_DECELERATE://停止
            // 进入停止状态，显示UI
            app_ui_show_stop();
            break;
        default:
            // 未知状态，不执行任何操作
            break;
    }
}

#ifndef APP_UI_H_
#define APP_UI_H_

#include "esp_err.h"

typedef enum {
    UI_STATE_INIT,
    UI_STATE_DRIVING,
    UI_STATE_TURN_LEFT,
    UI_STATE_TURN_LEFT_HARD,
    UI_STATE_TURN_LEFT_END,
    UI_STATE_TURN_RIGHT,
    UI_STATE_TURN_RIGHT_HARD,
    UI_STATE_TURN_RIGHT_END,
} ui_state_t;

/**
 * @brief 初始化UI底层驱动和LVGL库
 * @note 这个函数不再创建任务，只做UI的底层准备工作。
 * @return esp_err_t 错误码
 */
esp_err_t app_ui_init(void);

// --- 匀速状态 UI ---
/**
 * @brief 显示第N个匀速状态的UI
 * @param index UI界面的索引 (0-9)
 */
void app_ui_show_uniform_speed(int index);

// --- 左转状态 UI ---
void app_ui_show_turn_left_start(void);
void app_ui_show_turn_left_end(void);
void app_ui_show_turn_left_hard(void);

// --- 右转状态 UI (TODO) ---
void app_ui_show_turn_right_start(void);
void app_ui_show_turn_right_hard(void);
void app_ui_show_turn_right_end(void);

// --- 加速状态 UI (TODO) ---
void app_ui_show_accelerate_start(void);
void app_ui_show_accelerate_end(void);

// --- 刹车状态 UI (TODO) ---
void app_ui_show_decelerate_start(void);
void app_ui_show_decelerate_end(void);
// Enum to track the current screen
typedef enum {
    SCREEN_ID_NONE,
    SCREEN_ID_E2,
    SCREEN_ID_E5,
    SCREEN_ID_E7,
    SCREEN_ID_E8,
    SCREEN_ID_E10,
    SCREEN_ID_E13,
    SCREEN_ID_E14,
    SCREEN_ID_E15,
    SCREEN_ID_E16,
    SCREEN_ID_E17,
} screen_id_t;
//定义直行表情枚举
typedef enum {
    STRAIGHT_EXPRESS_0, // 直行表情0
    STRAIGHT_EXPRESS_1, // 直行表情1
    STRAIGHT_EXPRESS_2, // 直行表情2
    STRAIGHT_EXPRESS_3, // 直行表情3
    STRAIGHT_EXPRESS_4, // 直行表情4
} straight_express_t;
screen_id_t app_ui_get_current_screen(void);
void app_ui_test(void);
void app_ui_show_straight(void);//显示当前直行表情
void app_ui_set_straight_express(straight_express_t express);//设置当前直行表情
void app_ui_show_left(void);//显示左转表情
void app_ui_show_right(void);//显示右转表情
void app_ui_show_stop(void);//显示停止表情
#endif /* APP_UI_H_ */
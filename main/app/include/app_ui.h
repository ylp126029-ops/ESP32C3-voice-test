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
int random_express(void);//随机返回1-4，第一次的时候将1-4随机排好序，每调用4次后又重新排序
int random_express_left(void);//随机返回1-3，第一次的时候将1-3随机排好序，每调用3次后又重新排序
int random_express_right(void);//随机返回1-3，第一次的时候将1-3随机排好序，每调用3次后又重新排序

/********************************************
 * ******************************************
以下代码是基于播放Gif图素材实现的UI显示功能的函数
********************************************
*******************************************/

//定义一个枚举类型，用于表示直行状态的Gif图的数量编号
typedef enum {
    Gif_Straight_NULL = 0,
    Gif_Straight_1 = 1,
    Gif_Straight_2 = 2,
    Gif_Straight_3 = 3,
    Gif_Straight_4 = 4,
    Gif_Straight_5 = 5,
    Gif_Straight_6 = 6,
    Gif_Straight_7 = 7,
    Gif_Straight_8 = 8,
    Gif_Straight_9 = 9,
    Gif_Straight_Num_MAX = Gif_Straight_9,
} Gif_Straight_Num_t;
//定义一个枚举类型，用于表示停止状态的Gif图的数量编号
typedef enum {
    Gif_Stop_NULL = 0,
    Gif_Stop_1 = 1,
    Gif_Stop_2 = 2,
    Gif_Stop_3 = 3,
    Gif_Stop_4 = 4,
    Gif_Stop_5 = 5,
    Gif_Stop_6 = 6,
    Gif_Stop_7 = 7,
    Gif_Stop_8 = 8,
    Gif_Stop_9 = 9,
    Gif_Stop_Num_MAX = Gif_Stop_9,
} Gif_Stop_Num_t;
//定义一个枚举类型，用于表示左转状态的Gif图的数量编号
typedef enum {
    Gif_Left_NULL = 0,
    Gif_Left_1 = 1,
    Gif_Left_2 = 2,
    Gif_Left_3 = 3,
    Gif_Left_4 = 4,
    Gif_Left_5 = 5,
    Gif_Left_6 = 6,
    Gif_Left_7 = 7,
    Gif_Left_8 = 8,
    Gif_Left_9 = 9,
    Gif_Left_Num_MAX = Gif_Left_9,
} Gif_Left_Num_t;
//定义一个枚举类型，用于表示右转状态的Gif图的数量编号
typedef enum {
    Gif_Right_NULL = 0,
    Gif_Right_1 = 1,
    Gif_Right_2 = 2,
    Gif_Right_3 = 3,
    Gif_Right_4 = 4,
    Gif_Right_5 = 5,
    Gif_Right_6 = 6,
    Gif_Right_7 = 7,
    Gif_Right_8 = 8,
    Gif_Right_9 = 9,
    Gif_Right_Num_MAX = Gif_Right_9,
} Gif_Right_Num_t;
void Gif_Ui_Init(void);//初始化Gif图UI
void Gif_Shou_straight(void);//显示当前直行状态的Gif图
Gif_Straight_Num_t random_express_straight(void);//随机返回一个直行Gif图编号,并更新当前要显示的直行状态的Gif图编号
void Gif_Shou_Right(void);//显示当前右转状态的Gif图
Gif_Right_Num_t random_right_Pass(void);//随机返回一个右转Gif图编号,并更新当前要显示的右转状态的Gif图编号
void Gif_Shou_Left(void);//显示当前左转状态的Gif图
Gif_Left_Num_t random_left_Pass(void);//随机返回一个左转Gif图编号,并更新当前要显示的左转状态的Gif图编号
void Gif_Shou_Stop(void);//显示当前停止状态的Gif图
Gif_Stop_Num_t random_express_stop(void);//随机返回一个停止Gif图编号,并更新当前要显示的停止Gif图编号



#endif /* APP_UI_H_ */
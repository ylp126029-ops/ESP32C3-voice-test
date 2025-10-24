/*
* Copyright 2025 NXP
* NXP Proprietary. This software is owned or controlled by NXP and may only be used strictly in
* accordance with the applicable license terms. By expressly accepting such terms or by downloading, installing,
* activating and/or otherwise using the software, you are agreeing that you have read, and that you agree to
* comply with and are bound by, such license terms.  If you do not agree to be bound by the applicable license
* terms, then you may not retain, install, activate or otherwise use the software.
*/

#ifndef GUI_GUIDER_H
#define GUI_GUIDER_H
#ifdef __cplusplus
extern "C" {
#endif

#include "lvgl.h"
#include "widgets_init.h"

typedef struct
{
  
	lv_obj_t *E_2;
	bool E_2_del;
	lv_obj_t *E_2_animimg_1;
	lv_obj_t *E_5;
	bool E_5_del;
	lv_obj_t *E_5_animimg_1;
	lv_obj_t *E_7;
	bool E_7_del;
	lv_obj_t *E_7_animimg_1;
	lv_obj_t *E_8;
	bool E_8_del;
	lv_obj_t *E_8_animimg_1;
	lv_obj_t *E_10;
	bool E_10_del;
	lv_obj_t *E_10_animimg_1;
	lv_obj_t *E_13;
	bool E_13_del;
	lv_obj_t *E_13_animimg_1;
	lv_obj_t *E_14;
	bool E_14_del;
	lv_obj_t *E_14_animimg_1;
	lv_obj_t *E_15;
	bool E_15_del;
	lv_obj_t *E_15_animimg_1;
	lv_obj_t *E_16;
	bool E_16_del;
	lv_obj_t *E_16_animimg_1;
	lv_obj_t *E_17;
	bool E_17_del;
	lv_obj_t *E_17_animimg_1;
}lv_ui;

typedef void (*ui_setup_scr_t)(lv_ui * ui);

void ui_init_style(lv_style_t * style);

void ui_load_scr_animation(lv_ui *ui, lv_obj_t ** new_scr, bool new_scr_del, bool * old_scr_del, ui_setup_scr_t setup_scr,
                           lv_screen_load_anim_t anim_type, uint32_t time, uint32_t delay, bool is_clean, bool auto_del);

void ui_animation(void * var, uint32_t duration, int32_t delay, int32_t start_value, int32_t end_value, lv_anim_path_cb_t path_cb,
                  uint32_t repeat_cnt, uint32_t repeat_delay, uint32_t playback_time, uint32_t playback_delay,
                  lv_anim_exec_xcb_t exec_cb, lv_anim_start_cb_t start_cb, lv_anim_completed_cb_t ready_cb, lv_anim_deleted_cb_t deleted_cb);


void init_scr_del_flag(lv_ui *ui);

void setup_bottom_layer(void);

void setup_ui(lv_ui *ui);

void video_play(lv_ui *ui);

void init_keyboard(lv_ui *ui);

extern lv_ui guider_ui;


void setup_scr_E_2(lv_ui *ui);
void setup_scr_E_5(lv_ui *ui);
void setup_scr_E_7(lv_ui *ui);
void setup_scr_E_8(lv_ui *ui);
void setup_scr_E_10(lv_ui *ui);
void setup_scr_E_13(lv_ui *ui);
void setup_scr_E_14(lv_ui *ui);
void setup_scr_E_15(lv_ui *ui);
void setup_scr_E_16(lv_ui *ui);
void setup_scr_E_17(lv_ui *ui);
LV_IMAGE_DECLARE(E_2_animimg_1smile_01);
LV_IMAGE_DECLARE(E_2_animimg_1smile_02);
LV_IMAGE_DECLARE(E_2_animimg_1smile_03);
LV_IMAGE_DECLARE(E_2_animimg_1smile_04);
LV_IMAGE_DECLARE(E_2_animimg_1smile_05);
LV_IMAGE_DECLARE(E_2_animimg_1smile_06);
LV_IMAGE_DECLARE(E_2_animimg_1smile_07);
LV_IMAGE_DECLARE(E_2_animimg_1smile_08);
LV_IMAGE_DECLARE(E_2_animimg_1smile_09);
LV_IMAGE_DECLARE(E_2_animimg_1smile_10);
LV_IMAGE_DECLARE(E_2_animimg_1smile_11);
LV_IMAGE_DECLARE(E_2_animimg_1smile_12);
LV_IMAGE_DECLARE(E_2_animimg_1smile_13);
LV_IMAGE_DECLARE(E_2_animimg_1smile_14);
LV_IMAGE_DECLARE(E_2_animimg_1smile_15);
LV_IMAGE_DECLARE(E_2_animimg_1smile_16);
LV_IMAGE_DECLARE(E_2_animimg_1smile_17);
LV_IMAGE_DECLARE(E_2_animimg_1smile_18);
LV_IMAGE_DECLARE(E_2_animimg_1smile_19);
LV_IMAGE_DECLARE(E_2_animimg_1smile_20);
LV_IMAGE_DECLARE(E_2_animimg_1smile_21);
LV_IMAGE_DECLARE(E_5_animimg_1drink_01);
LV_IMAGE_DECLARE(E_5_animimg_1drink_02);
LV_IMAGE_DECLARE(E_5_animimg_1drink_03);
LV_IMAGE_DECLARE(E_5_animimg_1drink_04);
LV_IMAGE_DECLARE(E_5_animimg_1drink_05);
LV_IMAGE_DECLARE(E_5_animimg_1drink_06);
LV_IMAGE_DECLARE(E_5_animimg_1drink_07);
LV_IMAGE_DECLARE(E_5_animimg_1drink_08);
LV_IMAGE_DECLARE(E_5_animimg_1drink_09);
LV_IMAGE_DECLARE(E_5_animimg_1drink_10);
LV_IMAGE_DECLARE(E_5_animimg_1drink_11);
LV_IMAGE_DECLARE(E_5_animimg_1drink_12);
LV_IMAGE_DECLARE(E_5_animimg_1drink_13);
LV_IMAGE_DECLARE(E_5_animimg_1drink_14);
LV_IMAGE_DECLARE(E_5_animimg_1drink_15);
LV_IMAGE_DECLARE(E_5_animimg_1drink_16);
LV_IMAGE_DECLARE(E_5_animimg_1drink_17);
LV_IMAGE_DECLARE(E_5_animimg_1drink_18);
LV_IMAGE_DECLARE(E_5_animimg_1drink_19);
LV_IMAGE_DECLARE(E_5_animimg_1drink_20);
LV_IMAGE_DECLARE(E_5_animimg_1drink_21);
LV_IMAGE_DECLARE(E_5_animimg_1drink_22);
LV_IMAGE_DECLARE(E_5_animimg_1drink_23);
LV_IMAGE_DECLARE(E_7_animimg_1shy_0);
LV_IMAGE_DECLARE(E_7_animimg_1shy_01);
LV_IMAGE_DECLARE(E_7_animimg_1shy_02);
LV_IMAGE_DECLARE(E_7_animimg_1shy_03);
LV_IMAGE_DECLARE(E_7_animimg_1shy_04);
LV_IMAGE_DECLARE(E_7_animimg_1shy_05);
LV_IMAGE_DECLARE(E_7_animimg_1shy_06);
LV_IMAGE_DECLARE(E_7_animimg_1shy_07);
LV_IMAGE_DECLARE(E_7_animimg_1shy_09);
LV_IMAGE_DECLARE(E_7_animimg_1shy_12);
LV_IMAGE_DECLARE(E_7_animimg_1shy_13);
LV_IMAGE_DECLARE(E_7_animimg_1shy_14);
LV_IMAGE_DECLARE(E_7_animimg_1shy_15);
LV_IMAGE_DECLARE(E_7_animimg_1shy_16);
LV_IMAGE_DECLARE(E_7_animimg_1shy_17);
LV_IMAGE_DECLARE(E_7_animimg_1shy_18);
LV_IMAGE_DECLARE(E_7_animimg_1shy_19);
LV_IMAGE_DECLARE(E_7_animimg_1shy_20);
LV_IMAGE_DECLARE(E_7_animimg_1shy_21);
LV_IMAGE_DECLARE(E_7_animimg_1shy_29);
LV_IMAGE_DECLARE(E_8_animimg_1sway_0);
LV_IMAGE_DECLARE(E_8_animimg_1sway_01);
LV_IMAGE_DECLARE(E_8_animimg_1sway_02);
LV_IMAGE_DECLARE(E_8_animimg_1sway_03);
LV_IMAGE_DECLARE(E_8_animimg_1sway_04);
LV_IMAGE_DECLARE(E_8_animimg_1sway_05);
LV_IMAGE_DECLARE(E_8_animimg_1sway_06);
LV_IMAGE_DECLARE(E_8_animimg_1sway_07);
LV_IMAGE_DECLARE(E_8_animimg_1sway_08);
LV_IMAGE_DECLARE(E_8_animimg_1sway_09);
LV_IMAGE_DECLARE(E_8_animimg_1sway_10);
LV_IMAGE_DECLARE(E_8_animimg_1sway_11);
LV_IMAGE_DECLARE(E_8_animimg_1sway_12);
LV_IMAGE_DECLARE(E_8_animimg_1sway_16);
LV_IMAGE_DECLARE(E_8_animimg_1sway_17);
LV_IMAGE_DECLARE(E_8_animimg_1sway_18);
LV_IMAGE_DECLARE(E_8_animimg_1sway_19);
LV_IMAGE_DECLARE(E_8_animimg_1sway_20);
LV_IMAGE_DECLARE(E_8_animimg_1sway_21);
LV_IMAGE_DECLARE(E_8_animimg_1sway_22);
LV_IMAGE_DECLARE(E_8_animimg_1sway_23);
LV_IMAGE_DECLARE(E_10_animimg_1sing_0);
LV_IMAGE_DECLARE(E_10_animimg_1sing_01);
LV_IMAGE_DECLARE(E_10_animimg_1sing_02);
LV_IMAGE_DECLARE(E_10_animimg_1sing_03);
LV_IMAGE_DECLARE(E_10_animimg_1sing_04);
LV_IMAGE_DECLARE(E_10_animimg_1sing_05);
LV_IMAGE_DECLARE(E_10_animimg_1sing_06);
LV_IMAGE_DECLARE(E_10_animimg_1sing_07);
LV_IMAGE_DECLARE(E_10_animimg_1sing_08);
LV_IMAGE_DECLARE(E_10_animimg_1sing_09);
LV_IMAGE_DECLARE(E_10_animimg_1sing_14);
LV_IMAGE_DECLARE(E_10_animimg_1sing_15);
LV_IMAGE_DECLARE(E_10_animimg_1sing_16);
LV_IMAGE_DECLARE(E_10_animimg_1sing_17);
LV_IMAGE_DECLARE(E_10_animimg_1sing_18);
LV_IMAGE_DECLARE(E_10_animimg_1sing_19);
LV_IMAGE_DECLARE(E_10_animimg_1sing_20);
LV_IMAGE_DECLARE(E_10_animimg_1sing_21);
LV_IMAGE_DECLARE(E_13_animimg_1glass_0);
LV_IMAGE_DECLARE(E_13_animimg_1glass_01);
LV_IMAGE_DECLARE(E_13_animimg_1glass_02);
LV_IMAGE_DECLARE(E_13_animimg_1glass_03);
LV_IMAGE_DECLARE(E_13_animimg_1glass_04);
LV_IMAGE_DECLARE(E_13_animimg_1glass_05);
LV_IMAGE_DECLARE(E_13_animimg_1glass_06);
LV_IMAGE_DECLARE(E_13_animimg_1glass_07);
LV_IMAGE_DECLARE(E_13_animimg_1glass_08);
LV_IMAGE_DECLARE(E_13_animimg_1glass_09);
LV_IMAGE_DECLARE(E_13_animimg_1glass_12);
LV_IMAGE_DECLARE(E_13_animimg_1glass_13);
LV_IMAGE_DECLARE(E_13_animimg_1glass_14);
LV_IMAGE_DECLARE(E_13_animimg_1glass_15);
LV_IMAGE_DECLARE(E_13_animimg_1glass_16);
LV_IMAGE_DECLARE(E_13_animimg_1glass_17);
LV_IMAGE_DECLARE(E_13_animimg_1glass_18);
LV_IMAGE_DECLARE(E_13_animimg_1glass_19);
LV_IMAGE_DECLARE(E_13_animimg_1glass_20);
LV_IMAGE_DECLARE(E_13_animimg_1glass_21);
LV_IMAGE_DECLARE(E_13_animimg_1glass_22);
LV_IMAGE_DECLARE(E_14_animimg_1normal_0);
LV_IMAGE_DECLARE(E_14_animimg_1normal_01);
LV_IMAGE_DECLARE(E_14_animimg_1normal_02);
LV_IMAGE_DECLARE(E_14_animimg_1normal_03);
LV_IMAGE_DECLARE(E_14_animimg_1normal_04);
LV_IMAGE_DECLARE(E_14_animimg_1normal_05);
LV_IMAGE_DECLARE(E_14_animimg_1normal_06);
LV_IMAGE_DECLARE(E_14_animimg_1normal_07);
LV_IMAGE_DECLARE(E_14_animimg_1normal_08);
LV_IMAGE_DECLARE(E_14_animimg_1normal_09);
LV_IMAGE_DECLARE(E_14_animimg_1normal_10);
LV_IMAGE_DECLARE(E_14_animimg_1normal_11);
LV_IMAGE_DECLARE(E_14_animimg_1normal_12);
LV_IMAGE_DECLARE(E_14_animimg_1normal_13);
LV_IMAGE_DECLARE(E_14_animimg_1normal_14);
LV_IMAGE_DECLARE(E_14_animimg_1normal_15);
LV_IMAGE_DECLARE(E_14_animimg_1normal_16);
LV_IMAGE_DECLARE(E_14_animimg_1normal_17);
LV_IMAGE_DECLARE(E_14_animimg_1normal_18);
LV_IMAGE_DECLARE(E_14_animimg_1normal_19);
LV_IMAGE_DECLARE(E_14_animimg_1normal_20);
LV_IMAGE_DECLARE(E_14_animimg_1normal_21);
LV_IMAGE_DECLARE(E_15_animimg_1happy_0);
LV_IMAGE_DECLARE(E_15_animimg_1happy_01);
LV_IMAGE_DECLARE(E_15_animimg_1happy_02);
LV_IMAGE_DECLARE(E_15_animimg_1happy_03);
LV_IMAGE_DECLARE(E_15_animimg_1happy_04);
LV_IMAGE_DECLARE(E_15_animimg_1happy_05);
LV_IMAGE_DECLARE(E_15_animimg_1happy_06);
LV_IMAGE_DECLARE(E_15_animimg_1happy_07);
LV_IMAGE_DECLARE(E_15_animimg_1happy_08);
LV_IMAGE_DECLARE(E_15_animimg_1happy_09);
LV_IMAGE_DECLARE(E_15_animimg_1happy_10);
LV_IMAGE_DECLARE(E_15_animimg_1happy_11);
LV_IMAGE_DECLARE(E_15_animimg_1happy_12);
LV_IMAGE_DECLARE(E_15_animimg_1happy_13);
LV_IMAGE_DECLARE(E_15_animimg_1happy_14);
LV_IMAGE_DECLARE(E_15_animimg_1happy_15);
LV_IMAGE_DECLARE(E_15_animimg_1happy_16);
LV_IMAGE_DECLARE(E_15_animimg_1happy_17);
LV_IMAGE_DECLARE(E_15_animimg_1happy_18);
LV_IMAGE_DECLARE(E_15_animimg_1happy_19);
LV_IMAGE_DECLARE(E_15_animimg_1happy_20);
LV_IMAGE_DECLARE(E_16_animimg_1left_0);
LV_IMAGE_DECLARE(E_16_animimg_1left_15);
LV_IMAGE_DECLARE(E_16_animimg_1left_16);
LV_IMAGE_DECLARE(E_16_animimg_1left_17);
LV_IMAGE_DECLARE(E_16_animimg_1left_18);
LV_IMAGE_DECLARE(E_16_animimg_1left_19);
LV_IMAGE_DECLARE(E_16_animimg_1left_20);
LV_IMAGE_DECLARE(E_16_animimg_1left_21);
LV_IMAGE_DECLARE(E_16_animimg_1left_22);
LV_IMAGE_DECLARE(E_16_animimg_1left_23);
LV_IMAGE_DECLARE(E_16_animimg_1left_24);
LV_IMAGE_DECLARE(E_16_animimg_1left_25);
LV_IMAGE_DECLARE(E_16_animimg_1left_26);
LV_IMAGE_DECLARE(E_16_animimg_1left_27);
LV_IMAGE_DECLARE(E_16_animimg_1left_28);
LV_IMAGE_DECLARE(E_16_animimg_1left_29);
LV_IMAGE_DECLARE(E_17_animimg_1right_0);
LV_IMAGE_DECLARE(E_17_animimg_1right_15);
LV_IMAGE_DECLARE(E_17_animimg_1right_16);
LV_IMAGE_DECLARE(E_17_animimg_1right_17);
LV_IMAGE_DECLARE(E_17_animimg_1right_18);
LV_IMAGE_DECLARE(E_17_animimg_1right_19);
LV_IMAGE_DECLARE(E_17_animimg_1right_20);
LV_IMAGE_DECLARE(E_17_animimg_1right_21);
LV_IMAGE_DECLARE(E_17_animimg_1right_22);
LV_IMAGE_DECLARE(E_17_animimg_1right_23);
LV_IMAGE_DECLARE(E_17_animimg_1right_24);
LV_IMAGE_DECLARE(E_17_animimg_1right_25);
LV_IMAGE_DECLARE(E_17_animimg_1right_26);
LV_IMAGE_DECLARE(E_17_animimg_1right_27);
LV_IMAGE_DECLARE(E_17_animimg_1right_28);
LV_IMAGE_DECLARE(E_17_animimg_1right_29);




#ifdef __cplusplus
}
#endif
#endif

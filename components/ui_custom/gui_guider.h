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
LV_IMAGE_DECLARE(E_2_animimg_1surprise20_0);
LV_IMAGE_DECLARE(E_2_animimg_1surprise20_01);
LV_IMAGE_DECLARE(E_2_animimg_1surprise20_02);
LV_IMAGE_DECLARE(E_2_animimg_1surprise20_03);
LV_IMAGE_DECLARE(E_2_animimg_1surprise20_04);
LV_IMAGE_DECLARE(E_2_animimg_1surprise20_05);
LV_IMAGE_DECLARE(E_2_animimg_1surprise20_06);
LV_IMAGE_DECLARE(E_2_animimg_1surprise20_07);
LV_IMAGE_DECLARE(E_2_animimg_1surprise20_08);
LV_IMAGE_DECLARE(E_2_animimg_1surprise20_09);
LV_IMAGE_DECLARE(E_2_animimg_1surprise20_10);
LV_IMAGE_DECLARE(E_2_animimg_1surprise20_11);
LV_IMAGE_DECLARE(E_2_animimg_1surprise20_12);
LV_IMAGE_DECLARE(E_2_animimg_1surprise20_13);
LV_IMAGE_DECLARE(E_2_animimg_1surprise20_14);
LV_IMAGE_DECLARE(E_2_animimg_1surprise20_15);
LV_IMAGE_DECLARE(E_2_animimg_1surprise20_16);
LV_IMAGE_DECLARE(E_2_animimg_1surprise20_17);
LV_IMAGE_DECLARE(E_2_animimg_1surprise20_18);
LV_IMAGE_DECLARE(E_2_animimg_1surprise20_19);
LV_IMAGE_DECLARE(E_2_animimg_1surprise20_20);
LV_IMAGE_DECLARE(E_2_animimg_1surprise20_21);
LV_IMAGE_DECLARE(E_2_animimg_1surprise20_22);
LV_IMAGE_DECLARE(E_2_animimg_1surprise20_23);
LV_IMAGE_DECLARE(E_2_animimg_1surprise20_24);
LV_IMAGE_DECLARE(E_2_animimg_1surprise20_25);
LV_IMAGE_DECLARE(E_2_animimg_1surprise20_26);
LV_IMAGE_DECLARE(E_2_animimg_1surprise20_27);
LV_IMAGE_DECLARE(E_2_animimg_1surprise20_28);
LV_IMAGE_DECLARE(E_2_animimg_1surprise20_29);
LV_IMAGE_DECLARE(E_2_animimg_1surprise20_30);
LV_IMAGE_DECLARE(E_2_animimg_1surprise20_31);
LV_IMAGE_DECLARE(E_2_animimg_1surprise20_32);
LV_IMAGE_DECLARE(E_2_animimg_1surprise20_33);
LV_IMAGE_DECLARE(E_2_animimg_1surprise20_34);
LV_IMAGE_DECLARE(E_2_animimg_1surprise20_35);
LV_IMAGE_DECLARE(E_2_animimg_1surprise20_36);
LV_IMAGE_DECLARE(E_2_animimg_1surprise20_37);
LV_IMAGE_DECLARE(E_2_animimg_1surprise20_38);
LV_IMAGE_DECLARE(E_2_animimg_1surprise20_39);
LV_IMAGE_DECLARE(E_5_animimg_1starface20_0);
LV_IMAGE_DECLARE(E_5_animimg_1starface20_01);
LV_IMAGE_DECLARE(E_5_animimg_1starface20_02);
LV_IMAGE_DECLARE(E_5_animimg_1starface20_03);
LV_IMAGE_DECLARE(E_5_animimg_1starface20_04);
LV_IMAGE_DECLARE(E_5_animimg_1starface20_05);
LV_IMAGE_DECLARE(E_5_animimg_1starface20_06);
LV_IMAGE_DECLARE(E_5_animimg_1starface20_07);
LV_IMAGE_DECLARE(E_5_animimg_1starface20_08);
LV_IMAGE_DECLARE(E_5_animimg_1starface20_09);
LV_IMAGE_DECLARE(E_5_animimg_1starface20_10);
LV_IMAGE_DECLARE(E_5_animimg_1starface20_11);
LV_IMAGE_DECLARE(E_5_animimg_1starface20_12);
LV_IMAGE_DECLARE(E_5_animimg_1starface20_13);
LV_IMAGE_DECLARE(E_5_animimg_1starface20_14);
LV_IMAGE_DECLARE(E_5_animimg_1starface20_15);
LV_IMAGE_DECLARE(E_5_animimg_1starface20_16);
LV_IMAGE_DECLARE(E_5_animimg_1starface20_17);
LV_IMAGE_DECLARE(E_5_animimg_1starface20_18);
LV_IMAGE_DECLARE(E_5_animimg_1starface20_19);
LV_IMAGE_DECLARE(E_5_animimg_1starface20_20);
LV_IMAGE_DECLARE(E_5_animimg_1starface20_21);
LV_IMAGE_DECLARE(E_5_animimg_1starface20_22);
LV_IMAGE_DECLARE(E_5_animimg_1starface20_23);
LV_IMAGE_DECLARE(E_5_animimg_1starface20_24);
LV_IMAGE_DECLARE(E_5_animimg_1starface20_25);
LV_IMAGE_DECLARE(E_5_animimg_1starface20_26);
LV_IMAGE_DECLARE(E_5_animimg_1starface20_27);
LV_IMAGE_DECLARE(E_5_animimg_1starface20_28);
LV_IMAGE_DECLARE(E_5_animimg_1starface20_29);
LV_IMAGE_DECLARE(E_5_animimg_1starface20_30);
LV_IMAGE_DECLARE(E_5_animimg_1starface20_31);
LV_IMAGE_DECLARE(E_5_animimg_1starface20_32);
LV_IMAGE_DECLARE(E_5_animimg_1starface20_33);
LV_IMAGE_DECLARE(E_5_animimg_1starface20_34);
LV_IMAGE_DECLARE(E_5_animimg_1starface20_35);
LV_IMAGE_DECLARE(E_5_animimg_1starface20_36);
LV_IMAGE_DECLARE(E_5_animimg_1starface20_37);
LV_IMAGE_DECLARE(E_5_animimg_1starface20_38);
LV_IMAGE_DECLARE(E_5_animimg_1starface20_39);
LV_IMAGE_DECLARE(E_7_animimg_1glasseswhite20_0);
LV_IMAGE_DECLARE(E_7_animimg_1glasseswhite20_01);
LV_IMAGE_DECLARE(E_7_animimg_1glasseswhite20_02);
LV_IMAGE_DECLARE(E_7_animimg_1glasseswhite20_03);
LV_IMAGE_DECLARE(E_7_animimg_1glasseswhite20_04);
LV_IMAGE_DECLARE(E_7_animimg_1glasseswhite20_05);
LV_IMAGE_DECLARE(E_7_animimg_1glasseswhite20_06);
LV_IMAGE_DECLARE(E_7_animimg_1glasseswhite20_07);
LV_IMAGE_DECLARE(E_7_animimg_1glasseswhite20_08);
LV_IMAGE_DECLARE(E_7_animimg_1glasseswhite20_09);
LV_IMAGE_DECLARE(E_7_animimg_1glasseswhite20_10);
LV_IMAGE_DECLARE(E_7_animimg_1glasseswhite20_11);
LV_IMAGE_DECLARE(E_7_animimg_1glasseswhite20_12);
LV_IMAGE_DECLARE(E_7_animimg_1glasseswhite20_13);
LV_IMAGE_DECLARE(E_7_animimg_1glasseswhite20_14);
LV_IMAGE_DECLARE(E_7_animimg_1glasseswhite20_15);
LV_IMAGE_DECLARE(E_7_animimg_1glasseswhite20_16);
LV_IMAGE_DECLARE(E_7_animimg_1glasseswhite20_17);
LV_IMAGE_DECLARE(E_7_animimg_1glasseswhite20_18);
LV_IMAGE_DECLARE(E_7_animimg_1glasseswhite20_19);
LV_IMAGE_DECLARE(E_7_animimg_1glasseswhite20_20);
LV_IMAGE_DECLARE(E_7_animimg_1glasseswhite20_21);
LV_IMAGE_DECLARE(E_7_animimg_1glasseswhite20_22);
LV_IMAGE_DECLARE(E_7_animimg_1glasseswhite20_23);
LV_IMAGE_DECLARE(E_7_animimg_1glasseswhite20_24);
LV_IMAGE_DECLARE(E_7_animimg_1glasseswhite20_25);
LV_IMAGE_DECLARE(E_7_animimg_1glasseswhite20_26);
LV_IMAGE_DECLARE(E_7_animimg_1glasseswhite20_27);
LV_IMAGE_DECLARE(E_7_animimg_1glasseswhite20_28);
LV_IMAGE_DECLARE(E_7_animimg_1glasseswhite20_29);
LV_IMAGE_DECLARE(E_7_animimg_1glasseswhite20_30);
LV_IMAGE_DECLARE(E_7_animimg_1glasseswhite20_31);
LV_IMAGE_DECLARE(E_7_animimg_1glasseswhite20_32);
LV_IMAGE_DECLARE(E_7_animimg_1glasseswhite20_33);
LV_IMAGE_DECLARE(E_7_animimg_1glasseswhite20_34);
LV_IMAGE_DECLARE(E_7_animimg_1glasseswhite20_35);
LV_IMAGE_DECLARE(E_7_animimg_1glasseswhite20_36);
LV_IMAGE_DECLARE(E_7_animimg_1glasseswhite20_37);
LV_IMAGE_DECLARE(E_7_animimg_1glasseswhite20_38);
LV_IMAGE_DECLARE(E_7_animimg_1glasseswhite20_39);
LV_IMAGE_DECLARE(E_8_animimg_1happy_0);
LV_IMAGE_DECLARE(E_8_animimg_1happy_01);
LV_IMAGE_DECLARE(E_8_animimg_1happy_02);
LV_IMAGE_DECLARE(E_8_animimg_1happy_03);
LV_IMAGE_DECLARE(E_8_animimg_1happy_04);
LV_IMAGE_DECLARE(E_8_animimg_1happy_05);
LV_IMAGE_DECLARE(E_8_animimg_1happy_06);
LV_IMAGE_DECLARE(E_8_animimg_1happy_07);
LV_IMAGE_DECLARE(E_8_animimg_1happy_08);
LV_IMAGE_DECLARE(E_8_animimg_1happy_09);
LV_IMAGE_DECLARE(E_8_animimg_1happy_10);
LV_IMAGE_DECLARE(E_8_animimg_1happy_11);
LV_IMAGE_DECLARE(E_8_animimg_1happy_12);
LV_IMAGE_DECLARE(E_8_animimg_1happy_13);
LV_IMAGE_DECLARE(E_8_animimg_1happy_14);
LV_IMAGE_DECLARE(E_8_animimg_1happy_15);
LV_IMAGE_DECLARE(E_8_animimg_1happy_16);
LV_IMAGE_DECLARE(E_8_animimg_1happy_17);
LV_IMAGE_DECLARE(E_8_animimg_1happy_18);
LV_IMAGE_DECLARE(E_8_animimg_1happy_19);
LV_IMAGE_DECLARE(E_8_animimg_1happy_20);
LV_IMAGE_DECLARE(E_8_animimg_1happy_21);
LV_IMAGE_DECLARE(E_8_animimg_1happy_22);
LV_IMAGE_DECLARE(E_8_animimg_1happy_23);
LV_IMAGE_DECLARE(E_8_animimg_1happy_24);
LV_IMAGE_DECLARE(E_8_animimg_1happy_25);
LV_IMAGE_DECLARE(E_8_animimg_1happy_26);
LV_IMAGE_DECLARE(E_8_animimg_1happy_27);
LV_IMAGE_DECLARE(E_8_animimg_1happy_28);
LV_IMAGE_DECLARE(E_8_animimg_1happy_29);
LV_IMAGE_DECLARE(E_10_animimg_1dizzy_0);
LV_IMAGE_DECLARE(E_10_animimg_1dizzy_01);
LV_IMAGE_DECLARE(E_10_animimg_1dizzy_02);
LV_IMAGE_DECLARE(E_10_animimg_1dizzy_03);
LV_IMAGE_DECLARE(E_10_animimg_1dizzy_04);
LV_IMAGE_DECLARE(E_10_animimg_1dizzy_05);
LV_IMAGE_DECLARE(E_10_animimg_1dizzy_06);
LV_IMAGE_DECLARE(E_10_animimg_1dizzy_07);
LV_IMAGE_DECLARE(E_10_animimg_1dizzy_08);
LV_IMAGE_DECLARE(E_10_animimg_1dizzy_09);
LV_IMAGE_DECLARE(E_10_animimg_1dizzy_10);
LV_IMAGE_DECLARE(E_10_animimg_1dizzy_11);
LV_IMAGE_DECLARE(E_10_animimg_1dizzy_12);
LV_IMAGE_DECLARE(E_10_animimg_1dizzy_13);
LV_IMAGE_DECLARE(E_10_animimg_1dizzy_14);
LV_IMAGE_DECLARE(E_10_animimg_1dizzy_15);
LV_IMAGE_DECLARE(E_10_animimg_1dizzy_16);
LV_IMAGE_DECLARE(E_10_animimg_1dizzy_17);
LV_IMAGE_DECLARE(E_10_animimg_1dizzy_18);
LV_IMAGE_DECLARE(E_10_animimg_1dizzy_19);
LV_IMAGE_DECLARE(E_10_animimg_1dizzy_20);
LV_IMAGE_DECLARE(E_10_animimg_1dizzy_21);
LV_IMAGE_DECLARE(E_10_animimg_1dizzy_22);
LV_IMAGE_DECLARE(E_10_animimg_1dizzy_23);
LV_IMAGE_DECLARE(E_10_animimg_1dizzy_24);
LV_IMAGE_DECLARE(E_10_animimg_1dizzy_25);
LV_IMAGE_DECLARE(E_10_animimg_1dizzy_26);
LV_IMAGE_DECLARE(E_10_animimg_1dizzy_27);
LV_IMAGE_DECLARE(E_10_animimg_1dizzy_28);
LV_IMAGE_DECLARE(E_10_animimg_1dizzy_29);
LV_IMAGE_DECLARE(E_13_animimg_1left_0);
LV_IMAGE_DECLARE(E_13_animimg_1left_01);
LV_IMAGE_DECLARE(E_13_animimg_1left_02);
LV_IMAGE_DECLARE(E_13_animimg_1left_03);
LV_IMAGE_DECLARE(E_13_animimg_1left_04);
LV_IMAGE_DECLARE(E_13_animimg_1left_05);
LV_IMAGE_DECLARE(E_13_animimg_1left_06);
LV_IMAGE_DECLARE(E_13_animimg_1left_07);
LV_IMAGE_DECLARE(E_13_animimg_1left_08);
LV_IMAGE_DECLARE(E_13_animimg_1left_09);
LV_IMAGE_DECLARE(E_13_animimg_1left_10);
LV_IMAGE_DECLARE(E_13_animimg_1left_12);
LV_IMAGE_DECLARE(E_13_animimg_1left_13);
LV_IMAGE_DECLARE(E_13_animimg_1left_14);
LV_IMAGE_DECLARE(E_13_animimg_1left_15);
LV_IMAGE_DECLARE(E_13_animimg_1left_16);
LV_IMAGE_DECLARE(E_13_animimg_1left_17);
LV_IMAGE_DECLARE(E_13_animimg_1left_18);
LV_IMAGE_DECLARE(E_13_animimg_1left_19);
LV_IMAGE_DECLARE(E_13_animimg_1left_20);
LV_IMAGE_DECLARE(E_13_animimg_1left_21);
LV_IMAGE_DECLARE(E_13_animimg_1left_22);
LV_IMAGE_DECLARE(E_13_animimg_1left_23);
LV_IMAGE_DECLARE(E_13_animimg_1left_24);
LV_IMAGE_DECLARE(E_13_animimg_1left_25);
LV_IMAGE_DECLARE(E_13_animimg_1left_26);
LV_IMAGE_DECLARE(E_13_animimg_1left_27);
LV_IMAGE_DECLARE(E_13_animimg_1left_28);
LV_IMAGE_DECLARE(E_13_animimg_1left_29);
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
LV_IMAGE_DECLARE(E_14_animimg_1normal_22);
LV_IMAGE_DECLARE(E_14_animimg_1normal_23);
LV_IMAGE_DECLARE(E_14_animimg_1normal_24);
LV_IMAGE_DECLARE(E_14_animimg_1normal_25);
LV_IMAGE_DECLARE(E_14_animimg_1normal_26);
LV_IMAGE_DECLARE(E_14_animimg_1normal_27);
LV_IMAGE_DECLARE(E_14_animimg_1normal_28);
LV_IMAGE_DECLARE(E_14_animimg_1normal_29);
LV_IMAGE_DECLARE(E_15_animimg_1leftlook20_0);
LV_IMAGE_DECLARE(E_15_animimg_1leftlook20_01);
LV_IMAGE_DECLARE(E_15_animimg_1leftlook20_02);
LV_IMAGE_DECLARE(E_15_animimg_1leftlook20_03);
LV_IMAGE_DECLARE(E_15_animimg_1leftlook20_04);
LV_IMAGE_DECLARE(E_15_animimg_1leftlook20_05);
LV_IMAGE_DECLARE(E_15_animimg_1leftlook20_06);
LV_IMAGE_DECLARE(E_15_animimg_1leftlook20_07);
LV_IMAGE_DECLARE(E_15_animimg_1leftlook20_08);
LV_IMAGE_DECLARE(E_15_animimg_1leftlook20_09);
LV_IMAGE_DECLARE(E_15_animimg_1leftlook20_10);
LV_IMAGE_DECLARE(E_15_animimg_1leftlook20_11);
LV_IMAGE_DECLARE(E_15_animimg_1leftlook20_12);
LV_IMAGE_DECLARE(E_15_animimg_1leftlook20_13);
LV_IMAGE_DECLARE(E_15_animimg_1leftlook20_14);
LV_IMAGE_DECLARE(E_15_animimg_1leftlook20_15);
LV_IMAGE_DECLARE(E_15_animimg_1leftlook20_16);
LV_IMAGE_DECLARE(E_15_animimg_1leftlook20_17);
LV_IMAGE_DECLARE(E_15_animimg_1leftlook20_18);
LV_IMAGE_DECLARE(E_15_animimg_1leftlook20_19);
LV_IMAGE_DECLARE(E_15_animimg_1leftlook20_20);
LV_IMAGE_DECLARE(E_15_animimg_1leftlook20_21);
LV_IMAGE_DECLARE(E_15_animimg_1leftlook20_22);
LV_IMAGE_DECLARE(E_15_animimg_1leftlook20_23);
LV_IMAGE_DECLARE(E_15_animimg_1leftlook20_24);
LV_IMAGE_DECLARE(E_15_animimg_1leftlook20_25);
LV_IMAGE_DECLARE(E_15_animimg_1leftlook20_26);
LV_IMAGE_DECLARE(E_15_animimg_1leftlook20_27);
LV_IMAGE_DECLARE(E_15_animimg_1leftlook20_28);
LV_IMAGE_DECLARE(E_15_animimg_1leftlook20_29);
LV_IMAGE_DECLARE(E_15_animimg_1leftlook20_30);
LV_IMAGE_DECLARE(E_15_animimg_1leftlook20_31);
LV_IMAGE_DECLARE(E_15_animimg_1leftlook20_32);
LV_IMAGE_DECLARE(E_15_animimg_1leftlook20_33);
LV_IMAGE_DECLARE(E_15_animimg_1leftlook20_34);
LV_IMAGE_DECLARE(E_15_animimg_1leftlook20_35);
LV_IMAGE_DECLARE(E_15_animimg_1leftlook20_36);
LV_IMAGE_DECLARE(E_15_animimg_1leftlook20_37);
LV_IMAGE_DECLARE(E_15_animimg_1leftlook20_38);
LV_IMAGE_DECLARE(E_15_animimg_1leftlook20_39);
LV_IMAGE_DECLARE(E_16_animimg_1rightlook20_0);
LV_IMAGE_DECLARE(E_16_animimg_1rightlook20_01);
LV_IMAGE_DECLARE(E_16_animimg_1rightlook20_02);
LV_IMAGE_DECLARE(E_16_animimg_1rightlook20_03);
LV_IMAGE_DECLARE(E_16_animimg_1rightlook20_04);
LV_IMAGE_DECLARE(E_16_animimg_1rightlook20_05);
LV_IMAGE_DECLARE(E_16_animimg_1rightlook20_06);
LV_IMAGE_DECLARE(E_16_animimg_1rightlook20_07);
LV_IMAGE_DECLARE(E_16_animimg_1rightlook20_08);
LV_IMAGE_DECLARE(E_16_animimg_1rightlook20_09);
LV_IMAGE_DECLARE(E_16_animimg_1rightlook20_10);
LV_IMAGE_DECLARE(E_16_animimg_1rightlook20_11);
LV_IMAGE_DECLARE(E_16_animimg_1rightlook20_12);
LV_IMAGE_DECLARE(E_16_animimg_1rightlook20_13);
LV_IMAGE_DECLARE(E_16_animimg_1rightlook20_14);
LV_IMAGE_DECLARE(E_16_animimg_1rightlook20_15);
LV_IMAGE_DECLARE(E_16_animimg_1rightlook20_16);
LV_IMAGE_DECLARE(E_16_animimg_1rightlook20_17);
LV_IMAGE_DECLARE(E_16_animimg_1rightlook20_18);
LV_IMAGE_DECLARE(E_16_animimg_1rightlook20_19);
LV_IMAGE_DECLARE(E_16_animimg_1rightlook20_20);
LV_IMAGE_DECLARE(E_16_animimg_1rightlook20_21);
LV_IMAGE_DECLARE(E_16_animimg_1rightlook20_22);
LV_IMAGE_DECLARE(E_16_animimg_1rightlook20_23);
LV_IMAGE_DECLARE(E_16_animimg_1rightlook20_24);
LV_IMAGE_DECLARE(E_16_animimg_1rightlook20_25);
LV_IMAGE_DECLARE(E_16_animimg_1rightlook20_26);
LV_IMAGE_DECLARE(E_16_animimg_1rightlook20_27);
LV_IMAGE_DECLARE(E_16_animimg_1rightlook20_28);
LV_IMAGE_DECLARE(E_16_animimg_1rightlook20_29);
LV_IMAGE_DECLARE(E_16_animimg_1rightlook20_30);
LV_IMAGE_DECLARE(E_16_animimg_1rightlook20_31);
LV_IMAGE_DECLARE(E_16_animimg_1rightlook20_32);
LV_IMAGE_DECLARE(E_16_animimg_1rightlook20_33);
LV_IMAGE_DECLARE(E_16_animimg_1rightlook20_34);
LV_IMAGE_DECLARE(E_16_animimg_1rightlook20_35);
LV_IMAGE_DECLARE(E_16_animimg_1rightlook20_36);
LV_IMAGE_DECLARE(E_16_animimg_1rightlook20_37);
LV_IMAGE_DECLARE(E_16_animimg_1rightlook20_38);
LV_IMAGE_DECLARE(E_16_animimg_1rightlook20_39);
LV_IMAGE_DECLARE(E_17_animimg_1right_0);
LV_IMAGE_DECLARE(E_17_animimg_1right_01);
LV_IMAGE_DECLARE(E_17_animimg_1right_02);
LV_IMAGE_DECLARE(E_17_animimg_1right_03);
LV_IMAGE_DECLARE(E_17_animimg_1right_04);
LV_IMAGE_DECLARE(E_17_animimg_1right_05);
LV_IMAGE_DECLARE(E_17_animimg_1right_06);
LV_IMAGE_DECLARE(E_17_animimg_1right_07);
LV_IMAGE_DECLARE(E_17_animimg_1right_08);
LV_IMAGE_DECLARE(E_17_animimg_1right_09);
LV_IMAGE_DECLARE(E_17_animimg_1right_10);
LV_IMAGE_DECLARE(E_17_animimg_1right_11);
LV_IMAGE_DECLARE(E_17_animimg_1right_12);
LV_IMAGE_DECLARE(E_17_animimg_1right_13);
LV_IMAGE_DECLARE(E_17_animimg_1right_14);
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

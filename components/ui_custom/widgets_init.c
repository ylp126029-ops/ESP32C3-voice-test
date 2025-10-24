/*
* Copyright 2025 NXP
* NXP Proprietary. This software is owned or controlled by NXP and may only be used strictly in
* accordance with the applicable license terms. By expressly accepting such terms or by downloading, installing,
* activating and/or otherwise using the software, you are agreeing that you have read, and that you agree to
* comply with and are bound by, such license terms.  If you do not agree to be bound by the applicable license
* terms, then you may not retain, install, activate or otherwise use the software.
*/

#include "lvgl.h"
#include "gui_guider.h"
#include "widgets_init.h"
#include <stdlib.h>
#include <string.h>


__attribute__((unused)) void kb_event_cb (lv_event_t *e) {
    lv_event_code_t code = lv_event_get_code(e);
    lv_obj_t *kb = lv_event_get_target(e);
    if(code == LV_EVENT_READY || code == LV_EVENT_CANCEL) {
        lv_obj_add_flag(kb, LV_OBJ_FLAG_HIDDEN);
    }
}

__attribute__((unused)) void ta_event_cb (lv_event_t *e) {
#if LV_USE_KEYBOARD
    lv_event_code_t code = lv_event_get_code(e);
    lv_obj_t * ta = lv_event_get_target(e);
    lv_obj_t * kb = lv_event_get_user_data(e);

    if(code == LV_EVENT_FOCUSED) {
        if(lv_indev_get_type(lv_indev_active()) != LV_INDEV_TYPE_KEYPAD) {
            lv_keyboard_set_textarea(kb, ta);
            lv_obj_remove_flag(kb, LV_OBJ_FLAG_HIDDEN);
        }
    } else if(code == LV_EVENT_READY) {
        lv_obj_add_flag(kb, LV_OBJ_FLAG_HIDDEN);
        lv_obj_remove_state(ta, LV_STATE_FOCUSED);
        lv_indev_reset(NULL, ta);
    } else if(code == LV_EVENT_DEFOCUSED) {
        lv_keyboard_set_textarea(kb, NULL);
        lv_obj_add_flag(kb, LV_OBJ_FLAG_HIDDEN);
    }
#endif
}

void clock_count(int *hour, int *min, int *sec)
{
    (*sec)++;
    if(*sec == 60)
    {
        *sec = 0;
        (*min)++;
    }
    if(*min == 60)
    {
        *min = 0;
        if(*hour < 12)
        {
            (*hour)++;
        } else {
            (*hour)++;
            *hour = *hour %12;
        }
    }
}

void digital_clock_count(int * hour, int * minute, int * seconds, char * meridiem)
{

    (*seconds)++;
    if(*seconds == 60) {
        *seconds = 0;
        (*minute)++;
    }
    if(*minute == 60) {
        *minute = 0;
        if(*hour < 12) {
            (*hour)++;
        }
        else {
            (*hour)++;
            (*hour) = (*hour) % 12;
        }
    }
    if(*hour == 12 && *seconds == 0 && *minute == 0) {
        if((lv_strcmp(meridiem, "PM") == 0)) {
            lv_strcpy(meridiem, "AM");
        }
        else {
            lv_strcpy(meridiem, "PM");
        }
    }
}


const lv_image_dsc_t * E_2_animimg_1_imgs[21] = {
    &E_2_animimg_1smile_01,
    &E_2_animimg_1smile_02,
    &E_2_animimg_1smile_03,
    &E_2_animimg_1smile_04,
    &E_2_animimg_1smile_05,
    &E_2_animimg_1smile_06,
    &E_2_animimg_1smile_07,
    &E_2_animimg_1smile_08,
    &E_2_animimg_1smile_09,
    &E_2_animimg_1smile_10,
    &E_2_animimg_1smile_11,
    &E_2_animimg_1smile_12,
    &E_2_animimg_1smile_13,
    &E_2_animimg_1smile_14,
    &E_2_animimg_1smile_15,
    &E_2_animimg_1smile_16,
    &E_2_animimg_1smile_17,
    &E_2_animimg_1smile_18,
    &E_2_animimg_1smile_19,
    &E_2_animimg_1smile_20,
    &E_2_animimg_1smile_21,
};
const lv_image_dsc_t * E_5_animimg_1_imgs[23] = {
    &E_5_animimg_1drink_01,
    &E_5_animimg_1drink_02,
    &E_5_animimg_1drink_03,
    &E_5_animimg_1drink_04,
    &E_5_animimg_1drink_05,
    &E_5_animimg_1drink_06,
    &E_5_animimg_1drink_07,
    &E_5_animimg_1drink_08,
    &E_5_animimg_1drink_09,
    &E_5_animimg_1drink_10,
    &E_5_animimg_1drink_11,
    &E_5_animimg_1drink_12,
    &E_5_animimg_1drink_13,
    &E_5_animimg_1drink_14,
    &E_5_animimg_1drink_15,
    &E_5_animimg_1drink_16,
    &E_5_animimg_1drink_17,
    &E_5_animimg_1drink_18,
    &E_5_animimg_1drink_19,
    &E_5_animimg_1drink_20,
    &E_5_animimg_1drink_21,
    &E_5_animimg_1drink_22,
    &E_5_animimg_1drink_23,
};
const lv_image_dsc_t * E_7_animimg_1_imgs[20] = {
    &E_7_animimg_1shy_0,
    &E_7_animimg_1shy_01,
    &E_7_animimg_1shy_02,
    &E_7_animimg_1shy_03,
    &E_7_animimg_1shy_04,
    &E_7_animimg_1shy_05,
    &E_7_animimg_1shy_06,
    &E_7_animimg_1shy_07,
    &E_7_animimg_1shy_09,
    &E_7_animimg_1shy_12,
    &E_7_animimg_1shy_13,
    &E_7_animimg_1shy_14,
    &E_7_animimg_1shy_15,
    &E_7_animimg_1shy_16,
    &E_7_animimg_1shy_17,
    &E_7_animimg_1shy_18,
    &E_7_animimg_1shy_19,
    &E_7_animimg_1shy_20,
    &E_7_animimg_1shy_21,
    &E_7_animimg_1shy_29,
};
const lv_image_dsc_t * E_8_animimg_1_imgs[21] = {
    &E_8_animimg_1sway_0,
    &E_8_animimg_1sway_01,
    &E_8_animimg_1sway_02,
    &E_8_animimg_1sway_03,
    &E_8_animimg_1sway_04,
    &E_8_animimg_1sway_05,
    &E_8_animimg_1sway_06,
    &E_8_animimg_1sway_07,
    &E_8_animimg_1sway_08,
    &E_8_animimg_1sway_09,
    &E_8_animimg_1sway_10,
    &E_8_animimg_1sway_11,
    &E_8_animimg_1sway_12,
    &E_8_animimg_1sway_16,
    &E_8_animimg_1sway_17,
    &E_8_animimg_1sway_18,
    &E_8_animimg_1sway_19,
    &E_8_animimg_1sway_20,
    &E_8_animimg_1sway_21,
    &E_8_animimg_1sway_22,
    &E_8_animimg_1sway_23,
};
const lv_image_dsc_t * E_10_animimg_1_imgs[18] = {
    &E_10_animimg_1sing_0,
    &E_10_animimg_1sing_01,
    &E_10_animimg_1sing_02,
    &E_10_animimg_1sing_03,
    &E_10_animimg_1sing_04,
    &E_10_animimg_1sing_05,
    &E_10_animimg_1sing_06,
    &E_10_animimg_1sing_07,
    &E_10_animimg_1sing_08,
    &E_10_animimg_1sing_09,
    &E_10_animimg_1sing_14,
    &E_10_animimg_1sing_15,
    &E_10_animimg_1sing_16,
    &E_10_animimg_1sing_17,
    &E_10_animimg_1sing_18,
    &E_10_animimg_1sing_19,
    &E_10_animimg_1sing_20,
    &E_10_animimg_1sing_21,
};
const lv_image_dsc_t * E_13_animimg_1_imgs[21] = {
    &E_13_animimg_1glass_0,
    &E_13_animimg_1glass_01,
    &E_13_animimg_1glass_02,
    &E_13_animimg_1glass_03,
    &E_13_animimg_1glass_04,
    &E_13_animimg_1glass_05,
    &E_13_animimg_1glass_06,
    &E_13_animimg_1glass_07,
    &E_13_animimg_1glass_08,
    &E_13_animimg_1glass_09,
    &E_13_animimg_1glass_12,
    &E_13_animimg_1glass_13,
    &E_13_animimg_1glass_14,
    &E_13_animimg_1glass_15,
    &E_13_animimg_1glass_16,
    &E_13_animimg_1glass_17,
    &E_13_animimg_1glass_18,
    &E_13_animimg_1glass_19,
    &E_13_animimg_1glass_20,
    &E_13_animimg_1glass_21,
    &E_13_animimg_1glass_22,
};
const lv_image_dsc_t * E_14_animimg_1_imgs[22] = {
    &E_14_animimg_1normal_0,
    &E_14_animimg_1normal_01,
    &E_14_animimg_1normal_02,
    &E_14_animimg_1normal_03,
    &E_14_animimg_1normal_04,
    &E_14_animimg_1normal_05,
    &E_14_animimg_1normal_06,
    &E_14_animimg_1normal_07,
    &E_14_animimg_1normal_08,
    &E_14_animimg_1normal_09,
    &E_14_animimg_1normal_10,
    &E_14_animimg_1normal_11,
    &E_14_animimg_1normal_12,
    &E_14_animimg_1normal_13,
    &E_14_animimg_1normal_14,
    &E_14_animimg_1normal_15,
    &E_14_animimg_1normal_16,
    &E_14_animimg_1normal_17,
    &E_14_animimg_1normal_18,
    &E_14_animimg_1normal_19,
    &E_14_animimg_1normal_20,
    &E_14_animimg_1normal_21,
};
const lv_image_dsc_t * E_15_animimg_1_imgs[21] = {
    &E_15_animimg_1happy_0,
    &E_15_animimg_1happy_01,
    &E_15_animimg_1happy_02,
    &E_15_animimg_1happy_03,
    &E_15_animimg_1happy_04,
    &E_15_animimg_1happy_05,
    &E_15_animimg_1happy_06,
    &E_15_animimg_1happy_07,
    &E_15_animimg_1happy_08,
    &E_15_animimg_1happy_09,
    &E_15_animimg_1happy_10,
    &E_15_animimg_1happy_11,
    &E_15_animimg_1happy_12,
    &E_15_animimg_1happy_13,
    &E_15_animimg_1happy_14,
    &E_15_animimg_1happy_15,
    &E_15_animimg_1happy_16,
    &E_15_animimg_1happy_17,
    &E_15_animimg_1happy_18,
    &E_15_animimg_1happy_19,
    &E_15_animimg_1happy_20,
};
const lv_image_dsc_t * E_16_animimg_1_imgs[16] = {
    &E_16_animimg_1left_0,
    &E_16_animimg_1left_15,
    &E_16_animimg_1left_16,
    &E_16_animimg_1left_17,
    &E_16_animimg_1left_18,
    &E_16_animimg_1left_19,
    &E_16_animimg_1left_20,
    &E_16_animimg_1left_21,
    &E_16_animimg_1left_22,
    &E_16_animimg_1left_23,
    &E_16_animimg_1left_24,
    &E_16_animimg_1left_25,
    &E_16_animimg_1left_26,
    &E_16_animimg_1left_27,
    &E_16_animimg_1left_28,
    &E_16_animimg_1left_29,
};
const lv_image_dsc_t * E_17_animimg_1_imgs[16] = {
    &E_17_animimg_1right_0,
    &E_17_animimg_1right_15,
    &E_17_animimg_1right_16,
    &E_17_animimg_1right_17,
    &E_17_animimg_1right_18,
    &E_17_animimg_1right_19,
    &E_17_animimg_1right_20,
    &E_17_animimg_1right_21,
    &E_17_animimg_1right_22,
    &E_17_animimg_1right_23,
    &E_17_animimg_1right_24,
    &E_17_animimg_1right_25,
    &E_17_animimg_1right_26,
    &E_17_animimg_1right_27,
    &E_17_animimg_1right_28,
    &E_17_animimg_1right_29,
};

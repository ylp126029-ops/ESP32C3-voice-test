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


const lv_image_dsc_t * E_2_animimg_1_imgs[40] = {
    &E_2_animimg_1surprise20_0,
    &E_2_animimg_1surprise20_01,
    &E_2_animimg_1surprise20_02,
    &E_2_animimg_1surprise20_03,
    &E_2_animimg_1surprise20_04,
    &E_2_animimg_1surprise20_05,
    &E_2_animimg_1surprise20_06,
    &E_2_animimg_1surprise20_07,
    &E_2_animimg_1surprise20_08,
    &E_2_animimg_1surprise20_09,
    &E_2_animimg_1surprise20_10,
    &E_2_animimg_1surprise20_11,
    &E_2_animimg_1surprise20_12,
    &E_2_animimg_1surprise20_13,
    &E_2_animimg_1surprise20_14,
    &E_2_animimg_1surprise20_15,
    &E_2_animimg_1surprise20_16,
    &E_2_animimg_1surprise20_17,
    &E_2_animimg_1surprise20_18,
    &E_2_animimg_1surprise20_19,
    &E_2_animimg_1surprise20_20,
    &E_2_animimg_1surprise20_21,
    &E_2_animimg_1surprise20_22,
    &E_2_animimg_1surprise20_23,
    &E_2_animimg_1surprise20_24,
    &E_2_animimg_1surprise20_25,
    &E_2_animimg_1surprise20_26,
    &E_2_animimg_1surprise20_27,
    &E_2_animimg_1surprise20_28,
    &E_2_animimg_1surprise20_29,
    &E_2_animimg_1surprise20_30,
    &E_2_animimg_1surprise20_31,
    &E_2_animimg_1surprise20_32,
    &E_2_animimg_1surprise20_33,
    &E_2_animimg_1surprise20_34,
    &E_2_animimg_1surprise20_35,
    &E_2_animimg_1surprise20_36,
    &E_2_animimg_1surprise20_37,
    &E_2_animimg_1surprise20_38,
    &E_2_animimg_1surprise20_39,
};

const lv_image_dsc_t * E_5_animimg_1_imgs[40] = {
    &E_5_animimg_1starface20_0,
    &E_5_animimg_1starface20_01,
    &E_5_animimg_1starface20_02,
    &E_5_animimg_1starface20_03,
    &E_5_animimg_1starface20_04,
    &E_5_animimg_1starface20_05,
    &E_5_animimg_1starface20_06,
    &E_5_animimg_1starface20_07,
    &E_5_animimg_1starface20_08,
    &E_5_animimg_1starface20_09,
    &E_5_animimg_1starface20_10,
    &E_5_animimg_1starface20_11,
    &E_5_animimg_1starface20_12,
    &E_5_animimg_1starface20_13,
    &E_5_animimg_1starface20_14,
    &E_5_animimg_1starface20_15,
    &E_5_animimg_1starface20_16,
    &E_5_animimg_1starface20_17,
    &E_5_animimg_1starface20_18,
    &E_5_animimg_1starface20_19,
    &E_5_animimg_1starface20_20,
    &E_5_animimg_1starface20_21,
    &E_5_animimg_1starface20_22,
    &E_5_animimg_1starface20_23,
    &E_5_animimg_1starface20_24,
    &E_5_animimg_1starface20_25,
    &E_5_animimg_1starface20_26,
    &E_5_animimg_1starface20_27,
    &E_5_animimg_1starface20_28,
    &E_5_animimg_1starface20_29,
    &E_5_animimg_1starface20_30,
    &E_5_animimg_1starface20_31,
    &E_5_animimg_1starface20_32,
    &E_5_animimg_1starface20_33,
    &E_5_animimg_1starface20_34,
    &E_5_animimg_1starface20_35,
    &E_5_animimg_1starface20_36,
    &E_5_animimg_1starface20_37,
    &E_5_animimg_1starface20_38,
    &E_5_animimg_1starface20_39,
};


const lv_image_dsc_t * E_7_animimg_1_imgs[40] = {
    &E_7_animimg_1glasseswhite20_0,
    &E_7_animimg_1glasseswhite20_01,
    &E_7_animimg_1glasseswhite20_02,
    &E_7_animimg_1glasseswhite20_03,
    &E_7_animimg_1glasseswhite20_04,
    &E_7_animimg_1glasseswhite20_05,
    &E_7_animimg_1glasseswhite20_06,
    &E_7_animimg_1glasseswhite20_07,
    &E_7_animimg_1glasseswhite20_08,
    &E_7_animimg_1glasseswhite20_09,
    &E_7_animimg_1glasseswhite20_10,
    &E_7_animimg_1glasseswhite20_11,
    &E_7_animimg_1glasseswhite20_12,
    &E_7_animimg_1glasseswhite20_13,
    &E_7_animimg_1glasseswhite20_14,
    &E_7_animimg_1glasseswhite20_15,
    &E_7_animimg_1glasseswhite20_16,
    &E_7_animimg_1glasseswhite20_17,
    &E_7_animimg_1glasseswhite20_18,
    &E_7_animimg_1glasseswhite20_19,
    &E_7_animimg_1glasseswhite20_20,
    &E_7_animimg_1glasseswhite20_21,
    &E_7_animimg_1glasseswhite20_22,
    &E_7_animimg_1glasseswhite20_23,
    &E_7_animimg_1glasseswhite20_24,
    &E_7_animimg_1glasseswhite20_25,
    &E_7_animimg_1glasseswhite20_26,
    &E_7_animimg_1glasseswhite20_27,
    &E_7_animimg_1glasseswhite20_28,
    &E_7_animimg_1glasseswhite20_29,
    &E_7_animimg_1glasseswhite20_30,
    &E_7_animimg_1glasseswhite20_31,
    &E_7_animimg_1glasseswhite20_32,
    &E_7_animimg_1glasseswhite20_33,
    &E_7_animimg_1glasseswhite20_34,
    &E_7_animimg_1glasseswhite20_35,
    &E_7_animimg_1glasseswhite20_36,
    &E_7_animimg_1glasseswhite20_37,
    &E_7_animimg_1glasseswhite20_38,
    &E_7_animimg_1glasseswhite20_39,
};

const lv_image_dsc_t * E_8_animimg_1_imgs[30] = {
    &E_8_animimg_1happy_0,
    &E_8_animimg_1happy_01,
    &E_8_animimg_1happy_02,
    &E_8_animimg_1happy_03,
    &E_8_animimg_1happy_04,
    &E_8_animimg_1happy_05,
    &E_8_animimg_1happy_06,
    &E_8_animimg_1happy_07,
    &E_8_animimg_1happy_08,
    &E_8_animimg_1happy_09,
    &E_8_animimg_1happy_10,
    &E_8_animimg_1happy_11,
    &E_8_animimg_1happy_12,
    &E_8_animimg_1happy_13,
    &E_8_animimg_1happy_14,
    &E_8_animimg_1happy_15,
    &E_8_animimg_1happy_16,
    &E_8_animimg_1happy_17,
    &E_8_animimg_1happy_18,
    &E_8_animimg_1happy_19,
    &E_8_animimg_1happy_20,
    &E_8_animimg_1happy_21,
    &E_8_animimg_1happy_22,
    &E_8_animimg_1happy_23,
    &E_8_animimg_1happy_24,
    &E_8_animimg_1happy_25,
    &E_8_animimg_1happy_26,
    &E_8_animimg_1happy_27,
    &E_8_animimg_1happy_28,
    &E_8_animimg_1happy_29,
};
const lv_image_dsc_t * E_10_animimg_1_imgs[30] = {
    &E_10_animimg_1dizzy_0,
    &E_10_animimg_1dizzy_01,
    &E_10_animimg_1dizzy_02,
    &E_10_animimg_1dizzy_03,
    &E_10_animimg_1dizzy_04,
    &E_10_animimg_1dizzy_05,
    &E_10_animimg_1dizzy_06,
    &E_10_animimg_1dizzy_07,
    &E_10_animimg_1dizzy_08,
    &E_10_animimg_1dizzy_09,
    &E_10_animimg_1dizzy_10,
    &E_10_animimg_1dizzy_11,
    &E_10_animimg_1dizzy_12,
    &E_10_animimg_1dizzy_13,
    &E_10_animimg_1dizzy_14,
    &E_10_animimg_1dizzy_15,
    &E_10_animimg_1dizzy_16,
    &E_10_animimg_1dizzy_17,
    &E_10_animimg_1dizzy_18,
    &E_10_animimg_1dizzy_19,
    &E_10_animimg_1dizzy_20,
    &E_10_animimg_1dizzy_21,
    &E_10_animimg_1dizzy_22,
    &E_10_animimg_1dizzy_23,
    &E_10_animimg_1dizzy_24,
    &E_10_animimg_1dizzy_25,
    &E_10_animimg_1dizzy_26,
    &E_10_animimg_1dizzy_27,
    &E_10_animimg_1dizzy_28,
    &E_10_animimg_1dizzy_29,
};
const lv_image_dsc_t * E_13_animimg_1_imgs[30] = {
    &E_13_animimg_1left_0,
    &E_13_animimg_1left_01,
    &E_13_animimg_1left_02,
    &E_13_animimg_1left_03,
    &E_13_animimg_1left_04,
    &E_13_animimg_1left_05,
    &E_13_animimg_1left_06,
    &E_13_animimg_1left_07,
    &E_13_animimg_1left_08,
    &E_13_animimg_1left_09,
    &E_13_animimg_1left_10,
    &E_13_animimg_1left_12,
    &E_13_animimg_1left_13,
    &E_13_animimg_1left_14,
    &E_13_animimg_1left_15,
    &E_13_animimg_1left_16,
    &E_13_animimg_1left_17,
    &E_13_animimg_1left_18,
    &E_13_animimg_1left_19,
    &E_13_animimg_1left_20,
    &E_13_animimg_1left_21,
    &E_13_animimg_1left_22,
    &E_13_animimg_1left_23,
    &E_13_animimg_1left_24,
    &E_13_animimg_1left_25,
    &E_13_animimg_1left_26,
    &E_13_animimg_1left_27,
    &E_13_animimg_1left_28,
    &E_13_animimg_1left_29,
};
const lv_image_dsc_t * E_14_animimg_1_imgs[30] = {
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
    &E_14_animimg_1normal_22,
    &E_14_animimg_1normal_23,
    &E_14_animimg_1normal_24,
    &E_14_animimg_1normal_25,
    &E_14_animimg_1normal_26,
    &E_14_animimg_1normal_27,
    &E_14_animimg_1normal_28,
    &E_14_animimg_1normal_29,
};
const lv_image_dsc_t * E_15_animimg_1_imgs[40] = {
    &E_15_animimg_1leftlook20_0,
    &E_15_animimg_1leftlook20_01,
    &E_15_animimg_1leftlook20_02,
    &E_15_animimg_1leftlook20_03,
    &E_15_animimg_1leftlook20_04,
    &E_15_animimg_1leftlook20_05,
    &E_15_animimg_1leftlook20_06,
    &E_15_animimg_1leftlook20_07,
    &E_15_animimg_1leftlook20_08,
    &E_15_animimg_1leftlook20_09,
    &E_15_animimg_1leftlook20_10,
    &E_15_animimg_1leftlook20_11,
    &E_15_animimg_1leftlook20_12,
    &E_15_animimg_1leftlook20_13,
    &E_15_animimg_1leftlook20_14,
    &E_15_animimg_1leftlook20_15,
    &E_15_animimg_1leftlook20_16,
    &E_15_animimg_1leftlook20_17,
    &E_15_animimg_1leftlook20_18,
    &E_15_animimg_1leftlook20_19,
    &E_15_animimg_1leftlook20_20,
    &E_15_animimg_1leftlook20_21,
    &E_15_animimg_1leftlook20_22,
    &E_15_animimg_1leftlook20_23,
    &E_15_animimg_1leftlook20_24,
    &E_15_animimg_1leftlook20_25,
    &E_15_animimg_1leftlook20_26,
    &E_15_animimg_1leftlook20_27,
    &E_15_animimg_1leftlook20_28,
    &E_15_animimg_1leftlook20_29,
    &E_15_animimg_1leftlook20_30,
    &E_15_animimg_1leftlook20_31,
    &E_15_animimg_1leftlook20_32,
    &E_15_animimg_1leftlook20_33,
    &E_15_animimg_1leftlook20_34,
    &E_15_animimg_1leftlook20_35,
    &E_15_animimg_1leftlook20_36,
    &E_15_animimg_1leftlook20_37,
    &E_15_animimg_1leftlook20_38,
    &E_15_animimg_1leftlook20_39,
};
const lv_image_dsc_t * E_16_animimg_1_imgs[40] = {
    &E_16_animimg_1rightlook20_0,
    &E_16_animimg_1rightlook20_01,
    &E_16_animimg_1rightlook20_02,
    &E_16_animimg_1rightlook20_03,
    &E_16_animimg_1rightlook20_04,
    &E_16_animimg_1rightlook20_05,
    &E_16_animimg_1rightlook20_06,
    &E_16_animimg_1rightlook20_07,
    &E_16_animimg_1rightlook20_08,
    &E_16_animimg_1rightlook20_09,
    &E_16_animimg_1rightlook20_10,
    &E_16_animimg_1rightlook20_11,
    &E_16_animimg_1rightlook20_12,
    &E_16_animimg_1rightlook20_13,
    &E_16_animimg_1rightlook20_14,
    &E_16_animimg_1rightlook20_15,
    &E_16_animimg_1rightlook20_16,
    &E_16_animimg_1rightlook20_17,
    &E_16_animimg_1rightlook20_18,
    &E_16_animimg_1rightlook20_19,
    &E_16_animimg_1rightlook20_20,
    &E_16_animimg_1rightlook20_21,
    &E_16_animimg_1rightlook20_22,
    &E_16_animimg_1rightlook20_23,
    &E_16_animimg_1rightlook20_24,
    &E_16_animimg_1rightlook20_25,
    &E_16_animimg_1rightlook20_26,
    &E_16_animimg_1rightlook20_27,
    &E_16_animimg_1rightlook20_28,
    &E_16_animimg_1rightlook20_29,
    &E_16_animimg_1rightlook20_30,
    &E_16_animimg_1rightlook20_31,
    &E_16_animimg_1rightlook20_32,
    &E_16_animimg_1rightlook20_33,
    &E_16_animimg_1rightlook20_34,
    &E_16_animimg_1rightlook20_35,
    &E_16_animimg_1rightlook20_36,
    &E_16_animimg_1rightlook20_37,
    &E_16_animimg_1rightlook20_38,
    &E_16_animimg_1rightlook20_39,
};
const lv_image_dsc_t * E_17_animimg_1_imgs[30] = {
    &E_17_animimg_1right_0,
    &E_17_animimg_1right_01,
    &E_17_animimg_1right_02,
    &E_17_animimg_1right_03,
    &E_17_animimg_1right_04,
    &E_17_animimg_1right_05,
    &E_17_animimg_1right_06,
    &E_17_animimg_1right_08,
    &E_17_animimg_1right_09,
    &E_17_animimg_1right_10,
    &E_17_animimg_1right_11,
    &E_17_animimg_1right_12,
    &E_17_animimg_1right_13,
    &E_17_animimg_1right_14,
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

// Copyright 2022 Framework Computer
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H
#include "framework.h"

// This version has seperate rgb groupings,  layer tracking

enum _layers {
  _BASE,
  _FN,
  _RGB,
  _FN_LOCK,
  _CAPS,
  _SFT,
  _CTRL
};

// I could not find an RGB equivalent to the Backlight step brightness code
// so i made my own.
enum Custom_Keycodes {
    RGB_STEP,
};

// these are variables for RGB_STEP. brite_adj is set initially
// to 255 so the rgb is max brightness when keyboard initializes.
static int rgb_brite_val = 0;
static int brite_adj     = 255;

// variable to switch between per key rgb and animations
static int rgb_switch = 1;

// these are to keep track on the stacking of layers and mods
static int rgb_x   = 0;
static int caps_x  = 0;
static int sft_x   = 0;
static int ctrl_x  = 0;
static int lyr_num = 0;

static int lyr_off  = 0;
static int lyr_val  = 0;
static int lsft_val = 0;
static int rsft_val = 0;
static int lctl_val = 0;
static int rctl_val = 0;
static int rgb_val  = 0;
 

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* ANSI/US RGB keyboard key location to LED Index (Zeroed Values)
*
*   row 1      ┌────────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬──────┬────┬───────┐
*    LED's 17  │  0, 1  │  2  │  3  │  4  │  5  │  6  │  7  │  8  │  9  │ 10  │ 11  │12, 13│ 14 │15, 16 │
*   row 2      ├─────┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬───┴─┬──┴───────┤
*    LED's 15  │ 17  │ 18  │ 19  │ 20  │ 21  │ 22  | 23  │ 24  │ 25  │ 26  │ 27  │ 28  │ 29  │  30, 31  │
*   row 3      ├─────┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬───────┤
*    LED's 15  │ 32, 33 │ 34  │ 35  │ 36  │ 37  │ 38  │ 39  │ 40  │ 41  │ 42  │ 43  │ 44  │ 45  │  46   │
*   row 4      ├────────┴─┬───┴─┬───┴─┬───┴─┬───┴─┬───┴─┬───┴─┬───┴─┬───┴─┬───┴─┬───┴─┬───┴─┬───┴───────┤
*    LED's 16  │47, 48, 49│ 50  │ 51  │ 52  │ 53  │ 54  │ 55  │ 56  │ 57  │ 58  │ 59  │ 60  │  61, 62   │
*   row 5      ├──────────┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴───────────┤
*    LED's 17  │ 63, 64, 65  │ 66  │ 67  │ 68  │ 69  │ 70  │ 71  │ 72  │ 73  │ 74  │ 75  │76, 77, 78, 79│
*              ├────────┬────┴─┬───┴──┬──┴───┬─┴─────┴─────┴─────┴────┬┴─────┼─────┼─────┴┬──────┬──────┤
*   row 6      │        │      │      │      │                        │      │     │      │  95  │      │
*   LED's 17   │ 80, 81 │  82  │  83  │  84  │ 85, 86, 87, 88, 89, 90 │  91  │ 92  │  93  ├──────┤  96  │
*              │        │      │      │      │                        │      │     │      │  94  │      │
*   TOTAL      └────────┴──────┴──────┴──────┴────────────────────────┴──────┴─────┴──────┴──────┴──────┘
*    LED's: 97
*/

/*             ┌────────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬───────┐
*   14 keys    │ ESCAPE │Mute │VolDn│VolUp│Prevs│Play │Next │LghDn│LghUp│Sceen│Airpl│Print│ App │Delete │
*              ├─────┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬───┴─┬──┴───────┤
*   14 keys    │  `  │  1  │  2  │  3  │  4  │  5  │  6  │  7  │  8  │  9  │  0  │  -  │  =  │Backspace │
*              ├─────┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬───────┤
*   14 keys    │  Tab   │Q, q │W, w │E, e │R, r │T, t │Y, y │U, u │I, i │O, o │P, p │[, { │], } │ \, |  │
*              ├────────┴─┬───┴─┬───┴─┬───┴─┬───┴─┬───┴─┬───┴─┬───┴─┬───┴─┬───┴─┬───┴─┬───┴─┬───┴───────┤
*   13 keys    │  Caps    │A, a │S, s │D, d │F, f │G, g │H, h │J, j │K, k │L, l │;, : │', ' │    Enter  │
*              ├──────────┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴───────────┤
*   12 keys    │  Shift      │Z, z │X, x │C, c │V, v │B, b │N, n │M, m │,, < │., > │/, ? │       Shift  │
*              ├────────┬────┴─┬───┴──┬──┴───┬─┴─────┴─────┴─────┴────┬┴─────┼─────┼─────┴┬──────┬──────┤
*              │        │      │      │      │                        │      │     │      │  ↑   │      │
*   11 keys    │Control │Functn│ GUI  │ Alt  │        SpaceBar        │ Alt  │Cntrl│  ←   ├──────┤   →  │
*              │        │      │      │      │                        │      │     │      │  ↓   │      │
*              └────────┴──────┴──────┴──────┴────────────────────────┴──────┴─────┴──────┴──────┴──────┘
*   78 total
*/

    [_BASE] = LAYOUT(
        KC_ESC,       KC_MUTE,  KC_VOLD,  KC_VOLU,  KC_MPRV, KC_MPLY, KC_MNXT, KC_BRID, KC_BRIU, KC_SCRN, KC_AIRP, KC_PSCR, KC_MSEL, KC_DEL,
        KC_GRV,       KC_1,     KC_2,     KC_3,     KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSPC,
        KC_TAB,       KC_Q,     KC_W,     KC_E,     KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSLS,
        KC_CAPS,      KC_A,     KC_S,     KC_D,     KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,          KC_ENT,
        KC_LSFT,      KC_Z,     KC_X,     KC_C,     KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,                   KC_RSFT,
        KC_LCTL,      MO(_FN),  KC_LGUI,  KC_LALT,           KC_SPC,                    KC_RALT, KC_RCTL, KC_LEFT, KC_UP,   KC_DOWN, KC_RGHT
    ),

   [_FN] = LAYOUT(
        TG(_FN_LOCK), KC_F1,    KC_F2,    KC_F3,    KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_INS,
        _______,      _______,  _______,  _______,  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______,      _______,  _______,  _______,  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______,      _______,  _______,  _______,  _______, _______, _______, _______, _______, _______, _______, _______,          _______,
        _______,      _______,  _______,  _______,  _______, _______, _______, _______, _______, _______, _______,                   _______,
        _______,      _______,  KC_MENU,  _______,           _______,                   _______, _______, KC_HOME, KC_PGUP, KC_PGDN, KC_END
   ),
        
   [_RGB] = LAYOUT(
        _______,      _______,  _______,  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______,      _______,  _______,  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______,      RGB_MOD,  RGB_HUI,  RGB_SAI, RGB_VAI, RGB_SPI, _______, _______, _______, _______, _______, _______, _______, _______,
        _______,      RGB_RMOD, RGB_HUD,  RGB_SAD, RGB_VAD, RGB_SPD, _______, _______, _______, _______, _______, _______,          _______,
        _______,      QK_BOOT,  RGB_STEP, RGB_TOG, BL_STEP, _______, _______, _______, _______, _______, _______,                   _______,
        _______,      _______,  KC_MENU,  _______,          _______,                   _______, _______, _______, _______, _______, _______
    ),

    [_FN_LOCK] = LAYOUT(
        TG(_FN_LOCK), KC_F1,    KC_F2,    KC_F3,    KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_INS,
        _______,      _______,  _______,  _______,  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______,      _______,  _______,  _______,  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______,      _______,  _______,  _______,  _______, _______, _______, _______, _______, _______, _______, _______,          _______,
        _______,      _______,  _______,  _______,  _______, _______, _______, _______, _______, _______, _______,                   _______,
        _______,      _______,  _______,  _______,           _______,                   _______, _______, _______, _______, _______, _______
    ),

    [_CAPS] = LAYOUT(
        _______,      _______,  _______,  _______,  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______,      _______,  _______,  _______,  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______,      _______,  _______,  _______,  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______,      _______,  _______,  _______,  _______, _______, _______, _______, _______, _______, _______, _______,          _______,
        _______,      _______,  _______,  _______,  _______, _______, _______, _______, _______, _______, _______,                   _______,
        _______,      _______,  _______,  _______,           _______,                   _______, _______, _______, _______, _______, _______
    ),

    [_SFT] = LAYOUT(
        _______,      _______,  _______,  _______,  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______,      _______,  _______,  _______,  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______,      _______,  _______,  _______,  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______,      _______,  _______,  _______,  _______, _______, _______, _______, _______, _______, _______, _______,          _______,
        _______,      _______,  _______,  _______,  _______, _______, _______, _______, _______, _______, _______,                   _______,
        _______,      _______,  _______,  _______,           _______,                   _______, _______, _______, _______, _______, _______
    ),

    [_CTRL] = LAYOUT(
        _______,      _______,  _______,  _______,  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______,      _______,  _______,  _______,  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______,      _______,  _______,  _______,  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______,      _______,  _______,  _______,  _______, _______, _______, _______, _______, _______, _______, _______,          _______,
        _______,      _______,  _______,  _______,  _______, _______, _______, _______, _______, _______, _______,                   _______,
        _______,      _______,  _______,  _______,           _______,                   _______, _______, _______, _______, _______, _______
    ),
};


void Lyr_On(int lyr_val) {
    lyr_val = lyr_val < 7 ? lyr_val : lyr_val - 2;
    layer_on(lyr_val);
    ++lyr_num;
    switch (lyr_val) {
        case 2: rgb_x  = lyr_num; break;
        case 4: caps_x = lyr_num; break;
        case 5: sft_x  = lyr_num; break;
        case 6: ctrl_x = lyr_num; break;
    };
};

void Lyr_Off(int lyr_val) {
    lyr_val = lyr_val < 7 ? lyr_val : lyr_val - 2;
    layer_off(lyr_val);
    --lyr_num;
    switch (lyr_val) {
        case 2: lyr_off = rgb_x;  rgb_x   = 0; break;
        case 4: lyr_off = caps_x; caps_x  = 0; break;
        case 5: lyr_off = sft_x;  sft_x   = 0; break;
        case 6: lyr_off = ctrl_x; ctrl_x  = 0; break;
    }
    if (rgb_x > lyr_off) { --rgb_x;};
    if (caps_x > lyr_off) { --caps_x;};
    if (sft_x > lyr_off) { --sft_x;};
    if (ctrl_x > lyr_off) { --ctrl_x;};
};


bool process_record_user(uint16_t keycode, keyrecord_t *record) {

// code to change the brightness for per key rgb. after the brightness hits 0 the animations will be active.
    switch (keycode) {
        case RGB_STEP:
            if (record->event.pressed) {
                if (rgb_brite_val <= 0) {
                    rgb_brite_val = 1;
                } else if (rgb_brite_val <= 10) {
                    rgb_brite_val = rgb_brite_val + 1;
                    if (rgb_brite_val == 11) {
                        rgb_switch = 0;
                    }
                } else if (rgb_brite_val > 10) {
                    rgb_brite_val = 0;
                    rgb_switch    = 1;
                };
                //rgbv[x]: x =  0    1    2    3    4    5    6    7    8    9    10   11
                int rgbv[]   = {255, 230, 204, 178, 153, 128, 102, 77,  51,  26,  0,   255};
                brite_adj    = rgbv[rgb_brite_val];
            }
            return brite_adj && rgb_brite_val;
    
        case KC_MENU:
            if (record->event.pressed) {
                if (rgb_x == 0) {
                    lyr_val = 2;
                    Lyr_On(lyr_val);
                    rgb_val = 0;
                    return false;
                } else {
                    rgb_val = 1;
                    return false;
                }
            } else {
                if (rgb_x > 0 && rgb_val == 1) {
                    rgb_val = 0;
                    lyr_val = 2;
                    Lyr_Off(lyr_val);
                    return false;
                }
            }
            return false;

        case KC_CAPS:
            if (record->event.pressed) {
                if (caps_x == 0) {
                    lyr_val = 4;
                    Lyr_On(lyr_val);
                    return true;
                } else if (caps_x > 0) {
                    lyr_val = 4;
                    Lyr_Off(lyr_val);
                    return true;
                }
            } else {
                if (host_keyboard_led_state().caps_lock && (sft_x > 0 || ctrl_x > 0 || rgb_x > 0)) {
                    register_code(KC_CAPS);
                    unregister_code(KC_CAPS);
                }
            }
            return false;

        case KC_LSFT:
            if (record->event.pressed) {
                if (IS_LAYER_ON(_SFT) && sft_x > 0) { break; }
                lyr_val = 5;
                Lyr_On(lyr_val);
                return true;
            } else {
                if (IS_LAYER_OFF(_SFT) && sft_x == 0) { break; }
                lyr_val = 5;
                Lyr_Off(lyr_val);
                return true; 
            }
            return false;

        

        case KC_RSFT:
            if (record->event.pressed) {
                if (IS_LAYER_ON(_SFT) && sft_x > 0) { break; }
                lyr_val = 7;
                Lyr_On(lyr_val);
                return true;
            } else {
                if (IS_LAYER_OFF(_SFT) && sft_x == 0) { break; }
                lyr_val = 7;
                Lyr_Off(lyr_val);
                return true;
            }
            return false;

        case KC_LCTL:
            if (record->event.pressed) {
                if (IS_LAYER_ON(_CTRL) && ctrl_x > 0) { break; }
                lyr_val = 6;
                Lyr_On(lyr_val);
                return true;
            } else {
                if (IS_LAYER_OFF(_CTRL) && ctrl_x == 0) { break; }
                lyr_val = 6;
                Lyr_Off(lyr_val);
                return true;
            }
            return false;

        case KC_RCTL:
            if (record->event.pressed) {
                if (IS_LAYER_ON(_CTRL) && ctrl_x > 0) { break; }
                lyr_val = 8;
                Lyr_On(lyr_val);
                return true;
            } else {
                if (IS_LAYER_OFF(_CTRL) && ctrl_x == 0) { break; }
                lyr_val = 8;
                Lyr_Off(lyr_val);
                return true;
            }
            return false;
    }
    return false;
};


bool rgb_matrix_indicators_advanced_user(uint8_t led_min, uint8_t led_max) {

    if (IS_LAYER_ON(_FN) && rgb_switch == 1) {
        //  a      =  0    1    2    3 
        int lmin[] = {0,   2,   84,  93 };
        int lmax[] = {2,   17,  92,  97 };
        int a;
        int LEDr[] = {255, 255, 0,   255};
        int LEDg[] = {0,   0,   0,   0  };
        int LEDb[] = {0,   72,  255, 72 };
        for (a = 0; a <= 3; a++) {
            led_min = lmin[a];
            led_max = lmax[a];
            for (uint8_t i = led_min; i < led_max; i++) {
                RGB_MATRIX_INDICATOR_SET_COLOR(i, LEDr[a] * brite_adj / 255, LEDg[a] * brite_adj / 255, LEDb[a] * brite_adj / 255);
            }
        }
    } else if (IS_LAYER_ON(_FN_LOCK) && rgb_switch == 1) {
        //  a      =  0    1    2    3    
        int lmin[] = {0,   2,   84,  93 };
        int lmax[] = {2,   17,  92,  97 };
        int a;
        int LEDr[] = {255, 255, 0,   0  };
        int LEDg[] = {0,   0,   0,   0  };
        int LEDb[] = {0,   72,  255, 255};
        for (a = 0; a <= 3; a++) {
            led_min = lmin[a];
            led_max = lmax[a];
            for (uint8_t i = led_min; i < led_max; i++) {
                RGB_MATRIX_INDICATOR_SET_COLOR(i, LEDr[a] * brite_adj / 255, LEDg[a] * brite_adj / 255, LEDb[a] * brite_adj / 255);
            }
        }
    } else if (IS_LAYER_OFF(_FN) && IS_LAYER_OFF(_FN_LOCK) && rgb_switch == 1) {
        //  a      =  0    1    2
        int lmin[] = {0, 84, 93};
        int lmax[] = {17, 92, 97};
        int a;
        int LEDr[] = {0, 0, 0};
        int LEDg[] = {0, 0, 0};
        int LEDb[] = {255, 255, 255};
        for (a = 0; a <= 2; a++) {
            led_min = lmin[a];
            led_max = lmax[a];
            for (uint8_t i = led_min; i < led_max; i++) {
                RGB_MATRIX_INDICATOR_SET_COLOR(i, LEDr[a] * brite_adj / 255, LEDg[a] * brite_adj / 255, LEDb[a] * brite_adj / 255);
            }
        }
    };



    if (lyr_num >= 0 && rgb_switch == 1) {
        //  a      =  0    1    2    3    4    5    6
        int lmin[] = {47, 63, 76, 80, 82, 83, 92};
        int lmax[] = {50, 66, 80, 82, 83, 84, 93};
        int a;
        int LEDr[] = {255, 255, 255, 255, 255, 0, 255};
        int LEDg[] = {0, 0, 0, 0, 0, 0, 0};
        int LEDb[] = {255, 255, 255, 255, 255, 255, 255};
        int led_r  = 255;
        int led_g  = 0;
        int led_b  = 255;
        for (a = 0; a <= 6; a++) {
            if (a < 5 || a == 6) {
                if ((a == 0 && caps_x > 0) || ((a == 1 || a == 2) && sft_x > 0) || ((a == 3 || a == 6) && ctrl_x > 0) || (a == 4 && IS_LAYER_ON(_FN))) {
                    led_r = LEDr[a];
                    led_g = LEDg[a];
                    led_b = 0;
                } else {
                    led_r = LEDr[a];
                    led_g = LEDg[a];
                    led_b = LEDb[a];
                }
            }
            if (a == 5) {
                if (IS_LAYER_ON(_RGB)) {
                    led_r = 255;
                    led_g = LEDg[a];
                    led_b = 0;
                } else if (IS_LAYER_ON(_FN)) {
                    led_r = 255;
                    led_g = 36;
                    led_b = 0;
                } else {
                    led_r = LEDr[a];
                    led_g = LEDg[a];
                    led_b = LEDb[a];
                }
            }
            led_min = lmin[a];
            led_max = lmax[a];
            for (uint8_t i = led_min; i < led_max; i++) {
                RGB_MATRIX_INDICATOR_SET_COLOR(i, led_r * brite_adj / 255, led_g * brite_adj / 255, led_b * brite_adj / 255);
            }
        }
    };

    if (((rgb_x == 0 && caps_x == 0 && sft_x == 0 && ctrl_x == 0) || lyr_num == 0) && rgb_switch == 1) {
        //  a      =  0    1    2
        int lmin[] = {17,  50,  66 };
        int lmax[] = {47,  63,  76 };
        int a;
        int LEDr[] = {0,   0,   0  };
        int LEDg[] = {0,   0,   0  };
        int LEDb[] = {255, 255, 255};
        for (a = 0; a <= 2; a++) {
            led_min = lmin[a];
            led_max = lmax[a];
            for (uint8_t i = led_min; i < led_max; i++) {
                RGB_MATRIX_INDICATOR_SET_COLOR(i, LEDr[a] * brite_adj / 255, LEDg[a] * brite_adj / 255, LEDb[a] * brite_adj / 255);
            }
        }
    } else if (IS_LAYER_ON(_RGB) && rgb_switch == 1) {
        //  a      =  0    1    2    3    4    5    6    7    8    9    10   11   12   13   14   15
        int lmin[] = {17,  34,  35,  36,  37,  38,  39,  50,  51,  52,  53,  54,  55,  66,  67,  70 };
        int lmax[] = {34,  35,  36,  37,  38,  39,  47,  51,  52,  53,  54,  55,  63,  67,  69,  76 };
        int a;
        int LEDr[] = {0,   255, 255, 60,  0,   255, 0,   255, 255, 60,  0,   255, 0,   255, 255, 0  };
        int LEDg[] = {0,   36,  0,   0,   255, 0,   0,   36,  0,   0,   255, 0,   0,   0,   0,   0  };
        int LEDb[] = {255, 0,   0,   255, 255, 72,  255, 0,   0,   255, 255, 72,  255, 0,   72,  255};
        for (a = 0; a <= 15; a++) {
            led_min = lmin[a];
            led_max = lmax[a];
            for (uint8_t i = led_min; i < led_max; i++) {
                RGB_MATRIX_INDICATOR_SET_COLOR(i, LEDr[a] * brite_adj / 255, LEDg[a] * brite_adj / 255, LEDb[a] * brite_adj / 255);
            }
        }
    } else if (IS_LAYER_ON(_RGB) && rgb_switch == 0) {
        //  a      =  0    1    2    3    4    5    6    7    8    9    10   11
        int lmin[] = {34,  35,  36,  37,  38,  50,  51,  52,  53,  54,  66,  67 };
        int lmax[] = {35,  36,  37,  38,  39,  51,  52,  53,  54,  55,  67,  70 };
        int a;
        int LEDr[] = {255, 255, 60,  0,   255, 255, 255, 60,  0,   255, 255, 255};
        int LEDg[] = {36,  0,   0,   255, 0,   36,  0,   0,   255, 0,   0,   0  };
        int LEDb[] = {0,   0,   255, 255, 72,  0,   0,   255, 255, 72,  0,   72 };
        for (a = 0; a <= 11; a++) {
            led_min = lmin[a];
            led_max = lmax[a];
            for (uint8_t i = led_min; i < led_max; i++) {
                RGB_MATRIX_INDICATOR_SET_COLOR(i, LEDr[a] * brite_adj / 255, LEDg[a] * brite_adj / 255, LEDb[a] * brite_adj / 255);
            }
        }
    } else if (caps_x > 0 && IS_LAYER_OFF(_RGB) && IS_LAYER_OFF(_SFT) && IS_LAYER_OFF(_CTRL) && rgb_switch == 1) {
        //  a      =  0    1    2    3    4    5
        int lmin[] = {17,  34,  44,  50,  59,  66 };
        int lmax[] = {34,  44,  47,  59,  63,  76 };
        int a;
        int LEDr[] = {0,   0,   0,   0,   0,   0  };
        int LEDg[] = {0,   255, 0,   255, 0,   255};
        int LEDb[] = {255, 255, 255, 255, 255, 255};
        for (a = 0; a <= 5; a++) {
            led_min = lmin[a];
            led_max = lmax[a];
            for (uint8_t i = led_min; i < led_max; i++) {
                RGB_MATRIX_INDICATOR_SET_COLOR(i, LEDr[a] * brite_adj / 255, LEDg[a] * brite_adj / 255, LEDb[a] * brite_adj / 255);
            }
        }
    } else if (sft_x > 0 && ctrl_x == 0 && rgb_x == 0 && rgb_switch == 1) {
        //  a      =  0    1    2    3    4    5    6    7    8
        int lmin[] = {17,  30,  34,  44,  50,  59,  61,  66,  73 };
        int lmax[] = {30,  34,  44,  47,  59,  61,  63,  73,  76 };
        int a;
        int LEDr[] = {255, 0,   0,   255, 0,   255, 0,   0,   255};
        int LEDg[] = {36,  0,   255, 36,  255, 36,  0,   255, 36 };
        int LEDb[] = {0,   255, 255, 0,   255, 0,   255, 255, 0  };
        for (a = 0; a <= 8; a++) {
            led_min = lmin[a];
            led_max = lmax[a];
            for (uint8_t i = led_min; i < led_max; i++) {
                RGB_MATRIX_INDICATOR_SET_COLOR(i, LEDr[a] * brite_adj / 255, LEDg[a] * brite_adj / 255, LEDb[a] * brite_adj / 255);
            }
        }
    } else if (ctrl_x > 0 && rgb_x == 0 && rgb_switch == 1) {
        //  a      =  0    1    2    3    4    5    6    7
        int lmin[] = {17, 39, 44, 50, 51, 52, 66, 72};
        int lmax[] = {39, 44, 47, 51, 52, 63, 72, 76};
        int a;
        int LEDr[] = {0, 255, 0, 0, 255, 0, 255, 0};
        int LEDg[] = {0, 0, 0, 0, 0, 0, 0, 0};
        int LEDb[] = {255, 72, 255, 255, 72, 255, 72, 255};
        for (a = 0; a <= 7; a++) {
            led_min = lmin[a];
            led_max = lmax[a];
            for (uint8_t i = led_min; i < led_max; i++) {
                RGB_MATRIX_INDICATOR_SET_COLOR(i, LEDr[a] * brite_adj / 255, LEDg[a] * brite_adj / 255, LEDb[a] * brite_adj / 255);
            }
        }
    };
    if (IS_LAYER_ON(_RGB) || IS_LAYER_ON(_SFT) || IS_LAYER_ON(_CTRL)) {
        if (host_keyboard_led_state().caps_lock) {
            register_code(KC_CAPS);
            unregister_code(KC_CAPS);
        }
    };
    if (IS_LAYER_OFF(_RGB) && IS_LAYER_OFF(_SFT) && IS_LAYER_OFF(_CTRL)) {
        if (!host_keyboard_led_state().caps_lock && IS_LAYER_ON(_CAPS)) {
            register_code(KC_CAPS);
            unregister_code(KC_CAPS);
        }
    };
    if (IS_LAYER_ON(_RGB)) {
        if (get_mods() == MOD_BIT(KC_LSFT) && sft_x  > 0) { unregister_code(KC_LSFT); lsft_val = 1; }
        if (get_mods() == MOD_BIT(KC_RSFT) && sft_x  > 0) { unregister_code(KC_RSFT); rsft_val = 1; }
        if (get_mods() == MOD_BIT(KC_LCTL) && ctrl_x > 0) { unregister_code(KC_LCTL); lctl_val = 1; }
        if (get_mods() == MOD_BIT(KC_RCTL) && ctrl_x > 0) { unregister_code(KC_RCTL); rctl_val = 1; }
    };
    if (IS_LAYER_OFF(_RGB)) {
        if (get_mods() != MOD_BIT(KC_LSFT) && lsft_val == 1 && sft_x  > 0) { register_code(KC_LSFT); lsft_val = 0; }
        if (get_mods() != MOD_BIT(KC_RSFT) && rsft_val == 1 && sft_x  > 0) { register_code(KC_RSFT); rsft_val = 0; }
        if (get_mods() != MOD_BIT(KC_LCTL) && lctl_val == 1 && ctrl_x > 0) { register_code(KC_LCTL); lctl_val = 0; }
        if (get_mods() != MOD_BIT(KC_RCTL) && rctl_val == 1 && ctrl_x > 0) { register_code(KC_RCTL); rctl_val = 0; }
    };
    return true;
}

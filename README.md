# IF YOU WANT TO TRY THE KEYMAP JUST DOWNLOAD THE UF2 FILE ABOVE AND FLASH TO KEYBOARD
OTHERWISE YOU CAN DOWNLOAD THE KEYBOARD FILE (FRAMEWORK) TO MODIFY THE KEYMAP AND RGB COLORS AND COMPILE YOURSELF

I have more versions of RGB Keymaps with more or less complexity but need to polish before adding to the file. I just wanted to get at least one keymap available for those that didnt spend months figuring out how to code this
##
##
## ANSI/US RGB keyboard key location to LED Index (Zeroed Values)
  I reordered the LED's in LED.py so that they can be referenced in sequence. As you see below:

    ┌────────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬──────┬────┬───────┐    row 1
    │  0, 1  │  2  │  3  │  4  │  5  │  6  │  7  │  8  │  9  │ 10  │ 11  │12, 13│ 14 │15, 16 │    LED's 17
    ├─────┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬───┴─┬──┴───────┤    row 2
    │ 17  │ 18  │ 19  │ 20  │ 21  │ 22  | 23  │ 24  │ 25  │ 26  │ 27  │ 28  │ 29  │  30, 31  │    LED's 15
    ├─────┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬───────┤    row 3
    │ 32, 33 │ 34  │ 35  │ 36  │ 37  │ 38  │ 39  │ 40  │ 41  │ 42  │ 43  │ 44  │ 45  │  46   │    LED's 15
    ├────────┴─┬───┴─┬───┴─┬───┴─┬───┴─┬───┴─┬───┴─┬───┴─┬───┴─┬───┴─┬───┴─┬───┴─┬───┴───────┤    row 4
    │47, 48, 49│ 50  │ 51  │ 52  │ 53  │ 54  │ 55  │ 56  │ 57  │ 58  │ 59  │ 60  │  61, 62   │    LED's 16
    ├──────────┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴───────────┤    row 5
    │ 63, 64, 65  │ 66  │ 67  │ 68  │ 69  │ 70  │ 71  │ 72  │ 73  │ 74  │ 75  │76, 77, 78, 79│    LED's 17
    ├────────┬────┴─┬───┴──┬──┴───┬─┴─────┴─────┴─────┴────┬┴─────┼─────┼─────┴┬──────┬──────┤    
    │        │      │      │      │                        │      │     │      │  95  │      │    row 6
    │ 80, 81 │  82  │  83  │  84  │ 85, 86, 87, 88, 89, 90 │  91  │ 92  │  93  ├──────┤  96  │    LED's 17
    │        │      │      │      │                        │      │     │      │  94  │      │    
    └────────┴──────┴──────┴──────┴────────────────────────┴──────┴─────┴──────┴──────┴──────┘   TOTAL
                                                                                              LED's: 97
    BASE LAYER:
	┌────────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬───────┐
	│ ESCAPE │Mute │VolDn│VolUp│Prevs│Play │Next │LghDn│LghUp│Sceen│Airpl│Print│ App │Delete │   14 keys
	├─────┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬───┴─┬──┴───────┤
	│  `  │  1  │  2  │  3  │  4  │  5  │  6  │  7  │  8  │  9  │  0  │  -  │  =  │Backspace │   14 keys
	├─────┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬───────┤
	│  Tab   │Q, q │W, w │E, e │R, r │T, t │Y, y │U, u │I, i │O, o │P, p │[, { │], } │ \, |  │   14 keys
	├────────┴─┬───┴─┬───┴─┬───┴─┬───┴─┬───┴─┬───┴─┬───┴─┬───┴─┬───┴─┬───┴─┬───┴─┬───┴───────┤
	│  Caps    │A, a │S, s │D, d │F, f │G, g │H, h │J, j │K, k │L, l │;, : │', ' │    Enter  │   13 keys
	├──────────┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴───────────┤
	│  Shift      │Z, z │X, x │C, c │V, v │B, b │N, n │M, m │,, < │., > │/, ? │       Shift  │   12 keys
	├────────┬────┴─┬───┴──┬──┴───┬─┴─────┴─────┴─────┴────┬┴─────┼─────┼─────┴┬──────┬──────┤
	│        │      │      │      │                        │      │     │      │  ↑   │      │
	│Control │Functn│ GUI  │ Alt  │        SpaceBar        │ Alt  │Cntrl│  ←   ├──────┤   →  │   11 keys
	│        │      │      │      │                        │      │     │      │  ↓   │      │
	└────────┴──────┴──────┴──────┴────────────────────────┴──────┴─────┴──────┴──────┴──────┘   78 total



# THESE ARE THE KEYS ASSOCIATED WITH EACH LAYER.
  ** 3 LAYERS LAYOUTS ARE NOT INCLUDED AS EVERY KEY IS TRANSPARENT ON THESE LAYERS: _CAPS, _SFT AND _CTRL.

The Layer Priority is _RGB then _CTRL then _SFT and then _CAPS. 

(If higher priority layer is on then the layers with lower priority will have mods turned off until the higher priority layer is deactivated)

The Base Layers are _BASE and _FN_LOCK (toggle)  with _FN (momentary key)

 ## BASE LAYER 

    [_BASE] = LAYOUT(
        KC_ESC,       KC_MUTE,  KC_VOLD,  KC_VOLU,  KC_MPRV, KC_MPLY, KC_MNXT, KC_BRID, KC_BRIU, KC_SCRN, KC_AIRP, KC_PSCR, KC_MSEL, KC_DEL,
        KC_GRV,       KC_1,     KC_2,     KC_3,     KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSPC,
        KC_TAB,       KC_Q,     KC_W,     KC_E,     KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSLS,
        KC_CAPS,      KC_A,     KC_S,     KC_D,     KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,          KC_ENT,
        KC_LSFT,      KC_Z,     KC_X,     KC_C,     KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,                   KC_RSFT,
        KC_LCTL,      MO(_FN),  KC_LGUI,  KC_LALT,           KC_SPC,                    KC_RALT, KC_RCTL, KC_LEFT, KC_UP,   KC_DOWN, KC_RGHT
    ),

![BASE LAYER with NO KEYS PRESSED](https://github.com/user-attachments/assets/021c029c-2015-476c-bb77-26cfc49801d1)


## FUNCTION LAYER
   
    [_FN] = LAYOUT(
        TG(_FN_LOCK), KC_F1,    KC_F2,    KC_F3,    KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_INS,
        _______,      _______,  _______,  _______,  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______,      _______,  _______,  _______,  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______,      _______,  _______,  _______,  _______, _______, _______, _______, _______, _______, _______, _______,          _______,
        _______,      _______,  _______,  _______,  _______, _______, _______, _______, _______, _______, _______,                   _______,
        _______,      _______,  KC_MENU,  _______,           _______,                   _______, _______, KC_HOME, KC_PGUP, KC_PGDN, KC_END
    ),

![FUNCTION LAYER ACTIVE while FN KEY PRESSED](https://github.com/user-attachments/assets/6f8298f3-925f-43d4-a292-17aaf6d28718)

## RGB LAYER / RGB MENU

    [_RGB] = LAYOUT(
        _______,      _______,  _______,  _______,  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______,      _______,  _______,  _______,  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______,      RGB_MOD,  RGB_HUI,  RGB_SAI,  RGB_VAI, RGB_SPI, _______, _______, _______, _______, _______, _______, _______, _______,
        _______,      RGB_RMOD, RGB_HUD,  RGB_SAD,  RGB_VAD, RGB_SPD, _______, _______, _______, _______, _______, _______,          _______,
        _______,      QK_BOOT,  RGB_STEP, RGB_TOG,  BL_STEP, _______, _______, _______, _______, _______, _______,                   _______,
        _______,      _______,  KC_MENU,  _______,           _______,                   _______, _______, _______, _______, _______, _______
    ),

![RGB LAYER ACTIVE with FN KEY PRESSED and HELD then WIN KEY PRESSED](https://github.com/user-attachments/assets/1dc1de66-c637-4af9-9c88-90be8d0d196e)

![RGB LAYER ACTIVE after ALL KEYS RELEASED](https://github.com/user-attachments/assets/2552af36-b674-43fc-979e-b3e3fe27b9f0)

## FN_LOCK LAYER


    [_FN_LOCK] = LAYOUT(
        TG(_FN_LOCK), KC_F1,    KC_F2,    KC_F3,    KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_INS,
        _______,      _______,  _______,  _______,  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______,      _______,  _______,  _______,  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______,      _______,  _______,  _______,  _______, _______, _______, _______, _______, _______, _______, _______,          _______,
        _______,      _______,  _______,  _______,  _______, _______, _______, _______, _______, _______, _______,                   _______,
        _______,      _______,  _______,  _______,           _______,                   _______, _______, _______, _______, _______, _______
    ),

![FN_LOCK LAYER ACTIVE while FN KEY PRESSED and HELD then FN_LOCK KEY PRESSED](https://github.com/user-attachments/assets/bf603023-10fd-45e7-b5e8-7551a93366d9)

![FN_LOCK LAYER ACTIVE after ALL KEYS RELEASED](https://github.com/user-attachments/assets/37640774-93cb-4a59-bd3d-8f3530cc7850)

## CAPS_LOCK LAYER

![CAPS LAYER ACTIVE after CAPS_LOCK PRESSED](https://github.com/user-attachments/assets/501e39be-1105-431e-9c01-ce2a3f1f2b10)
![CAPS LAYER ACTIVE after ALL KEYS RELEASED](https://github.com/user-attachments/assets/dcbb174f-94c3-4914-b67f-d335feec11c1)

## SHIFT LAYER

![SHIFT LAYER ACTIVE while LEFT SHIFT KEY PRESSED](https://github.com/user-attachments/assets/c506fa71-8765-4cc5-8c79-560a888a321d)
![SHIFT LAYER ACTIVE while RIGHT SHIFT KEY PRESSED](https://github.com/user-attachments/assets/0a768094-dc2d-4f99-8311-6b363de4c873)

## CONTROL LAYER

![CONTROL LAYER ACTIVE while LEFT CTRL KEY PRESSED](https://github.com/user-attachments/assets/1981b8f5-fc24-4015-90eb-e6c29875f490)
![CONTROL LAYER ACTIVE while RIGHT CTRL KEY PRESSED](https://github.com/user-attachments/assets/b061cc90-23d2-4e77-9c96-48afa82fcc4c)


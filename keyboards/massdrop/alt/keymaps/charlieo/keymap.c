#include QMK_KEYBOARD_H

enum alt_keycodes {
    U_T_AUTO = SAFE_RANGE, //USB Extra Port Toggle Auto Detect / Always Active
    U_T_AGCR,              //USB Toggle Automatic GCR control
    DBG_TOG,               //DEBUG Toggle On / Off
    DBG_MTRX,              //DEBUG Toggle Matrix Prints
    DBG_KBD,               //DEBUG Toggle Keyboard Prints
    DBG_MOU,               //DEBUG Toggle Mouse Prints
    MD_BOOT,               //Restart into bootloader after hold timeout
};

// Keymap layers
enum layer_names {
    _BASE_LAYER,
    // _RAISE_LAYER,
    // _LOWER_LAYER,
    // _NUMPAD_LAYER,
    _NAVIGATION_LAYER,
    _UI_LAYER,
    _KEYBOARD_LAYER,
};

// Layer switches aliases
// #define L_LOWER MO(_LOWER_LAYER)
// #define L_RAISE MO(_RAISE_LAYER)
// #define L_NUMPAD MO(_NUMPAD_LAYER)
#define L_UI MO(_UI_LAYER)
#define L_KEYBD MO(_KEYBOARD_LAYER)
#define SCL_NAV LT(_NAVIGATION_LAYER, KC_SCLN)
// #define SFT_MIN MT(MOD_RSFT, KC_MINS)
// #define SFT_ENT KC_SFTENT

// GUI chords
#define GUI_1 LGUI(KC_1)
#define GUI_2 LGUI(KC_2)
#define GUI_3 LGUI(KC_3)
#define GUI_4 LGUI(KC_4)
#define GUI_5 LGUI(KC_5)
#define GUI_6 LGUI(KC_6)
#define GUI_7 LGUI(KC_7)
#define GUI_8 LGUI(KC_8)
#define GUI_9 LGUI(KC_9)
#define GUI_0 LGUI(KC_0)
// #define GUI_MIN LGUI(KC_MINS)
// #define GUI_EQL LGUI(KC_EQL)
// #define GUI_LBR LGUI(KC_LBRC)
// #define GUI_RBR LGUI(KC_RBRC)
// #define GUI_ENT LGUI_T(KC_ENT)
// #define GUI_ESC LGUI_T(KC_ESC)
#define GUI_TAB LGUI(KC_TAB) // application toggle
// #define GUI_GRV LGUI(KC_GRV) // window toggle
// #define GUI_SSF LGUI(LSFT(KC_3)) // Full screen shot
// #define GUI_SST LGUI(LSFT(KC_4)) // Targetted screen shot
#define SCRN_BRIU LCA(KC_RIGHT)
#define SCRN_BRID LCA(KC_LEFT)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_BASE_LAYER] = LAYOUT_65_ansi_blocker(
        KC_GESC, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSPC, KC_DEL,  \
        KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSLS, KC_HOME, \
        KC_CAPS, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    SCL_NAV, KC_QUOT,          KC_ENT,  KC_PGUP, \
        KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,          KC_UP,   KC_PGDN, \
        KC_LGUI, KC_LALT, KC_LCTL,                      LT(L_UI, KC_SPC),                KC_RCTL, KC_RALT, KC_LEFT, KC_DOWN, KC_RGHT  \
    ),
    [_NAVIGATION_LAYER] = LAYOUT_65_ansi_blocker(
        KC_GRV ,  KC_F1,  KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,  KC_F9,   KC_F10,  KC_F11,  KC_F12,  _______, KC_MUTE, \
        _______, _______, _______, KC_PGUP, _______, _______, _______, _______, KC_UP,   _______, KC_PSCR, KC_SLCK, KC_PAUS, _______, KC_VOLU, \
        MO(L_UI),_______, KC_LCTL, KC_PGDN, KC_RCTL, _______, _______, KC_LEFT, KC_DOWN, KC_RGHT, _______, _______,          _______, KC_VOLD, \
        _______, _______, _______, _______, _______, MD_BOOT, NK_TOGG, DBG_TOG, _______, _______, _______, MO(L_KEYBD),      KC_PGUP, KC_MPLY, \
        _______, _______, _______,                            _______,                            _______, _______, KC_HOME, KC_PGDN, KC_END  \
    ),
    //  LCG_SWP = MAGIC_SWAP_LCTL_LGUI
    //  LCG_NRM = MAGIC_UNSWAP_LCTL_LGUI
    [_UI_LAYER] = LAYOUT(
        GUI_TAB, GUI_1,   GUI_2,   GUI_3,   GUI_4,   GUI_5,   GUI_6,   GUI_7,   GUI_8,     GUI_9,     GUI_0,   _______, _______, _______, _______, \
        _______, _______, LCG_NRM, _______, _______, _______, _______, _______, SCRN_BRID, SCRN_BRIU, _______, _______, _______, _______, _______, \
        _______, _______, _______, _______, _______, _______, _______, _______, _______,   _______,   _______, _______,          _______, _______, \
        _______, _______, _______, _______, _______, _______, _______, LCG_SWP, _______,   _______,   _______, _______,          _______, _______, \
        _______, _______, _______,                            _______,                                _______, _______, _______, _______, _______  \
    ),
    [_KEYBOARD_LAYER] = LAYOUT_65_ansi_blocker(
        _______, _______,  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
        _______, RGB_SPD,  RGB_VAI, RGB_SPI, RGB_HUI, RGB_SAI, _______, U_T_AUTO,_______, _______, _______, _______, _______, _______, _______, \
        _______, RGB_RMOD, RGB_VAD, RGB_MOD, RGB_HUD, RGB_SAD, _______, _______, _______, _______, _______, _______,          _______, _______, \
        _______, RGB_TOG,  _______, _______, _______, MD_BOOT, NK_TOGG, DBG_TOG, _______, _______, _______, _______,          _______, _______, \
        _______, _______,  _______,                            _______,                            _______, _______, _______, _______, _______  \
    ),
};

#define MODS_SHIFT  (get_mods() & MOD_BIT(KC_LSHIFT) || get_mods() & MOD_BIT(KC_RSHIFT))
#define MODS_CTRL  (get_mods() & MOD_BIT(KC_LCTL) || get_mods() & MOD_BIT(KC_RCTRL))
#define MODS_ALT  (get_mods() & MOD_BIT(KC_LALT) || get_mods() & MOD_BIT(KC_RALT))

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    static uint32_t key_timer;

    switch (keycode) {
        case U_T_AUTO:
            if (record->event.pressed && MODS_SHIFT && MODS_CTRL) {
                TOGGLE_FLAG_AND_PRINT(usb_extra_manual, "USB extra port manual mode");
            }
            return false;
        case U_T_AGCR:
            if (record->event.pressed && MODS_SHIFT && MODS_CTRL) {
                TOGGLE_FLAG_AND_PRINT(usb_gcr_auto, "USB GCR auto mode");
            }
            return false;
        case DBG_TOG:
            if (record->event.pressed) {
                TOGGLE_FLAG_AND_PRINT(debug_enable, "Debug mode");
            }
            return false;
        case DBG_MTRX:
            if (record->event.pressed) {
                TOGGLE_FLAG_AND_PRINT(debug_matrix, "Debug matrix");
            }
            return false;
        case DBG_KBD:
            if (record->event.pressed) {
                TOGGLE_FLAG_AND_PRINT(debug_keyboard, "Debug keyboard");
            }
            return false;
        case DBG_MOU:
            if (record->event.pressed) {
                TOGGLE_FLAG_AND_PRINT(debug_mouse, "Debug mouse");
            }
            return false;
        case MD_BOOT:
            if (record->event.pressed) {
                key_timer = timer_read32();
            } else {
                if (timer_elapsed32(key_timer) >= 500) {
                    reset_keyboard();
                }
            }
            return false;
        case RGB_TOG:
            if (record->event.pressed) {
              switch (rgb_matrix_get_flags()) {
                case LED_FLAG_ALL: {
                    rgb_matrix_set_flags(LED_FLAG_KEYLIGHT | LED_FLAG_MODIFIER | LED_FLAG_INDICATOR);
                    rgb_matrix_set_color_all(0, 0, 0);
                  }
                  break;
                case (LED_FLAG_KEYLIGHT | LED_FLAG_MODIFIER | LED_FLAG_INDICATOR): {
                    rgb_matrix_set_flags(LED_FLAG_UNDERGLOW);
                    rgb_matrix_set_color_all(0, 0, 0);
                  }
                  break;
                case LED_FLAG_UNDERGLOW: {
                    rgb_matrix_set_flags(LED_FLAG_NONE);
                    rgb_matrix_disable_noeeprom();
                  }
                  break;
                default: {
                    rgb_matrix_set_flags(LED_FLAG_ALL);
                    rgb_matrix_enable_noeeprom();
                  }
                  break;
              }
            }
            return false;
        default:
            return true; //Process all other keycodes normally
    }
}

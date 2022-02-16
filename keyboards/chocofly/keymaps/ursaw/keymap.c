#include QMK_KEYBOARD_H
/*#include "g/keymap_combo.h"*/

/* https://getreuer.info/posts/keyboards/select-word/index.html */
#include "select_word.h"
#include "caps_word.h"


/*
*   qmk compile -kb chocofly/v1 -km ursaw
*/







#define _________________QWERTY_L0_________________        KC_GESC , KC_1   , KC_2   , KC_3   , KC_4   , KC_5
#define _________________QWERTY_L1_________________        KC_TAB  , KC_Q   , KC_W   , KC_E   , KC_R   , KC_T
#define _________________QWERTY_L2_________________        KC_LSFT , KC_A   , KC_S   , KC_D   , KC_F   , KC_G
#define _________________QWERTY_L3_________________        KC_LCTRL, KC_Z   , KC_X   , KC_C   , KC_V   , KC_B

#define _________________QWERTY_R0_________________        KC_6   , KC_7   , KC_8   , KC_9   , KC_0   , KC_DEL
#define _________________QWERTY_R1_________________        KC_Y   , KC_U   , KC_I   , KC_O   , KC_P   , KC_BSPC
#define _________________QWERTY_R2_________________        KC_H   , KC_J   , KC_K   , KC_L   , KC_SCLN, KC_QUOT
#define _________________QWERTY_R3_________________        KC_N   , KC_M   , KC_COMM, KC_DOT , KC_SLSH, KC_RSFT


#define RS_SPC LT(_RAISE, KC_SPC)
#define LW_LGUI LT(_LOWER, KC_LGUI)
#define RS_LGUI LT(_RAISE, KC_LGUI)
#define MT_LALT LALT_T(KC_ESC)
#define MT_RALT RALT_T(KC_ENT)
#define MT_LSFT LSFT_T(KC_EQL)
#define MT_RSFT RSFT_T(KC_MINS)

enum layers {
    _QWERTY,
    _LOWER,
    _RAISE,
};

enum custom_keycodes {
    SELWORD  = SAFE_RANGE
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_QWERTY] = LAYOUT(
        KC_GESC , KC_1   , KC_2   , KC_3   , KC_4   , KC_5,                                          KC_6   , KC_7   , KC_8   , KC_9   , KC_0   , KC_DEL,
        KC_TAB  , KC_Q   , KC_W   , KC_E   , KC_R   , KC_T,                                          KC_Y   , KC_U   , KC_I   , KC_O   , KC_P   , KC_BSPC,
        KC_LSFT , KC_A   , KC_S   , KC_D   , KC_F   , KC_G,    KC__MUTE,                             KC_H   , KC_J   , KC_K   , KC_L   , KC_SCLN, KC_QUOT,
        KC_LCTRL, KC_Z   , KC_X   , KC_C   , KC_V   , KC_B,     KC_LGUI,  XXXXXXX,      MO(_LOWER),  KC_RGUI, KC_N   , KC_M   , KC_COMM, KC_DOT , KC_SLSH, KC_RSFT,
                                             KC_LALT, MO(_RAISE), KC_ENT, XXXXXXX,     XXXXXXX,KC_SPC,  MO(_RAISE), KC_RALT
    ),
    [_LOWER] = LAYOUT(
        XXXXXXX, XXXXXXX, KC_7  , KC_8  , KC_9  , KC_BSPC,                                           DM_REC1, DM_REC1, DM_RSTP, XXXXXXX, XXXXXXX, XXXXXXX,
        _______, KC_PAST, KC_4  , KC_5  , KC_6  , KC_PLUS,                                           DM_PLY1, DM_PLY2, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        XXXXXXX ,KC_PSLS, KC_1  , KC_2  , KC_3  , KC_MINUS,  _______,                                XXXXXXX, KC_MPLY, KC_MPRV, KC_MNXT, XXXXXXX, KC_CAPS,
        XXXXXXX, XXXXXXX, KC_0  , KC_0  ,KC_DOT , KC_EQUAL,  _______, _______, _______, _______,     XXXXXXX, KC_MUTE, KC_VOLD, KC_VOLU, XXXXXXX, XXXXXXX,
                                             _______, _______, _______, _______, _______, _______, _______, _______
    ),
    [_RAISE] = LAYOUT(
        _______, KC_F1  , KC_F2  , KC_F3  , KC_F4   , KC_F5   ,                                      KC_F6  , KC_F7  , KC_F8  , KC_F9  , KC_F10  , KC_F11  ,
        _______, SELWORD, KC_LCBR, KC_RCBR, KC_PLUS , KC_GRV  ,                                      KC_PGUP, KC_HOME, KC_UP  , KC_END , KC_INS  , KC_F12  ,
        _______, KC_PIPE, KC_LBRC, KC_RBRC, KC_MINUS, KC_EQUAL,  _______,                            KC_PGDN, KC_LEFT, KC_DOWN, KC_RGHT, KC_MINUS, KC_EQUAL,
        _______, KC_UNDO, KC_LGUI, KC_APP , KC_SPC  , KC_UNDS ,  _______, _______, _______, _______, KC_DEL , KC_BSPC, KC_LBRC, KC_RBRC, KC_BSLASH, _______,
                                              _______, _______, _______, _______, _______, _______, _______, _______
    ),
};

bool encoder_update_user(uint8_t index, bool clockwise) {
    if (index == 0) { /* First encoder */
        if (clockwise) {
            tap_code(KC_PGDOWN);
        } else {
            tap_code(KC_PGUP);
        }
    }
    return true;
}


bool process_record_user(uint16_t keycode, keyrecord_t *record) {

    /* for select word */
    if (!process_select_word(keycode, record, SELWORD)) { return false; }
    /* for caps word */
    if (!process_caps_word(keycode, record)) { return false; }
    return true;
}

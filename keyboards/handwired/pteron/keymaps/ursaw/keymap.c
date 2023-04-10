#include QMK_KEYBOARD_H
#include "g/keymap_combo.h"

//  https://arduino.stackexchange.com/questions/61359/avrdude-error-butterfly-programmer-uses-avr-write-page-but-does-not-provide
//  systemctl stop ModemManager.service

//  PINS  https://golem.hu/article/pro-micro-pinout/
//  TEST  https://config.qmk.fm/#/test

// cd keyboards/handwired/pteron/keymaps/ursaw
// qmk compile
// qmk flash


enum pteron_layers {
  _QWERTY,
  _LOWER,
  _RAISE,
  _ADJUST
};

#define COMBO_ONLY_FROM_LAYER _QWERTY

#define LOWER MO(_LOWER)
#define RAISE MO(_RAISE)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Qwerty
 * +-----------------------------------------+      +-----------------------------------------+
 * |   `  |   1  |   2  |   3  |   4  |   5  |      |   6  |   7  |   8  |   9  |   0  | Bksp |
 * |------+------+------+------+------+------|      |------+------+------+------+------+------|
 * | Tab  |   Q  |   W  |   E  |   R  |   T  |      |   Y  |   U  |   I  |   O  |   P  | Del  |
 * |------+------+------+------+------+------|      |------+------+------+------+------+------|
 * | Esc  |   A  |   S  |   D  |   F  |   G  |      |   H  |   J  |   K  |   L  |   ;  |  "   |
 * |------+------+------+------+------+------|      |------+------+------+------+------+------|
 * | Shift|   Z  |   X  |   C  |   V  |   B  |      |   N  |   M  |   ,  |   .  |   /  |Enter |
 * +-------------+------+------+------+------|      |------+------+------+------+-------------+
 *               |Lower | SPC  | Alt  | GUI  |      | Alt  | GUI  | SPC  |Raise |
 *               +---------------------------+      +---------------------------+
 */
[_QWERTY] = LAYOUT( \
  QK_GESC,        KC_1,     KC_2,    KC_3,    KC_4,    KC_5,                     KC_6,    KC_7,    KC_8,    KC_9,    KC_0,  KC_DEL, \
  KC_TAB,         KC_Q,     KC_W,    KC_E,    KC_R,    KC_T,                     KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,  KC_BSPC, \
  KC_LSFT,        KC_A,     KC_S,    KC_D,    KC_F,    KC_G,                     KC_H,    KC_J,    KC_K,    KC_L, KC_SCLN,  KC_QUOT, \
  KC_LCTL ,       KC_Z,     KC_X,    KC_C,    KC_V,    KC_B,                     KC_N,    KC_M, KC_COMM,  KC_DOT, KC_SLSH,  KC_RSFT, \
                    KC_LALT, RAISE,   KC_ENT,  XXXXXXX,        KC_SPC , KC_SPC, RAISE, KC_RALT \
),

/* Lower
 * +-----------------------------------------+      +-----------------------------------------+
 * |   ~  |   !  |   @  |   #  |   $  |   %  |      |   ^  |   &  |   *  |   (  |   )  | Bksp |
 * |------+------+------+------+------+------|      |------+------+------+------+------+------|/home/urs/qmk_firmware/keyboards/handwired/pteron/keymaps/ursaw/keymap.c
 * |   ~  |   !  |   @  |   #  |   $  |   %  |      |   ^  |   &  |   *  |   (  |   )  | Del  |
 * |------+------+------+------+------+------|      |------+------+------+------+------+------|
 * | Del  |  F1  |  F2  |  F3  |  F4  |  F5  |      |  F6  |   _  |   +  |   {  |   }  |  |   |
 * |------+------+------+------+------+------|      |------+------+------+------+------+------|
 * |      |  F7  |  F8  |  F9  |  F10 |  F11 |      |  F12 |ISO ~ |ISO | |      |      |      |
 * +-------------+------+------+------+------|      |------+------+------+------+-------------+
 *               |      |      |      |      |      | Next | Vol- | Vol+ | Play |
 *               +---------------------------+      +---------------------------+
 */
[_LOWER] = LAYOUT( \
  KC_TILD, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC,         KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_BSPC, \
  KC_TILD, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC,         KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_DEL,  \
  KC_DEL,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,           KC_F6,   KC_UNDS, KC_PLUS, KC_LCBR, KC_RCBR, KC_PIPE, \
  _______, KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,          KC_F12,S(KC_NUHS),S(KC_NUBS),KC_HOME, KC_END, _______, \
                    _______, _______, _______, _______,         KC_MNXT, KC_VOLD, KC_VOLU, KC_MPLY \
),

/* Raise
 * +-----------------------------------------+      +-----------------------------------------+
 * |   `  |   1  |   2  |   3  |   4  |   5  |      |   6  |   7  |   8  |   9  |   0  | Bksp |
 * |------+------+------+------+------+------|      |------+------+------+------+------+------|
 * |   `  |   1  |   2  |   3  |   4  |   5  |      |   6  |   7  |   8  |   9  |   0  | Del  |
 * |------+------+------+------+------+------|      |------+------+------+------+------+------|
 * | Del  |  F1  |  F2  |  F3  |  F4  |  F5  |      |  F6  |   -  |   =  |   [  |   ]  |  \   |
 * |------+------+------+------+------+------|      |------+------+------+------+------+------|
 * |      |  F7  |  F8  |  F9  |  F10 |  F11 |      |  F12 |ISO # |ISO / |      |      |      |
 * +-------------+------+------+------+------|      |------+------+------+------+-------------+
[] *               |      |      |      |      |      | Next | Vol- | Vol+ | Play |
 *               +---------------------------+      +---------------------------+
 */
[_RAISE] = LAYOUT( \
  _______,   KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                           KC_F6,   KC_F7,   KC_F8,   KC_F9,  KC_F10,  KC_F11,\
  _______,  KC_LGUI,  KC_LCBR,   KC_RCBR,  KC_PLUS, KC_GRV,                       KC_PGUP, KC_HOME,  KC_UP, KC_END   ,XXXXXXX, KC_F12, \
  _______,  KC_PIPE,  KC_LBRC, KC_RBRC, KC_MINUS, KC_EQUAL,                       KC_PGDN,  KC_LEFT, KC_DOWN, KC_RGHT,  KC_MINUS, KC_EQUAL, \
  _______, XXXXXXX, KC_LGUI, KC_APP, KC_SPC, KC_UNDS,                            KC_DEL, KC_BSPC, KC_LBRC, KC_RBRC,   KC_BSLS, _______, \
                         _______, _______, _______, KC_LGUI ,          _______, _______, _______, _______ \
),

/* Adjust (Lower + Raise)
 * +-----------------------------------------+      +-----------------------------------------+
 * |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |      |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 |
 * |------+------+------+------+------+------|      |------+------+------+------+------+------|
 * |      | Reset|      |      |      |      |      |      |      |      |      |      |  Del |
 * |------+------+------+------+------+------|      |------+------+------+------+------+------|
 * |      |      |      |Aud on|AudOff|AGnorm|      |AGswap|Qwerty|Colemk|Dvorak|      |      |
 * |------+------+------+------+------+------|      |------+------+------+------+------+------|
 * |      |Voice-|Voice+|Mus on|MusOff|MidiOn|      |MidOff|      |      |      |      |      |
 * +-------------+------+------+------+------|      |------+------+------+------+-------------+
 *               |      |      |      |      |      |      |      |      |      |
 *               +---------------------------+      +---------------------------+
 */
[_ADJUST] = LAYOUT( \
  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,           KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  \
  _______, _______,  _______,   _______, _______, _______,         _______, _______, _______, _______, _______, KC_DEL,  \
  _______, _______, _______, _______, _______, _______,         _______, _______, _______, _______, _______, _______, \
  _______, _______, _______, _______, _______, _______,         _______, _______, _______, _______, _______, _______, \
                    _______, _______, _______, _______,         _______, _______, _______, _______  \
)

};

layer_state_t layer_state_set_user(layer_state_t state) {
  return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
}

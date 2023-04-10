#include QMK_KEYBOARD_H
#include "g/keymap_combo.h"

/* https://getreuer.info/posts/keyboards/select-word/index.html */
// #include "select_word.h"


//  https://arduino.stackexchange.com/questions/61359/avrdude-error-butterfly-programmer-uses-avr-write-page-but-does-not-provide
//  systemctl stop ModemManager.service

//  PINS  https://golem.hu/article/pro-micro-pinout/
//  TEST  https://config.qmk.fm/#/test

// cd keyboards/handwired/dactyl_monoblock/keymaps/ursaw
// qmk compile
// qmk flash


enum layer_names {
  _QWERTY,
  _LOWER,
  _RAISE,
  _ADJUST
};

enum custom_keycodes {
    SELWORD  = SAFE_RANGE
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
  KC_GESC,        KC_1,     KC_2,    KC_3,    KC_4,    KC_5,                     KC_6,    KC_7,    KC_8,    KC_9,    KC_0,  KC_DEL, \
  KC_TAB,         KC_Q,     KC_W,    KC_E,    KC_R,    KC_T,                     KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,  KC_BSPC, \
  KC_LSFT,        KC_A,     KC_S,    KC_D,    KC_F,    KC_G,                     KC_H,    KC_J,    KC_K,    KC_L, KC_SCLN,  KC_QUOT, \
  KC_LCTRL,       KC_Z,     KC_X,    KC_C,    KC_V,    KC_B,                     KC_N,    KC_M, KC_COMM,  KC_DOT, KC_SLSH,  KC_RSFT, \
                 KC_LGUI,     KC_LALT, RAISE,   KC_ENT,  XXXXXXX,        KC_SPC , KC_SPC, RAISE, KC_RALT , LOWER \
),

/* Lower
 * .-----------------------------------------.                                 .-----------------------------------------.
 * |      |      |   7  |   8  |   9  |  BS  |                                  |  Mr1 |  Mr2 | Mstp |      |      |      |
 * |------+------+------+------+------+------|                                  |------+------+------+------+------+------|
 * |  TAB |   *  |   4  |   5  |   6  |   +  |                                  |  M1  |  M2  |      |      |      |      |
 * |------+------+------+------+------+------|                                  |------+------+------+------+------+------|
 * |      |   /  |   1  |   2  |   3  |  -   |                                  |      | STOP | PREV | NEXT |      | CAPS |
 * |------+------+------+------+------+------|                                  |------+------+------+------+------+------|
 * |      |      |   0  |   0  |   .  |  ENT |                                  |      | Mute |  V+  | V-   |      |      |
 * '-----------------------------------------/                                  \-----------------------------------------'
 *               |      |      |      |      |      | Next | Vol- | Vol+ | Play |
 *               +---------------------------+      +---------------------------+
 */
[_LOWER] = LAYOUT( \
   XXXXXXX, XXXXXXX, KC_7  , KC_8  , KC_9  , KC_BSPC,                                DM_REC1, DM_REC1, DM_RSTP, XXXXXXX, XXXXXXX, XXXXXXX,
   _______, KC_PAST, KC_4  , KC_5  , KC_6  , KC_PLUS,                                DM_PLY1, DM_PLY2, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
   XXXXXXX ,KC_PSLS, KC_1  , KC_2  , KC_3  , KC_MINUS,                               XXXXXXX, KC_MPLY, KC_MPRV, KC_MNXT, XXXXXXX, KC_CAPS,
   XXXXXXX, XXXXXXX, KC_0  , KC_0  ,KC_DOT , KC_ENT,                                 XXXXXXX, KC_MUTE, KC_VOLD, KC_VOLU, XXXXXXX, XXXXXXX,
           _______,  _______, _______, _______, _______,     KC_MNXT, KC_VOLD, KC_VOLU, KC_MPLY, _______ \
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
 *               |      |      |      |      |      | Next | Vol- | Vol+ | Play |
 *               +---------------------------+      +---------------------------+
 */
[_RAISE] = LAYOUT( \
  _______,   KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                           KC_F6,   KC_F7,   KC_F8,   KC_F9,  KC_F10,  KC_F11,\
  _______,  SELWORD,  KC_LCBR,   KC_RCBR,  KC_PLUS, KC_GRV,                       KC_PGUP, KC_HOME,  KC_UP, KC_END   ,XXXXXXX, KC_F12, \
  _______,  KC_PIPE,  KC_LBRC, KC_RBRC, KC_MINUS, KC_EQUAL,                       KC_PGDN,  KC_LEFT, KC_DOWN, KC_RGHT,  KC_MINUS, KC_EQUAL, \
  _______, XXXXXXX, KC_LGUI, KC_APP, KC_SPC, KC_UNDS,                            KC_DEL, KC_BSPC, KC_LBRC, KC_RBRC,   KC_BSLASH, _______, \
                   _______,        _______, _______, _______, KC_LGUI ,          _______, _______, _______, _______ , _______ \
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
  _______, _______,   DEBUG,   _______, _______, _______,         _______, _______, _______, _______, _______, KC_DEL,  \
  _______, _______, _______, _______, _______, _______,         _______, _______, _______, _______, _______, _______, \
  _______, _______, _______, _______, _______, _______,         _______, _______, _______, _______, _______, _______, \
           _______,  _______, _______, _______, _______,         _______, _______, _______, _______ , _______  \
)

};

layer_state_t layer_state_set_user(layer_state_t state) {
  return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
}


bool process_record_user(uint16_t keycode, keyrecord_t* record) {


    /* for select word
    if (!process_select_word(keycode, record, SELWORD)) { return false; }
 */
  // Your macros ...

  return true;
}

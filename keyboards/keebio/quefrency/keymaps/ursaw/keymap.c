#include QMK_KEYBOARD_H

//  make  keebio/quefrency/rev2:ursaw
//  qmk compile -kb  keebio/quefrency/rev2 -km ursaw
//  config in $HOME/.config/qmk/qnk.ini



// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
enum keyboard_layers {
  _BL = 0, // Base Layer
  _FK  ,   // Function Keys
  _FL  ,   // Function Layer
  _ML      // Mouse Layer
};


enum custom_keycodes {
  QWERTY = SAFE_RANGE,
};
  /* Keymap: (Base Layer) Default Layer
   * ,-----------------------------------------------------------.
   * |Esc~| 1|  2|  3|  4|  5|  6|  7|  8|  9|  0|  -|  =|  \| MO|
   * |-----------------------------------------------------------|
   * |Tab  |  Q|  W|  E|  R|  T|  Y|  U|  I|  O|  P|  [|  ]|BCKSP|
   * |-----------------------------------------------------------|
   * |   MO  |  A|  S|  D|  F|  G|  H|  J|  K|  L|  ;|  '|Return |
   * |-----------------------------------------------------------|
   * |Shift   |  Z|  X|  C|  V|  B|  N|  M|  ,|  .|  /|Shift | MO|
   * |-----------------------------------------------------------|
   * |Ctrl|Gui |Alt |      Space            |Alt  | LE| DN|RE/CTR|
   * ,-----------------------------------------------------------.
   */
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_BL] = LAYOUT(
    KC_GESC, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL, KC_BSLS ,KC_DEL , \
    KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSPC, \
    MO(_FL), KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,   /*LT(_ML,*/ KC_SCLN, KC_QUOT, KC_ENT, \
    KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, RSFT_T(KC_UP), MO(_FL), \
    KC_LCTL, KC_LGUI, MO(_FL), KC_LALT,  KC_SPC,          KC_BSPC,KC_SPC, KC_RALT, KC_LEFT, KC_NO, KC_DOWN, RCTL_T(KC_RIGHT)
  ),
   /* Keymap: (Functional Layer)
   * ,-----------------------------------------------------------.
   * |Esc~|F1| F2| F3| F4| F5| F6| F7| F8| F9|F10|F11|F12| ~ |INS|
   * |-----------------------------------------------------------|
   * | CAPS|   | UP|   |   |   |   |   |   |   |PLY|PRV|NXT| DEL |
   * |-----------------------------------------------------------|
   * |   MO  | LE| DN| RE|   |   | LE| DN| UP| RE| _ML | ` |Rtrn |
   * |-----------------------------------------------------------|
   * |Shift   |   |   |MENU|  |   |   |MUT|MUP|MDN|  \|  PUP | MO|
   * |-----------------------------------------------------------|
   * |Ctrl|Gui |Alt |      Space            |ALT| HOME |PDN |END |
   * ,-----------------------------------------------------------.
   */
  [_FL] = LAYOUT(
    KC_GESC, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_TILDE,  KC_INS, \
    KC_CAPS, RGB_MOD, _______, KC_UP,   _______, _______, _______, _______, _______, _______, KC_MPLY, KC_MPRV, KC_MNXT, KC_DEL, \
                        /* WASD for cursor */                    /* - - - -  VI for cursor  - - - - */ /* _ML */
    _______, _______, KC_LEFT, KC_DOWN, KC_RGHT, _______, _______, KC_LEFT, KC_DOWN, KC_UP  , KC_RIGHT ,_______, KC_GRAVE,\
    _______, _______, KC_LGUI, KC_APP , _______, _______, _______, KC_MUTE, KC_VOLD, KC_VOLU, KC_BSLS, KC_PGUP, _______, \
    _______, _______, _______, _______, _______,          _______, _______, _______, KC_HOME,  KC_NO , KC_PGDOWN, KC_END
  ),
};

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
   * ,---------------------------.      ,-------------------------------.
   * |Esc~| 1|  2|  3|  4|  5|  6|      |  7|  8|  9|  0|  -|  =|  \| MO|
   * |---------------------------'    ,---------------------------------|
   * |Tab  |  Q|  W|  E|  R|  T|      |  Y|  U|  I|  O|  P|  [|  ]|BCKSP|
   * |---------------------------.    '---------------------------------|
   * |   _FL  |  A|  S|  D|  F|  G|      |  H|  J|  K|  L|  ;|  '|Return|
   * |----------------------------.     '-------------------------------|
   * |Shift   |  Z|  X|  C|  V|  B|      |  N|  M|  ,|  .|  /|Shift | MO|
   * |----------------------------|      |------------------------------|
   * |Ctrl|Gui |Alt |Alt | Return |      | SPACE   |Alt  | LE| DN|RE/CTR|
   * ,----------------------------'      '------------------------------'
   */
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_BL] = LAYOUT(
    KC_GESC, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL, KC_BSLS ,KC_DEL , \
    KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSPC, \
    MO(_FL), KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L, LT(_ML,KC_SCLN), KC_QUOT, KC_ENT, \
    KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, RSFT_T(KC_UP), MO(_FL), \
    KC_LCTL, KC_LGUI, KC_LALT,   KC_LALT, KC_ENT,         KC_NO,  KC_SPC, KC_RALT, KC_LEFT, KC_NO, KC_DOWN, RCTL_T(KC_RIGHT)
  ),
   /* Keymap: (Functional Layer)
   * ,-----------------------------------------------------------.
   * |Esc~|F1| F2| F3| F4| F5| F6| F7| F8| F9|F10|F11|F12| ~ |INS|
   * |-----------------------------------------------------------|
   * | CAPS|   | UP|   |   |   |   |   |   |   |PLY|PRV|NXT| DEL |
   * |-----------------------------------------------------------|
   * |   MO  | LE| DN| RE|   |   | LE| DN| UP| RE| _ML | ` |Rtrn |
   * |-----------------------------------------------------------|
   * |Shift   |   |WIN|MENU|  |   |   |MUT|MUP|MDN|  \|  PUP | MO|
   * |-----------------------------------------------------------|
   * |Ctrl|Gui |Alt |      Space            |ALT| HOME |PDN |END |
   * ,-----------------------------------------------------------.
   */
  [_FL] = LAYOUT(
    KC_GESC, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_TILDE,  KC_INS, \
    _______, _______, KC_UP, _______,   _______, _______, _______, _______, _______, _______, KC_MPLY, KC_MPRV, KC_MNXT, KC_DEL, \
                        /* WASD for cursor */                    /* - - - -  VI for cursor  - - - - */ /* _ML */
    _______, KC_LEFT, KC_DOWN, KC_RGHT, _______, _______, _______, KC_LEFT, KC_DOWN, KC_UP  , KC_RIGHT , KC_GRAVE ,_______,\
    _______, _______, KC_LGUI, KC_APP , _______, _______, _______, KC_MUTE, KC_VOLD, KC_VOLU, KC_BSLS  , KC_PGUP, _______, \
    _______, _______, _______, _______, _______,          _______, _______, _______, KC_HOME,  KC_NO   , KC_PGDOWN, KC_END
  ),
    /*
     *  Funktional keys
     */
  [_FK] = LAYOUT(
    KC_GESC, KC_F1  , KC_F2  , KC_F3  , KC_F4  , KC_F5  , KC_F6  , KC_F7  , KC_F8  , KC_F9  , KC_F10 , KC_F11 , KC_F12 , _______,  _______, \
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
    _______, _______, _______, _______, _______,          _______, _______, _______, _______, _______, _______, _______
  ),
   /* Keymap: (Mouse Layer) incl Macros TODO
   * ,-----------------------------------------------------------.
   * |Esc~|M1| M2| M3| M4| M5| M6| M7| M8| M9|M10|<F>11|F12| |RST|
   * |-----------------------------------------------------------|
   * |     |  L| UP|  R|   |   |   |   |   |   |PLY|PRV|NXT| DEL |
   * |-----------------------------------------------------------|
   * |   MO  | LE| DN| RE|   |   |   |   |   |   |   |   |Return |
   * |-----------------------------------------------------------|
   * |Shift   |   |   |   |   |   |   |MUT|MUP|MDN|  \|  PUP | MO|
   * |-----------------------------------------------------------|
   * |Ctrl|Gui |Alt |      Space            |ALT| HOME |PDN |END |
   * ,-----------------------------------------------------------.
   */
  [_ML] = LAYOUT(
  //  KC_TRNS, M(1)   , M(2)   , M(3)   , M(4)   , M(5)   , M(6)   , M(7)   , M(8)   , M(9)   , M(10)  , M(11)  , M(12)  , XXXXXXX, RESET   ,
    KC_TRNS, DYN_MACRO_PLAY1   , DYN_MACRO_PLAY2   , M(3)   , M(4)   , M(5)   , M(6)   ,DYN_REC_START1   , DYN_REC_START2  , XXXXXXX  ,DYN_REC_STOP  ,XXXXXXX  , M(12)  , XXXXXXX, RESET   , \
   	KC_CAPS,  KC_MS_BTN1, KC_MS_UP,  KC_MS_BTN2,   XXXXXXX, RGB_TOG, RGB_MOD, RGB_HUI, RGB_HUD, RGB_SAI, RGB_SAD, _______, RGB_VAD, RGB_MODE_PLAIN, \
	_______,  KC_MS_LEFT, KC_MS_DOWN,KC_MS_RIGHT,   TG(_FK), XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______, _______, _______, \
    XXXXXXX, XXXXXXX, KC_MS_ACCEL0, KC_MS_ACCEL1, KC_MS_ACCEL2,  XXXXXXX, BL_DEC,  BL_TOGG, BL_INC,  BL_STEP, XXXXXXX, _______, _______, \
    _______, _______, _______, _______, _______,          _______, _______, _______, _______, _______, _______, _______
  )
};


/*
 rules.mk: LEADER_ENABLE = yes
comfig.h: #define LEADER_TIMEOUT 300
define KC_LEAD somewhere


LEADER_EXTERNS();

// Declare a boolean variable to keep track of whether any sequence
// will have been matched.
bool did_leader_succeed;

void matrix_scan_user(void) {
  LEADER_DICTIONARY() {
    // Initialize did_leader_succeed as well as leading to be false
    did_leader_succeed = leading = false;

    // Replace the sequences below with your own sequences.
    SEQ_ONE_KEY(KC_A) {
      SEND_STRING(SS_LCTRL(SS_LSFT("t")));
      // In each sequence, set our flag to true. This way, we'll
      // know when any sequence was matched.
      did_leader_succeed = true;
    }
    SEQ_ONE_KEY(KC_T) {
      SEND_STRING(SS_LCTRL(SS_LSFT("t")));
      // In each sequence, set our flag to true. This way, we'll
      // know when any sequence was matched.
      did_leader_succeed = true;
    }
    SEQ_TWO_KEYS(KC_N, KC_T) {
      SEND_STRING(SS_LCTRL("t"));
      did_leader_succeed = true;
    }
    //SEQ_TWO_KEYS(KC_C, KC_C) {
    //  SEND_STRING("Per key timing is great!!!");
    //}

    // Call leader_end at the end of the function, instead of at
    // the start. This way, we're sure we have set did_leader_succeed.
    leader_end();
  }
}

void leader_end(void) {
  if (did_leader_succeed) {
    // If any sequence was matched, did_leader_succeed will have
    // been set to true up in the matrix_scan_user function.
    // Put your code for a matched leader key sequence here.
  } else {
    // If no sequence was matched, did_leader_succeed will not
    // have been set to true anywhere, so we'll end up here.
    // Put your code for an unmatched leader key sequence here.
  }
}

*/

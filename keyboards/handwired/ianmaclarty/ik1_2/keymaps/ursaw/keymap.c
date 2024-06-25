#include QMK_KEYBOARD_H

//
//   util/docker_build.sh  handwired/ianmaclarty/ik1_2:ursaw
//
// https://forum.colemak.com/topic/1858-learn-colemak-in-steps-with-the-tarmak-layouts/

//  todo otionally add a enum  SAFE_RANGE

enum ik_layers {
   LBASE1,
   LBASE2,
   LNUM,
   LNAV,
   LFN,
   LBSEL,
   _RAISE,
   _LOWER,
   _MOUSE,
   _TARMAK1,
   _TARMAK2,
   _TARMAK3
};


enum custom_keycodes {
    MS_NE = SAFE_RANGE,  // keycodes for specific mouse movement
    MS_NW ,
    MS_SE ,
    MS_SW ,
    MSM_N,
    MSM_S,
    MSM_E,
    MSM_W,
    MSM_NE ,
    MSM_NW ,
    MSM_SE ,
    MSM_SW ,
};



#define TABNUM LT(LNUM, KC_TAB)
#define ENTNAV LT(LNAV, KC_ENT)
#define BSNAV LT(LNAV, KC_BSPC)
#define NAV MO(LNAV)
#define BSSFT MT(MOD_RSFT,KC_BSPC)
#define FN MO(LFN)
#define BASE1 DF(LBASE1)
#define BASE2 DF(LBASE2)
#define BSEL MO(LBSEL)

#define LMSE5  LT(_MOUSE, KC_5)


#define SPC_RSE  LT(_RAISE, KC_SPC)
#define SPC_BS2  LT(LBASE2, KC_SPC)
#define ENT_RSE  LT(_RAISE, KC_ENT)
#define ENT_LWR  LT(_LOWER, KC_ENT)
#define SPC_LWR  LT(_LOWER, KC_SPC)


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

[LBASE1] = LAYOUT_split_4x6_3(
_______,    KC_1,       KC_2,       KC_3,       KC_4,       LMSE5,                             KC_6,       KC_7,       KC_8,       KC_9,       KC_0,       _______,
KC_TAB,     KC_Q,       KC_W,       KC_E,       KC_R,       KC_T,                              KC_Y,       KC_U,       KC_I,       KC_O,       KC_P,       KC_BSPC,
KC_LSFT,    KC_A,       KC_S,       KC_D,       KC_F,       KC_G,                              KC_H,       KC_J,       KC_K,       KC_L,       KC_SCLN,    KC_QUOT,
KC_LCTL,    KC_Z,       KC_X,       KC_C,       KC_V,       KC_B,                              KC_N,       KC_M,       KC_COMM,    KC_DOT,     KC_SLSH,    KC_RSFT,
                                                KC_LALT,    ENT_RSE, ENT_LWR,        SPC_BS2, SPC_RSE,    KC_RALT

),

[LBASE2] = LAYOUT_split_4x6_3(
_______,    KC_1,       KC_2,       KC_3,       KC_4,       KC_5,                              KC_6,       KC_7,       KC_8,       KC_9,       KC_0,       _______,
QK_GESC,    KC_Q,       KC_W,       KC_E,       KC_R,       KC_T,                              KC_Y,       KC_U,       KC_I,       KC_O,       KC_P,       KC_DEL,
KC_LSFT,    KC_A,       KC_S,       KC_D,       KC_F,       KC_G,                              KC_H,       KC_J,       KC_K,       KC_L,       KC_SCLN,    KC_QUOT,
KC_LCTL,    KC_Z,       KC_X,       KC_C,       KC_V,       KC_B,                              KC_N,       KC_M,       KC_COMM,    KC_DOT,     KC_SLSH,    KC_RSFT,
                                                 KC_LGUI,    ENT_RSE, MO(_LOWER),     SPC_BS2, SPC_RSE,    KC_RALT
),



[_TARMAK1] = LAYOUT_split_4x6_3(
_______,    KC_1,       KC_2,       KC_3,       KC_4,       KC_5,                              KC_6,       KC_7,       KC_8,       KC_9,       KC_0,       _______,
KC_TAB,     KC_Q,       KC_W,       KC_J,       KC_R,       KC_T,                              KC_Y,       KC_U,       KC_I,       KC_O,       KC_P,       KC_BSPC,
KC_LSFT,    KC_A,       KC_S,       KC_D,       KC_F,       KC_G,                              KC_H,       KC_N,       KC_E,       KC_L,       KC_SCLN,    KC_QUOT,
KC_LCTL,    KC_Z,       KC_X,       KC_C,       KC_V,       KC_B,                              KC_N,       KC_K,       KC_COMM,    KC_DOT,     KC_SLSH,    KC_RSFT,
                                                KC_LALT,    ENT_RSE, ENT_LWR,        SPC_BS2*****, SPC_RSE,    KC_RALT
),



  /* RAISE
   *
   * .-----------------------------------------.                                  .-----------------------------------------.
   * |      |  F1  |  F2  |  F3  |  F4  |  F5  |                                  |  F6  |  F7  |  F8  |  F9  |  F10 |      |
   * |------+------+------+------+------+------|                                  |------+------+------+------+------+------|
   * |      |  ESC |  {   |   }  |   +  |  `   |                                  |  PGUP| HOME |   UP |  END |      |  F11 |
   * |------+------+------+------+------+------|                                  |------+------+------+------+------+------|
   * |      |   |  |  [   |   ]  |   -  |  =   |                                  |  PGDN|  LFT |  DWN |  RGT |  -   |  F12 |
   * |------+------+------+------+------+------|                                  |------+------+------+------+------+------|
   * |      |  UNDO|  GUI |  APP |  SPC |  _   |                                  |  DEL | BSPC |   [  |  ]   |   \  |      |
   * '-----------------------------------------/                                  \-----------------------------------------'
   */
[_RAISE] = LAYOUT_split_4x6_3(
 _______, KC_F1  , KC_F2  , KC_F3  , KC_F4   , KC_F5   ,                                 KC_F6  , KC_F7  , KC_F8  , KC_F9  , KC_F10  ,_______   ,
   _______, QK_GESC, KC_LCBR, KC_RCBR, KC_PLUS , KC_GRV  ,                                 KC_PGUP, KC_HOME, KC_UP  , KC_END , KC_INS  , KC_F11  ,
   _______, KC_PIPE, KC_LBRC, KC_RBRC, KC_MINUS, KC_EQUAL,                                 KC_PGDN, KC_LEFT, KC_DOWN, KC_RGHT, KC_MINUS, KC_F12,
   _______, KC_UNDO, KC_LGUI, KC_APP , KC_SPC  , KC_UNDS ,                                 KC_BSPC,KC_MS_BTN1,KC_MS_BTN3,KC_MS_BTN2, KC_BSLS, _______,
                                               KC_LALT,    ENT_RSE, KC_LGUI,        SPC_LWR, SPC_RSE,    KC_RALT
),

[_LOWER] = LAYOUT_split_4x6_3(
   XXXXXXX, XXXXXXX, KC_7  , KC_8  , KC_9  , KC_BSPC,                                DM_REC1, DM_REC1, DM_RSTP, XXXXXXX, XXXXXXX, XXXXXXX,
   _______, KC_PAST, KC_4  , KC_5  , KC_6  , KC_PLUS,                                DM_PLY1, DM_PLY2, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
   XXXXXXX ,KC_PSLS, KC_1  , KC_2  , KC_3  , KC_MINUS,                              XXXXXXX, KC_MPLY, KC_MPRV, KC_MNXT, XXXXXXX, KC_CAPS,
   XXXXXXX, XXXXXXX, KC_0  , KC_0  ,KC_DOT , KC_ENT,                                XXXXXXX, KC_MUTE, KC_VOLD, KC_VOLU, XXXXXXX, XXXXXXX,
                                                  KC_LGUI,    ENT_RSE, KC_LGUI,        SPC_LWR, SPC_RSE,    KC_RALT
),

// WIP
[_MOUSE] = LAYOUT_split_4x6_3(
 _______, KC_F1  , KC_F2  , KC_F3  , KC_F4   , KC_F5   ,                                 KC_F6  , KC_F7  , KC_F8  , KC_F9  , KC_F10  ,_______   ,
   _______, QK_GESC, KC_LCBR, KC_RCBR, KC_PLUS , KC_GRV  ,                                 KC_PGUP, KC_HOME, KC_MS_U	  , KC_END , KC_INS  , KC_F11  ,
   _______, KC_PIPE, KC_LBRC, KC_RBRC, KC_MINUS, KC_EQUAL,                                 KC_PGDN, KC_MS_L	, KC_MS_D	, KC_MS_R	, KC_MINUS, KC_F12,
   _______, KC_UNDO, KC_LGUI, KC_APP , KC_SPC  , KC_UNDS ,                                 KC_BSPC,KC_MS_BTN1,KC_MS_BTN3,KC_MS_BTN2, KC_BSLS, _______,
                                                _______,    _______,    _______,    KC_BTN1 ,    KC_BTN2,    KC_MS_BTN3
),


[LNUM] = LAYOUT_split_4x6_3(
_______,    KC_F1,      KC_F2,      KC_F3,      KC_F4,      KC_F5,                              KC_F6,      KC_F7,      KC_F8,      KC_F9,      KC_F10,     _______,
_______,    KC_EXLM,    KC_AT,      KC_HASH,    KC_DLR,     KC_TILD,                            _______,    KC_7,       KC_8,       KC_9,       _______,    KC_BSPC,
_______,    KC_PERC,    KC_CIRC,    KC_AMPR,    KC_ASTR,    KC_GRV,                             KC_MINS,    KC_4,       KC_5,       KC_6,       KC_PIPE,    _______,
_______,    _______,    _______,    _______,    _______,    _______,                            _______,    KC_1,       KC_2,       KC_3,       KC_BSLS,    _______,
                                                _______,    _______,    _______,    _______,    KC_0,       KC_DOT
),

[LNAV] = LAYOUT_split_4x6_3(
_______,    KC_F1,      KC_F2,      KC_F3,      KC_F4,      KC_F5,                              KC_F6,      KC_F7,      KC_F8,      KC_F9,      KC_F10,     _______,
_______,    KC_UNDS,    KC_PLUS,    KC_LCBR,    KC_RCBR,    KC_TILD,                            KC_PGUP,    KC_HOME,    KC_UP,      KC_END,     KC_PSCR,    KC_BSPC,
_______,    KC_MINS,    KC_EQL,     KC_LBRC,    KC_RBRC,    KC_GRV,                             KC_PGDN,    KC_LEFT,    KC_DOWN,    KC_RIGHT,   KC_PIPE,    _______,
_______,    KC_F11,     KC_F12,     KC_LPRN,    KC_RPRN,    _______,                            KC_INS,     KC_MUTE,    KC_VOLD,    KC_VOLU,    KC_BSLS,    _______,
                                                _______,    _______,    _______,    _______,    _______,    _______
),

[LFN] = LAYOUT_split_4x6_3(
_______,    KC_F1,      KC_F2,      KC_F3,      KC_F4,      KC_F5,                              KC_F6,      KC_F7,      KC_F8,      KC_F9,      KC_F10,     _______,
_______,    KC_F1,      KC_F2,      KC_F3,      KC_F4,      _______,                            _______,    _______,    _______,    _______,    KC_PSCR,    _______,
_______,    KC_F5,      KC_F6,      KC_F7,      KC_F8,      _______,                            _______,    _______,    _______,    _______,    _______,    _______,
_______,    KC_F9,      KC_F10,     KC_F11,     KC_F12,     BSEL,                               _______,    _______,    _______,    _______,    _______,    _______,
                                                _______,    _______,    _______,    _______,    _______,    _______
),

[LBSEL] = LAYOUT_split_4x6_3(
_______,    DF(_TARMAK1),      BASE2,      _______,    _______,    _______,                            _______,    _______,    _______,    _______,    _______,    _______,
_______,    BASE1,      _______,    _______,    _______,    _______,                            _______,    _______,    _______,    _______,    _______,    _______,
_______,    _______,    _______,    _______,    _______,    _______,                            _______,    _______,    _______,    _______,    _______,    _______,
_______,    _______,    _______,    _______,    _______,    _______,                            _______,    _______,    _______,    _______,    _______,    _______,
                                                _______,    _______,    _______,    _______,    _______,    _______
),

};


bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
    case MS_NE:
        if (record->event.pressed) {
            // when keycode QMKBEST is pressed
            SEND_STRING("QMK is the best thing ever!");
        } else {
            // when keycode QMKBEST is released
        }
        break;
    }
    return true;
};

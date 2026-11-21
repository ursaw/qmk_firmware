// HEADING_WORDS - see heading_word.h for the description.

#include "heading_word.h"

#ifndef HEADING_WORD_GAP
#    define HEADING_WORD_GAP 3 // spaces between words
#endif

#ifndef HEADING_WORD_UNDO_SIZE
#    define HEADING_WORD_UNDO_SIZE 32 // number of characters Backspace can undo
#endif

typedef enum {
    HW_IGNORE,  // not handled here, mode stays on (layer and modifier keys)
    HW_LETTER,  // a-z, sent uppercase
    HW_SYMBOL,  // digits and punctuation, sent as typed
    HW_SPACE,   // word gap
    HW_BSPC,    // undo last character
    HW_ENTER,   // end mode, key is sent
    HW_ESC,     // end mode, key is swallowed
    HW_OTHER,   // end mode, key is passed through
} hw_class_t;

static bool    active      = false;
static bool    has_output  = false; // something was sent since the mode started
static bool    gap_pending = false; // Space pressed, gap not yet sent

// Ring buffer with the number of characters each unit has sent.
static uint8_t undo[HEADING_WORD_UNDO_SIZE];
static uint8_t undo_len  = 0;
static uint8_t undo_head = 0;

static void undo_push(uint8_t n) {
    undo[undo_head] = n;
    undo_head       = (undo_head + 1) % HEADING_WORD_UNDO_SIZE;
    if (undo_len < HEADING_WORD_UNDO_SIZE) {
        undo_len++;
    }
}

static uint8_t undo_pop(void) {
    if (undo_len == 0) {
        return 0;
    }
    undo_head = (undo_head + HEADING_WORD_UNDO_SIZE - 1) % HEADING_WORD_UNDO_SIZE;
    undo_len--;
    return undo[undo_head];
}

static void reset_state(void) {
    has_output  = false;
    gap_pending = false;
    undo_len    = 0;
    undo_head   = 0;
}

void heading_word_on(void) {
#ifdef CAPS_WORD_ENABLE
    caps_word_off();
#endif
    reset_state();
    active = true;
}

void heading_word_off(void) {
    active = false;
    reset_state();
}

void heading_word_toggle(void) {
    if (active) {
        heading_word_off();
    } else {
        heading_word_on();
    }
}

bool is_heading_word_on(void) {
    return active;
}

static bool is_symbol(uint8_t kc) {
    switch (kc) {
        case KC_1 ... KC_0:              // digits
        case KC_MINUS ... KC_SLASH:      // - = [ ] \ # ; ' ` , . /
        case KC_NONUS_BACKSLASH:         // ISO < >
        case KC_KP_SLASH ... KC_KP_PLUS: // keypad / * - +
        case KC_KP_1 ... KC_KP_DOT:      // keypad digits and .
        case KC_KP_EQUAL:
        case KC_KP_COMMA:
            return true;
        default:
            return false;
    }
}

// Classify a basic (8 bit) keycode.
static hw_class_t classify_basic(uint8_t kc) {
    if (kc >= KC_A && kc <= KC_Z) {
        return HW_LETTER;
    }
    if (is_symbol(kc)) {
        return HW_SYMBOL;
    }
    switch (kc) {
        case KC_SPACE:
            return HW_SPACE;
        case KC_BACKSPACE:
            return HW_BSPC;
        case KC_ENTER:
        case KC_KP_ENTER:
            return HW_ENTER;
        case KC_ESCAPE:
            return HW_ESC;
        case KC_LEFT_CTRL ... KC_RIGHT_GUI:
            return HW_IGNORE;
        default:
            return HW_OTHER;
    }
}

// Classify any keycode. May replace *keycode with the tapped basic keycode.
static hw_class_t classify(uint16_t *keycode, keyrecord_t *record) {
    uint16_t kc = *keycode;

    switch (kc) {
#ifndef NO_ACTION_TAPPING
        case QK_MOD_TAP ... QK_MOD_TAP_MAX:
            if (record->tap.count == 0) {
                return HW_IGNORE; // held: acts as modifier
            }
            kc = QK_MOD_TAP_GET_TAP_KEYCODE(kc);
            break;
#    ifndef NO_ACTION_LAYER
        case QK_LAYER_TAP ... QK_LAYER_TAP_MAX:
            if (record->tap.count == 0) {
                return HW_IGNORE; // held: acts as layer key
            }
            kc = QK_LAYER_TAP_GET_TAP_KEYCODE(kc);
            break;
#    endif
#endif
#ifndef NO_ACTION_LAYER
        case QK_TO ... QK_TO_MAX:
        case QK_MOMENTARY ... QK_MOMENTARY_MAX:
        case QK_DEF_LAYER ... QK_DEF_LAYER_MAX:
        case QK_TOGGLE_LAYER ... QK_TOGGLE_LAYER_MAX:
        case QK_LAYER_TAP_TOGGLE ... QK_LAYER_TAP_TOGGLE_MAX:
        case QK_LAYER_MOD ... QK_LAYER_MOD_MAX:
        case QK_ONE_SHOT_LAYER ... QK_ONE_SHOT_LAYER_MAX:
#endif
#ifndef NO_ACTION_ONESHOT
        case QK_ONE_SHOT_MOD ... QK_ONE_SHOT_MOD_MAX:
#endif
            return HW_IGNORE;

        case QK_GRAVE_ESCAPE:
            return HW_ESC;

        case QK_MODS ... QK_MODS_MAX: {
            // e.g. KC_EXLM = LSFT(KC_1). Only plain shifted keys are kept.
            const uint8_t mods = QK_MODS_GET_MODS(kc);
            // Bit 4 only marks "right hand"; Shift is bit 1.
            if ((mods & 0x0F) & ~MOD_LSFT) {
                return HW_OTHER;
            }
            const hw_class_t c = classify_basic(QK_MODS_GET_BASIC_KEYCODE(kc));
            return (c == HW_LETTER || c == HW_SYMBOL) ? HW_SYMBOL : HW_OTHER;
        }

        default:
            break;
    }

    if (kc > 0xFF) {
        return HW_OTHER;
    }
    *keycode = kc;
    return classify_basic((uint8_t)kc);
}

// Send the spaces that belong in front of the next character, the character
// itself, and remember how many characters were sent for Backspace.
static void send_unit(uint16_t keycode, bool uppercase) {
    uint8_t n = 0;

    if (has_output) {
        const uint8_t spaces = gap_pending ? HEADING_WORD_GAP : 1;
        for (uint8_t i = 0; i < spaces; i++) {
            tap_code(KC_SPACE);
        }
        n += spaces;
    }
    gap_pending = false;

    if (uppercase) {
        // With Caps Lock on, the OS already uppercases; Shift would undo it.
        if (host_keyboard_led_state().caps_lock) {
            tap_code16(keycode);
        } else {
            tap_code16(LSFT(keycode));
        }
    } else {
        tap_code16(keycode);
    }
    n += 1;

    undo_push(n);
    has_output = true;
}

bool process_heading_word(uint16_t keycode, keyrecord_t *record, uint16_t hd_keycode) {
    if (keycode == hd_keycode) {
        if (record->event.pressed) {
            heading_word_toggle();
        }
        return false;
    }

    if (!active) {
        return true;
    }

    hw_class_t c = classify(&keycode, record);

    if (c == HW_IGNORE) {
        return true;
    }

    // Keys handled on press are swallowed on release as well.
    if (!record->event.pressed) {
        return !(c == HW_LETTER || c == HW_SYMBOL || c == HW_SPACE || c == HW_BSPC || c == HW_ESC);
    }

    // A shortcut with Ctrl, Alt or GUI held ends the mode.
    const uint8_t mods = get_mods() | get_oneshot_mods();
    if ((mods & (MOD_MASK_CTRL | MOD_MASK_ALT | MOD_MASK_GUI)) && c != HW_ESC) {
        heading_word_off();
        return true;
    }

    switch (c) {
        case HW_LETTER:
            send_unit(keycode, true);
            return false;

        case HW_SYMBOL:
            send_unit(keycode, false);
            return false;

        case HW_SPACE:
            if (has_output) {
                gap_pending = true; // sent together with the next character
            }
            return false;

        case HW_BSPC: {
            if (gap_pending) {
                gap_pending = false;
                return false;
            }
            const uint8_t n = undo_pop();
            if (n == 0) {
                return true; // nothing to undo: normal Backspace
            }
            for (uint8_t i = 0; i < n; i++) {
                tap_code(KC_BACKSPACE);
            }
            if (undo_len == 0) {
                has_output = false;
            }
            return false;
        }

        case HW_ENTER:
            heading_word_off();
            return true;

        case HW_ESC:
            heading_word_off();
            return false;

        case HW_OTHER:
        default:
            heading_word_off();
            return true;
    }
}

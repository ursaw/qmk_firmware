// HEADING_WORDS
//
// While active, typed text is converted into a spaced-out heading:
//
//   keys:   t h i s <space> i s <enter>
//   output: "T H I S   I S" + Enter
//
// Rules:
//   * Letters a-z are sent uppercase.
//   * Digits and punctuation are sent unshifted (as typed).
//   * Every character gets one space in front of it, except the very first.
//   * Space marks a word gap: the next character gets three spaces in front.
//     The gap is only sent together with the next character, so there is
//     never a leading or trailing space.
//   * Backspace removes the last character together with the spaces sent
//     in front of it (or cancels a pending word gap).
//   * Enter ends the mode and is sent (a pending word gap is dropped).
//   * Esc ends the mode and is NOT sent.
//   * Pressing the heading key again ends the mode.
//   * Any other key (arrows, Tab, F-keys, shortcuts with Ctrl/Alt/GUI, ...)
//     ends the mode and is passed through.
//   * Layer keys and modifier keys pressed alone do not end the mode.
//
// Usage in keymap.c:
//
//   #include "heading_word.h"
//   enum custom_keycodes { HD_WORD = SAFE_RANGE, ... };
//
//   bool process_record_user(uint16_t keycode, keyrecord_t *record) {
//       if (!process_heading_word(keycode, record, HD_WORD)) { return false; }
//       ...
//   }

#pragma once

#include QMK_KEYBOARD_H

bool process_heading_word(uint16_t keycode, keyrecord_t *record, uint16_t hd_keycode);

void heading_word_on(void);
void heading_word_off(void);
void heading_word_toggle(void);
bool is_heading_word_on(void);



#include QMK_KEYBOARD_H
#include "midi.h"
#include "qmk_midi.h"

enum layers
{
  _BL,
  _FL,
  _SL,
  _TL
};

uint8_t currentLayer;

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {


[_BL] = LAYOUT(
  KC_ESC,   KC_1,   KC_2,    KC_3,    KC_4,    KC_5,                     KC_6,    KC_7,    KC_8,    KC_9,    KC_0,  KC_DEL,
  KC_TAB,   KC_Q,   KC_W,    KC_E,    KC_R,    KC_T,                     KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,  KC_BSPC,
  KC_LCTRL,   KC_A,   KC_S,    KC_D,    KC_F,    KC_G,                     KC_H,    KC_J,    KC_K,    KC_L, KC_SCLN,  KC_QUOT,
  KC_LSFT,  KC_Z,   KC_X,    KC_C,    KC_V,    KC_B, KC_MUTE,     KC_PSCR,KC_N,    KC_M, KC_COMM,  KC_DOT, KC_SLSH,  KC_RSFT,
                 KC_LGUI,KC_LALT,KC_LCTRL, MO(1), KC_SPC,      KC_ENT,  MO(2), KC_RCTRL, KC_RALT, KC_RGUI
),


[_FL] = LAYOUT(
  KC_GRV,   KC_F1,  KC_F2,   KC_F3,   KC_F4,   KC_F5,                     KC_F6,   KC_F7,   KC_F8,   KC_F9,  KC_F10,  KC_F11,
  _______,_______,KC_UP,_______,_______,_______,                   _______, _______, _______, _______, _______,   KC_F12,
  _______, KC_LEFT, KC_DOWN,KC_RIGHT, _______, _______,                   _______, _______, _______, _______, _______,  _______,
  _______,_______,_______, _______,_______, _______, _______,      _______,_______, _______, _______, _______, _______,  _______,
                 _______,_______,_______,_______, _______,      _______,  _______, _______, _______, _______
),

 
[_SL] = LAYOUT(
  _______, _______ , _______ , _______ , _______ , _______,                           _______,  _______  , _______,  _______ ,  _______ ,_______,
  _______,_______,_______,_______,_______,_______,                   _______, _______, _______, _______, _______, _______,
  _______, KC_EXCLAIM, KC_AT, KC_HASH, KC_DLR, KC_PERC,                   KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN,  KC_PIPE,
  _______,KC_PEQL,KC_MINS,KC_PPLS,KC_LCBR,KC_RCBR, _______,      _______,KC_LBRC, KC_RBRC, KC_SCLN, KC_COLN, KC_BSLS,  KC_RSFT,
                 _______,_______,_______,_______, _______,      _______, _______, _______, _______, _______
),

 
[_TL] = LAYOUT(
  _______, _______ , _______ , _______ , _______ , _______,                           _______,  _______  , _______,  _______ ,  _______ ,_______,
  _______,_______,_______,_______,_______,_______,                   _______, _______, _______, _______, _______, _______,
  _______, _______, _______, _______, _______, _______,                   _______, _______, _______, _______, _______,  _______,
  _______,_______,_______, _______,_______, _______, _______,      _______,_______, _______, _______, _______, _______,  _______,
                 _______,_______,_______,_______, _______,      _______, _______, _______, _______, _______
)
};

void encoder_update_user(uint8_t index, bool clockwise) {
    if (index == 0) { /* left encoder */
      switch(currentLayer) { //break each encoder update into a switch statement for the current layer
            case _BL:
                if (clockwise) {
                    midi_send_cc(&midi_device, 0, 0x14, 1);
                } else {
                    midi_send_cc(&midi_device, 0, 0x14, 65);
                }
                break;
            case _FL:
                if (clockwise) {
                    midi_send_cc(&midi_device, 0, 0x1A, 1);
                } else {
                    midi_send_cc(&midi_device, 0, 0x1B, 1);
                }
                break;

      }
    } else if (index == 1) { /* right encoder */
        switch (currentLayer) {
            case _BL:
                if (clockwise) {
                    midi_send_cc(&midi_device, 0, 0x15, 1);
                } else {
                    midi_send_cc(&midi_device, 0, 0x15, 65);
                }
                break;
            case _FL:
                if (clockwise) {
                    midi_send_cc(&midi_device, 0, 0x1C, 1);
                } else {
                    midi_send_cc(&midi_device, 0, 0x1D, 1);
                }
                break;
        }
    }
}
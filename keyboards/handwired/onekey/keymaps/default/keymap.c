#include QMK_KEYBOARD_H

#define _BL   0
#define _FL   1

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
[_BL] = LAYOUT_ortho_1x1( KC_ESC, KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, KC_MINS, KC_EQL, KC_BSPC, \
         KC_TAB, KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P, KC_LBRC, KC_RBRC, KC_BSLASH, \
         KC_CAPS, KC_A, KC_S, KC_D, KC_F, KC_G, KC_H, KC_J, KC_K, KC_L, KC_SCLN, KC_QUOT, KC_ENT, \
         KC_LSFT, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, KC_RSFT, KC_UP, KC_RCTL, \
         KC_LCTL, KC_LGUI, KC_LALT,                 KC_SPC,          F(0), KC_RALT, KC_LEFT, KC_DOWN, KC_RIGHT ),
[_FL] = LAYOUT_ortho_1x1(
         KC_GRAVE, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, KC_F11, KC_F12, KC_DELETE, \
         KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_INSERT, KC_TRNS, KC_PSCREEN, KC_SCROLLLOCK, KC_PAUSE, KC_TRNS, \
         KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, F(2), KC_TRNS, KC_HOME, KC_PGUP, KC_ENT, \
         KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_AUDIO_VOL_DOWN, KC_AUDIO_MUTE, KC_AUDIO_VOL_UP, KC_TRNS, KC_TRNS, KC_END, KC_PGDOWN, KC_TRNS, KC_MEDIA_STOP, KC_TRNS, \
         KC_TRNS, KC_TRNS, KC_TRNS,                 KC_TRNS,          KC_TRNS, KC_TRNS, KC_MEDIA_PREV_TRACK, KC_MEDIA_PLAY_PAUSE, KC_MEDIA_NEXT_TRACK
)
};

const uint16_t PROGMEM fn_actions[] = {
    [0] = ACTION_LAYER_MOMENTARY(1),  // to Fn overlay
    [2] = ACTION_FUNCTION(2)
};

void action_function(keyrecord_t *record, uint8_t id, uint8_t opt) {
  switch (id) {
  case 2:
    if (record->event.pressed) {
      palTogglePad(TEENSY_PIN13_IOPORT, TEENSY_PIN13);
    }
    break;
  }
}


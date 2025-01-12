#include QMK_KEYBOARD_H

enum preonic_layers {
  _QWERTY,
  _LOWER,
  _RAISE,
  _DNEFF
};

#define MEDIA_KEY_DELAY 10

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
	[_QWERTY] = LAYOUT_preonic_grid( \
			KC_ESC,        KC_1,    KC_2,    KC_3,    KC_4,  KC_5,   KC_6,   KC_7,  KC_8,     KC_9,     KC_0,    KC_BSPC, \
			KC_TAB,        KC_Q,    KC_W,    KC_E,    KC_R,  KC_T,   KC_Y,   KC_U,  KC_I,     KC_O,     KC_P,    KC_DEL,  \
			MO(3),         KC_A,    KC_S,    KC_D,    KC_F,  KC_G,   KC_H,   KC_J,  KC_K,     KC_L,     KC_SCLN, KC_QUOT, \
			KC_LSFT,       KC_Z,    KC_X,    KC_C,    KC_V,  KC_B,   KC_N,   KC_M,  KC_COMM,  KC_DOT,   KC_SLSH, KC_ENT,  \
			KC_AUDIO_MUTE, KC_LCTL, KC_LALT, KC_LGUI, MO(1), KC_SPC, KC_SPC, MO(2), KC_MINUS, KC_EQUAL, KC_LBRC, KC_RBRC  \
			),
	[_LOWER] = LAYOUT_preonic_grid( \
			KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,   KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC, \
			KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,   KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_DEL,  \
			KC_DEL,  KC_F1,   KC_F2,   KC_F3,   KC_F4,  KC_F5,   KC_F6,   KC_MINS, KC_EQL,  KC_LBRC, KC_RBRC, KC_BSLS, \
			KC_TRNS, KC_F7,   KC_F8,   KC_F9,   KC_F10, KC_F11,  KC_F12,  KC_NUHS, KC_NUBS, KC_PGUP, KC_PGDN, KC_TRNS, \
			KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, MO(3),  KC_TRNS, KC_TRNS, KC_TRNS, KC_MNXT, KC_VOLD, KC_VOLU, KC_MPLY  \
			),
	[_RAISE] = LAYOUT_preonic_grid( \
			KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,    KC_F10,  KC_F11,  KC_F12,  \
			KC_TRNS, RESET,   DEBUG,   KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, TERM_ON, TERM_OFF, KC_TRNS, KC_TRNS, KC_DEL,  \
			KC_TRNS, KC_TRNS, MU_MOD,  AU_ON,   AU_OFF,  AG_NORM, AG_SWAP, DF(0),   DF(1),    DF(2),   KC_TRNS, KC_TRNS, \
			KC_TRNS, MUV_DE,  MUV_IN,  MU_ON,   MU_OFF,  MI_ON,   MI_OFF,  KC_TRNS, KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, \
			KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS  \
			),
	[_DNEFF] = LAYOUT_preonic_grid( \
			KC_GRV,     KC_F1,   KC_F2,   KC_F3,   KC_F4, KC_F5, KC_F6, KC_F7,   KC_F8,   KC_F9,   KC_F10, KC_NO, \
			KC_NO,      KC_MPRV, KC_MPLY, KC_MNXT, KC_NO, KC_NO, KC_NO, KC_PGDN, KC_UP,   KC_PGUP, KC_NO,  KC_NO, \
			KC_TRNS,    KC_VOLD, KC_MUTE, KC_VOLU, KC_NO, KC_NO, KC_NO, KC_LEFT, KC_DOWN, KC_RGHT, KC_NO,  KC_NO, \
			KC_LSFT,    KC_NO,   KC_NO,   KC_NO,   KC_NO, KC_NO, KC_NO, KC_NO,   KC_NO,   KC_NO,   KC_NO,  KC_NO, \
			KC_MS_BTN1, KC_NO,   KC_NO,   KC_NO,   KC_NO, KC_NO, KC_NO, KC_NO,   KC_NO,   KC_NO,   KC_NO,  KC_NO  \
			)
};


void encoder_update_user(uint8_t index, bool clockwise) {
    // clockwise is true when knob is turned counter-clockwise
    if (IS_LAYER_ON(_RAISE)) {
        if (clockwise) {
            tap_code(KC_BRID);
        } else {
            tap_code(KC_BRIU);
        }
    } else if (IS_LAYER_ON(_LOWER)) {
        if (clockwise) {
            tap_code(KC_AUDIO_VOL_DOWN);
        } else {
            tap_code(KC_AUDIO_VOL_UP);
        }
    } else if (IS_LAYER_ON(_DNEFF)) {
        if (clockwise) {
            tap_code(KC_MS_WH_UP);
        } else {
            tap_code(KC_MS_WH_DOWN);
        }
    } else {
        if (clockwise) {
            tap_code(KC_AUDIO_VOL_DOWN);
        } else {
            tap_code(KC_AUDIO_VOL_UP);
        }
    }
}

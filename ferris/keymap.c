#include QMK_KEYBOARD_H

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT(KC_Q, KC_W, KC_F, KC_P, KC_G, KC_J, KC_L, KC_U, KC_Y, KC_QUOT,
                 KC_A, KC_R, KC_S, KC_T, KC_D, KC_H, KC_N, KC_E, KC_I, KC_O,
                 KC_Z, KC_X, KC_X, KC_X, KC_B, KC_K, KC_M, KC_COMM, KC_DOT,
                 KC_ENT, KC_LSFT, KC_SPC, KC_BSPC, KC_S),
};

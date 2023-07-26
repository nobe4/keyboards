#include QMK_KEYBOARD_H
#include "./utils.h"

#undef TAPPING_TERM
#define TAPPING_TERM 1000

enum {
  // Layouts
  LY_CL, // Colemak
  LY_SY, // Symbols
  LY_OS, // Operating System
  LY_FN, // Function keys

  // Tap dance
  A_AT,
  S_DLR,
  R_AMP,
  O_SCL,
  CO_UD,
  DO_EX,
  SL_BL,
  QO_GR,
};

#define _MG(kc) MT(MOD_LGUI, kc) // Mod Tap GUI
#define _MC(kc) MT(MOD_LCTL, kc) // Mod Tap Control
#define _MS(kc) MT(MOD_LSFT, kc) // Mod Tap Shift

// clang-format off
tap_dance_action_t tap_dance_actions[] = {
  TD_DEF(A_AT, KC_A,    KC_AT)
  TD_DEF(S_DLR, KC_S,    KC_DLR)
  TD_DEF(O_SCL, KC_O,    KC_SCLN)
  TD_DEF(CO_UD, KC_COMM, KC_UNDS)
  TD_DEF(DO_EX, KC_DOT,  KC_EXLM)
  TD_DEF(SL_BL, KC_SLSH, KC_BSLS)
  TD_DEF(QO_GR, KC_QUOT, KC_GRV)
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [LY_CL] = LAYOUT_planck_grid(
    KC_Q,     KC_W,    KC_F,      KC_P,       KC_G,        _______, /**/ _______, KC_J,         KC_L,      KC_U,      KC_Y,      TD(QO_GR),
    TD(A_AT), KC_R,    TD(S_DLR), _MG(KC_T),  KC_D,        _______, /**/ _______, KC_H,         _MG(KC_N), KC_E,      KC_I,      TD(O_SCL),
    KC_Z,     KC_X,    KC_C,      KC_V,       _MG(KC_B),   _______, /**/ _______, KC_K,         KC_M,      TD(CO_UD), TD(DO_EX), TD(SL_BL),
    _______,  _______, _______,   OSL(LY_SY), _MS(KC_SPC), _______, /**/ _______, _MC(KC_BSPC), KC_ENT,    _______,   _______,   _______
  ),
  [LY_SY] = LAYOUT_planck_grid(
    KC_1,     KC_2,    KC_3,      KC_4,       KC_5,        _______, /**/ _______, KC_6,         KC_7,      KC_8,      KC_9,      KC_0,
    KC_ESC,   KC_AMPR, KC_ASTR,   _MG(KC_AT), XXXXXXX,     _______, /**/ _______, KC_MINS,      KC_PLUS,   KC_EQL,    KC_LPRN,   KC_RPRN,
    KC_TAB,   KC_PERC, KC_DLR,    KC_HASH,    XXXXXXX,     _______, /**/ _______, KC_CIRC,      KC_LCBR,   KC_RCBR,   KC_LBRC,   KC_RBRC,
    _______,  _______, _______,   TO(LY_OS),  KC_LSFT,     _______, /**/ _______, KC_DEL,       TO(LY_CL), _______,   _______,   _______
  ),
  [LY_OS] = LAYOUT_planck_grid(
    _______,  _______, _______,   _______,    _______,     _______, /**/ _______, _______,      _______,   _______,   _______,   _______,
    _______,  KC_MUTE, KC_VOLD,   KC_VOLU,    _______,     _______, /**/ _______, KC_LEFT,      KC_DOWN,   KC_UP,     KC_RGHT,   _______,
    _______,  KC_MRWD, KC_MPLY,   KC_MFFD,    _______,     _______, /**/ _______, KC_HOME,      KC_PGDN,   KC_PGUP,   KC_END,    _______,
    _______,  _______, _______,   TO(LY_FN),  _______,     _______, /**/ _______, KC_PWR,       TO(LY_CL), _______,   _______,   _______
  ),
  [LY_FN] = LAYOUT_planck_grid(
    KC_F1,    KC_F2,   KC_F3,     KC_F4,      KC_F5,       _______, /**/ _______, _______,      _______,   _______,   _______,   _______,
    KC_F6,    KC_F7,   KC_F8,     KC_F9,      KC_F10,      _______, /**/ _______, _______,      _______,   _______,   _______,   _______,
    KC_F11,   KC_F12,  _______,   _______,    _______,     _______, /**/ _______, _______,      _______,   _______,   _______,   _______,
    _______,  _______, _______,   _______,    _______,     _______, /**/ _______, _______,      TO(LY_CL), _______,   _______,   _______
  ),
};
// clang-format on

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  tap_dance_action_t *action;

  switch (keycode) {

  case TD(A_AT):
  case TD(S_DLR):
  case TD(O_SCL):
  case TD(CO_UD):
  case TD(DO_EX):
  case TD(SL_BL):
  case TD(QO_GR):
    TAP_DANCE_UPDATE
  }

  return true;
}

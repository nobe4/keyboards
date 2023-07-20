#include QMK_KEYBOARD_H
#include "./utils.h"

enum {
  // Layouts
  LY_CL, // Colemak
  LY_QW, // Qwerty for gaming
  LY_SY, // Symbols
  LY_AR, // Arrows
  LY_OS, // Operating System

  // Tap dance
  A_TAB,
  O_SCL,
  CO_UD,
  DO_EX,
  SL_BL,
  QO_GR,
};

#define _SY(kc) LT(LY_SY, kc)    // Layout switch to Symbols
#define _OS(kc) LT(LY_OS, kc)    // Layout switch to OS
#define _MG(kc) MT(MOD_LGUI, kc) // Mod Tap GUI
#define _MC(kc) MT(MOD_LCTL, kc) // Mod Tap Control
#define _MS(kc) MT(MOD_LSFT, kc) // Mod Tap Shift
#define _MA(kc) MT(MOD_LALT, kc) // Mod Tap Alt

// clang-format off
tap_dance_action_t tap_dance_actions[] = {
  TD_DEF(A_TAB, KC_A, KC_TAB)
  TD_DEF(O_SCL, KC_O, KC_SCLN)
  TD_DEF(CO_UD, KC_COMM, KC_UNDS)
  TD_DEF(DO_EX, KC_DOT, KC_EXLM)
  TD_DEF(SL_BL, KC_SLSH, KC_BSLS)
  TD_DEF(QO_GR, KC_QUOT, KC_GRV)
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [LY_CL] = LAYOUT_planck_grid(
    KC_Q,      KC_W,      KC_F,      KC_P,        KC_G,        _______, /**/ _______, KC_J,    KC_L,        KC_U,      KC_Y,      TD(QO_GR),
    TD(A_TAB), _MA(KC_R), _MC(KC_S), _MG(KC_T),   KC_D,        _______, /**/ _______, KC_H,    _MG(KC_N),   _MC(KC_E), _MA(KC_I), TD(O_SCL),
    KC_Z,      KC_X,      KC_C,      KC_V,        _MG(KC_B),   _______, /**/ _______, KC_K,    KC_M,        TD(CO_UD), TD(DO_EX), TD(SL_BL),
    _______,   _______,   _______,   _SY(KC_ESC), _MS(KC_SPC), _______, /**/ _______, KC_BSPC, _OS(KC_ENT), _______,   _______,   _______
  ),
  // keep QWERTY for gaming
  [LY_QW] = LAYOUT_planck_grid(
    KC_Q,      KC_W,      KC_E,      KC_R,        KC_T,        _______, /**/ _______, KC_Y,    KC_U,        KC_I,      KC_O,      KC_P,
    TD(A_TAB), _MA(KC_S), _MC(KC_D), _MG(KC_F),   KC_G,        _______, /**/ _______, KC_H,    _MG(KC_J),   _MC(KC_K), _MA(KC_L), TD(O_SCL),
    KC_Z,      KC_X,      KC_C,      KC_V,        _MG(KC_B),   _______, /**/ _______, KC_N,    KC_M,        KC_COMM,   KC_DOT,    DF(LY_CL),
    _______,   _______,   _______,   _SY(KC_ESC), _MS(KC_SPC), _______, /**/ _______, KC_BSPC, _OS(KC_ENT), _______,   _______,   _______
  ),
  // just the arrows
  [LY_AR] = LAYOUT_planck_grid(
    DF(LY_CL), _______,   _______,   _______,     _______,     _______, /**/ _______, _______, _______,     _______,   _______,   _______,
    _______,   _______,   _______,   _______,     _______,     _______, /**/ _______, KC_LEFT, KC_DOWN,     KC_UP,     KC_RGHT,   _______,
    _______,   _______,   _______,   _______,     _______,     _______, /**/ _______, _______, _______,     _______,   _______,   _______,
    _______,   _______,   _______,   _______,     _______,     _______, /**/ _______, _______, _______,     _______,   _______,   _______
  ),
  [LY_SY] = LAYOUT_planck_grid(
    KC_1,      KC_2,      KC_3,      KC_4,        KC_5,        _______, /**/ _______, KC_6,    KC_7,        KC_8,      KC_9,      KC_0,
    KC_AT,     KC_AMPR,   KC_ASTR,   XXXXXXX,     XXXXXXX,     _______, /**/ _______, KC_MINS, KC_PLUS,     KC_EQL,    KC_LPRN,   KC_RPRN,
    XXXXXXX,   KC_PERC,   KC_DLR,    KC_HASH,     XXXXXXX,     _______, /**/ _______, KC_CIRC, KC_LCBR,     KC_RCBR,   KC_LBRC,   KC_RBRC,
    _______,   _______,   _______,   _______,     DF(LY_AR),   _______, /**/ _______, KC_DEL,  DF(LY_QW),   _______,   _______,   _______
  ),
  [LY_OS] = LAYOUT_planck_grid(
    KC_F1,     KC_F2,     KC_F3,     KC_F4,       KC_F5,       KC_F6,   /**/ KC_F7,   KC_F8,   KC_F9,       KC_F10,    KC_F11,    KC_F12,
    _______,   KC_MUTE,   KC_VOLD,   KC_VOLU,     _______,     _______, /**/ _______, KC_LEFT, KC_DOWN,     KC_UP,     KC_RGHT,   _______,
    _______,   KC_MRWD,   KC_MPLY,   KC_MFFD,     _______,     _______, /**/ _______, KC_HOME, KC_PGDN,     KC_PGUP,   KC_END,    _______,
    _______,   _______,   _______,   _______,     _______,     _______, /**/ _______, KC_PWR,  _______,     _______,   _______,   _______
  ),
};
// clang-format on

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  tap_dance_action_t *action;

  switch (keycode) {

  case TD(A_TAB):
  case TD(O_SCL):
  case TD(CO_UD):
  case TD(DO_EX):
  case TD(SL_BL):
  case TD(QO_GR):
    TAP_DANCE_UPDATE
  }

  return true;
}

#include QMK_KEYBOARD_H
#include "./utils.h"

#define ___ KC_NO

enum layouts {
  LY_CL, // Colemak
  LY_SY, // Symbols
  LY_OS, // Operating System
  LY_FN, // Function keys
};

enum tap_dance {
  START, // keep first

  P_PRC,
  QO_GR,

  A_AT,
  S_DLR,
  R_AMP,
  O_SCL,

  CO_UD,
  DO_EX,
  SL_BL,

  END, // keep last
};

#define _MG(kc) MT(MOD_LGUI, kc) // Mod Tap GUI
#define _MC(kc) MT(MOD_LCTL, kc) // Mod Tap Control
#define _MS(kc) MT(MOD_LSFT, kc) // Mod Tap Shift

// clang-format off
tap_dance_action_t tap_dance_actions[] = {
  TD_DEF(P_PRC, KC_P,    KC_PERC)
  TD_DEF(QO_GR, KC_QUOT, KC_GRV)

  TD_DEF(A_AT,  KC_A,    KC_AT)
  TD_DEF(S_DLR, KC_S,    KC_DLR)
  TD_DEF(R_AMP, KC_R,    KC_AMPR)
  TD_DEF(O_SCL, KC_O,    KC_SCLN)

  TD_DEF(CO_UD, KC_COMM, KC_UNDS)
  TD_DEF(DO_EX, KC_DOT,  KC_EXLM)
  TD_DEF(SL_BL, KC_SLSH, KC_BSLS)
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [LY_CL] = LAYOUT_planck_grid(
    KC_Q,     KC_W,      KC_F,      TD(P_PRC),  KC_G,        ___, /**/ ___, KC_J,         KC_L,      KC_U,      KC_Y,      TD(QO_GR),
    TD(A_AT), TD(R_AMP), TD(S_DLR), _MG(KC_T),  KC_D,        ___, /**/ ___, KC_H,         KC_N,      KC_E,      KC_I,      TD(O_SCL),
    KC_Z,     KC_X,      KC_C,      KC_V,       _MG(KC_B),   ___, /**/ ___, KC_K,         KC_M,      TD(CO_UD), TD(DO_EX), TD(SL_BL),
    ___,      ___,       ___,       OSL(LY_SY), _MS(KC_SPC), ___, /**/ ___, _MC(KC_BSPC), KC_ENT,    ___,       ___,       ___
  ),
  [LY_SY] = LAYOUT_planck_grid(
    KC_1,     KC_2,      KC_3,      KC_4,       KC_5,        ___, /**/ ___, KC_6,         KC_7,      KC_8,      KC_9,      KC_0,
    KC_ESC,   ___,       KC_ASTR,   ___,        ___,         ___, /**/ ___, KC_MINS,      KC_PLUS,   KC_EQL,    KC_LPRN,   KC_RPRN,
    KC_TAB,   ___,       ___,       KC_HASH,    ___,         ___, /**/ ___, KC_CIRC,      KC_LCBR,   KC_RCBR,   KC_LBRC,   KC_RBRC,
    ___,      ___,       ___,       TO(LY_OS),  KC_LSFT,     ___, /**/ ___, KC_DEL,       TO(LY_CL), ___,       ___,       ___
  ),
  [LY_OS] = LAYOUT_planck_grid(
    ___,      ___,       ___,       ___,        ___,         ___, /**/ ___, ___,          ___,       ___,       ___,       ___,
    ___,      KC_MUTE,   KC_VOLD,   KC_VOLU,    ___,         ___, /**/ ___, KC_LEFT,      KC_DOWN,   KC_UP,     KC_RGHT,   ___,
    ___,      KC_MRWD,   KC_MPLY,   KC_MFFD,    ___,         ___, /**/ ___, KC_HOME,      KC_PGDN,   KC_PGUP,   KC_END,    ___,
    ___,      ___,       ___,       TO(LY_FN),  ___,         ___, /**/ ___, KC_LCTL,      TO(LY_CL), ___,       ___,       ___
  ),
  [LY_FN] = LAYOUT_planck_grid(
    KC_F1,    KC_F2,     KC_F3,     KC_F4,      KC_F5,       ___, /**/ ___, ___,          ___,       ___,       ___,       ___,
    KC_F6,    KC_F7,     KC_F8,     KC_F9,      KC_F10,      ___, /**/ ___, ___,          ___,       ___,       ___,       ___,
    KC_F11,   KC_F12,    ___,       ___,        ___,         ___, /**/ ___, ___,          ___,       ___,       ___,       ___,
    ___,      ___,       ___,       ___,        ___,         ___, /**/ ___, ___,          TO(LY_CL), ___,       ___,       ___
  ),
};
// clang-format on

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  tap_dance_action_t *action;

  if (TD(START) <= keycode && keycode <= TD(END)) {
    TAP_DANCE_UPDATE
  }

  return true;
}

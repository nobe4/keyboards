#include QMK_KEYBOARD_H
#include "./utils.h"

#define ___ KC_NO

enum layouts {
  LY_CL, // Colemak
  LY_SY, // Symbols
  LY_OS, // Operating System
};

enum tap_dance {
  START, // keep first

  Q_HASH,
  Y_DLR,
  QO_GR,

  K_AMP,

  Z_AST,
  V_CIR,
  X_PRC,
  C_AT,
  M_UND,
  CO_QES,
  DO_EX,

  END, // keep last
};

#define B_GUI MT(MOD_LGUI, KC_B)
#define BSP_CTL MT(MOD_LCTL, KC_BSPC)

// clang-format off
tap_dance_action_t tap_dance_actions[] = {
  TD_DEF(Q_HASH, KC_Q,    KC_HASH)
  TD_DEF(Y_DLR,  KC_Y,    KC_DLR)
  TD_DEF(QO_GR,  KC_QUOT, KC_GRV)
  TD_DEF(X_PRC,  KC_X,    KC_PERC)
  TD_DEF(C_AT,   KC_C,    KC_AT)
  TD_DEF(Z_AST,  KC_Z,    KC_ASTR)
  TD_DEF(K_AMP,  KC_K,    KC_AMPR)
  TD_DEF(V_CIR,  KC_V,    KC_CIRC)
  TD_DEF(M_UND,  KC_M,    KC_UNDS)
  TD_DEF(CO_QES, KC_COMM, KC_QUES)
  TD_DEF(DO_EX,  KC_DOT,  KC_EXLM)
};

// Key Overrides
const key_override_t **key_overrides = (const key_override_t *[]){
    KO_SHIFT(BSP_CTL,    KC_DEL)
    KO_SHIFT(TD(CO_QES), KC_SCLN)
    KO_SHIFT(TD(DO_EX),  KC_COLN)
    NULL
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [LY_CL] = LAYOUT_planck_grid(
    TD(Q_HASH), KC_W,      KC_F,     KC_P,      KC_G,    ___, /**/ ___, KC_J,      KC_L,       KC_U,       TD(Y_DLR), TD(QO_GR),
    KC_A,       KC_R,      KC_S,     KC_T,      KC_D,    ___, /**/ ___, KC_H,      KC_N,       KC_E,       KC_I,      KC_O,
    TD(Z_AST),  TD(X_PRC), TD(C_AT), TD(V_CIR), B_GUI,   ___, /**/ ___, TD(K_AMP), TD(M_UND),  TD(CO_QES), TD(DO_EX), KC_ENT,
    ___,        ___,       ___,      KC_LSFT,   KC_SPC,  ___, /**/ ___, BSP_CTL,   OSL(LY_SY), ___,        ___,       ___
  ),
  [LY_SY] = LAYOUT_planck_grid(
    KC_0,       KC_1,      KC_2,     KC_3,      KC_PLUS, ___, /**/ ___, KC_LPRN,   KC_RPRN,    KC_LBRC,    KC_RBRC,   KC_PIPE,
    KC_ESC,     KC_4,      KC_5,     KC_6,      KC_EQL,  ___, /**/ ___, KC_LEFT,   KC_DOWN,    KC_UP,      KC_RGHT,   KC_BSLS,
    KC_TAB,     KC_7,      KC_8,     KC_9,      KC_MINS, ___, /**/ ___, KC_LCBR,   KC_RCBR,    KC_LT,      KC_GT,     KC_SLSH,
    ___,        ___,       ___,      TO(LY_CL), KC_RCMD, ___, /**/ ___, KC_RCTL,   TO(LY_OS),  ___,        ___,       ___
  ),
  [LY_OS] = LAYOUT_planck_grid(
    KC_F1,      KC_F2,     KC_F3,    KC_F4,     KC_F5,   ___, /**/ ___, KC_VOLU,   ___,        ___,        ___,       ___,
    KC_F6,      KC_F7,     KC_F8,    KC_F9,     KC_F10,  ___, /**/ ___, KC_MUTE,   KC_MPLY,    ___,        ___,       ___,
    KC_F11,     KC_F12,    KC_F13,   KC_F14,    KC_F15,  ___, /**/ ___, KC_VOLD,   ___,        ___,        ___,       ___,
    ___,        ___,       ___,      TO(LY_CL), ___,     ___, /**/ ___, ___,       ___,        ___,        ___,       ___
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

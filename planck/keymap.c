#include "../common/utils.h"

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [LY_CL] = LAYOUT(
    TD(Q_HASH), KC_W,      KC_F,     KC_P,      KC_G,    ___, /**/ ___, KC_J,      KC_L,       KC_U,       TD(Y_DLR), TD(QO_GR),
    KC_A,       KC_R,      KC_S,     KC_T,      KC_D,    ___, /**/ ___, KC_H,      KC_N,       KC_E,       KC_I,      KC_O,
    TD(Z_AST),  TD(X_PRC), TD(C_AT), TD(V_CIR), B_GUI,   ___, /**/ ___, TD(K_AMP), TD(M_UND),  TD(CO_QES), TD(DO_EX), KC_ENT,
    ___,        ___,       ___,      KC_LSFT,   KC_SPC,  ___, /**/ ___, BSP_CTL,   OSL(LY_SY), ___,        ___,       ___
  ),
  [LY_SY] = LAYOUT(
    KC_0,       KC_1,      KC_2,     KC_3,      KC_PLUS, ___, /**/ ___, KC_LPRN,   KC_RPRN,    KC_LBRC,    KC_RBRC,   KC_PIPE,
    KC_ESC,     KC_4,      KC_5,     KC_6,      KC_EQL,  ___, /**/ ___, KC_LEFT,   KC_DOWN,    KC_UP,      KC_RGHT,   KC_BSLS,
    KC_TAB,     KC_7,      KC_8,     KC_9,      KC_MINS, ___, /**/ ___, KC_LCBR,   KC_RCBR,    KC_LT,      KC_GT,     KC_SLSH,
    ___,        ___,       ___,      TO(LY_CL), KC_RCMD, ___, /**/ ___, KC_RCTL,   OSL(LY_OS),  ___,        ___,       ___
  ),
  [LY_OS] = LAYOUT(
    KC_F1,      KC_F2,     KC_F3,    KC_F4,     KC_F5,   ___, /**/ ___, KC_VOLU,   ___,        ___,        ___,       TO(LY_AS),
    KC_F6,      KC_F7,     KC_F8,    KC_F9,     KC_F10,  ___, /**/ ___, KC_MUTE,   KC_MPLY,    ___,        ___,       ___,
    KC_F11,     KC_F12,    KC_F13,   KC_F14,    KC_F15,  ___, /**/ ___, KC_VOLD,   ___,        ___,        ___,       ___,
    ___,        ___,       ___,      TO(LY_CL), ___,     ___, /**/ ___, ___,       ___,        ___,        ___,       ___
  ),
  [LY_AS] = LAYOUT(
    ___,  KC_W, ___,  ___,       ___, ___, /**/ ___, ___, ___, ___, ___, ___,
    KC_A, KC_S, KC_D, ___,       ___, ___, /**/ ___, ___, ___, ___, ___, ___,
    ___,  ___,  ___,  ___,       ___, ___, /**/ ___, ___, ___, ___, ___, ___,
    ___,  ___,  ___,  TO(LY_CL), ___, ___, /**/ ___, ___, ___, ___, ___, ___
  ),
};
// clang-format on

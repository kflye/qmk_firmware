// <name>.h file for user or keymap specific settings (such as the enum for layer or keycodes)
#pragma once
#include QMK_KEYBOARD_H
#include "version.h"

#include "wrappers.h"
#define XXX  KC_NO
#define U_NA KC_NO // Present but not available for use.
#define U_NU KC_NO // Available but not used.

bool process_record_keymap(uint16_t keycode, keyrecord_t *record);

enum layers { _BASE, _GAMING, _ALT, _QWERTY, _SYM, _NUM, _NAV,  _MEDIA, _FUN, _MOUSE  };

enum custom_keycodes {
    VRSN = SAFE_RANGE,
    U_BASE,
    U_ALT,
    U_GAMING,
     // ascii emojies
    SHRUG,
    NEW_SAFE_RANGE  //use "NEW_SAFE_RANGE" for keymap specific codes
};

// Tap Dance declarations
enum {
    TD_BOOT,
    TD_EECLEAR,
    TD_BASE,
    TD_ALT,
    TD_QWERTY,
    TD_GAMING,
    TD_RBT
};

enum unicode_names {
    AE_L,
    AE_U,
    OE_L,
    OE_U,
    AA_L,
    AA_U,
    IRONY,
    SNEK,
};

#define KC_AE UP(AE_L,AE_U)
#define KC_OE UP(OE_L,OE_U)
#define KC_AA UP(AA_L,AA_U)

//// Colemak

// Left-hand home row mods (row 1)
#define HOME_COL_Q LGUI_T(KC_Q)
#define HOME_COL_W LCTL_T(KC_W)
#define HOME_COL_F LALT_T(KC_F)
#define HOME_COL_P LSFT_T(KC_P)

// Left-hand home row mods (row 2)
#define HOME_COL_A LGUI_T(KC_A)
#define HOME_COL_R LCTL_T(KC_R)
#define HOME_COL_S LALT_T(KC_S)
#define HOME_COL_T LSFT_T(KC_T)

// Left-hand home row mods (row 3)
#define HOME_COL_Z LGUI_T(KC_Z)
#define HOME_COL_X LCTL_T(KC_X)
#define HOME_COL_C LALT_T(KC_C)
#define HOME_COL_D LSFT_T(KC_D)

// Right-hand home row mods (row 1)
#define HOME_COL_L RSFT_T(KC_L)
#define HOME_COL_U LALT_T(KC_U)
#define HOME_COL_Y RCTL_T(KC_Y)
#define HOME_COL_SCLN RGUI_T(KC_SCLN)

// Right-hand home row mods (row 2)
#define HOME_COL_N RSFT_T(KC_N)
#define HOME_COL_E LALT_T(KC_E)
#define HOME_COL_I RCTL_T(KC_I)
#define HOME_COL_O RGUI_T(KC_O)

// Right-hand home row mods (row 3)
#define HOME_COL_H RSFT_T(KC_H)
#define HOME_COL_COMM LALT_T(KC_COMM)
#define HOME_COL_DOT RCTL_T(KC_DOT)
#define HOME_COL_SLASH RGUI_T(KC_SLASH)

//// QWERTY

// Left-hand home row mods (row 1)
#define HOME_QWE_Q LGUI_T(KC_Q)
#define HOME_QWE_W LCTL_T(KC_W)
#define HOME_QWE_E LALT_T(KC_E)
#define HOME_QWE_R LSFT_T(KC_R)

// Left-hand home row mods (row 2)
#define HOME_QWE_A LGUI_T(KC_A)
#define HOME_QWE_S LCTL_T(KC_S)
#define HOME_QWE_D LALT_T(KC_D)
#define HOME_QWE_F LSFT_T(KC_F)

// Left-hand home row mods (row 3)
#define HOME_QWE_Z LGUI_T(KC_Z)
#define HOME_QWE_X LCTL_T(KC_X)
#define HOME_QWE_C LALT_T(KC_C)
#define HOME_QWE_V LSFT_T(KC_V)

// Right-hand home row mods (row 1)
#define HOME_QWE_U RSFT_T(KC_U)
#define HOME_QWE_I LALT_T(KC_I)
#define HOME_QWE_O RCTL_T(KC_O)
#define HOME_QWE_P RGUI_T(KC_P)

// Right-hand home row mods (row 2)
#define HOME_QWE_J RSFT_T(KC_J)
#define HOME_QWE_K LALT_T(KC_K)
#define HOME_QWE_L RCTL_T(KC_L)
#define HOME_QWE_SCLN RGUI_T(KC_SCLN)

// Right-hand home row mods (row 3)
#define HOME_QWE_M RSFT_T(KC_M)
#define HOME_QWE_COMM LALT_T(KC_COMM)
#define HOME_QWE_DOT RCTL_T(KC_DOT)
#define HOME_QWE_SLASH RGUI_T(KC_SLASH)


#define U_RDO C(KC_Y)
#define U_PST C(KC_V)
#define U_CPY C(KC_C)
#define U_CUT C(KC_X)
#define U_UND C(KC_Z)

#define U_OSX_RDO LGUI(KC_Y)
#define U_OSX_PST LGUI(KC_V)
#define U_OSX_CPY LGUI(KC_C)
#define U_OSX_CUT LGUI(KC_X)
#define U_OSX_UND LGUI(KC_Z)

#define GAM_WIN LT(_FUN, KC_LGUI)

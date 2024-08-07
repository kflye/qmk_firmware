/* Copyright 2023 piit79
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
#include "kflye.h"


#define LAYOUT_rev57lp_wrapper(...) LAYOUT_ergo5x12(__VA_ARGS__)

#define LAYOUT_rev57lp_base(\
     K000, K001, K002, K003, K004, K005,                K006, K007, K008, K009, K010, K011,\
     K100, K101, K102, K103, K104, K105,                K106, K107, K108, K109, K110, K111,\
     K200, K201, K202, K203, K204, K205,                K206, K207, K208, K209, K210, K211,\
     N300, N301, N302, K303, K304, K305,                K306, K307, K308, N309, N310, K311\
) \
LAYOUT_rev57lp_wrapper(\
    KC_GRV,   ________________NUMBER_LEFT________________,                          ________________NUMBER_RIGHT_______________,      KC_DEL,\
    K000,      K001,     K002,     K003,     K004,     K005,                         K006,     K007,     K008,     K009,     K010,     K011,\
    K100,      K101,     K102,     K103,     K104,     K105,         KC_MPLY,        K106,     K107,     K108,     K109,     K110,     K111,\
    K200,      K201,     K202,     K203,     K204,     K205,                         K206,     K207,     K208,     K209,     K210,     K211,\
                                  K303,      K304,     K305,     KC_LBRC, KC_RBRC,   K306,    K307,  K308 \
)

#define LAYOUT_base_wrapper(...) LAYOUT_rev57lp_base(__VA_ARGS__)

layer_state_t layer_state_set_user(layer_state_t state) {
    state = update_tri_layer_state(state, _NAV, _SYM, _MEDIA);
    state = update_tri_layer_state(state, _NAV, _NUM, _MOUSE);
    return state;
}

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_BASE] = LAYOUT_base_wrapper(
        _________________COLEMAK_L1_________________, _________________COLEMAK_R1_________________,
        _________________COLEMAK_L2_________________, _________________COLEMAK_R2_________________,
        _________________COLEMAK_L3_________________, _________________COLEMAK_R3_________________,
        _________________THUMB_LEFT________________,  _________________THUMB_RIGHT_______________
    ),
    [_GAMING] = LAYOUT_base_wrapper(
        _________________GAMING_L1__________________, _________________GAMING_R1__________________,
        _________________GAMING_L2__________________, _________________GAMING_R2__________________,
        _________________GAMING_L3__________________, _________________GAMING_R3__________________,
        _________________GAMING_L4__________________, _________________GAMING_R4__________________
    ),
    [_ALT] = LAYOUT_base_wrapper(
        _________________QWERTY_L1__________________, _________________QWERTY_R1__________________,
        _________________QWERTY_L2__________________, _________________QWERTY_R2__________________,
        _________________QWERTY_L3__________________, _________________QWERTY_R3__________________,
        _________________THUMB_LEFT________________,  _________________THUMB_RIGHT_______________
    ),
    [_SYM] = LAYOUT_base_wrapper(
        ___________________SYM_L1___________________, ___________________SYM_R1___________________,
        ___________________SYM_L2___________________, ___________________SYM_R2___________________,
        ___________________SYM_L3___________________, ___________________SYM_R3___________________,
        ___________________SYM_L4___________________, ___________________SYM_R4___________________
    ),
    [_NUM] = LAYOUT_base_wrapper(
        ___________________NUM_L1___________________, ___________________NUM_R1___________________,
        ___________________NUM_L2___________________, ___________________NUM_R2___________________,
        ___________________NUM_L3___________________, ___________________NUM_R3___________________,
        ___________________NUM_L4___________________, ___________________NUM_R4___________________
    ),
    [_NAV] = LAYOUT_base_wrapper(
        ___________________NAV_L1___________________, ___________________NAV_R1___________________,
        ___________________NAV_L2___________________, ___________________NAV_R2___________________,
        ___________________NAV_L3___________________, ___________________NAV_R3___________________,
        ___________________NAV_L4___________________, ___________________NAV_R4___________________
    ),
    [_MEDIA] = LAYOUT_base_wrapper(
        __________________MEDIA_L1__________________, __________________MEDIA_R1__________________,
        __________________MEDIA_L2__________________, __________________MEDIA_R2__________________,
        __________________MEDIA_L3__________________, __________________MEDIA_R3__________________,
        __________________MEDIA_L4__________________, __________________MEDIA_R4__________________
    ),
    [_FUN] = LAYOUT_base_wrapper(
        ___________________FUN_L1___________________, ___________________FUN_R1___________________,
        ___________________FUN_L2___________________, ___________________FUN_R2___________________,
        ___________________FUN_L3___________________, ___________________FUN_R3___________________,
        ___________________FUN_L4___________________, ___________________FUN_R4___________________
    ),
    [_MOUSE] = LAYOUT_base_wrapper(
        __________________MOUSE_L1__________________, __________________MOUSE_R1__________________,
        __________________MOUSE_L2__________________, __________________MOUSE_R2__________________,
        __________________MOUSE_L3__________________, __________________MOUSE_R3__________________,
        __________________MOUSE_L4__________________, __________________MOUSE_R4__________________
    ),
};

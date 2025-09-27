#include "kflye.h"
#include "print.h"


#define LAYOUT_dactyl_wrapper(...) LAYOUT_5x6_5(__VA_ARGS__)

/*
const uint8_t PROGMEM digital_pin_to_bit_mask_PGM[] = {
	_BV(2), // D0 - PD2
	_BV(3),	// D1 - PD3
	_BV(1), // D2 - PD1
	_BV(0),	// D3 - PD0
	_BV(4),	// D4 - PD4
	_BV(6), // D5 - PC6
	_BV(7), // D6 - PD7
	_BV(6), // D7 - PE6

	_BV(4), // D8 - PB4
	_BV(5),	// D9 - PB5
	_BV(6), // D10 - PB6
	_BV(7),	// D11 - PB7
	_BV(6), // D12 - PD6
	_BV(7), // D13 - PC7

	_BV(3),	// D14 - MISO - PB3
	_BV(1),	// D15 - SCK - PB1
	_BV(2),	// D16 - MOSI - PB2
	_BV(0),	// D17 - SS - PB0

	_BV(7),	// D18 - A0 - PF7
	_BV(6), // D19 - A1 - PF6
	_BV(5), // D20 - A2 - PF5
	_BV(4), // D21 - A3 - PF4
	_BV(1), // D22 - A4 - PF1
	_BV(0), // D23 - A5 - PF0

	_BV(4), // D24 / D4 - A6 - PD4
	_BV(7), // D25 / D6 - A7 - PD7
	_BV(4), // D26 / D8 - A8 - PB4
	_BV(5), // D27 / D9 - A9 - PB5
	_BV(6), // D28 / D10 - A10 - PB6
	_BV(6), // D29 / D12 - A11 - PD6
	_BV(5), // D30 / TX Led - PD5
};
*/
#define LAYOUT_dactyl_base( \
     K000, K001, K002, K003, K004, K005,                K006, K007, K008, K009, K010, K011,\
     K100, K101, K102, K103, K104, K105,                K106, K107, K108, K109, K110, K111,\
     K200, K201, K202, K203, K204, K205,                K206, K207, K208, K209, K210, K211,\
     N300, N301, N302, K303, K304, K305,                K306, K307, K308, N309, N310, K311\
    ) \
    LAYOUT_dactyl_wrapper( \
        KC_ESC,  ________________NUMBER_LEFT_________________,                   ________________NUMBER_RIGHT________________,      XXX,\
        K000,    K001,     K002,     K003,     K004,     K005,                   K006,     K007,     K008,     K009,     K010,     K011,\
        K100,    K101,     K102,     K103,     K104,     K105,                   K106,     K107,     K108,     K109,     K110,     K111,\
        K200,    K201,     K202,     K203,     K204,     K205,                   K206,     K207,     K208,     K209,     K210,     K211,\
            XXX,     XXX,                        K304,  K305,  K303,       K308,  K306,  K307,                XXX,    XXX, \
                                                   KC_LBRC,  KC_RBRC,     KC_LBRC,  KC_RBRC\
    )

#define LAYOUT_base_wrapper(...) LAYOUT_dactyl_base(__VA_ARGS__)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_BASE] = LAYOUT_base_wrapper(
        _________________COLEMAK_L1_________________, _________________COLEMAK_R1_________________,
        _________________COLEMAK_L2_________________, _________________COLEMAK_R2_________________,
        _________________COLEMAK_L3_________________, _________________COLEMAK_R3_________________,
        _________________THUMB_LEFT_________________, _________________THUMB_RIGHT________________
    ),
    [_QWERTY] = LAYOUT_base_wrapper(
        _________________QWERTY_L1__________________, _________________QWERTY_R1__________________,
        _________________QWERTY_L2__________________, _________________QWERTY_R2__________________,
        _________________QWERTY_L3__________________, _________________QWERTY_R3__________________,
        _________________THUMB_LEFT_________________, _________________THUMB_RIGHT________________
    ),
    [_ALT] = LAYOUT_base_wrapper(
        _________________GALLIUM_COL_L1_____________, _________________GALLIUM_COL_R1_____________,
        _________________GALLIUM_COL_L2_____________, _________________GALLIUM_COL_R2_____________,
        _________________GALLIUM_COL_L3_____________, _________________GALLIUM_COL_R3_____________,
        _________________THUMB_LEFT_________________, _________________THUMB_RIGHT________________
    ),
    // [_GAMING] = LAYOUT_base_wrapper(
    //     ______________GAMING_QWERTY_L1______________, ______________GAMING_QWERTY_R1______________,
    //     ______________GAMING_QWERTY_L2______________, ______________GAMING_QWERTY_R2______________,
    //     ______________GAMING_QWERTY_L3______________, ______________GAMING_QWERTY_R3______________,
    //     ______________GAMING_QWERTY_L4______________, ______________GAMING_QWERTY_R4______________
    // ),
    [_GAMING] = LAYOUT_base_wrapper(
        _________________GAMING_L1__________________, _________________GAMING_R1__________________,
        _________________GAMING_L2__________________, _________________GAMING_R2__________________,
        _________________GAMING_L3__________________, _________________GAMING_R3__________________,
        _________________GAMING_L4__________________, _________________GAMING_R4__________________
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
    // [_NAV] = LAYOUT_base_wrapper(
    //     ___________________NAV_L1___________________, ___________________NAV_R1___________________,
    //     ___________________NAV_L2___________________, ___________________NAV_VI_R2________________,
    //     ___________________NAV_L3___________________, ___________________NAV_VI_R3________________,
    //     ___________________NAV_L4___________________, ___________________NAV_R4___________________
    // ),
    [_NAV] = LAYOUT_base_wrapper(
        ___________________NAV_L1___________________, ___________________NAV_R1___________________,
        ___________________NAV_L2___________________, ___________________NAV_R2___________________,
        ___________________NAV_L3___________________, ___________________NAV_R3___________________,
        ___________________NAV_L4___________________, ___________________NAV_R4___________________
    ),
    // [_MEDIA] = LAYOUT_base_wrapper(
    //     __________________MEDIA_L1__________________, __________________MEDIA_R1__________________,
    //     __________________MEDIA_L2__________________, __________________MEDIA_VI_R2_______________,
    //     __________________MEDIA_L3__________________, __________________MEDIA_R3__________________,
    //     __________________MEDIA_L4__________________, __________________MEDIA_R4__________________
    // ),
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

layer_state_t layer_state_set_user(layer_state_t state) {
    state = update_tri_layer_state(state, _NAV, _SYM, _MEDIA);
    state = update_tri_layer_state(state, _NAV, _NUM, _MOUSE);
    return state;
}

// const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
// 	[0] = LAYOUT_5x6_5(
// 		KC_GRV, KC_1, KC_2, KC_3, KC_4, KC_5,   								KC_6, KC_7, KC_8, KC_9, KC_0, KC_MINS,
// 		KC_TAB, KC_Q, KC_W, KC_E, KC_R, KC_T, 									KC_Y, KC_U, KC_I, KC_O, KC_P, KC_LBRC,
// 		LCTL_T(KC_ESC), KC_A, KC_S, KC_D, KC_F, KC_G, 							KC_H, KC_J, KC_K, KC_L, KC_SCLN, KC_QUOT,
// 		SC_LSPO, KC_Z, KC_X, KC_C, KC_V, KC_B, 									KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, SC_RSPC,

// 		KC_LGUI, KC_LALT, 			TT(2), LT(6,KC_SPC), LT(4,KC_DEL), 			LT(4,KC_ENT), KC_SPC, LT(2,KC_BSPC), 		LALT_T(KC_RALT), KC_RGUI,
// 									LCTL_T(KC_LBRC), LCTL_T(KC_LBRC), 			LT(4,KC_ENT), RCTL_T(KC_RBRC)),
// 	[1] = LAYOUT_5x6_5(KC_GRV, KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, KC_MINS, KC_TAB, KC_Q, KC_W, KC_F, KC_P, KC_G, KC_J, KC_L, KC_U, KC_Y, KC_SCLN, KC_LBRC, LCTL_T(KC_ESC), KC_A, KC_R, KC_S, KC_T, KC_D, KC_H, KC_N, KC_E, KC_I, KC_O, KC_QUOT, SC_LSPO, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_K, KC_M, KC_COMM, KC_DOT, KC_SLSH, SC_RSPC, KC_LGUI, KC_LALT, TT(2), LT(6,KC_SPC), LT(4,KC_DEL), LT(4,KC_ENT), KC_SPC, LT(2,KC_BSPC), LALT_T(KC_RALT), KC_RGUI, LCTL_T(KC_LBRC), LCTL_T(KC_LBRC), LT(4,KC_ENT), RCTL_T(KC_RBRC)),
// 	[2] = LAYOUT_5x6_5(QK_BOOT, KC_PWR, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_PWR, QK_BOOT, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_7, KC_7, KC_8, KC_9, KC_TRNS, KC_RBRC, KC_TRNS, DF(0), DF(1), KC_NO, MO(3), MO(3), KC_4, KC_4, KC_5, KC_6, KC_MINS, KC_EQL, KC_TRNS, MO(5), KC_NO, KC_NO, KC_NO, KC_NO, KC_1, KC_1, KC_2, KC_3, KC_BSLS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_SPC, KC_DEL, KC_ENT, KC_0, KC_BSPC, KC_TRNS, KC_TRNS, TG(2), KC_TRNS, KC_ENT, KC_TRNS),
// 	[3] = LAYOUT_5x6_5(KC_TRNS, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, KC_F11, KC_TRNS, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_F7, KC_F7, KC_F8, KC_F9, KC_F10, KC_NO, KC_TRNS, KC_NO, KC_NO, KC_NO, MO(3), MO(3), KC_F4, KC_F4, KC_F5, KC_F6, KC_F11, KC_NO, KC_TRNS, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_F1, KC_F1, KC_F2, KC_F3, KC_F12, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_SPC, KC_DEL, KC_ENT, KC_SPC, KC_BSPC, KC_TRNS, KC_TRNS, TG(3), KC_TRNS, KC_ENT, KC_TRNS),
// 	[4] = LAYOUT_5x6_5(KC_ESC, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_ESC, KC_ESC, LCTL(KC_W), LCTL(KC_T), LCTL(KC_PGDN), LCTL(KC_PGDN), KC_PGDN, KC_HOME, KC_UP, KC_INS, LSFT(KC_INS), KC_ESC, KC_TRNS, KC_CAPS, LGUI(KC_LEFT), LGUI(KC_TAB), LGUI(KC_RGHT), LGUI(KC_RGHT), KC_LEFT, KC_LEFT, KC_DOWN, KC_RGHT, KC_END, KC_PSCR, KC_TRNS, KC_NO, KC_NO, KC_NO, LCTL(KC_PGUP), LCTL(KC_PGUP), KC_PGUP, KC_TRNS, KC_DOWN, KC_NO, KC_APP, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_SPC, KC_DEL, KC_ENT, KC_SPC, KC_BSPC, KC_TRNS, KC_TRNS, TG(4), KC_TRNS, KC_ENT, KC_TRNS),
// 	[5] = LAYOUT_5x6_5(KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_TRNS, KC_NO, KC_MPLY, KC_VOLU, KC_VOLU, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, QK_BOOT, KC_PWR, KC_TRNS, KC_NO, KC_MPRV, KC_MUTE, KC_MNXT, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_SLEP, KC_TRNS, MO(5), KC_NO, KC_VOLD, KC_VOLD, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_TRNS, KC_TRNS, KC_TRNS, KC_SPC, KC_DEL, KC_ENT, KC_SPC, KC_BSPC, KC_TRNS, KC_TRNS, TG(5), TG(5), KC_ENT, KC_TRNS),
// 	[6] = LAYOUT_5x6_5(KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_TRNS, KC_ACL1, KC_NO, KC_NO, KC_NO, KC_NO, KC_WH_U, KC_WH_L, KC_MS_U, KC_WH_R, KC_NO, KC_NO, KC_TRNS, KC_ACL2, KC_BTN2, KC_BTN3, KC_BTN1, KC_BTN1, KC_MS_L, KC_MS_L, KC_MS_D, KC_MS_R, KC_NO, KC_NO, KC_TRNS, KC_ACL0, KC_NO, KC_NO, KC_NO, KC_NO, KC_WH_D, KC_NO, KC_MS_D, KC_NO, KC_NO, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_SPC, KC_DEL, KC_ENT, KC_SPC, KC_BSPC, KC_TRNS, KC_TRNS, TG(6), KC_TRNS, KC_ENT, KC_TRNS)
// };

#if defined(ENCODER_ENABLE) && defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {

};
#endif // defined(ENCODER_ENABLE) && defined(ENCODER_MAP_ENABLE)






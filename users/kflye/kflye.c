#include <stdio.h>
#include "kflye.h"
#include "print.h"


user_config_t user_config;

const uint32_t unicode_map[] PROGMEM = {
    [AE_L]  = 0x00E6,  // æ
    [AE_U]  = 0x00C6,  // Æ
    [OE_L]  = 0x00F8,  // ø
    [OE_U]  = 0x00D8,  // Ø
    [AA_L]  = 0x00E5,  // å
    [AA_U]  = 0x00C5,  // Å
    [SNEK]  = 0x1F40D, // 🐍
};


void keyboard_post_init_user(void) {
   debug_enable=true;
   debug_matrix=true;
   debug_keyboard=true;

   // Read the user config from EEPROM to facilitate
    // appropriate platform support

//    user_config.raw = 0; // reset
//    eeconfig_update_user(user_config.raw); // write the setings to EEPROM
    /*
    user_config.OSIndex use 0 for Mac; 1 for Win
     */
    user_config.raw = eeconfig_read_user();
    eeconfig_read_default_layer(); // get the default layer from eeprom.
}

__attribute__ ((weak))
bool process_record_keymap(uint16_t keycode, keyrecord_t *record) {
  return true;
}


__attribute__((weak)) void matrix_scan_keymap(void) {}

void fn_boot(tap_dance_state_t *state, void *user_data) {
  if (state->count == 2) {
    reset_keyboard();
  }
}

void fn_reboot(tap_dance_state_t *state, void *user_data) {
  if (state->count == 2) {
    soft_reset_keyboard();
  }
}

void fn_eeclear(tap_dance_state_t *state, void *user_data) {
  if (state->count == 4) {
    eeconfig_init();
  }
}

void fn_base(tap_dance_state_t *state, void *user_data){
    if (state ->count == 2){
        default_layer_set((layer_state_t)1 << _BASE);
    }
}

void fn_alt(tap_dance_state_t *state, void *user_data){
    if (state ->count == 2){
        default_layer_set((layer_state_t)1 << _ALT);
    }
}

void fn_qwerty(tap_dance_state_t *state, void *user_data){
    if (state ->count == 2){
        default_layer_set((layer_state_t)1 << _QWERTY);
    }
}

void fn_gaming(tap_dance_state_t *state, void *user_data){
    if (state ->count == 2){
        default_layer_set((layer_state_t)1 << _GAMING);
    }
}

// Tap Dance definitions
tap_dance_action_t tap_dance_actions[] = {
    [TD_BOOT] = ACTION_TAP_DANCE_FN(fn_boot),
    [TD_BASE] = ACTION_TAP_DANCE_FN(fn_base),
    [TD_ALT] = ACTION_TAP_DANCE_FN(fn_alt),
    [TD_QWERTY] = ACTION_TAP_DANCE_FN(fn_qwerty),
    [TD_GAMING] = ACTION_TAP_DANCE_FN(fn_gaming),
    [TD_EECLEAR] = ACTION_TAP_DANCE_FN(fn_eeclear),
    [TD_RBT] = ACTION_TAP_DANCE_FN(fn_reboot),
};

#ifdef TAPPING_TERM_PER_KEY
uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {

        // colemak - shift
        case HOME_COL_P:
        case HOME_COL_L:
          return TAPPING_TERM - 80;

        // colemak - wln
        case HOME_COL_Q:
        case HOME_COL_SCLN:
          return TAPPING_TERM + 180;

        default:
          return TAPPING_TERM;
    }
}
#endif

#include "semantickeys.c"

#include "kflye_process_record.c"
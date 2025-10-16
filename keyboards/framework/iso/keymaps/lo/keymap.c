// Copyright 2022 Framework Computer
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H
#include "framework.h"
#include "sendstring_german.h"
#include "private.h"

enum _layers {
  _BASE,
  _FN,
  L_SYM,
  L_NAV
};

enum custom_keycodes {
    LT_LEADER = SAFE_RANGE,
    LT_HAT,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/*
 * BASE (tap / hold annotations shown below each key where relevant)
 *
 *         ┌─────┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬────┐
 * 14 keys │Esc  │F1 │F2 │F3 │F4 │F5 │F6 │F7 │F8 │F9 │F10│F11│F12│ Ins│
 *         ├───┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴────┤
 * 14 keys │ ` │ 1 │ 2 │ 3 │ 4 │ 5 │ 6 │ 7 │ 8 │ 9 │ 0 │ - │ = │Backsp│
 *         ├───┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬────┤
 * 13 keys │ Tab │ Q │ W │ E │ R │ T │ Y │ U │ I │ O │ P │ [ │ ] │Entr│
 *         ├─────┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┐   │
 * 14 keys │      │ A │ S │ D │ F │ G │ H │ J │ K │ L │ ; │ ' │ # │   │
 *         │ NAV  │Ctl│Gui│Alt│Sft│   │   │Sft│Alt│Gui│Ctl│   │   │   │  ← tap/hold (home-row mods)
 *         ├────┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴───┴───┤
 * 13 keys │Shft│ \ │ Z │ X │ C │ V │ B │ N │ M │ , │ . │ / │   SYM   │
 *         ├────┼───┼───┼───┼───┴───┴───┴───┴───┼───┼───┼───┴┬───┬────┤
 *         │    │   │   │   │                   │   │   │    │↑  │    │
 * 11 keys │Ctrl│FN │GUI│Alt│       Space       │Alt│Ctl│ ←  ├───┤  → │
 *         │    │   │   │   │                   │   │   │    │  ↓│    │
 *         └────┴───┴───┴───┴───────────────────┴───┴───┴────┴───┴────┘
 * 79 total
 */
[_BASE] = LAYOUT(
    KC_ESC,  KC_F1,        KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12, KC_DEL,
    KC_GRV,  KC_1,         KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSPC,
    KC_TAB,  KC_Q,         KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC,
    MO(L_NAV),   LCTL_T(KC_A), LGUI_T(KC_S), LT(L_NAV, KC_D), LSFT_T(KC_F), KC_G, KC_H, RSFT_T(KC_J), KC_K, RGUI_T(KC_L), RCTL_T(KC_SCLN), KC_QUOT, KC_NUHS, KC_ENT,
    KC_LSFT, KC_NUBS,      KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,                   MO(L_SYM),
    KC_LCTL, MO(_FN),      KC_LGUI, KC_LALT,          KC_SPC,                                   KC_RALT, KC_RCTL, KC_LEFT, KC_UP,   KC_DOWN, KC_RGHT
),

/*
 * FN (momentary) – media/brightness/system (hold FN)
 *
 *         ┌─────┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬────┐
 *         │Esc  │Mut│vDn│vUp│Prv│Ply│Nxt│bDn│bUp│Scn│Air│Prt│Rst│ Del│
 *         └───────────────────────────────────────────────────────────┘
 */
[_FN] = LAYOUT(
    KC_ESC,  KC_MUTE, KC_VOLD, KC_VOLU, KC_MPRV, KC_MPLY, KC_MNXT, KC_BRID, KC_BRIU, KC_SCRN, KC_AIRP, KC_PSCR, QK_BOOT,  KC_DEL,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_PAUS, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, KC_SCRL, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, BL_BRTG, _______, KC_BRK,  _______, _______, _______, _______, _______,          _______,
    _______, _______, _______, _______,          BL_STEP,                   _______, _______, KC_HOME, KC_PGUP, KC_PGDN, KC_END
),

[L_SYM] = LAYOUT(
    /* Row 1 (F-row) */ 
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,

    /* Row 2 (number row) */
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,

    /* Row 3 (Q–P row) */
    KC_NO  ,            /* Tab */
    LSFT(KC_MINS),      /* Q -> _ */
    LSFT(KC_8),         /* W -> ( */
    LSFT(KC_0),         /* E -> = */
    LSFT(KC_9),         /* R -> ) */
    RALT(KC_RBRC),      /* T -> ~ (AltGr + ]) */
    KC_NO  ,            /* Y -> (none in ref) */
    LSFT(KC_6),         /* U -> & */
    LSFT(KC_NUHS),      /* I -> ' (DE: Shift + #) */
    RALT(KC_NUBS),      /* O -> | (AltGr + <) */
    KC_RBRC,            /* P -> ] */
    KC_MINS,            /* [ (DE Ü position) -> - */
    KC_NO  ,            /* ] (none in ref) */

    /* Row 4 (A–; row) */
    KC_NO  ,            /* Caps */
    LSFT(KC_1),         /* A -> ! */
    RALT(KC_8),         /* S -> [ */
    KC_NO  ,            /* D -> (none) */
    RALT(KC_9),         /* F -> ] */
    RSFT(KC_NUBS),      /* G -> > (Shift + <) */
    KC_NUHS,            /* H -> # */
    KC_NO  ,            /* J -> (none) */
    KC_NUBS,            /* K -> < */
    KC_NO  ,            /* L -> (none) */
    KC_NO  ,            /* ; (DE Ö) -> (none) */
    KC_NO  ,            /* ' (DE Ä) -> (none) */
    KC_NO  ,            /* # key -> (none) */
    KC_NO  ,            /* Enter */

    /* Row 5 (Z–/ row) */
    KC_NO  ,            /* LShift */
    KC_NO  ,            /* NUBS (<) */
    LSFT(KC_2),         /* Z -> " */
    RALT(KC_7),         /* X -> { */
    KC_NO  ,            /* C -> (none) */
    RALT(KC_0),         /* V -> } */
    RALT(KC_MINS),      /* B -> \ */
    LSFT(KC_7),         /* N -> / */
    LSFT(KC_RBRC),      /* M -> * (Shift + +) */
    KC_NO  ,            /* , -> (none) */
    KC_NO  ,            /* . -> (none) */
    KC_NO  ,            /* / -> (none) */
    KC_NO  ,            /* RShift */

    /* Row 6 (space / arrows row) */
    _______, _______, _______, _______,          _______,                              _______, _______, _______, _______, _______, _______
),

/*
 * NAV (hold Caps) – ported 1:1 by underlying letter from split reference
 * (tap Caps = Caps; hold = NAV)
 *
 *  H = Left, J = Down, K = Right, L = MO(3)
 *  U = Home, I = Up, O = End
 *  T = Ctrl+PgUp, G = Ctrl+PgDn
 *  N = TO(1)
 *  Thumbs: Del / Enter / Ctrl+Backspace
 */
[L_NAV] = LAYOUT(
    /* F-row */ 
    _______, _______, _______, _______, _______, _______, KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  ,

    /* Number row */
    _______, _______, _______, _______, _______, _______, KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  ,

    /* Q row (Q–P) */
    _______, _______, _______, _______, _______, _______, LCTL(KC_PGUP), KC_HOME, KC_UP,   KC_END,  KC_NO,  KC_NO  , KC_NO  , 

    /* A row (Caps–#) — home row arrows & helpers */
    _______, _______, _______, _______, _______, _______, LCTL(KC_PGDN), KC_LEFT, KC_DOWN, KC_RGHT, KC_NO  , KC_NO  , KC_NO  , KC_NO  ,

    /* Z row (Z–/) — extras: Z = Ctl+PgUp, N = TO(1) */
    _______, _______, _______, _______, _______, _______, KC_NO  ,    KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  ,              _______,

    /* Bottom / thumbs — editing cluster on the right */
    _______, _______, _______, _______,          _______,                            _______,  _______, _______, _______, _______, _______
),
};


enum combo_events {
    COM_LEADER,
    COM_SS,
    COM_DOT_SLASH
};

const uint16_t PROGMEM leader_combo[] = {KC_E, KC_R, KC_W, COMBO_END};
const uint16_t PROGMEM ss_combo[] = {LGUI_T(KC_S), KC_Y, COMBO_END};
const uint16_t PROGMEM dot_slash_combo[] = {LT(L_NAV, KC_D), LGUI_T(KC_S), COMBO_END};


combo_t key_combos[] = {
    [COM_LEADER]             = COMBO_ACTION(leader_combo),
    [COM_SS]                 = COMBO_ACTION(ss_combo),
    [COM_DOT_SLASH]          = COMBO_ACTION(dot_slash_combo),
};
/* COMBO_ACTION(x) is same as COMBO(x, KC_NO) */

void process_combo_event(uint16_t combo_index, bool pressed) {
    switch(combo_index) 
    {
        case COM_LEADER:
        if (pressed) 
        {
            leader_start();
        }
        break;

        case COM_SS:
        if (pressed) 
        {
            tap_code(KC_MINS);
        }
        break;

        case COM_DOT_SLASH:
        {
            if (pressed) 
            {
                SEND_STRING("./");
            }
        }
    }
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    // static uint16_t key_timer;

    switch (keycode) {

    /* Prevent press of Ctrl + Home/End, as this would jump to end or beginning
     * of file, which I do not want to. Instead, process without the Ctrl button
     */
    case KC_Q:
        tap_code(KC_Q);
        tap_code(KC_S);
        return false;
        break;

    case KC_END:
    case KC_HOME:
        if (record->event.pressed) {
            // Check if Ctrl is held down
            if (get_mods() & MOD_MASK_CTRL)
            {
                tap_code(KC_C);
            }
            else
            {
                tap_code(KC_O);
            }
            if (get_mods() & MOD_MASK_CTRL) {
                uint8_t mods = get_mods();       // Save current modifiers
                set_mods(mods & ~MOD_MASK_CTRL); // Remove CTL mod
                tap_code16(keycode);             // Send the key without Ctrl (Shift remains if held)
                set_mods(mods);                  // Restore modifiers as before
                return false;                    // Skip default processing for this key
            }
        }
        /* if not pressed during CTRL modifier is active, process normally */
        return true;
    break;

    /* When selecting words with holding Ctrl and Shift, often I want to 
     * select until the upper or lower line. But for this, I would need to 
     * release Ctl, which often leaves to misspresses (especially with home
     * row mods). Therefore, do press the button without Ctrl in this case.
     */
    case KC_UP:
    case KC_DOWN:
        if (record->event.pressed) 
        {
            uint8_t mods = get_mods(); // Get current modifiers
            const bool shift_pressed = mods & MOD_MASK_SHIFT;
                /* Checks if the right OR left shift is pressed */
            const bool ctrl_pressed  = mods & MOD_MASK_CTRL;
                /* Checks if the right OR left ctrl is pressed */
            if (shift_pressed && ctrl_pressed)  
            {
                set_mods(mods & ~MOD_MASK_CTRL); // Remove CTL mod
                tap_code(keycode); // Press Up/Down without Ctrl
                set_mods(mods); // Restore previous modifiers
                return false; // Skip normal processing
            }
        }
        return true; // Process normally if condition is not met
    break;

    default:
        return true; // Process all other keycodes normally
    }
}

/* Needed to make fire combos only if they are tapped. Only working
 * if COMBO_MUST_TAP_PER_COMBO is defined. 
 */
bool get_combo_must_tap(uint16_t combo_index, combo_t *combo)
{
    switch(combo_index) 
    {
    default:
        return true;
    }
}

void leader_end_user(void) {
    uint16_t i;
    if (leader_sequence_two_keys(KC_A, KC_T)) 
    {
        SEND_STRING("@");
    }
    else if (leader_sequence_two_keys(KC_D, KC_S)) 
    {
        SEND_STRING("./");
    }
    else if (leader_sequence_three_keys(KC_D, KC_E, KC_G)) 
    {
        register_code(KC_LSFT);
        tap_code(KC_GRV);
        unregister_code(KC_LSFT);
    }
    else if (leader_sequence_two_keys(KC_F, KC_T)) 
    {
        // front tick ´
        tap_code(KC_EQL);
        tap_code(KC_EQL);
    }
    else if (leader_sequence_two_keys(KC_S, KC_Q)) 
    {
        // single quote '
        tap_code(KC_EQL);
        tap_code(KC_SPC);
    }
    else if (leader_sequence_two_keys(KC_B, KC_T)) 
    {
        // Backtick
        SEND_STRING("`");
    }
    else if (leader_sequence_two_keys(KC_T, KC_B)) 
    {
        // Triple Backtick
        SEND_STRING("```");
    }
    else if (leader_sequence_three_keys(KC_P, KC_E, KC_R)) 
    {
        // Percent %
        register_code(KC_LSFT);
        tap_code(KC_5);
        unregister_code(KC_LSFT);
    }
    else if (leader_sequence_three_keys(KC_D, KC_O, KC_L)) 
    {
        // $
        SEND_STRING("$");
    }
    else if (leader_sequence_three_keys(KC_E, KC_U, KC_R)) 
    {
        // €
        register_code(KC_RALT);
        tap_code(KC_E);
        unregister_code(KC_RALT);
    }
    else if (leader_sequence_two_keys(KC_P, KC_M)) 
    {
        SEND_STRING(PRIVATE_MAIL);
    }
    else if (leader_sequence_two_keys(KC_W, KC_M)) 
    {
        SEND_STRING(WORK_MAIL);
    }
    else if (leader_sequence_two_keys(KC_V, KC_N)) 
    {
        SEND_STRING(FIRST_NAME);
    }
    else if (leader_sequence_two_keys(KC_N, KC_N)) 
    {
        SEND_STRING(LAST_NAME);
    }
    else if (leader_sequence_two_keys(KC_F, KC_N)) 
    {
        SEND_STRING(FULL_NAME);
    }
    else if (leader_sequence_three_keys(KC_T, KC_E, KC_L))
    {
        SEND_STRING(TEL_NUMBER);
    }
    else if (leader_sequence_four_keys(KC_T, KC_E, KC_L, KC_S))
    {
        SEND_STRING(TEL_NUMBER_SPACES);
    }
    else if (leader_sequence_four_keys(KC_T, KC_E, KC_L, KC_L))
    {
        SEND_STRING(TEL_NUMBER_LOCAL);
    }
    else if (leader_sequence_two_keys(KC_C, KC_B)) 
    {
        // Code Block
        SEND_STRING("```");
        tap_code(KC_ENTER);
        tap_code(KC_ENTER);
        SEND_STRING("```");
        tap_code(KC_UP);
    }
    else if (leader_sequence_two_keys(KC_C, KC_I)) 
    {
        // Code Inline
        SEND_STRING("``");
        tap_code(KC_LEFT);
    }
    else if (leader_sequence_two_keys(KC_D, KC_S)) 
    {
        // double slash
        SEND_STRING("//");
    }
    else if (leader_sequence_two_keys(KC_C, KC_O)) 
    {
        // Comment out
        tap_code(KC_HOME);
        tap_code(KC_HOME);
            /* multiple times for some weird editors like sublime 
             * only jump to begin of whitespace or so */
        SEND_STRING("//");
    }
    else if (leader_sequence_two_keys(KC_D, KC_L)) 
    {
        // Delete Line
        tap_code(KC_END);
        register_code(KC_LSFT);
        tap_code(KC_HOME);
        tap_code(KC_HOME);
        /* multiple times for some weird editors like sublime 
         * only jump to begin of whitespace or so */
        unregister_code(KC_LSFT);
        tap_code(KC_BSPC);
        tap_code(KC_BSPC);
    }
    else if (leader_sequence_two_keys(KC_C, KC_L)) 
    {
        // Clone Line
        tap_code(KC_END);
        register_code(KC_LSFT);
        tap_code(KC_HOME);
        /* multiple times for some weird editors like sublime 
         * only jump to begin of whitespace or so */
        unregister_code(KC_LSFT);

        register_code(KC_LCTL);
        tap_code(KC_C);
        unregister_code(KC_LCTL);

        tap_code(KC_END);
        tap_code(KC_ENTER);

        register_code(KC_LCTL);
        tap_code(KC_V);
        unregister_code(KC_LCTL);
    }
    else if (leader_sequence_two_keys(KC_S, KC_S))
    {
        // ß
        tap_code(KC_MINS);
    } 
    else if (leader_sequence_three_keys(KC_G, KC_R, KC_H))
    {
        // git reset --hard
        SEND_STRING("git reset --hard");
    } 
    else if (leader_sequence_two_keys(KC_G, KC_C))
    {
        // git reset --hard
        SEND_STRING("git checkout ");
    }
    else if (leader_sequence_three_keys(KC_O, KC_M, KC_B))
    {
        // obsidian math block
        SEND_STRING("$$");
        tap_code(KC_ENTER);
        SEND_STRING("\\begin{aligned}");
        tap_code(KC_ENTER);
        tap_code(KC_ENTER);
        SEND_STRING("\\end{aligned}");
        tap_code(KC_ENTER);
        SEND_STRING("$$");
        tap_code(KC_UP);
        tap_code(KC_UP);
    }    
    else if (leader_sequence_three_keys(KC_O, KC_M, KC_A))
    {
        // obsidian math align
        SEND_STRING("\\begin{aligned}");
        tap_code(KC_ENTER);
        tap_code(KC_ENTER);
        SEND_STRING("\\end{aligned}");
        tap_code(KC_UP);
    }
    else if (leader_sequence_three_keys(KC_O, KC_M, KC_I))
    {
        // obsidian math inline
        SEND_STRING("$");
        SEND_STRING("$");
        tap_code(KC_LEFT);
    }
    else if (leader_sequence_three_keys(KC_O, KC_M, KC_E))
    {
        // obsidian math inline
        SEND_STRING("$\\Omega$");
    }
    else if (leader_sequence_two_keys(KC_O, KC_V))
    {
        // obsidian paste
        register_code(KC_LCTL);
        tap_code(KC_V);
        wait_ms(300);
        unregister_code(KC_LCTL);
        for (i = 0; i < 35; i++)
        {
            tap_code(KC_LEFT);
        }
        tap_code(KC_BSPC);
        for (i = 0; i < 35; i++)
        {
            tap_code(KC_RGHT);
        }
    }
}
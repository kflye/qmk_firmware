#pragma once
// Implementation from https://github.com/moutis/HandsDown/tree/main

enum sematic_keycodes {
    SK_sf = SAFE_RANGE,

    SK_Mac,     //  mac (using ABC-Extended keyboard)
    SK_Win,     //  windows (using US-Intl keyboard)
    SK_Lux,     //  linux
        // the rest of these semantic keys do need to be translated.
        // everything from SK_KILL on has SemKeys_t table entry.
        // System-wide controls
    SK_KILL,    // SK_KILL must be the first of contiguous block of SKs
    SK_DKT8,    // speech to text
    SK_AIVC,    // AI voice control (mac Siri/Win cortana)
        // extended characters/ editing commands
    SK_HENT,    // Hard-Enter
    SK_UNDO,    // undo
    SK_REDO,    // redo
    SK_CUT,     // cut
    SK_COPY,    // copy
    SK_PSTE,    // paste
    SK_PSTM,    // paste_match
    SK_SALL,    // select all
    SK_SWRD,    // select current word
    SK_CLOZ,    // close
    SK_QUIT,    // quit
    SK_NEW,     // new
    SK_OPEN,    // open
    SK_FIND,    // find
    SK_FAGN,    // find again
    SK_SCAP,    // screen capture to clipboard
    SK_SCLP,    // selection capture to clipboard
    SK_SRCH,    // platform search (siri/cortana, etc.)
    SK_DELWDL,  // Delete word left of cursor
    SK_DELWDR,  // Delete word right of cursor
    SK_DELLNL,  // Delete line left of cursor
    SK_DELLNR,  // Delete line right of cursor
        // extended navigation
    SK_WORDPRV, // WORD LEFT
    SK_WORDNXT, // WORD RIGHT
    SK_DOCBEG,  // Go to start of document
    SK_DOCEND,  // Go to end of document
    SK_LINEBEG, // Go to beg of line
    SK_LINEEND, // Go to end of line
    SK_PARAPRV, // Go to previous paragraph
    SK_PARANXT, // Go to next paragraph
    SK_HISTPRV, // BROWSER BACK
    SK_HISTNXT, // BROWSER FWD
    SK_ZOOMIN,  // ZOOM IN
    SK_ZOOMOUT, // ZOOM OUT
    SK_ZOOMRST, // ZOOM RESET
    SK_APPNXT,  // APP switcher Next (last used)
    SK_APPPRV,  // APP switcher Prev (least recently used)
    SK_WINNXT,  // Window/tab switcher Next
    SK_WINPRV,  // Window/tab switcher Prev
        // Punctuation & typography
    SK_NDSH,    // — N-Dash
    SK_MDSH,    // — M-Dash
    SK_ELPS,    // … Elipsis
    SK_SCRS,    // † Single Cross
    SK_DCRS,    // ‡ Double Cross
    SK_BBLT,    // • Bold Bullet
    SK_SBLT,    // · Small Bullet
    SK_PARA,    // ¶ Paragraph symbol
    SK_SECT,    // § Section symbol
        // Number & Math symbols
    SK_PERM,    // ‰ Per Mille
    SK_DEGR,    // ° DEGREE
    SK_GTEQ,    // ≥ Greater Than or Equal to
    SK_LTEQ,    // ≤ Less Than or Equal to
    SK_PLMN,    // ± Plus/Minus
    SK_DIV,     // ÷ Divide symbol
    SK_FRAC,    // ⁄ Fraction "Solidus" symbol
    SK_NOTEQ,   // ≠ NOT Equal to
    SK_APXEQ,   // ≈ APPROX Equal to
    SK_OMEGA,   // Ω OMEGA
        // Currency
    SK_EURO,    // €
    SK_CENT,    // ¢
    SK_BPND,    // £
    SK_JPY,     // ¥
    SK_No,      // № ordinal number symbol
        // Quotations
    SK_SQUL,    // ’ Left single quote (linger for paired)
    SK_SQUR,    // ’ Right single quote
    SK_SDQL,    // “ Left double quote (linger for paired)
    SK_SDQR,    // ” Right double quote
    SK_FDQL,    // « Left double French quote (linger for paired)
    SK_FDQR,    // » Right double French quote
    SK_FSQL,    // ‹ Left single French quote (linger for paired)
    SK_FSQR,    // › Right single French quote
    SK_IQUE,    // ¿ Spanish inverted Question Mark
    SK_IEXC,    // ¡ Spanish inverted Exclamation Mark
        // Composed letters with diacritics
    SK_ENYE,    // ñ/Ñ ENYE
    

    
    SK_end, // end of SemKeys
            // 
    
    NEW_SAFE_RANGE  //use "NEW_NEW_SAFE_RANGE" for keymap specific codes
};

#define SK_beg SK_KILL
#define SK_count (SK_end - SK_beg)
#define SK_ndx(sk) (sk - SK_beg)

#define is_SemKey(sk) ((sk >= (uint16_t)(SK_beg)) && (sk < (uint16_t)SK_end))

#define get_SemKeyCode(sk) (SemKeys_t[SK_ndx(sk)][user_config.OSIndex])

#define linger_SemKey(sk) {register_SemKey(sk);linger_key = sk;linger_timer = state_reset_timer = timer_read();}
#define unlinger_SemKey(sk) {unregister_SemKey(linger_key);linger_key = 0;}
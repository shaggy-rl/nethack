#include "hack.h"

#include "templatehack_nhoutput.h"

/* ------------------------------------------------------------------------- */

/*
putstr(window, attr, str)
		-- Print str on the window with the given attribute.  Only
		   printable ASCII characters (040-0126) must be supported.
		   Multiple putstr()s are output on separate lines.  Attributes
		   can be one of
			ATR_NONE (or 0)
			ATR_ULINE
			ATR_BOLD
			ATR_BLINK
			ATR_INVERSE
		   If a window-port does not support all of these, it may map
		   unsupported attributes to a supported one (e.g. map them
		   all to ATR_INVERSE).  putstr() may compress spaces out of
		   str, break str, or truncate str, if necessary for the
		   display.  Where putstr() breaks a line, it has to clear
		   to end-of-line.
		-- putstr should be implemented such that if two putstr()s
		   are done consecutively the user will see the first and
		   then the second.  In the tty port, pline() achieves this
		   by calling more() or displaying both on the same line.
*/
void
templatehack_putstr (window, attr, str)
    winid window;
    int attr;
    const char *str;
{
#ifdef DEBUG
    printf("- templatehack_putstr(%d, %d, \"%s\");\n", window, attr, str);
#endif

    /* "window" is the result as you returned it from create_nhwindow */

    /* safety first ;) */
    if (window==WIN_ERR) {
        if (attr=ATR_BOLD) {
            templatehack_raw_print_bold(str);
        } else {
            templatehack_raw_print(str);
        }
        return;
    }

    /*TODO*/
};

/* ------------------------------------------------------------------------- */

/*
display_file(str, boolean complain)
		-- Display the file named str.  Complain about missing files
		   if complain is TRUE.
*/
void
templatehack_display_file (fname, complain)
    const char *fname;
    BOOLEAN_P complain;
{
#ifdef DEBUG
    printf("- templatehack_display_file(\"%s\", %d);\n", fname, complain);
#endif

    /*TODO*/
};


/* ------------------------------------------------------------------------- */

/*
print_glyph(window, x, y, glyph)
		-- Print the glyph at (x,y) on the given window.  Glyphs are
		   integers at the interface, mapped to whatever the window-
		   port wants (symbol, font, colour, attributes, ...there's
		   a 1-1 map between glyphs and distinct things on the map).
*/
void
templatehack_print_glyph (window, x, y, glyph)
    winid window;
    int x;
    int y;
    int glyph;
{
#ifdef DEBUG
    printf("- templatehack_print_glyph(%d, %d, %d, %d);\n",
        window, x, y, glyph);
#endif

    /*TODO*/

/* retrieving text/ascii display information :
 *
    mapglyph (glyph, &character, &colour, &special, x, y);
 */

/* retrieveing background glyph (for alpha/layered tilesets):
 *
    background_glyph = back_to_glyph(x,y);
 */


/* retrieveing tile foreground :
 *
    tile = glyph2tile[glyph];
 */

};

/* ------------------------------------------------------------------------- */

/*
raw_print(str)	-- Print directly to a screen, or otherwise guarantee that
		   the user sees str.  raw_print() appends a newline to str.
		   It need not recognize ASCII control characters.  This is
		   used during startup (before windowing system initialization
		   -- maybe this means only error startup messages are raw),
		   for error messages, and maybe other "msg" uses.  E.g.
		   updating status for micros (i.e, "saving").
*/
void
templatehack_raw_print (str)
    const char *str;
{
#ifdef DEBUG
    printf("- templatehack_raw_print(\"%s\");\n", str);
#endif

/* generally speaking this should be output to the window that was created as
 * NHW_MESSAGE with templatehack_create_nhwindow(). (imo)
 * It is also used for printing messages pre/post templatehack windowing
 * system initialisation/closure.
 */

    if (WIN_MESSAGE!=WIN_ERR) {
        templatehack_putstr(WIN_MESSAGE,ATR_NONE,str);
    } else {
        printf("%s\n",str);
    }

    /*TODO*/
}

/* ------------------------------------------------------------------------- */

/*
raw_print_bold(str)
		-- Like raw_print(), but prints in bold/standout (if possible).
*/
void
templatehack_raw_print_bold (str)
    const char *str;
{
#ifdef DEBUG
    printf("- templatehack_raw_print_bold(\"%s\");\n", str);
#endif

    /*TODO*/

/* lazy man's (or no bold support) solution :
 *
    templatehack_raw_print (str);
 *
 */

    if (WIN_MESSAGE!=WIN_ERR) {
        templatehack_putstr(WIN_MESSAGE,ATR_BOLD,str);
    } else {
        printf("%s\n",str);
    }

}

/* ------------------------------------------------------------------------- */



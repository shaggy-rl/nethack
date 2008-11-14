#include "hack.h"

#include "templatehack_nhpaletted.h"

/*

    The lack of documentation for the following functions, is simply because
    I could not find much myself :/
    If anyone hase more info on what these do or how they work, *please*
    let me know.

    Dont let this worry you however, 99.9% of window ports can simply leave
    these as empty placeholder functions.

*/

/* ------------------------------------------------------------------------- */

/*
    Setting of colours' values on a paletted video system
*/
#ifdef CHANGE_COLOR
void
templatehack_change_colour(colour,rgb,reverse)
    int colour;
    long rgb;
    int reverse;
{
#ifdef DEBUG
    printf("- templatehack_change_colour(%d, %06X, %d);\n",
        colour, rgb, reverse);
#endif

    if (reverse) {
        /* pseudo-code :
        set_colour_index(colour,invert_colour(rgb));
        */
    } else {
        /*  pseudo-code :
        set_colour_index(colour,rgb);
        */
    }
};
#endif

/* ------------------------------------------------------------------------- */

/*
    Return the palette, as a string of colour rgb values.
*/
#ifdef CHANGE_COLOR
char *
templatehack_get_colour_string(void)
{
#ifdef DEBUG
    printf("- templatehack_get_colour_string();\n");
#endif

    return NULL;
};
#endif

/* ------------------------------------------------------------------------- */

/*
    Set the background colour to either black, or white.
*/
#ifdef CHANGE_COLOR
#ifdef MAC
void *
templatehack_change_background(white)
    int white;
{
#ifdef DEBUG
    printf("- templatehack_change_background(%s);\n",
        white ? "white" : "black");
#endif

    if (white) {
        /* white background */
    } else {
        /* black background */
    }
}
#endif
#endif

/* ------------------------------------------------------------------------- */

/*
    Set fonts per window type (NHW_foo style).
*/
#ifdef CHANGE_COLOR
#ifdef MAC
short
templatehack_set_font_name(wintype, font_name)
    int wintype;
    char *font_name;
{
#ifdef DEBUG
    printf("- templatehack_set_font_name(");
    switch (wintype) {
        case NHW_MESSAGE:
            printf("NHW_MESSAGE");
            break;
        case NHW_STATUS:
            printf("NHW_STATUS");
            break;
        case NHW_MAP:
            printf("NHW_MAP");
            break;
        case NHW_MENU:
            printf("NHW_MENU");
            break;
        case NHW_TEXT:
            printf("NHW_TEXT");
            break;
        default:
            printf("NHW_*unknown*");
            break;
    }
    printf(", \"%s\");\n", font_name);
#endif

}
#endif
#endif

/* ------------------------------------------------------------------------- */


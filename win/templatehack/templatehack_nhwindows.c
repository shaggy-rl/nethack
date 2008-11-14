#include "hack.h"

#include "templatehack_nhwindows.h"

/* ------------------------------------------------------------------------- */

/*
window = create_nhwindow(type)
		-- Create a window of type "type."

There are 5 basic window types, used to call create_nhwindow():

	NHW_MESSAGE	(top line)
	NHW_STATUS	(bottom lines)
	NHW_MAP		(main dungeon)
	NHW_MENU	(inventory or other "corner" windows)
	NHW_TEXT	(help/text, full screen paged window)

*/
winid
templatehack_create_nhwindow (type)
    int type;
{
    winid window;

#ifdef DEBUG
    printf("- templatehack_create_nhwindow(");
    switch (type) {
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
    printf(");\n");
#endif

    /*TODO*/
    /* you need to replace these values with your own unique window "ID"s. */
    switch (type) {
        case NHW_MESSAGE:
            window = 1;
            break;
        case NHW_STATUS:
            window = 2;
            break;
        case NHW_MAP:
            window = 3;
            break;
        case NHW_MENU:
            window = 10;
            break;
        case NHW_TEXT:
            window = 20;
            break;
    }

    return window;
}

/* ------------------------------------------------------------------------- */

/*
clear_nhwindow(window)
		-- Clear the given window, when appropriate.
*/
void
templatehack_clear_nhwindow (window)
    winid window;
{
#ifdef DEBUG
    printf("- templatehack_clear_nhwindow(%d);\n", window);
#endif

    /* "window" is the result as you returned it from create_nhwindow */
    /*TODO*/
}

/* ------------------------------------------------------------------------- */

/*
display_nhwindow(window, boolean blocking)
		-- Display the window on the screen.  If there is data
		   pending for output in that window, it should be sent.
		   If blocking is TRUE, display_nhwindow() will not
		   return until the data has been displayed on the screen,
		   and acknowledged by the user where appropriate.
		-- All calls are blocking in the tty window-port.
		-- Calling display_nhwindow(WIN_MESSAGE,???) will do a
		   --more--, if necessary, in the tty window-port.
*/
void
templatehack_display_nhwindow (window, blocking)
    winid window;
    BOOLEAN_P blocking;
{
#ifdef DEBUG
    printf("- templatehack_display_nhwindow(%d, %d);\n", window, blocking);
#endif

    /* "window" is the result as you returned it from create_nhwindow */

    /*TODO*/

    /* possibly add simple, yet workable, blocking ...
    if (blocking) {
        templatehack_nhgetch();
    }
    */
}

/* ------------------------------------------------------------------------- */

/*
destroy_nhwindow(window)
		-- Destroy will dismiss the window if the window has not
		   already been dismissed.
*/
void
templatehack_destroy_nhwindow (window)
    winid window;
{
#ifdef DEBUG
    printf("- templatehack_destroy_nhwindow(%d);\n", window);
#endif

    /* "window" is the result as you returned it from create_nhwindow */

    /*TODO*/
}

/* ------------------------------------------------------------------------- */



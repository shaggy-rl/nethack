#include "hack.h"

#include "templatehack_nhmenus.h"

#include "templatehack_nhinput.h"


/* ------------------------------------------------------------------------- */

/*
start_menu(window)
		-- Start using window as a menu.  You must call start_menu()
		   before add_menu().  After calling start_menu() you may not
		   putstr() to the window.  Only windows of type NHW_MENU may
		   be used for menus.
*/
void
templatehack_start_menu (window)
    winid window;
{
#ifdef DEBUG
    printf("- templatehack_start_menu(%d);\n", window);
#endif

    /* "window" is the result as you returned it from create_nhwindow */

    /*TODO*/
};

/* ------------------------------------------------------------------------- */

/*
add_menu(windid window, int glyph, const anything identifier,
				char accelerator, char groupacc,
				int attr, char *str, boolean preselected)
		-- Add a text line str to the given menu window.  If identifier
		   is 0, then the line cannot be selected (e.g. a title).
		   Otherwise, identifier is the value returned if the line is
		   selected.  Accelerator is a keyboard key that can be used
		   to select the line.  If the accelerator of a selectable
		   item is 0, the window system is free to select its own
		   accelerator.  It is up to the window-port to make the
		   accelerator visible to the user (e.g. put "a - " in front
		   of str).  The value attr is the same as in putstr().
		   Glyph is an optional glyph to accompany the line.  If
		   window port cannot or does not want to display it, this
		   is OK.  If there is no glyph applicable, then this
		   value will be NO_GLYPH.
		-- All accelerators should be in the range [A-Za-z],
		   but there are a few exceptions such as the tty player
		   selection code which uses '*'.
	        -- It is expected that callers do not mix accelerator
		   choices.  Either all selectable items have an accelerator
		   or let the window system pick them.  Don't do both.
		-- Groupacc is a group accelerator.  It may be any character
		   outside of the standard accelerator (see above) or a
		   number.  If 0, the item is unaffected by any group
		   accelerator.  If this accelerator conflicts with
		   the menu command (or their user defined alises), it loses.
		   The menu commands and aliases take care not to interfere
		   with the default object class symbols.
		-- If you want this choice to be preselected when the
		   menu is displayed, set preselected to TRUE.
*/
void
templatehack_add_menu ( window, glyph, identifier,
                        ch, gch, attr, str, preselected)
    winid window;
    int glyph;
    const anything* identifier;
	CHAR_P ch;
    CHAR_P gch;
    int attr;
    const char *str;
    BOOLEAN_P preselected;
{
#ifdef DEBUG
    printf("- templatehack_add_menu (%d,%d,%d,'%c','%c',%d,\"%s\",%d);\n",
        window, glyph, identifier, ch, gch, attr, str, preselected);
#endif

    /* "window" is the result as you returned it from create_nhwindow */

    /*TODO*/
};

/* ------------------------------------------------------------------------- */

/*
end_menu(window, prompt)
		-- Stop adding entries to the menu and flushes the window
		   to the screen (brings to front?).  Prompt is a prompt
		   to give the user.  If prompt is NULL, no prompt will
		   be printed.
		** This probably shouldn't flush the window any more (if
		** it ever did).  That should be select_menu's job.  -dean
*/
void
templatehack_end_menu (window, prompt)
    winid window;
    const char *prompt;
{
#ifdef DEBUG
    printf("- templatehack_end_menu (%d, \"%s\");\n", window, prompt);
#endif

    /* "window" is the result as you returned it from create_nhwindow */
    /* "prompt" could be used as the window title on windowing systems */

    /*TODO*/
};

/* ------------------------------------------------------------------------- */

/*
int select_menu(windid window, int how, menu_item **selected)
		-- Return the number of items selected; 0 if none were chosen,
		   -1 when explicitly cancelled.  If items were selected, then
		   selected is filled in with an allocated array of menu_item
		   structures, one for each selected line.  The caller must
		   free this array when done with it.  The "count" field
		   of selected is a user supplied count.  If the user did
		   not supply a count, then the count field is filled with
		   -1 (meaning all).  A count of zero is equivalent to not
		   being selected and should not be in the list.  If no items
		   were selected, then selected is NULL'ed out.  How is the
		   mode of the menu.  Three valid values are PICK_NONE,
		   PICK_ONE, and PICK_ANY, meaning: nothing is selectable,
		   only one thing is selectable, and any number valid items
		   may selected.  If how is PICK_NONE, this function should
		   never return anything but 0 or -1.
		-- You may call select_menu() on a window multiple times --
		   the menu is saved until start_menu() or destroy_nhwindow()
		   is called on the window.
		-- Note that NHW_MENU windows need not have select_menu()
		   called for them. There is no way of knowing whether
		   select_menu() will be called for the window at
		   create_nhwindow() time.
*/
int
templatehack_select_menu (window, how, menu_list)
    winid window;
    int how;
    menu_item ** menu_list;
{
#ifdef DEBUG
    printf("- templatehack_select_menu (%d, %d, #TODO#);\n", window, how);
#endif

    /* "window" is the result as you returned it from create_nhwindow */
    char ch;

    /*TODO*/
    switch (how) {
        case PICK_NONE:  /* simply wait for "space"/"enter"/"foo" and return */
            while(TRUE) {
                ch=templatehack_nhgetch();
                switch(ch) {
                    case MENU_FIRST_PAGE: /* top page of menu */
                        break;
                    case MENU_LAST_PAGE: /* bottom page of menu */
                        break;
                    case MENU_NEXT_PAGE: /* page down */
                        break;
                    case MENU_PREVIOUS_PAGE: /* page up */
                        break;
                    case ' ':
                    case '\n':
                    default:
                        return 0;
                }
            }
            break;
        case PICK_ONE:   /* return single selected item */
            while(TRUE) {
                ch=templatehack_nhgetch();
                switch(ch) {
                    case '\033': /* escaped out of menu */
                        return 0;
                    case MENU_FIRST_PAGE: /* top page of menu */
                        break;
                    case MENU_LAST_PAGE: /* bottom page of menu */
                        break;
                    case MENU_NEXT_PAGE: /* page down */
                        break;
                    case MENU_PREVIOUS_PAGE: /* page up */
                        break;
                    default:
                        /*
                        if (a valid item "identifier") {
                            fill "menu_list";
                            return 1;
                        } else break;
                        */
                        return 0;
                }
            }
            break;
        case PICK_ANY:   /* allow for multiple/mass selections and return results */
            while(TRUE) {
                ch=templatehack_nhgetch();
                switch(ch) {
                    case '\033': /* escaped out of menu */
                        return 0;
                    case MENU_FIRST_PAGE: /* top page of menu */
                        break;
                    case MENU_LAST_PAGE: /* bottom page of menu */
                        break;
                    case MENU_NEXT_PAGE: /* page down */
                        break;
                    case MENU_PREVIOUS_PAGE: /* page up */
                        break;
                    case MENU_SELECT_PAGE: /* select the page in view */
                        break;
                    case MENU_UNSELECT_PAGE: /* deselect the page in view */
                        break;
                    case MENU_INVERT_PAGE: /* invert selections in page */
                        break;
                    case MENU_SELECT_ALL: /* select everything */
                        break;
                    case MENU_UNSELECT_ALL: /* deselect everything */
                        break;
                    case MENU_INVERT_ALL: /* invert all selections */
                        break;
                    case MENU_SEARCH: /* search and toggle those found */
                        break;
                    case '\n':
                        /*
                            fill "menu_list" with all selected items;
                            return selected_amount;
                        */
                    default:
                        /*
                        if (a valid item "identifier") {
                            mask item as selected;
                        }
                        */
                        break;
                }
            }
            break;
    }

    return 0;
};

/* ------------------------------------------------------------------------- */

/*
char message_menu(char let, int how, const char *mesg)
		-- tty-specific hack to allow single line context-sensitive
		   help to behave compatibly with multi-line help menus.
		-- This should only be called when a prompt is active; it
		   sends `mesg' to the message window.  For tty, it forces
		   a --More-- prompt and enables `let' as a viable keystroke
		   for dismissing that prompt, so that the original prompt
		   can be answered from the message line "help menu".
		-- Return value is either `let', '\0' (no selection was made),
		   or '\033' (explicit cancellation was requested).
		-- Interfaces which issue prompts and messages to separate
		   windows typically won't need this functionality, so can
		   substitute genl_message_menu (windows.c) instead.
*/
char
templatehack_message_menu (let, how, mesg)
    CHAR_P let;
    int how;
    const char *mesg;
{
#ifdef DEBUG
    printf("- templatehack_message_menu ('%c', %d, \"%s\");\n",
        let, how, mesg);
#endif

    /*TODO*/
    return genl_message_menu(let, how, mesg);
};

/* ------------------------------------------------------------------------- */


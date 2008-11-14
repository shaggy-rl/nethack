#include "hack.h"

#include "templatehack_main.h"

#include "templatehack_nhwindows.h"
#include "templatehack_nhmenus.h"
#include "templatehack_nhinput.h"
#include "templatehack_nhoutput.h"
#include "templatehack_nhunixtty.h"
#include "templatehack_nhpaletted.h"

/* Interface definition, for windows.c */
/*
    if any of these are not required by your interface system,
    simply replace the function name in this list with :
        donull
*/
struct window_procs templatehack_procs = {
    "templatehack",
    WC_COLOR|WC_HILITE_PET,     /* window port capabilities "wincap" */
    0,                          /* additional window port capabilities
                                    "wincap2" */
/* example of a "null" function, one that isn't used :
 *
    donull,
*/
    templatehack_init_nhwindows,        /* templatehack_main.c */
    templatehack_player_selection,      /* templatehack_main.c */
    templatehack_askname,               /* templatehack_main.c */
    templatehack_get_nh_event,          /* templatehack_main.c */
    templatehack_exit_nhwindows,        /* templatehack_main.c */
    templatehack_suspend_nhwindows,     /* templatehack_main.c */
    templatehack_resume_nhwindows,      /* templatehack_main.c */
    templatehack_create_nhwindow,       /* templatehack_nhwindows.c */
    templatehack_clear_nhwindow,        /* templatehack_nhwindows.c */
    templatehack_display_nhwindow,      /* templatehack_nhwindows.c */
    templatehack_destroy_nhwindow,      /* templatehack_nhwindows.c */
    templatehack_curs,                  /* templatehack_main.c */
    templatehack_putstr,                /* templatehack_nhoutput.c */
    templatehack_display_file,          /* templatehack_nhoutput.c */
    templatehack_start_menu,            /* templatehack_nhmenus.c */
    templatehack_add_menu,              /* templatehack_nhmenus.c */
    templatehack_end_menu,              /* templatehack_nhmenus.c */
    templatehack_select_menu,           /* templatehack_nhmenus.c */
    templatehack_message_menu,          /* templatehack_nhmenus.c */
    templatehack_update_inventory,      /* templatehack_main.c */
    templatehack_mark_synch,            /* templatehack_main.c */
    templatehack_wait_synch,            /* templatehack_main.c */
#ifdef CLIPPING
    templatehack_cliparound,            /* templatehack_main.c */
#endif
#ifdef POSITIONBAR
    templatehack_update_positionbar,    /* templatehack_main.c */
#endif
    templatehack_print_glyph,           /* templatehack_nhoutput.c */
    templatehack_raw_print,             /* templatehack_nhoutput.c */
    templatehack_raw_print_bold,        /* templatehack_nhoutput.c */
    templatehack_nhgetch,               /* templatehack_nhinput.c */
    templatehack_nh_poskey,             /* templatehack_nhinput.c */
    templatehack_nhbell,                /* templatehack_main.c */
    templatehack_doprev_message,        /* templatehack_main.c */
    templatehack_yn_function,           /* templatehack_main.c */
    templatehack_getlin,                /* templatehack_nhinput.c */
    templatehack_get_ext_cmd,           /* templatehack_nhinput.c */
    templatehack_number_pad,            /* templatehack_main.c */
    templatehack_delay_output,          /* templatehack_main.c */
#ifdef CHANGE_COLOR		/* the Mac uses a palette device */
    templatehack_change_colour,         /* templatehack_nhpaletted.c */
#ifdef MAC
    templatehack_change_background,     /* templatehack_nhpaletted.c */
    templatehack_set_font_name,         /* templatehack_nhpaletted.c */
#endif
    templatehack_get_colour_string,     /* templatehack_nhpaletted.c */
#endif
    templatehack_start_screen,          /* templatehack_nhunixtty.c */
    templatehack_end_screen,            /* templatehack_nhunixtty.c */
    templatehack_outrip,                /* templatehack_main.c */
    templatehack_preference_update      /* templatehack_main.c */
};


/* ------------------------------------------------------------------------- */

void
templatehack_win_init(void)
{
#ifdef DEBUG
    printf("- templatehack_win_init();\n");
#endif
    /* ignore this functions completely !
     * this function exists purely as as "locator" for src/windows.c's
     * interface into your code.
     */
};

/* ------------------------------------------------------------------------- */

/*
init_nhwindows(int* argcp, char** argv)
		-- Initialize the windows used by NetHack.  This can also
		   create the standard windows listed at the top, but does
		   not display them.
		-- Any commandline arguments relevant to the windowport
		   should be interpreted, and *argcp and *argv should
		   be changed to remove those arguments.
		-- When the message window is created, the variable
		   iflags.window_inited needs to be set to TRUE.  Otherwise
		   all plines() will be done via raw_print().
		** Why not have init_nhwindows() create all of the "standard"
		** windows?  Or at least all but WIN_INFO?	-dean
*/
void
templatehack_init_nhwindows (argcp, argv)
    int *argcp;
    char **argv;
{
#ifdef DEBUG
    char **debug_argv;
#endif

#ifdef DEBUG
    printf("- templatehack_init_nhwindows(%d, \"",*argcp);
    debug_argv=argv;
    if (*debug_argv) {
        printf("%s",*debug_argv);
        debug_argv++;
    }
    while (*debug_argv) {
        printf(" %s",*debug_argv);
        debug_argv++;
    }
    printf("\");\n");
#endif
    /*TODO*/
}

/* ------------------------------------------------------------------------- */

/*
player_selection()
		-- Do a window-port specific player type selection.  If
		   player_selection() offers a Quit option, it is its
		   responsibility to clean up and terminate the process.
		   You need to fill in pl_character[0].
*/
void
templatehack_player_selection (void)
{
#ifdef DEBUG
    printf("- templatehack_player_selection();\n");
#endif
    /* randomize those selected as "random" within .nethackrc */
    if ( (flags.initrole ==ROLE_RANDOM) ||
         (flags.randomall && (flags.initrole ==ROLE_NONE) ) )
        flags.initrole =
        pick_role(flags.initrace,flags.initgend,flags.initalign,PICK_RANDOM);
    if ( (flags.initrace ==ROLE_RANDOM) ||
         (flags.randomall && (flags.initrace ==ROLE_NONE)))
        flags.initrace =
        pick_race(flags.initrole,flags.initgend,flags.initalign,PICK_RANDOM);
    if ( (flags.initgend ==ROLE_RANDOM) ||
         (flags.randomall && (flags.initgend ==ROLE_NONE)))
        flags.initgend =
        pick_gend(flags.initrole,flags.initrace,flags.initalign,PICK_RANDOM);
    if ( (flags.initalign==ROLE_RANDOM) ||
         (flags.randomall && (flags.initalign==ROLE_NONE)))
        flags.initalign =
        pick_align(flags.initrole,flags.initrace,flags.initgend ,PICK_RANDOM);

    /* here this interface should present it's character selection */
    /*TODO*/

    /* any manually selected as random or left out ? randomize them ... */
    if (flags.initrole == ROLE_NONE)
        flags.initrole =
        pick_role(flags.initrace,flags.initgend,flags.initalign,PICK_RANDOM);
    if (flags.initrace == ROLE_NONE)
        flags.initrace =
        pick_race(flags.initrole,flags.initgend,flags.initalign,PICK_RANDOM);
    if (flags.initgend == ROLE_NONE)
        flags.initgend =
        pick_align(flags.initrole,flags.initrace,flags.initalign,PICK_RANDOM);
    if (flags.initalign == ROLE_NONE)
        flags.initalign =
        pick_gend(flags.initrole,flags.initrace,flags.initgend ,PICK_RANDOM);

}

/* ------------------------------------------------------------------------- */

/*
askname()	-- Ask the user for a player name.
*/
void
templatehack_askname (void)
{
#ifdef DEBUG
    printf("- templatehack_askname();\n");
#endif
    /*TODO*/
    /* a simple working example : */
    templatehack_getlin("What is your name?",plname);
};

/* ------------------------------------------------------------------------- */

/*
get_nh_event()	-- Does window event processing (e.g. exposure events).
		   A noop for the tty and X window-ports.
*/
void
templatehack_get_nh_event (void)
{
#ifdef DEBUG
    printf("- templatehack_get_nh_event();\n");
#endif
    /*TODO*/
};

/* ------------------------------------------------------------------------- */

/*
exit_nhwindows(str)
		-- Exits the window system.  This should dismiss all windows,
		   except the "window" used for raw_print().  str is printed
		   if possible.
*/
void
templatehack_exit_nhwindows (str)
    const char *str;
{
#ifdef DEBUG
    printf("- templatehack_exit_nhwindows(\"%s\");\n",str);
#endif
    /*TODO*/
}

/* ------------------------------------------------------------------------- */

/*
suspend_nhwindows(str)
		-- Prepare the window to be suspended.
*/
void
templatehack_suspend_nhwindows (str)
    const char *str;
{
#ifdef DEBUG
    printf("- templatehack_suspend_nhwindows(\"%s\");\n",str);
#endif
    /* this is normally called on ^Z within *nix systems */
    /*TODO*/
};

/* ------------------------------------------------------------------------- */

/*
resume_nhwindows()
		-- Restore the windows after being suspended.
*/
void
templatehack_resume_nhwindows (void)
{
#ifdef DEBUG
    printf("- templatehack_resume_nhwindows();\n");
#endif
    /*TODO*/
};

/* ------------------------------------------------------------------------- */

/*
curs(window, x, y)
		-- Next output to window will start at (x,y), also moves
		   displayable cursor to (x,y).  For backward compatibility,
		   1 <= x < cols, 0 <= y < rows, where cols and rows are
		   the size of window.
		-- For variable sized windows, like the status window, the
		   behavior when curs() is called outside the window's limits
		   is unspecified. The mac port wraps to 0, with the status
		   window being 2 lines high and 80 columns wide.
		-- Still used by curs_on_u(), status updates, screen locating
		   (identify, teleport).
		-- NHW_MESSAGE, NHW_MENU and NHW_TEXT windows do not
		   currently support curs in the tty window-port.
*/
void
templatehack_curs (window, x, y)
    winid window;
    int x;
    int y;
{
#ifdef DEBUG
    printf("- templatehack_curs(%d, %d, %d);\n", window, x, y);
#endif
    /* "window" is the result as you returned it from create_nhwindow */

    /*TODO*/
};


/* ------------------------------------------------------------------------- */

/*
update_inventory()
		-- Indicate to the window port that the inventory has been
		   changed.
		-- Merely calls display_inventory() for window-ports that
		   leave the window up, otherwise empty.
*/
void
templatehack_update_inventory (void)
{
#ifdef DEBUG
    printf("- templatehack_update_inventory();\n");
#endif

    if (flags.perm_invent) display_inventory(NULL,FALSE);

    /*TODO*/
};


/* ------------------------------------------------------------------------- */

/*
mark_synch()
        -- Don't go beyond this point in I/O on any channel until
		   all channels are caught up to here.  Can be an empty call
		   for the moment
*/
void
templatehack_mark_synch (void)
{
#ifdef DEBUG
    printf("- templatehack_mark_synch();\n");
#endif

    /*TODO*/
    /* actullay, not "TODO", you can leave this one empty for now */
};

/* ------------------------------------------------------------------------- */

/*
wait_synch()
        -- Wait until all pending output is complete (*flush*() for
		   streams goes here).
		-- May also deal with exposure events etc. so that the
		   display is OK when return from wait_synch().
*/
void
templatehack_wait_synch (void)
{
#ifdef DEBUG
    printf("- templatehack_wait_synch();\n");
#endif
    /*TODO*/
    /*
    "flush_windows();"
    "flush_screen();"
    */
};

/* ------------------------------------------------------------------------- */

/*
cliparound(x, y)
        -- Make sure that the user is more-or-less centered on the
		   screen if the playing area is larger than the screen.
		-- This function is only defined if CLIPPING is defined.
*/
#ifdef CLIPPING
void
templatehack_cliparound (x, y)
    int x;
    int y;
{
#ifdef DEBUG
    printf("- templatehack_cliparound(%d, %d);\n", x, y);
#endif
    /*TODO*/
};
#endif

/* ------------------------------------------------------------------------- */

/*
update_positionbar(char *features)
		-- Optional, POSITIONBAR must be defined. Provide some
		   additional information for use in a horizontal
		   position bar (most useful on clipped displays).
		   Features is a series of char pairs.  The first char
		   in the pair is a symbol and the second char is the
		   column where it is currently located.
		   A '<' is used to mark an upstairs, a '>'
		   for a downstairs, and an '@' for the current player
		   location. A zero char marks the end of the list.
*/
#ifdef POSITIONBAR
void
templatehack_update_positionbar (features)
    char *features;
{
#ifdef DEBUG
    char *debug_features;
#endif
#ifdef DEBUG
    printf("- templatehack_update_positionbar(");
    debug_features=features;
    printf("(%c,%2d)",*degug_features++,*degug_features++);
    while (*debug_features)
        printf(",(%c,%2d)",*degug_features++,*degug_features++);
    printf(");\n");
#endif
    /*TODO*/
};
#endif

/* ------------------------------------------------------------------------- */

/*
nhbell()
        -- Beep at user.  [This will exist at least until sounds are
		   redone, since sounds aren't attributable to windows anyway.]
*/
void
templatehack_nhbell (void)
{
#ifdef DEBUG
    printf("- templatehack_nhbell();\n");
#endif

    /*TODO*/
};

/* ------------------------------------------------------------------------- */

/*
doprev_message()
		-- Display previous messages.  Used by the ^P command.
		-- On the tty-port this scrolls WIN_MESSAGE back one line.
*/
int
templatehack_doprev_message (void)
{
#ifdef DEBUG
    printf("- templatehack_doprev_message();\n");
#endif

    /*TODO*/
};

/* ------------------------------------------------------------------------- */

/*
char yn_function(const char *ques, const char *choices, char default)
		-- Print a prompt made up of ques, choices and default.
		   Read a single character response that is contained in
		   choices or default.  If choices is NULL, all possible
		   inputs are accepted and returned.  This overrides
		   everything else.  The choices are expected to be in
		   lower case.  Entering ESC always maps to 'q', or 'n',
		   in that order, if present in choices, otherwise it maps
		   to default.  Entering any other quit character (SPACE,
		   RETURN, NEWLINE) maps to default.
		-- If the choices string contains ESC, then anything after
		   it is an acceptable response, but the ESC and whatever
		   follows is not included in the prompt.
		-- If the choices string contains a '#' then accept a count.
		   Place this value in the global "yn_number" and return '#'.
		-- This uses the top line in the tty window-port, other
		   ports might use a popup.
		-- If choices is NULL, all possible inputs are accepted and
		   returned, preserving case (upper or lower.) This means that
		   if the calling function needs an exact match, it must handle
		   user input correctness itself.
*/
char
templatehack_yn_function (ques, choices, def)
    const char *ques;
    const char *choices;
    CHAR_P def;
{
#ifdef DEBUG
    printf("- templatehack_yn_function(\"%s\",\"%s\",'%c');\n",
        ques, choices, def);
#endif

    /*TODO*/
    templatehack_raw_print(ques);
    return templatehack_nhgetch();
};

/* ------------------------------------------------------------------------- */

/*
number_pad(state)
		-- Initialize the number pad to the given state.
*/
void
templatehack_number_pad (state)
    int state;
{
#ifdef DEBUG
    printf("- templatehack_number_pad(%d);\n", state);
#endif
    /*TODO*/

    /* most interfaces simply ignore this function, oh well ... */
    switch (state) {
        case -1:        /* keypad mode, escape sequenses [numlock off] */
            break;
        case 1:         /* numeric mode for keypad (digits) [numlock on] */
            break;
        case 0:         /* dont do anything, leave terminal "as-is" */
            break;
    }
};

/* ------------------------------------------------------------------------- */

/*
delay_output()
        -- Causes a visible delay of 50ms in the output.
		   Conceptually, this is similar to wait_synch() followed
		   by a nap(50ms), but allows asynchronous operation.
*/
void
templatehack_delay_output (void)
{
#ifdef DEBUG
    printf("- templatehack_delay_output();\n");
#endif
    /*TODO*/
    /*
    templatehack_wait_sync();
    sleep(50);
    */
};

/* ------------------------------------------------------------------------- */

/*
outrip(winid, int)
		-- The tombstone code.  If you want the traditional code use
		   genl_outrip for the value and check the #if in rip.c.
*/
void
templatehack_outrip(window, how)
    winid window;
    int how;
{
#ifdef DEBUG
    printf("- templatehack_outrip(%d,%d);\n", window, how);
#endif
   /*TODO*/

    /* simple text tombstone from src/rip.c.
     * if you get compile errors at this point, remember to add
     * "TEMPLATEHACK" to the #ifdef checks within rip.c
     * .. or remove this call, and add your own pretty tombstone :D
     */
	genl_outrip(window,how);
};

/* ------------------------------------------------------------------------- */

/*
preference_update(preference)
		-- The player has just changed one of the wincap preference
		   settings, and the NetHack core is notifying your window
		   port of that change.  If your window-port is capable of
		   dynamically adjusting to the change then it should do so.
		   Your window-port will only be notified of a particular
		   change if it indicated that it wants to be by setting the
		   corresponding bit in the wincap mask.
*/
void
templatehack_preference_update(pref)
    const char *pref;
{
#ifdef DEBUG
    printf("- templatehack_preference_update(\"%s\");\n", pref);
#endif
    /*TODO*/

    genl_preference_update(pref);
}

/* ------------------------------------------------------------------------- */


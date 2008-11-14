#include "hack.h"

#include "templatehack_nhinput.h"

/* ------------------------------------------------------------------------- */

/*
int nhgetch()
        -- Returns a single character input from the user.
        -- In the tty window-port, nhgetch() assumes that tgetch()
           will be the routine the OS provides to read a character.
           Returned character _must_ be non-zero and it must be
                   non meta-zero too (zero with the meta-bit set).
*/
int
templatehack_nhgetch (void)
{
#ifdef DEBUG
    printf("- templatehack_nhgetch();\n");
#endif

    /*TODO*/
    return (int)getchar();
};

/* ------------------------------------------------------------------------- */

/*
int nh_poskey(int *x, int *y, int *mod)
		-- Returns a single character input from the user or a
		   a positioning event (perhaps from a mouse).  If the
		   return value is non-zero, a character was typed, else,
		   a position in the MAP window is returned in x, y and mod.
		   mod may be one of

			CLICK_1		- mouse click type 1
			CLICK_2		- mouse click type 2

		   The different click types can map to whatever the
		   hardware supports.  If no mouse is supported, this
		   routine always returns a non-zero character.
*/
int
templatehack_nh_poskey (x, y, mod)
    int *x;
    int *y;
    int *mod;
{
#ifdef DEBUG
    printf("- templatehack_nh_poskey();\n");
#endif

    /*TODO*/
    return (int)getchar();
};

/* ------------------------------------------------------------------------- */

/*
getlin(const char *ques, char *input)
		-- Prints ques as a prompt and reads a single line of text,
		   up to a newline.  The string entered is returned without the
		   newline.  ESC is used to cancel, in which case the string
		   "\033\000" is returned.
		-- getlin() must call flush_screen(1) before doing anything.
		-- This uses the top line in the tty window-port, other
		   ports might use a popup.
		-- getlin() can assume the input buffer is at least BUFSZ
		   bytes in size and must truncate inputs to fit, including
		   the nul character.
*/
void
templatehack_getlin (ques, input)
    const char *ques;
    char *input;
{
#ifdef DEBUG
    printf("- templatehack_getlin(\"%s\", \"%s\");\n",ques,input);
#endif

    /*TODO*/
};

/* ------------------------------------------------------------------------- */

/*
int get_ext_cmd(void)
		-- Get an extended command in a window-port specific way.
		   An index into extcmdlist[] is returned on a successful
		   selection, -1 otherwise.
*/
int
templatehack_get_ext_cmd (void)
{
#ifdef DEBUG
    printf("- templatehack_get_ext_cmd();\n");
#endif

    /* user wnats extended menu ? If users does, then nethack makes
       is easy for us :D */
    if (iflags.extmenu) return extcmd_via_menu();

    /*TODO*/
    return extcmd_via_menu(); /* remove this when adding interface specific
                                    ext_cmd code. */
};

/* ------------------------------------------------------------------------- */



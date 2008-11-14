#ifndef TEMPLATEHACK_PROCS_H
#define TEMPLATEHACK_PROCS_H

void templatehack_win_init(void);
void templatehack_init_nhwindows (int *argcp, char **argv);
void templatehack_player_selection (void);
void templatehack_askname (void);
void templatehack_get_nh_event (void);
void templatehack_exit_nhwindows (const char *str);
void templatehack_suspend_nhwindows (const char *str);
void templatehack_resume_nhwindows (void);
void templatehack_curs (winid window, int x, int y);
void templatehack_update_inventory (void);
void templatehack_mark_synch (void);
void templatehack_wait_synch (void);
#ifdef CLIPPING
void templatehack_cliparound (int x, int y);
#endif
#ifdef POSITIONBAR
void templatehack_update_positionbar (char *features);
#endif
void templatehack_nhbell (void);
int templatehack_doprev_message (void);
char templatehack_yn_function (
    const char *quesl, const char *choices, CHAR_P def);
void templatehack_number_pad (int state);
void templatehack_delay_output (void);
void templatehack_outrip(winid window, int how);
void templatehack_preference_update(const char *pref);

#endif

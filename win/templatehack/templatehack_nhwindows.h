#ifndef TEMPLATEHACK_NHWINDOWS_H
#define TEMPLATEHACK_NHWINDOWS_H

winid templatehack_create_nhwindow (int type);
void templatehack_clear_nhwindow (winid window);
void templatehack_display_nhwindow (winid window, BOOLEAN_P blocking);
void templatehack_destroy_nhwindow (winid window);

#endif

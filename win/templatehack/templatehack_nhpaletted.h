#ifndef TEMPLATEHACK_NHPALETTED_H
#define TEMPLATEHACK_NHPALETTED_H

#ifdef CHANGE_COLOR
void templatehack_change_colour(int colour, long rgb, int reverse);
char *templatehack_get_colour_string(void);
#ifdef MAC
void *templatehack_change_background(int white);
short templatehack_set_font_name(int wintype, char *font_name);
#endif
#endif

#endif

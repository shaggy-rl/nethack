#ifndef TEMPLATEHACK_NHOUTPUT_H
#define TEMPLATEHACK_NHOUTPUT_H

void templatehack_putstr (winid window, int attr, const char *str);
void templatehack_display_file (const char *fname, BOOLEAN_P complain);
void templatehack_print_glyph (winid window, int x, int y, int glyph);
void templatehack_raw_print (const char *str);
void templatehack_raw_print_bold (const char *str);

#endif

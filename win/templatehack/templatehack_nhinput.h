#ifndef TEMPLATEHACK_NHINPUT_H
#define TEMPLATEHACK_NHINPUT_H

int templatehack_nhgetch (void);
int templatehack_nh_poskey (int *x, int *y, int *mod);
void templatehack_getlin (const char *ques, char *input);
int templatehack_get_ext_cmd (void);

#endif

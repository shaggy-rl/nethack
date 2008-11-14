#ifndef TEMPLATEHACK_MENUS_H
#define TEMPLATEHACK_MENUS_H

void templatehack_start_menu (winid window);
void templatehack_add_menu (
    winid window,
    int glyph,
    const anything* identifier,
	CHAR_P ch,
    CHAR_P gch,
    int attr,
    const char *str,
    BOOLEAN_P preselected);
void templatehack_end_menu (winid window, const char *prompt);
int templatehack_select_menu (winid window, int how, menu_item ** menu_list);
char templatehack_message_menu (CHAR_P let, int how, const char *mesg);

#endif

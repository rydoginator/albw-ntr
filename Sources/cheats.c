#include "cheats.h"
#include "hid.h"

extern char    money_level_buffer[40];
extern int     g_increase_menu_index;
extern int     g_decrease_menu_index;

void	coord(void)
{
	if (is_pressed(BUTTON_A + BUTTON_DU))
		SUBTOFLOAT(0x168B5E84, 0.1);
	if (is_pressed(BUTTON_A + BUTTON_DD))
		ADDTOFLOAT(0x168B5E84, 0.1);
	if (is_pressed(BUTTON_A + BUTTON_DL))
		SUBTOFLOAT(0x168B5E7C, 0.1);
	if (is_pressed(BUTTON_A + BUTTON_DR))
		ADDTOFLOAT(0x168B5E7C, 0.1);
}

void 	moon(void)
{
	if (is_pressed(BUTTON_R))
		ADDTOFLOAT(0x168B5E80, 0.1);
}

void	health(void)
{
	WRITEU16(0x168B6044, 0x5050);
}


void    set_current_money(u16 value)
{
    WRITEU16(0x168B5FA8, value);
}

u16      get_current_money(void)
{
    u16      current_money;

    current_money = READU16(0x168B5FA8);
    return (current_money);
}

void    update_money_entry(void)
{
    u16 current_money;

    current_money = get_current_money();
    xsprintf(money_level_buffer, "Current rupees: %d", current_money);
}

void    increase_money(void)
{
    u16  current_money;

    current_money = get_current_money();
    if (current_money < 0x270F)
        current_money++;
    else
        current_money = 0;
    set_current_money(current_money);
    update_money_entry();
    disableCheat(g_increase_menu_index);
}

void    decrease_money(void)
{
    u16  current_money;

    current_money = get_current_money();
    if (current_money > 0)
        current_money--;
    else
        current_money = 0x270F;
    set_current_money(current_money);
    update_money_entry();
    disableCheat(g_decrease_menu_index);
}

void    max_money(void)
{
    set_current_money(0x270F);
}
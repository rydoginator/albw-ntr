#include "cheats.h"
#include "hid.h"

u32     g_pos_x;
u32     g_pos_y;
u32     g_pos_z;
u32     g_health;
u32     g_money;
u32     g_energy;
u32     g_items;
u32     g_key;

extern char    money_level_buffer[40];
extern int     g_increase_menu_index;
extern int     g_decrease_menu_index;

void    assign_region(u32 region)
{
    switch (region)
    {
        case USA:
            g_pos_x = USA_X_POS_ADDR;
            g_pos_y = USA_Y_POS_ADDR;
            g_pos_z = USA_Z_POS_ADDR;
            g_health = USA_HEALTH_ADDR;
            g_money = USA_MONEY_ADDR;
            g_energy = USA_ENERGY_ADDR;
            g_items = USA_ITEMS_ADDR;
            g_key = USA_KEYS_ADDR;
            break;
        case EUR:
            g_pos_x = USA_X_POS_ADDR + EUR_DIFFERENCE;
            g_pos_y = USA_Y_POS_ADDR + EUR_DIFFERENCE;
            g_pos_z = USA_Z_POS_ADDR + EUR_DIFFERENCE;
            g_health = USA_HEALTH_ADDR + EUR_DIFFERENCE;
            g_money = USA_MONEY_ADDR + EUR_DIFFERENCE;
            g_energy = USA_ENERGY_ADDR + EUR_DIFFERENCE;
            g_items = USA_ITEMS_ADDR + EUR_DIFFERENCE;
            g_key = USA_KEYS_ADDR + EUR_DIFFERENCE;
        break;
        case JAP:
            g_pos_x = USA_X_POS_ADDR + JAP_DIFFERENCE;
            g_pos_y = USA_Y_POS_ADDR + JAP_DIFFERENCE;
            g_pos_z = USA_Z_POS_ADDR + JAP_DIFFERENCE;
            g_health = USA_HEALTH_ADDR + JAP_DIFFERENCE;
            g_money = USA_MONEY_ADDR + JAP_DIFFERENCE;
            g_energy = USA_ENERGY_ADDR + JAP_DIFFERENCE;
            g_items = USA_ITEMS_ADDR + JAP_DIFFERENCE;
            g_key = USA_KEYS_ADDR + JAP_DIFFERENCE;
            break;
    }
}


void	coord(void)
{
	if (is_pressed(BUTTON_A + BUTTON_DU))
		SUBTOFLOAT(g_pos_z, 0.1);
	if (is_pressed(BUTTON_A + BUTTON_DD))
		ADDTOFLOAT(g_pos_z, 0.1);
	if (is_pressed(BUTTON_A + BUTTON_DL))
		SUBTOFLOAT(g_pos_x, 0.1);
	if (is_pressed(BUTTON_A + BUTTON_DR))
		ADDTOFLOAT(g_pos_x, 0.1);
}

void 	moon(void)
{
	if (is_pressed(BUTTON_R))
		ADDTOFLOAT(g_pos_y, 0.2);
}

void	health(void)
{
	WRITEU16(g_health, 0x5050);
}


void    set_current_money(u16 value)
{
    WRITEU16(g_money, value);
}

u16      get_current_money(void)
{
    u16      current_money;

    current_money = READU16(g_money);
    return (current_money);
}

void    update_money_entry(void)
{
    u16 current_money;

    current_money = get_current_money();
    xsprintf(money_level_buffer, "Current Rupees: %d", current_money);
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
    update_money_entry();
}

void	inf_energy(void)
{
	WRITEU16(g_energy, 0x4461);
}

void	max_tails(void)
{
	WRITEU8(g_items + 1, 0x63);
}

void	max_guts(void)
{
	WRITEU8(g_items + 2, 0x63);
}

void	max_horns(void)
{
	WRITEU8(g_items + 3, 0x63);
}

void	max_baby(void)
{
	WRITEU8(g_items + 4, 0x64);
}

void    max_keys(void)
{
    WRITEU8(g_key, 0x5);
}
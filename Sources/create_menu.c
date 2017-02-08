#include "cheats.h"

#define ENTRY_COUNT 300

typedef struct s_menu
{
    int         count;
    int         status;
    u32         f[ENTRY_COUNT];
    u32         s[ENTRY_COUNT];
    int         a[ENTRY_COUNT];
    const char  *t[ENTRY_COUNT];
    const char  *n[ENTRY_COUNT];
    void        (*fp[ENTRY_COUNT])();
}             t_menu;


typedef void    (*FuncPointer)(void);
extern t_menu menu;



void    new_super_unselectable_entry(char *str, FuncPointer function)
{
    int index;

    index = menu.count;
    if (index >= 300)
        return;
    new_unselectable_entry(str);
    menu.f[index] |= BIT(0) | BIT(1);
    menu.fp[index] = function;
}

char    *builder_name = "RyDog";

    static const char * const cm_note = "Press A+D Pad in any direction to move around at turbo speed!";
    static const char * const moon_note = "Press R to make Link fly! Gravity may be stronger in some areas. I'm looking for a fix.";

void with_note_common(const char *name, const char *note, void (*cheatfunction)(void), int type)
{
    int     index;

    if (type == 0)
        index = new_entry((char *)name, cheatfunction);
    else if (type == 1)
        index = new_radio_entry((char *)name, cheatfunction);
    else if (type == 2)
        index = new_spoiler((char *)name);
    else return;
    set_note(note, index);
}

inline void new_entry_with_note(const char *name, const char *note, void (*cheatfunction)(void))
{
    with_note_common(name, note, cheatfunction, 0);
}

inline void new_radio_entry_with_note(const char *name, const char *note, void (*cheatfunction)(void))
{
    with_note_common(name, note, cheatfunction, 1);
}

inline void new_spoiler_with_note(const char *name, const char *note)
{
    with_note_common(name, note, NULL, 2);
}


char    money_level_buffer[40] = "Current Rupees:";
int     g_increase_menu_index = 0;
int     g_decrease_menu_index = 0;

static inline void  smenu(void)
{
    new_spoiler("Movement Codes");
        new_entry_with_note("Coordinates Modifier", cm_note, coord);
        new_entry_with_note("Moon Jump", moon_note, moon);
    exit_spoiler();
    new_spoiler("Rupee Codes");
        new_unselectable_entry(money_level_buffer);
        g_increase_menu_index = new_entry("+ 1", increase_money);
        g_decrease_menu_index = new_entry("- 1", decrease_money);
        new_entry("Max Rupees", max_money);
    exit_spoiler();
    new_spoiler("Combat Codes");
        new_entry("Fill Hearts", health);
        new_entry("Infinite Energy Gauge", inf_energy);
    exit_spoiler();
    new_spoiler("Items Codes");
        new_entry("Max Monster Tails", max_tails);
        new_entry("Max Monster Guts", max_guts);
        new_entry("Max Monster Horns", max_horns);
        new_entry("Max Miamias", max_baby);
    exit_spoiler();
}

/*
** USA: 00040000 000EC300
*/

/*void    while_plugin_is_alive(void)
{
    text_to_cheats();
}*/

void    my_menus(void)
{
    u32 tid;
    
    set_hid_address(0x10002000); //This is in order to unlock the advanced HID capabilities such as Touchscreen and the stick (No N3DS hid for the moment)
    tid = get_tid_low();
    if (tid == 0xEC300)
    {
        new_unselectable_entry("Zelda ALBTW Cheats Ver 1.0");
    }
    else
   {
		printf("Current TitleID: %s", get_title_id());	
        new_unselectable_entry("You're Using An Unsupported TitleID!");			
        new_unselectable_entry("This plugin does not support");
		new_unselectable_entry("your copy yet!");
		
        return;
    }
    smenu();
}

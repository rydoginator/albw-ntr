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

    static const char * const t2i_note = "Type item ID and send it into chat,\n\nPress X+D Pad Right,\n\nTo write item to slot 1!";
    static const char * const dup_note = "Press R to duplicate the slot 1 item to slot 2!";
    static const char * const tan_note = "Go into a different room to see changes.";
    static const char * const trans_note = "Do not execute during loading screens!";
    static const char * const cm_note = "Press A+D Pad in any direction to move around at turbo speed!";
    static const char * const mj_note = "Press and hold L + D Pad Up to fly higher, Press L + D Pad down to go lower.";
    static const char * const tele_note = "B+D Pad Up to save,\n\nB+D Pad Down to teleport,\n\nPress L/R to store multiple.";
    static const char * const speed_note = "Press and hold B to start running at turbo fast speed!";
    static const char * const warp_note = "Touch the map to warp anywhere!";
    static const char * const time_note = "Do not use online!";
    static const char * const tt_note = "Fast forward: B+D Pad Right;\n\nRewind: B+D Pad Left,\n\nB+D Pad Down to revert ingame time to system time.\n\nPress L+D Pad Right/Left to watch time rewind/fastforward.";
    static const char * const tm_note = "Type YYMMDDHHmm,\n\nPress Y+D Pad Right to fast forward to that,\n\nOr press Y+D Pad Left to rewind that amount.";
    static const char * const enviro_note = "After executing one of these codes,\n\nUpdate the status to verify the object!";
    static const char * const seed_note = "Hold R and A as you're dropping an item to change the item ID.";
    static const char * const tree_note = "Press X for your tree to instantly grow!";
    static const char * const sar_note = "Type in XXXXYYYY where XXXX is search value and YYYY is repalce value. Send it in chat, and press L + D pad left to execute.";
    static const char * const ra_note = "Enable one R+A cheat at a time,\n\nExecute one,\n\nThen go in and out of a house.";
    static const char * const warning_note = "!!! Warning !!!\n\nIn order to prevent a crash of the game," \
    "we strongly advise you to only open the menu either on the title screen or indoor.\n\nDon't ever open during a multiplayer session!";
    static const char * const real_note = "Type in the ID of the item ID you want, send it into chat and press R + D pad down to place the item directly where you're standing.";
    static const char * const des_note = "Press R + A to remove your grass!";
    static const char * const lush_note = "Press R + A to replenish all your grass!";
    static const char * const weed_note = "Press R + A to remove all weeds!";
    static const char * const flwr_note = "Press R + A to replenish all your flowers!";
    static const char * const cl_note = "Only works outdoors! Press L + D Pad up to enable, Press L + D Pad down to disable.";
    static const char * const eat_note = "Type item ID into chat, send it and press L to store it, and press R + A while eating an item to change that item into what you typed into the chat/keyboard.";
    static const char * const dynamic_note = "When inside a ADB, press Y + D pad right to write the decimal to slot 1.";
    static const char * const gr_note = "Rapid fire with tools, anti gravity and more. Enable with L + D Pad up, disable with L + D Pad down.";
    static const char * const cam_note = "R + Circle pad = rotation \n\n R + A stop player from moving or Y lock camera, X unlock camera (needed) \n\n B + D pad move camera, L/R up and down";
    static const char * const turn_note = "Set the turnip price to 990 bells for the current week.";	
    static const char * const badge_note = "Change all badges to selected type.";
    static const char * const med_note = "Change your Medal Amount to the selected value.";
    static const char * const meow_note = "Change your Meow Coupon Amount to the selected value.";
	static const char * const medun_note = "  WARNING!! Unstable!!\nMedals may become negative\nwhen Adding!! To fix: Decrease to a positive\nnumber & buy anything!\nTo Use: Press Up to increase medals by amount selected,Press Down to decrease by selected value.";
    static const char * const clear_note = "Press R + A to completely clear your town of everything. There is no going back, so don't save if you don't like it.";

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


char    money_level_buffer[40] = "First init";
int     g_increase_menu_index = 0;
int     g_decrease_menu_index = 0;

static inline void  smenu(void)
{
    //update_money_entry();
    new_spoiler("Movement Codes");
        new_entry("Coordinates Modifier", coord);
        new_entry("Moon Jump", moon);
    exit_spoiler();
    new_spoiler("Rupee Codes");
        new_unselectable_entry(money_level_buffer);
        g_increase_menu_index = new_entry("+ 1", increase_money);
        g_decrease_menu_index = new_entry("- 1", decrease_money);
    exit_spoiler();
    new_entry("Fill Hearts", health);


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
        new_unselectable_entry("Zelda ALBTW Cheats Preview");
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

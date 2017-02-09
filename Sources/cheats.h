#ifndef CHEATS_H
#define CHEATS_H

#include "../Includes/plugin.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

#define     add_search_replace(find, replace)   g_find[g_i] = find; g_replace[g_i] = replace; g_i++
#define     reset_search()                      memset(g_find, 0, sizeof(g_find)); memset(g_replace, 0, sizeof(g_replace)); g_i = 0
#define     ADD32(addr, value)         *(u32 *)addr += value
#define     SUB32(addr, value)         *(u32 *)addr -= value
#define     ADD64(addr, value)                  *(vs64 *)addr += value
#define     SUB64(addr, value)                  *(vs64 *)addr -= value
#define		ADD16(addr, value)					*(u16 *)addr += value
#define		SUB16(addr, value)					*(u16 *)addr -= value
#define     ADDTOFLOAT(addr, add_value)         *(float *)addr += (float)add_value
#define     SUBTOFLOAT(addr, sub_value)         *(float *)addr -= (float)sub_value


#define		USA_X_POS_ADDR				0x168B5E7C
#define		USA_Y_POS_ADDR				0x168B5E80
#define		USA_Z_POS_ADDR				0x168B5E84
#define		USA_HEALTH_ADDR				0x168B6044
#define		USA_MONEY_ADDR				0x168B5FA8
#define		USA_ENERGY_ADDR				0x168B9FCA
#define		USA_ITEMS_ADDR				0x168B5FB0
#define		USA_KEYS_ADDR				0x168B5EDC

#define		EUR_DIFFERENCE				0x1400
#define		JAP_DIFFERENCE				0x944E0



enum
{
    USA = 0,
    EUR,
    JAP
};				


void    disable_entry(int identifier);
void    assign_region(u32 region);

void	coord(void);
void	moon(void);
void	update_money_entry(void);
void    increase_money(void);
void    decrease_money(void);
void	health(void);
void	inf_energy(void);
void	max_money(void);
void	max_tails(void);
void	max_guts(void);
void	max_horns(void);
void	max_baby(void);
void	max_keys(void);

#endif

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

void    disable_entry(int identifier);

void	coord(void);
void	moon(void);
void	update_money_entry(void);
void    increase_money(void);
void    decrease_money(void);
void	health(void);

#endif

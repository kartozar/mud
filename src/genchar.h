/* ************************************************************************
*   File: genchar.h                                     Part of Bylins    *
*  Usage: header file for character generation                            *
*                                                                         *
*  All rights reserved.  See license.doc for complete information.        *
*                                                                         *
*  Copyright (C) 1993, 94 by the Trustees of the Johns Hopkins University *
*  CircleMUD is based on DikuMUD, Copyright (C) 1990, 1991.               *
* 									  *
*  $Author$                                                        *
*  $Date$                                           *
*  $Revision$                                                      *
************************************************************************ */

#ifndef _GENCHAR_H_
#define _GENCHAR_H_

#define SUM_ALL_STATS 95
#define SUM_STATS(ch) (GET_STR(ch) + GET_DEX(ch) + GET_INT(ch) +  GET_WIS(ch) + GET_CON(ch) +  GET_CHA(ch))

#define GENCHAR_CONTINUE 1
#define GENCHAR_EXIT 0

#define G_STR 0
#define G_DEX 1
#define G_INT 2
#define G_WIS 3
#define G_CON 4
#define G_CHA 5

#define MIN_STR(ch) min_stats[(int) GET_CLASS(ch)][G_STR]
#define MIN_DEX(ch) min_stats[(int) GET_CLASS(ch)][G_DEX]
#define MIN_INT(ch) min_stats[(int) GET_CLASS(ch)][G_INT]
#define MIN_WIS(ch) min_stats[(int) GET_CLASS(ch)][G_WIS]
#define MIN_CON(ch) min_stats[(int) GET_CLASS(ch)][G_CON]
#define MIN_CHA(ch) min_stats[(int) GET_CLASS(ch)][G_CHA]

#define MAX_STR(ch) max_stats[(int) GET_CLASS(ch)][G_STR]
#define MAX_DEX(ch) max_stats[(int) GET_CLASS(ch)][G_DEX]
#define MAX_INT(ch) max_stats[(int) GET_CLASS(ch)][G_INT]
#define MAX_WIS(ch) max_stats[(int) GET_CLASS(ch)][G_WIS]
#define MAX_CON(ch) max_stats[(int) GET_CLASS(ch)][G_CON]
#define MAX_CHA(ch) max_stats[(int) GET_CLASS(ch)][G_CHA]

extern const char *genchar_help;

void genchar_disp_menu(CHAR_DATA * ch);
int genchar_parse(CHAR_DATA * ch, char *arg);
void roll_real_abils(CHAR_DATA * ch);
void GetCase(char *name, int sex, int caseNum, char *result);

extern int max_stats[][6];
extern int min_stats[][6];

#endif

/* ************************************************************************
*   File: pk.h                                          Part of Bylins    *
*  Usage: header file: constants and fn prototypes for �� �������         *
*                                                                         *
*  All rights reserved.  See license.doc for complete information.        *
*                                                                         *
*  CircleMUD is based on DikuMUD, Copyright (C) 1990, 1991.               *
*                                                                         *
*  $Author$                                                        *
*  $Date$                                           *
*  $Revision$                                                       *
************************************************************************ */

#ifndef _PK_H_
#define _PK_H_

//*************************************************************************
// �������� ������ � ���������� ����������� �������� ����� ��������

// ������������� �������:
//   1. ����� ������� may_kill_here()
//      ����� �� ����� ��������� ������ (����������� �� �����, ����� � �.�.)
//   2. ����� ������� check_pkill()
//      ���������� ������������� ����������� �������� � ����������
//      ������� ��� ������ ���������
//   3. ����� ������� pk_agro_action() ��� ������ ��������
//   4. ����� ������� pk_thiefs_action() ��� ���������
//   5. ����� ������� pk_revenge_action() � ������ ��������

// ��������� ��� ���������� �� ���������
struct PK_Memory_type
{
	long unique;		// unique ������
	long kill_num;		// ���������� ������ �������� ��������� �� unique
	long kill_at;		// ����� ��������� ���������� ����� (��� spamm)
	long revenge_num;	// ���������� ������� ���������� ����� �� ������� unique
	long battle_exp;	// ����� ��������� ��������
	long thief_exp;		// ����� ��������� ����� ���������
	long clan_exp;		// ����� ��������� ����-�����
	long pentagram_exp;
	struct PK_Memory_type *next;
};

#define		PK_ACTION_NO		1	// ������� ����������
#define		PK_ACTION_FIGHT     2	// �������� � �������� ��������
#define		PK_ACTION_REVENGE	4	// ������� ����������� �����
#define		PK_ACTION_KILL		8	// ���������
#define		PK_ACTION_PENTAGRAM_REVENGE		16	// Pent restiction override

// agressor ��������� ������ victim
// ��������� - ��� �������� (��. ����)
int pk_action_type(CHAR_DATA * agressor, CHAR_DATA * victim);

// �������� ����� �� ch ������ ����������� �������� ������ victim
// TRUE - �����
// FALSE - �� �����
int may_kill_here(CHAR_DATA * ch, CHAR_DATA * victim);

// ����������� ������������� ������� ��� ������ ���������
bool need_full_alias(CHAR_DATA * ch, CHAR_DATA * opponent);

//�����������, �������� �� ������ arg ������ ������ ch
int name_cmp(CHAR_DATA * ch, const char *arg);

// ����������� ����������� ������������
int check_pkill(CHAR_DATA * ch, CHAR_DATA * opponent, const char *arg);
int check_pkill(CHAR_DATA * ch, CHAR_DATA * opponent, const std::string &arg);

// agressor �������� �������� ������ victim
void pk_agro_action(CHAR_DATA * agressor, CHAR_DATA * victim);

// thief �������� �������� ������ victim, ���������� � �������� �����
void pk_thiefs_action(CHAR_DATA * thief, CHAR_DATA * victim);

// killer ������� victim
void pk_revenge_action(CHAR_DATA * killer, CHAR_DATA * victim);

// ������� ������ ��
void pk_free_list(CHAR_DATA * ch);

// ��������� ���������� ������ �����
int pk_count(CHAR_DATA * ch);

//�������� ���� ���������� �����������
void set_pentagram_pk(CHAR_DATA * ch, bool isPortalEnter, int isGates);
void remove_pent_pk(CHAR_DATA * agressor, CHAR_DATA * victim);
//*************************************************************************
// �������������� ������� ����������� ������� ��

void aura(CHAR_DATA * ch, int lvl, CHAR_DATA * victim, char *s);
const char *CCPK(CHAR_DATA * ch, int lvl, CHAR_DATA * victim);
void pk_list_sprintf(CHAR_DATA * ch, char *buff);

//*************************************************************************
// ��������� ������� ����������/�������� �� ������
void save_pkills(CHAR_DATA * ch, FILE * saved);

//*************************************************************************
bool has_clan_members_in_group(CHAR_DATA * ch);

#endif

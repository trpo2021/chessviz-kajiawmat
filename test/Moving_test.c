#include<stdlib.h>
#include<stdio.h>
#include "ctest.h"
#include "Moving.h"
#include "Board.h"
#include "Chess_Game.h"

extern int move, gor_begin, ver_begin, gor_end, ver_end, typ_roki, move_rook[];
extern char letter_fig, typ_move, transform, last_cut, C[][9];
extern const int Players, Reg;

CTEST_SETUP(Moving)
{
	Game_Init();
	Board_NULL();
	int flag,i;
	char ch;
	FILE *ft;
	ft=fopen("res//test_game//Moving_test.txt","r");
}

CTEST(Moving, Moving_test)
{
	for(i=0;i<3;i++)
	{
		flag=0;
		ch=getc(ft);
		Move_Read(ft,ch);
		Moving();
		if(C[ver_begin][gor_begin]==' ' && C[ver_end][gor_end]==letter_fig+Reg*((move+1)%Players))
		{
			flag=1;
		}
		ASSERT_EQUAL(1,flag);
		move++;
	}
}

CTEST_SETUP(Move_Pawn)
{
	Game_Init();
	Board_NULL();
}

CTEST(Move_Pawn,Move_Pawn_test)
{
	letter_fig='P';
	tranform='B';
	const int ver=2;
	ver_begin=ver;
	gor_begin=3;
	C[ver_begin][gor_begin]='P';
	C[ver_begin+3][gor_begin-1]='q';
	typ_move='-';
	ver_end=ver_begin+2;
	gor_end=gor_begin;
	Move_Pawn();
	ASSERT_EQUAL(1,1);
	typ_move=':';
	ver_begin=ver_end;
	ver_end++;
	gor_end--;
	Move_Pawn();
	ASSERT_EQUAL(1,1);
	gor_begin=gor_end;
	typ_move='-';
	int i;
	for(i=ver_end;i<=8;i++)
	{
		ver_begin=ver_end;
		ver_end++;
		Move_Pawn();
		ASSERT_EQUAL(1,1);
	}
}

CTEST_SETUP(Move_figure)
{
	Game_Init();
	Board_NULL();
	int num_move,i;
}

CTEST_TEARDOWN(Move_figure)
{
	void (*figure) (void);
	switch (letter_fig)
	{
		case 'R':
			figure=Move_Rook;
			break;
		case 'N':
			figure=Move_Knight;
			break;
		case 'B':
			figure=Move_Bishop;
			break;
		case 'Q':
			figure=Move_Queen;
			break;
		case 'K':
			figure=Move_King;
			break;
		default:
			CTEST_ERR("letter_fig is wrong. Please repair and try again!!!");
	}
	C[ver_begin][gor_begin]=letter_fig+Reg*((move+1)%Players);
	for(i=0;i<num_move;i++)
	{
		ver_end=ver_begin+Move_ver[i];
		gor_end=gor_begin+Move_gor[i];
		typ_move=Move_typ[i];
		if((typ_move==':')||(typ_move=='x'))
		{
			C[ver_end][gor_end]=letter_fig+Reg-Reg*((move+1)%Players);
		}
		figure();
		ASSERT_EQUAL(1,1);
		ver_begin=ver_end;
		gor_begin=gor_end;
	}
}

CTEST(Move_figure,Move_Rook_test)
{
	move=2;
	num_move=4;
	int Move_gor[num_move]={-5,0,2,0};
	int Move_ver[num_move]={0,3,0,-1};
	char Move_typ[num_move]={'-','-','-',':'};
	letter_fig='R';
	gor_begin=6;
	ver_begin=5;
}

CTEST(Move_figure,Move_Knight_test)
{
	move=1;
	num_move=8;
	int Move_gor[num_move]={2,-2,1,1,-2,2,-1,-1};
	int Move_ver[num_move]={1,1,-2,2,-1,-1,2,-2};
	char Move_typ[num_move]={'-','-','x',':','-',':','-','-'};
	letter_fig='N';
	gor_begin=3;
	ver_begin=4;
}

CTEST(Move_figure,Move_Bishop_test)
{
	move=1;
	num_move=4;
	int Move_gor[num_move]={4,2,-3,-1};
	int Move_ver[num_move]={-4,2,3,-1};
	char Move_typ[num_move]={'-','-','-',':'};
	letter_fig='B';
	gor_begin=2;
	ver_begin=6;
}

CTEST(Move_figure,Move_Queen_test)
{
	move=2;
	num_move=8;
	int Move_gor[num_move]={-3,0,3,-3,3,0,-3,3};
	int Move_ver[num_move]={0,3,0,-3,3,-3,3,-3};
	char Move_typ[num_move]={'x',':','x','-','-','-','-','-'};
	letter_fig='Q';
	gor_begin=5;
	ver_begin=2;
}

CTEST(Move_figure,Move_King_test)
{
	move=1;
	num_move=8;
	int Move_gor[num_move]={0,-1,-1,-1,0,1,1,1};
	int Move_ver[num_move]={-1,-1,0,1,1,1,0,-1};
	char Move_typ[num_move]={'-',':','-','-','x','-','-','-'};
	letter_fig='K';
	gor_begin=5;
	ver_begin=5;
}

CTEST_SETUP(Rokirovka)
{
	Board_NULL();
	Game_Init();
	C[1][1]='R';
	C[1][8]='R';
	C[1][5]='K';
	C[8][1]='r';
	C[8][8]='r';
	C[8][5]='k';
	int flag,border,i;
}

CTEST(Rokirovka,Rokirovka_test)
{
	for(move=1;move<=2;move++)
	{
		for(typ_roki=1;typ_roki<=2;typ_roki++)
		{
			flag=0;
			Rokirovka();
			border=3-2*(move%Players);
			if(move_rook[border]==0 && move_rook[border+1]==0)
			{
				flag=1;
				move_rook[border]=1;
				move_rook[border+1]=1;
			}
			ASSERT_EQUAL(1,flag);
			C[1][5]='K';
			C[8][5]='k';
		}
	}
	flag=1;
	for(i=3;i<=7;i++)
	{
		if(C[8][i]==' ' || C[1][i]==' ')
		{
			flag=0;
			break;
		}
	}
	ASSERT_EQUAL(1,flag);
}

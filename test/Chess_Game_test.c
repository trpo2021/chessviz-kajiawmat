#include<stdio.h>
#include<stdlib.h>
#include "ctest.h"
#include "Chess_Game.h"
//If it will not work, I CAN ignore this test, because if other functions work, then it works too

extern int gor_begin, ver_begin, gor_end, ver_end, typ_roki, move;
extern char letter_fig, typ_move, transform, last_cut;
extern const int Ver_min;

CTEST_SETUP(Game)
{
	Game_Init();
	FILE *ft;
	ft=fopen("res//Chess_Game_test.txt","r");
	flag;
}

CTEST(Game,Chess_Game_test)
{
	flag=0;
	Chess_Game(ft);
	if(ft==NULL)
	{
		flag=1;
	}
	ASSERT_EQUAL(1,flag);
}

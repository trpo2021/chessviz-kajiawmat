#include<stdlib.h>
#include "ctest.h"
#include "Rules.h"
#include "Board.h"

extern int move, gor_begin, ver_begin, gor_end, ver_end, move_rook[];
extern char letter_fig, typ_move, C[][9],last_cut;
extern char const Type_figure[];

CTEST(Module,test_all)
{
	int a,b;
	for(a=10;a>=0;a--)
	{
		b=Module(a);
		ASSERT_EQUAL(a,b);
	}
	for(a=-10;a<0;a++)
	{
		b=Module(a);
		ASSERT_EQUAL(-a,b);
	}
}

CTEST_SETUP(Checking_Read)
{
	char x;
	int flag,i,j;
}

CTEST(Checking_Read, Check_Getc_test)
{
	char sym_massive[10]={' ','.','#','+','!','?',';','\n','\t','X'};
	for(x=32;x<'A';x++)
	{
		flag=0;
		for(i=0;i<10-3;i++)
		{
			if(x==sym_massive[i])
			{
				flag=1;
				break;
			}
		}
		ASSERT_EQUAL(flag,Check_Getc(x));
	}
	x=sym_massive[8];
	ASSERT_EQUAL(1,Check_Getc(x));
	x=sym_massive[9];
	ASSERT_EQUAL(1,Check_Getc(x));
	x=sym_massive[10];
	ASSERT_EQUAL(1,Check_Getc(x));
}

CTEST(Checking_Read, Check_Massive_test)
{
	for(x=60;x<=122;x++)
	{
		flag=0;
		for(i=0;i<6;i++)
		{
			if(x==Type_figure[i])
			{
				flag=1;
				break;
			}
		}
		ASSERT_EQUAL(flag,Check_Massive(x));
	}
}

CTEST(Checking_Read, Check_Gor_test)
{
	for(x=50;x<=127;x++)
	{
		flag=0;
		if(x>=97 && x<=104)
		{
			flag=1;
		}
		ASSERT_EQUAL(flag,Check_Gor(x));
	}
}

CTEST(Checking_Read, Check_Ver_test)
{
	for(x=30;x<=65;x++)
	{
		flag=0;
		if(x>=49 && x<=56)
		{
			flag=1;
		}
		ASSERT_EQUAL(flag,Check_Ver(x));
	}
}

CTEST(Checking_Read, Check_Transform_test)
{
	for(x=50;x<=127;x++)
	{
		flag=0;
		if(Check_Massive(ch) && x!='P' && x!='K')
		{
			flag=1;
		}
		ASSERT_EQUAL(flag,Check_Transform(x));
	}
	x='P';
	ASSERT_EQUAL(0,Check_Transform(x));
	x='K';
	ASSERT_EQUAL(0,Check_Transform(x));
}

CTEST_SETUP(Checking_Move)
{
	int flag,i;
}

CTEST(Checking_Move, Check_Move_End_test)
{
	gor_begin=3;
	ver_begin=5;
	for(i=1,ver_end=ver_begin;i<=8;i++)
	{
		flag=1;
		gor_end=i;
		if(gor_end==gor_begin)
		{
			flag=0;
		}
		ASSERT_EQUAL(flag,Check_Move_End());
	}
	for(i=1,gor_end=gor_begin;i<=8;i++)
	{
		flag=1;
		ver_end=i;
		if(gor_end==gor_begin)
		{
			flag=0;
		}
		ASSERT_EQUAL(flag,Check_Move_End());
	}
}

CTEST(Checking_Move, Check_Move_Color_test)
{
	gor_begin=2;
	ver_begin=6;
	for(move=1;move<=2;move++)
	{
		flag=move%2;
		for(i=0;i<6;i++)
		{
			C[ver_begin][gor_begin]=Type_figure[i];
			ASSERT_EQUAL(flag,Check_Move_Color());
			C[ver_begin][gor_begin]+=32;
			ASSERT_NOT_EQUAL(flag,Check_Move_Color());
		}
	}
}


CTEST(Checking_Move, Check_Move_Begin_test)
{
	gor_begin=1;
	ver_begin=7;
	for(move=1;move<=2;move++)
	{
		C[ver_begin][gor_begin]=Type_figure[rand()%6]+32*((move+1)%2);
		for(i=0;i<6;i++)
		{
			letter_fig=Type_figure[i];
			if(letter_fig+32*((move+1)%2==C[ver_begin][gor_begin])
			{
				ASSERT_EQUAL(1,Check_Move_Begin());
			}
			else
			{
				ASSERT_NOT_EQUAL(1,Check_Move_Color());
			}
			
		}
	}
}


CTEST(Checking_Move, Attack_or_Not_test)
{
	gor_end=4;
	ver_end=4;
	move=2;
	C[ver_end][gor_end]='R';
	typ_move='-';
	ASSERT_EQUAL(8,Attack_or_Not());
	typ_move=':';
	ASSERT_EQUAL(1,Attack_or_Not());
	typ_move='x';
	ASSERT_EQUAL(1,Attack_or_Not());
	move=1;
	ASSERT_EQUAL(9,Attack_or_Not());
	C[ver_end][gor_end]=' ';
	ASSERT_EQUAL(10,Attack_or_Not());
	typ_move='-';
	ASSERT_EQUAL(1,Attack_or_Not());
	typ_move=';';
	ASSERT_EQUAL(0,Attack_or_Not());
}

CTEST(Checking_Move, Check_Pown_test)
{
	
}

CTEST(Checking_Move, Check_Rook_test)
{
	ver_begin=8;
	gor_begin=1;
	for(i=1;i<=8;i++)
	{
		ver_end=i;
		for(j=1;j<=8;j++)
		{
			gor_end=j;
			flag=0;
			if((gor_begin==gor_end) || (ver_begin==ver_end))
			{
				flag=1;
			}
			ASSERT_EQUAL(flag,Check_Rook());
		}
	}
}

CTEST(Checking_Move, Check_Knight_test)
{
	ver_begin=2;
	gor_begin=7;
	for(i=1;i<=8;i++)
	{
		ver_end=i;
		for(j=1;j<=8;j++)
		{
			gor_end=j;
			flag=0;
			if(( Module(ver_end-ver_begin)+ Module(gor_end-gor_begin) == 3) && (ver_end!=ver_begin) && (gor_end!=gor_begin))
			{
				flag=1;
			}
			ASSERT_EQUAL(flag,Check_Knight());
		}
	}
}

CTEST(Checking_Move, Check_Bishop_test)
{
	ver_begin=2;
	gor_begin=2;
	for(i=1;i<=8;i++)
	{
		ver_end=i;
		for(j=1;j<=8;j++)
		{
			gor_end=j;
			flag=0;
			if(Module(ver_end-ver_begin) == Module(gor_end-gor_begin))
			{
				flag=1;
			}
			ASSERT_EQUAL(flag,Check_Bishop());
		}
	}
}

CTEST(Checking_Move, Check_King_test)
{
	ver_begin=2;
	gor_begin=2;
	for(i=1;i<=8;i++)
	{
		ver_end=i;
		for(j=1;j<=8;j++)
		{
			gor_end=j;
			flag=0;
			if(( Module(ver_end-ver_begin) <= 1) && ( Module(gor_end-gor_begin) <= 1))
			{
				flag=1;
			}
			ASSERT_EQUAL(flag,Check_King());
		}
	}
}

CTEST(Checking_Move, Check_BNQ_test)
//I don't know how good write this test with help cycle for()
{
	Board_NULL(); 
	ver_begin=4;
	gor_begin=5;
	C[6][5]='p';
	C[4][3]='p';
	C[5][6]='p';
	C[2][7]='p';
	ver_end=7;
	gor_end=2;
	ASSERT_EQUAL(1,Check_BNQ());
	gor_end=5;
	ASSERT_NOT_EQUAL(1,Check_BNQ());
	gor_end=8;
	ASSERT_NOT_EQUAL(1,Check_BNQ());
	ver_end=1;
	ASSERT_NOT_EQUAL(1,Check_BNQ());
	gor_end=5;
	ASSERT_EQUAL(1,Check_BNQ());
	gor_end=2;
	ASSERT_EQUAL(1,Check_BNQ());
	ver_end=4;
	ASSERT_NOT_EQUAL(1,Check_BNQ());
	gor_end=8;
	ASSERT_EQUAL(1,Check_BNQ());
}

CTEST(Checking_Move, Check_Roki_test)
{
	for(i=0;i<4;i++)
	{
		flag=0;
		move_rook[i]=rand()%2;
		if(move_rook[i])
		{
			flag=1;
		}
		ASSERT_EQUAL(flag,Check_Roki(i));
	}
}

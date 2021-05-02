#include "Error_Message.h"
#include "Rules.h"
#include "stdlib.h"

extern int move, gor_begin, ver_begin, gor_end, ver_end, typ_roki, move_rook[];
extern char letter_fig, typ_move, transform, C[][9];

void Moving()
{
	int x=Attack_or_Not();
	if(x==1)
	{
		C[ver_end][gor_end]=letter_fig+32*((move+1)%2);
		C[ver_begin][gor_begin]=' ';
	}
	else
	{
		Error_Text(x);
	}
}

void Move_Pawn()
{
	int x=Check_Pown();
	if(x==1)
	{
		if(ver_end==8 || ver_end==1)
		{
			letter_fig=transform;
		}
		Moving();
	}
	else
	{
		Error_Text(x);
	}
} 

void Move_Rook()
{
	if(Check_Rook())
	{
		if(Check_BNQ()==0)
		{
			Error_Text(15);
		}
		Moving();
		if(ver_begin==8-7*(move%2))
		{
			if(gor_begin==1)
			{
				move_rook[3-2*(move%2)]=0;
			}
			else
			{
				if(gor_begin==8)
				{
					move_rook[4-2*(move%2)]=0;
				}
			}
		}
	}
	else
	{
		Error_Text(16);
	}
} 

void Move_Knight()
{
	if(Check_Knight())
	//Если расстояние от коня три клетки и начало и конец не находятся на одной линии
	{
		Moving();
	}
	else
	{
		Error_Text(16);
	}
} 

void Move_Bishop()
{
	if(Check_Bishop())
	{
		if(Check_BNQ()==0)
		{
			Error_Text(15);
		}
		Moving();
	}
	else
	{
		Error_Text(16);
	}
} 

void Move_Queen()
{
	if(Check_Rook() || Check_Bishop()) //Проверка на ход как ладья
	{
		if(Check_BNQ()==0)
		{
			Error_Text(15);
		}
		Moving();
	}
	else
	{
		Error_Text(16);
	}
} 

void Move_King()
{
	if(Check_King())
	{
		Moving();
		if(ver_begin==8-7*(move%2))
		{
			move_rook[3-2*(move%2)]=0;
			move_rook[4-2*(move%2)]=0;
		}
	}
	else
	{
		Error_Text(16);
	}
} 

void Move_Figure()
{
	switch(letter_fig)
	{
		case 'P':
			Move_Pawn();
			break;
		case 'R':
			Move_Rook();
			break;
		case 'N':
			Move_Knight();
			break;
		case 'B':
			Move_Bishop();
			break;
		case 'Q':
			Move_Queen();
			break;
		case 'K':
			Move_King();
			break;
		default:
			Error_Text(19);
	}
}

void Rokirovka() //Ошибся, рокировка, даже БЕЗ шаха, требуют много сравнений
{
	int left=(move%2); 
	char temp;
	ver_begin=8-7*left;
	gor_begin=5;
	ver_end=ver_begin;
	int border=3-2*left;
	letter_fig='K';
	typ_move='-';
	
	if(Check_Roki(border)) //Если король не двигался, то для левой или правой пары массива move_rook
	{
		gor_end=1+7*(typ_roki%2);
		if(Check_BNQ()==0)
		{
			Error_Text(15);
		}
		if(Check_Roki(border+(typ_roki%2)))
		{
			temp=gor_end;
			gor_end=gor_begin-(2-4*(typ_roki%2));
			Moving();
			gor_begin=temp;
			gor_end-=(gor_end-5)/2;
			letter_fig='R';
			Moving();
		}
		else
		{
			Error_Text(18);
		}
	}
	else
	{
		Error_Text(17);
	}
}

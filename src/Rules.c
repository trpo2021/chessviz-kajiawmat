#include<stdlib.h>
#include "Error_Message.h"

extern int move, gor_begin, ver_begin, gor_end, ver_end, move_rook[];
extern char letter_fig, typ_move, C[][9],last_cut;
extern char const Type_figure[], Sym_Ignore[];
extern const int Players, Ver_min, Gor_min, Reg;


int Module(int x)
{
	if(x<0)
	{
		x=-x;
	}
	return x;
}

int Check_Getc(char ch)
{
	int i;
	for(i=0;i<11;i++)
	{
		if(ch==Sym_Ignore[i])
		{
			return 0;
		}
	}
	return 1;
}

int Check_Massive(char ch)
{
	int i;
	for(i=0;i<6;i++)
	{
		if(ch==Type_figure[i])
		{
			return 1;
		}
	}
	return 0;
}

int Check_Gor(char ch)
{
	if(ch>=(Gor_min+1) && ch<=(Gor_min+9)) return 1;
	return 0;
}

int Check_Ver(char ch)
{
	if(ch>=(Ver_min+1) && ch<=(Ver_min+9)) return 1;
	return 0;
}

int Check_Move_End()
{
	if((gor_begin==gor_end)&&(ver_begin==ver_end)) return 0; //Негативное условие
	return 1;
}

int Check_Move_Color()
{
	if(((move % Players == 1)+(C[ver_begin][gor_begin]<=Gor_min))==1) return 0; //Выполняется только одно из условий
	return 1;
}

int Check_Move_Begin()
{
	if(C[ver_begin][gor_begin]==letter_fig+Reg*((move+1)%Players)) return 1;
	return 0;
}

int Check_Transform(char ch)
{
	if(Check_Massive(ch) && ch!=Type_figure[0] && ch!=Type_figure[5])
	{
		return 1;
	}
	return 0;
}

int Attack_or_Not()
{
	if(typ_move=='-')
	{
		if(C[ver_end][gor_end]==' ')
		{
			return 1;
		}
		else
		{
			return 8;
		}
	}
	if((typ_move==':') || (typ_move=='x'))
	{
		if(C[ver_end][gor_end]!=' ')
		{
			if(((move % Players == 1)+(C[ver_end][gor_end]<=Gor_min))==1) 
			//Первое выражение возвращает 1 если белых ход, второе -- 1 если белая фигура (принцип исключающего ИЛИ (XOR))
			{
				last_cut=C[ver_end][gor_end];
				return 1;
			}
			else
			{
				return 9;
			}
		}
		else
		{
			return 10;
		}
	}
	return 0;
}

int Check_Pown() //К удивлению самая сложная проверка
{
	int distance=-1+2*(move%Players);
	int dif_ver=ver_end-ver_begin;
	if(typ_move=='-')
	{
		if(gor_begin==gor_end)
		{
			if(ver_begin==2 || ver_begin==7)
			{
				distance*=2;
			}
			if((dif_ver==distance) || (dif_ver==distance/2))
			{
				return 1;
			}
			else
			{
				return 11;
			}
		}
		else
		{
			return 12;
		}
	}
	if(((typ_move==':') || (typ_move=='x')) && (Module(gor_begin-gor_end)==1))
	{
		if(dif_ver==distance)
		{
			return 1;
		}
		else
		{
			return 13;
		}
	}
	else
	{
		return 14;
	}
}

int Check_Rook()
{
	if((gor_begin==gor_end) || (ver_begin==ver_end))
	{
		return 1;
	}
	return 0;
}

int Check_Knight()
{
	if(( Module(ver_end-ver_begin)+ Module(gor_end-gor_begin) == 3) && (ver_end!=ver_begin) && (gor_end!=gor_begin))
	{
		return 1;
	}
	return 0;
}

int Check_Bishop()
{
	if( Module(ver_end-ver_begin) == Module(gor_end-gor_begin))
	{
		return 1;
	}
	return 0;
}

int Check_King()
{
	if(( Module(ver_end-ver_begin) <= 1) && ( Module(gor_end-gor_begin) <= 1))
	{
		return 1;
	}
	return 0;
}

int Check_BNQ()
{
	int i,j, dif_i=0,dif_j=0;
	i=ver_begin;
	j=gor_begin;
	if(ver_end-i)
	{
		dif_i=(ver_end-i)/Module(ver_end-i);
	}
	if(gor_end-j)
	{
		dif_j=(gor_end-j)/Module(gor_end-j);
	}
	i+=dif_i;
	j+=dif_j;
	while((i!=ver_end)||(j!=gor_end))
	{
		if(C[i][j]!=' ')
		{
			return 0;
		}
		i+=dif_i;
		j+=dif_j;
	}
	return 1;
}

int Check_Roki(int x)
{
	if(move_rook[x])
	{
		return 1;
	}
	return 0;
}

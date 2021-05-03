#include<stdlib.h>
#include<stdio.h>
#include "Error_Message.h"
#include "Rules.h"



extern int move, gor_begin, ver_begin, gor_end, ver_end, typ_roki;
extern char letter_fig, typ_move, transform, last_cut, C[][9]; 
extern const char Type_figure[];


char Search_Read(FILE *f1,char ch)
{
	while(Check_Getc(ch)!=1) //Поиск нормального символа
	{
		ch=getc(f1);
	}
	return ch;
}

void Move_input(FILE *f1,char ch)
{
	int move_input=0;
	while(Check_Getc(ch))
	{
		move_input=move_input*10+ch-48;
		ch=getc(f1);
	}
	if(move_input!=(move / 2)+(move % 2))
	{
		printf("\n--------------");
		printf("\nНаписан ход %i",move_input);
		printf("\n--------------");
		system("pause");
		Error_Text(2);
	}
}

void Move_Read(FILE *f1, char ch)
{
	transform=0;
	last_cut=0;
	if(Check_Gor(ch))
	{
		letter_fig=Type_figure[0];
	}
	else
	{
		if(Check_Massive(ch))
		{
			letter_fig=ch;
			ch=getc(f1);
		}
		else
		{
			Error_Text(3);
		}
	}
	
	ch=Search_Read(f1,ch);
	if(Check_Gor(ch))
	{
		gor_begin=ch-96;
		ch=getc(f1);
	}
	else
	{
		Error_Text(3);
	}
	
	ch=Search_Read(f1,ch);
	if(Check_Ver(ch))
	{
		ver_begin=ch-48;
		ch=getc(f1);
	}
	else
	{
		Error_Text(3);
	}
	
	ch=Search_Read(f1,ch);
	if(ch=='-' || ch=='x' || ch==':')
	{
		typ_move=ch;
		ch=getc(f1);
	}
	else
	{
		Error_Text(3);
	}
	
	ch=Search_Read(f1,ch);
	if(Check_Gor(ch))
	{
		gor_end=ch-96;
		ch=getc(f1);
	}
	else
	{
		Error_Text(3);
	}
	
	ch=Search_Read(f1,ch);
	if(Check_Ver(ch))
	{
		ver_end=ch-48;
		ch=getc(f1);
	}
	else
	{
		Error_Text(3);
	}
	//Проверка на логическую корректность ходов
	if(Check_Move_End()==0)
	{
		Error_Text(4);
	}
	
	if(Check_Move_Color()==0)
	{
		Error_Text(5);
	}
	
	if(Check_Move_Begin()==0)
	{
		Error_Text(6);
	}
	
	//Заготовка для превлащения
	if(letter_fig=='P' && (ver_end==1 || ver_end==8))
	{
		ch=Search_Read(f1,ch);
		if(Check_Transform(ch))
		{
			transform=ch;
		}
		else
		{
			Error_Text(20);
		}
	}
}

void Roki_Read(FILE *f1, char ch)
{
	ch=getc(f1);
	ch=Search_Read(f1,ch);
	while(ch=='-')
	{
		ch=getc(f1);
		ch=Search_Read(f1,ch);
		if(ch=='O')
		{
			typ_roki++;
			ch=getc(f1);
		}
		else
		{
			Error_Text(3);
		}
	}
	if(typ_roki==0 || typ_roki>2)
	{
		Error_Text(7);
	}
}

void Move_Write()
{
	printf("\nХод №%i за ",move/2+move % 2);
	if(move % 2)
	{
		printf("белых: ");
	}
	else
	{
		printf("чёрных: ");
	}
	if(letter_fig!='P')
	{
		printf("%c",letter_fig);
	}
	printf("%c%c%c%c%c",gor_begin+96, ver_begin+48, typ_move, gor_end+96, ver_end+48);
	if((typ_move==':') || (typ_move=='x'))
	{
		printf("\nВзята фигура %c на поле %c%c",C[ver_end][gor_end],gor_end+96, ver_end+48);
	}
	else
	{
		printf("\n");
	}
	if(transform)
	{
		printf("\nПешка %c%c попала на поле %c%c и стала %c",gor_begin+96, ver_begin+48,gor_end+96, ver_end+48,transform);
	}
	else
	{
		printf("\n");
	}
	printf("\n");
	printf("\n");
}

void Roki_Write()
{
	int i=0;
	printf("\nХод №%i за ",move/2+move % 2);
	if(move % 2)
	{
		printf("белых: ");
	}
	else
	{
		printf("чёрных: ");
	}
	printf("O");
	while(i<typ_roki)
	{
		printf("-O");
		i++;
	}
	printf("\n\n\n\n");
}

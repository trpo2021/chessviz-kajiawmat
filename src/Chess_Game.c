#include<stdio.h>
#include<stdlib.h>
#include "Board.h"
#include "IO.h"
#include "Moving.h"
#include "Rules.h"

extern int typ_roki, move;

void Chess_Game(FILE *f1)
{
	char ch;
	Board_Init();
	while((ch=getc(f1))!=EOF)
	{
		ch=Search_Read(f1,ch);	
		
		if(ch>=48 && ch<=57)  //48 и 57 -- символьные коды цифр '0' и '9'
		{
			Move_input(f1,ch);
		}
		
		if(Check_Massive(ch) || Check_Gor(ch))
		{
			Move_Read(f1,ch);
			system("CLS");
			Move_Write();
			Move_Figure();
			Board();
			system("Pause");
			move++;
		}
		
		if(ch=='O')
		{
			typ_roki=0;
			Roki_Read(f1,ch);
			system("CLS");
			Roki_Write();
			Rokirovka();
			Board();
			system("Pause");
			move++;
		}
	}
	printf("\n\nИгра окончена!!!\n");
	system("Pause");
}

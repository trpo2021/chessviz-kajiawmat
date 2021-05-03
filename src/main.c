#include<stdio.h>
#include<stdlib.h>
#include"Chess_Game.h"
#include"Error_Message.h"


const char Type_figure[6]={'P','R','N','B','Q','K'};
char C[9][9];

int ver_begin=0, gor_begin=0, ver_end=0, gor_end=0, move=1;
char letter_fig=0, typ_move=0, transform=0, last_cut=0;
int typ_roki=0, move_rook[4]={1,1,1,1};

int main()
{
	FILE *f1;
	system("chcp 1251>nul");
	f1=fopen("res//Chess_Game.txt","r");
	if(f1== NULL)
	{
		Error_Text(1);
	}
	Chess_Game(f1);
	return 0;
}


#include<stdlib.h>
#include<stdio.h>
#include "IO.h"
#include "Board.h"
extern int move, gor_begin, ver_begin, gor_end, ver_end;
extern char letter_fig, C[][9];
extern const int Players, Ver_min, Gor_min, Reg;


void Error_Move()
{
	printf("\n������ ��� �%i �� ",move/Players + move%Players);
	if(move % Players)
	{
		printf("�����, ");
	}
	else
	{
		printf("������, ");
	}
}

void Error_Text(int i)
{
	system("CLS");
	printf("������ �%i\n",i);
	switch(i)
	{
		case 1:
			printf("� ���������, ������� �������� ���� ����, �� ��������������� ���������.");
			break;
			
		case 2:
			printf("����� ���� ������ �� �����");
			Error_Move();
			break;
			
		case 3:
			Error_Move();
			printf("\n������ ����� ������ ����.");
			break;
			
		case 4:
			Move_Write();
			printf("\n������ �� ����� �������� �� ��� �� ����.");
			break;
			
		case 5:
			Move_Write();
			printf("\n������ ��� ������� �����, ��� ��� �������� ������� ������� �����.");
			break;
			
			
		case 6:
			Move_Write();
			printf("�� ���� %c%c ������ %c �� �����.",gor_begin+Gor_min,ver_begin+Ver_min,letter_fig+Reg*((move+1)%Players));
			break;

		case 7:
			Error_Move();
			printf("����������� �������� ���������: ��������� ��� �������� ���������� �������� \'-O\'.");
			break;
			
		case 8:
			Move_Write();
			printf("\n������ �� ����� ������ �� ������� ������� %c ���� %c%c.",C[ver_end][gor_end],gor_end+Gor_min,ver_end+Ver_min);
			break;
			
		case 9:
			Move_Write();
			printf("\n������ �� ����� ������� ������ %c �� ���� %c%c, ��� ��� ��� ������ �����.",C[ver_end][gor_end],gor_end+Gor_min,ver_end+Ver_min);
			break;
			
		case 10:
			Move_Write();
			printf("\n������ �� ����� ������� ������ �� ���� %c%c, ��� ��� �� ���� ���� ��� ������.",gor_end+Gor_min,ver_end+Ver_min);
			break;
			
		case 11:
			Move_Write();
			printf("����� �� ���� %c%c ����� ���� ������ �� 1 ������ �����, ��� �� 2 ������ �����, ���� ��� � �������������� �������",gor_begin+Gor_min,ver_begin+Ver_min);
			break;
			
		case 12:
			Move_Write();
			printf("����� �� ���� %c%c ����� ������ ������ ����� ����� ���������",gor_begin+Gor_min,ver_begin+Ver_min);
			break;
			
		case 13:
			Move_Write();
			printf("����� �� ���� %c%c ����� ������ ������ ����� ��������� �� ���� ������ ����� �����",gor_begin+Gor_min,ver_begin+Ver_min);
			break;
			
		case 14:
			Move_Write();
			printf("����� �� ���� %c%c ����� ������ ������ ������ �� �������� ����������",gor_begin+Gor_min,ver_begin+Ver_min);
			break;
			
		case 15:
			Move_Write();
			printf("������ %c �� ����� ������������ ����� ������", letter_fig);
			break;
			
		case 16:
			Move_Write();
			printf("������ %c � ���� %c%c �� ����� ����� �� ���� %c%c.",letter_fig,gor_begin+Gor_min,ver_begin+Ver_min,gor_end+Gor_min,ver_end+Ver_min);
			break;
			
		case 17:
			Roki_Write();
			printf("\n������ ��� ������������ ����� ��� ������ � ���� ������.");
			break;
			
		case 18:
			Roki_Write();
			printf("\n������������ ����� ��� ������ � ���� ������.");
			break;
			
		case 19:
			Move_Write();
			printf("����� ������ �������� ����� ����� ��� ������.");
			break;
			
		case 20:
			Move_Write();
			printf("��������� �� ������� � ����� ������ ������������ �����, ����� ����� �� ���� %c%c.",gor_end+Gor_min,ver_end+Ver_min);
			break;
			
		default:
			printf("� �� ���� ������ ������");
	}
	printf("\n��������� ������ � ���������� �����!\n");
	if(i!=1)
	{
		Board();
	}
	system("pause>nul");
	exit(1);
}

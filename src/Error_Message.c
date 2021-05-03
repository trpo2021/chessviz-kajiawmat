#include<stdlib.h>
#include<stdio.h>
#include "IO.h"
#include "Board.h"
extern int move, gor_begin, ver_begin, gor_end, ver_end;
extern char letter_fig, C[][9];


void Error_Move()
{
	printf("\n������ ��� �%i �� ",move/2+move % 2);
	if(move % 2)
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
			printf("�� ���� %c%c ������ %c �� �����.",gor_begin+96,ver_begin+48,letter_fig+32*((move+1)%2));
			break;

		case 7:
			Error_Move();
			printf("����������� �������� ���������: ��������� ��� �������� ���������� �������� \'-O\'.");
			break;
			
		case 8:
			Move_Write();
			printf("\n������ �� ����� ������ �� ������� ������� %c ���� %c%c.",C[ver_end][gor_end],gor_end+96,ver_end+48);
			break;
			
		case 9:
			Move_Write();
			printf("\n������ �� ����� ������� ������ %c �� ���� %c%c, ��� ��� ��� ������ �����.",C[ver_end][gor_end],gor_end+96,ver_end+48);
			break;
			
		case 10:
			Move_Write();
			printf("\n������ �� ����� ������� ������ �� ���� %c%c, ��� ��� �� ���� ���� ��� ������.",gor_end+96,ver_end+48);
			break;
			
		case 11:
			Move_Write();
			printf("����� �� ���� %c%c ����� ���� ������ �� 1 ������ �����, ��� �� 2 ������ �����, ���� ��� � �������������� �������",gor_begin+96,ver_begin+48);
			break;
			
		case 12:
			Move_Write();
			printf("����� �� ���� %c%c ����� ������ ������ ����� ����� ���������",gor_begin+96,ver_begin+48);
			break;
			
		case 13:
			Move_Write();
			printf("����� �� ���� %c%c ����� ������ ������ ����� ��������� �� ���� ������ ����� �����",gor_begin+96,ver_begin+48);
			break;
			
		case 14:
			Move_Write();
			printf("����� �� ���� %c%c ����� ������ ������ ������ �� �������� ����������",gor_begin+96,ver_begin+48);
			break;
			
		case 15:
			Move_Write();
			printf("������ %c �� ����� ������������ ����� ������", letter_fig);
			break;
			
		case 16:
			Move_Write();
			printf("������ %c � ���� %c%c �� ����� ����� �� ���� %c%c.",letter_fig,gor_begin+96,ver_begin+48,gor_end+96,ver_end+48);
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
			printf("��������� �� ������� � ����� ������ ������������ �����, ����� ����� �� ���� %c%c.",gor_end+96,ver_end+48);
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

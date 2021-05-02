#include<stdlib.h>
#include<stdio.h>

extern char Type_figure[], C[][9];

void Board_Init()
{
	int i,j;
	C[0][0]=' ';
	for(i=1;i<=8;i++)
	{
		C[i][0]=i+48;
		C[0][i]=i+96;
		C[2][i]=Type_figure[0];
		C[7][i]=Type_figure[0]+32;
		for(j=3;j<=6;j++)
		{
			C[j][i]=' ';
		}
	}
	for(j=1;j<=5;j++)
	{
		C[1][j]=Type_figure[j];
		C[8][j]=Type_figure[j]+32;
	}
	for(j=6;j<=8;j++)
	{
		C[1][j]=Type_figure[9-j];
		C[8][j]=Type_figure[9-j]+32;
	}
	
}

void Board()
{
	int i,j;
	for(i=8;i>=1;i--)
	{
		printf("\n%c  ",C[i][0]);
		for(j=1;j<=8;j++)
		{
			printf("%2c",C[i][j]);
		}
	}
	printf("\n");
	printf("\n%c  ",C[0][0]);
	for(j=1;j<=8;j++)
	{
		printf("%2c",C[0][j]);
	}
	printf("\n");
}

void Board_NULL()
{
	int i,j;
	for(i=1;i<=8;i++)
	{
		for(j=1;j<=8;j++)
		{
			C[j][i]=' ';
		}
	}
}

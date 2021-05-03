#include "ctest.h"
#include<stdlib.h>
#include<stdio.h>

CTEST(open_file, test1)
{
	FILE *ft;
	int open=0;
	ft=fopen("res//Chess_Game.txt","r");
	if(ft) open=1;
	ASSERT_EQUAL(1,open);
	fclose(ft);
}

CTEST(open_file, test2)
{
	FILE *ft;
	int open=0;
	ft=fopen("res//Chess_Game_test.txt","r");
	if(ft) open=1;
	ASSERT_EQUAL(1,open);
	fclose(ft);
}


#include "ctest.h"
#include<stdlib.h>
#include<stdio.h>

CTEST_SETUP(open_file)
{
	FILE *ft;
	int open=0;
}

CTEST_TEARDOWN(open_file)
{
	fclose(ft);
	ft=NULL;
}

CTEST(open_file, test1)
{
	ft=fopen("res//Chess_Game.txt","r");
	if(ft!=NULL) open=1;
	ASSERT_EQUAL(1,open);
}

CTEST(open_file, test2)
{
	ft=fopen("res//test_game//Chess_Game_test.txt","r");
	if(ft!=NULL) open=1;
	ASSERT_EQUAL(1,open);
}

CTEST(open_file, test3)
{
	ft=fopen("res//test_game//Number_test.txt","r");
	if(ft!=NULL) open=1;
	ASSERT_EQUAL(1,open);
}

CTEST(open_file, test4)
{
	ft=fopen("res//test_game//Move_test.txt","r");
	if(ft!=NULL) open=1;
	ASSERT_EQUAL(1,open);
}

CTEST(open_file, test5)
{
	ft=fopen("res//test_game//Rokirovka_test.txt","r");
	if(ft!=NULL) open=1;
	ASSERT_EQUAL(1,open);
}

CTEST(open_file, test6)
{
	ft=fopen("res//test_game//Ignore_test.txt","r");
	if(ft!=NULL) open=1;
	ASSERT_EQUAL(1,open);
}

CTEST(open_file, test7)
{
	ft=fopen("res//test_game//Moving_test.txt","r");
	if(ft!=NULL) open=1;
	ASSERT_EQUAL(1,open);
}

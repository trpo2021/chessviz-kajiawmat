

#include <stdio.h>

#include "ctest.h"

CTEST(open_file, test1)
{
    FILE* ft;
    int open = 0;
    ft = fopen("bin/res/Chess_Game.txt", "r");
    if (ft != NULL)
        open = 1;
    ASSERT_EQUAL(1, open);
    fclose(ft);
}

CTEST(open_file, test2)
{
    FILE* ft;
    int open = 0;
    ft = fopen("res/test_game/Chess_Game_test.txt", "r");
    if (ft != NULL)
        open = 1;
    ASSERT_EQUAL(1, open);
    fclose(ft);
}

CTEST(open_file, test3)
{
    FILE* ft;
    int open = 0;
    ft = fopen("res/test_game/Number_test.txt", "r");
    if (ft != NULL)
        open = 1;
    ASSERT_EQUAL(1, open);
    fclose(ft);
}

CTEST(open_file, test4)
{
    FILE* ft;
    int open = 0;
    ft = fopen("res/test_game/Move_test.txt", "r");
    if (ft != NULL)
        open = 1;
    ASSERT_EQUAL(1, open);
    fclose(ft);
}

CTEST(open_file, test5)
{
    FILE* ft;
    int open = 0;
    ft = fopen("res/test_game/Rokirovka_test.txt", "r");
    if (ft != NULL)
        open = 1;
    ASSERT_EQUAL(1, open);
    fclose(ft);
}

CTEST(open_file, test6)
{
    FILE* ft;
    int open = 0;
    ft = fopen("res/test_game/Ignore_test.txt", "r");
    if (ft != NULL)
        open = 1;
    ASSERT_EQUAL(1, open);
    fclose(ft);
}

CTEST(open_file, test7)
{
    FILE* ft;
    int open = 0;
    ft = fopen("res/test_game/Moving_test.txt", "r");
    if (ft != NULL)
        open = 1;
    ASSERT_EQUAL(1, open);
    fclose(ft);
}

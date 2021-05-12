#include <stdlib.h>

#include <stdio.h>

#include "libchessviz/Board.h"

#include "ctest.h"

#include "libchessviz/Chess_Game.h"

#include "libchessviz/IO.h"

extern int move, gor_begin, ver_begin, gor_end, ver_end, typ_roki, move_rook[];
extern char letter_fig, typ_move, transform, last_cut, C[][9];
extern const char Type_figure[];

CTEST(Ignore, Search_Read_test)
{
    FILE* ft;
    ft = fopen("res/test_game/Ignore_test.txt", "r");
    if (ft == NULL) {
        CTEST_ERR("FILE is not open. Please repair and try again!!!");
        ASSERT_FAIL();
    }
    char ch;
    int flag = 0;
    ch = getc(ft);
    flag = 0;
    ch = Search_Read(ft, ch);
    if (ch == 'B') {
        flag = 1;
    }
    ASSERT_EQUAL(1, flag);
    fclose(ft);
    ft = NULL;
}

CTEST(Read_number, Move_input_test)
{
    FILE* ft;
    ft = fopen("res/test_game/Number_test.txt", "r");
    if (ft == NULL) {
        CTEST_ERR("FILE is not open. Please repair and try again!!!");
        ASSERT_FAIL();
    }
    char ch;
    ch = getc(ft);
    move = 57 * 2 - 1;
    Move_input(ft, ch);
    ASSERT_EQUAL(1, 1);
    fclose(ft);
    ft = NULL;
}

CTEST(Read_Move, Move_Read_test)
{
    FILE* ft;
    ft = fopen("res/test_game/Move_test.txt", "r");
    if (ft == NULL) {
        CTEST_ERR("FILE is not open. Please repair and try again!!!");
        ASSERT_FAIL();
    }
    char ch;
    Board_NULL();
    Game_Init();
    C[2][5] = 'P';
    C[5][4] = 'b';
    C[7][6] = 'P';
    int flag = 0;
    ch = getc(ft);
    Move_Read(ft, ch);
    if (letter_fig == 'P' && ver_begin == 2 && gor_begin == 5 && typ_move == '-'
        && ver_end == 4 && gor_end == 5) {
        flag = 1;
        move++;
    }
    ASSERT_EQUAL(1, flag);
    flag = 0;
    ch = getc(ft);
    Move_Read(ft, ch);
    if (letter_fig == 'B' && ver_begin == 5 && gor_begin == 4
        && (typ_move == ':' || typ_move == 'x') && ver_end == 4
        && gor_end == 5) {
        flag = 1;
        move++;
    }
    ASSERT_EQUAL(1, flag);
    flag = 0;
    ch = getc(ft);
    Move_Read(ft, ch);
    if (letter_fig == 'P' && ver_begin == 7 && gor_begin == 6 && typ_move == '-'
        && ver_end == 8 && gor_end == 6 && transform == 'N') {
        flag = 1;
        move++;
    }
    ASSERT_EQUAL(1, flag);
    fclose(ft);
    ft = NULL;
}

CTEST(Read_Rokirovka, Roki_Read_test)
{
    FILE* ft;
    ft = fopen("res/test_game/Rokirovka_test.txt", "r");
    if (ft == NULL) {
        CTEST_ERR("FILE is not open. Please repair and try again!!!");
        ASSERT_FAIL();
    }
    char ch;
    int i;
    for (i = 0; i < 4; i++) {
        ch = getc(ft);
        Roki_Read(ft, ch);
        ASSERT_EQUAL(1, 1);
    }
    fclose(ft);
    ft = NULL;
}

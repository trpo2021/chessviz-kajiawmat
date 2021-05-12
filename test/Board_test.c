#include <stdlib.h>

#include <stdio.h>

#include <ctest.h>

#include "libchessviz/Board.h"

extern char Type_figure[], C[][9];
extern const int Ver_min, Gor_min, Reg;

CTEST(Board, test_Init_1)
{
    Board_Init();
    int i;
    for (i = 1; i <= 8; i++) {
        ASSERT_EQUAL(i + Ver_min, C[i][0]);
        ASSERT_EQUAL(i + Gor_min, C[0][i]);
    }
}

CTEST(Board, test_Init_2)
{
    Board_Init();
    int i, j;
    for (i = 1; i <= 8; i++) {
        for (j = 3; j <= 6; j++) {
            ASSERT_EQUAL(' ', C[j][i]);
        }
    }
}

CTEST(Board, test_Init_3)
{
    Board_Init();
    int i;
    for (i = 1; i <= 8; i++) {
        ASSERT_EQUAL('P', C[2][i]);
        ASSERT_EQUAL('p', C[7][i]);
    }
    C[2][5] = Type_figure[0] + Reg;
    C[7][2] = Type_figure[0];
    ASSERT_NOT_EQUAL('P', C[2][5]);
    ASSERT_NOT_EQUAL('p', C[7][2]);
}

CTEST(Board, test_Init_4)
{
    Board_Init();
    int j;
    for (j = 1; j <= 5; j++) {
        ASSERT_EQUAL(Type_figure[j], C[1][j]);
        ASSERT_EQUAL(Type_figure[j] + Reg, C[8][j]);
    }
    for (j = 6; j <= 8; j++) {
        ASSERT_EQUAL(Type_figure[9 - j], C[1][j]);
        ASSERT_EQUAL(Type_figure[9 - j] + Reg, C[8][j]);
    }
    C[1][2] = 'n';
    C[8][6] = 'R';
    ASSERT_NOT_EQUAL(Type_figure[2], C[1][2]);
    ASSERT_NOT_EQUAL(Type_figure[9 - 6] + Reg, C[8][6]);
}

CTEST(Board, test_Null_1)
{
    Board_NULL();
    int i, j;
    for (i = 1; i <= 8; i++) {
        for (j = 1; j <= 8; j++) {
            ASSERT_EQUAL(' ', C[j][i]);
        }
    }
}

CTEST(Board, test_NULL_2)
{
    Board_Init();
    int i;
    for (i = 1; i <= 8; i++) {
        ASSERT_EQUAL(i + Ver_min, C[i][0]);
        ASSERT_EQUAL(i + Gor_min, C[0][i]);
    }
}

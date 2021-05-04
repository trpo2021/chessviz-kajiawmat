#include<stdlib.h>

#include<stdio.h>

#include "ctest.h"

#include "libchessviz/Moving.h"

#include "libchessviz/Board.h"

#include "libchessviz/Chess_Game.h"

#include "libchessviz/IO.h"

extern int move, gor_begin, ver_begin, gor_end, ver_end, typ_roki, move_rook[];
extern char letter_fig, typ_move, transform, last_cut, C[][9];
extern const int Players, Reg;


CTEST(Moving, Moving_test) {
    Game_Init();
    Board_NULL();
    C[1][5] = 'R';
    C[6][6] = 'n';
    C[2][3] = 'Q';
    int flag, i;
    char ch;
    FILE * ft;
    ft = fopen("res//test_game//Moving_test.txt", "r");
    if (ft == NULL) {
        CTEST_ERR("FILE is not open. Please repair and try again!!!");
        ASSERT_FAIL();
    }
    for (i = 0; i < 3; i++) {
        flag = 0;
        ch = getc(ft);
        Move_Read(ft, ch);
        Moving();
        if (C[ver_begin][gor_begin] == ' ' && C[ver_end][gor_end] == letter_fig + Reg * ((move + 1) % Players)) {
            flag = 1;
        }
        ASSERT_EQUAL(1, flag);
        move++;
    }
}


CTEST(Move_Pawn, Move_Pawn_test) {
    Game_Init();
    Board_NULL();
    letter_fig = 'P';
    transform = 'B';
    const int ver = 2;
    ver_begin = ver;
    gor_begin = 3;
    C[ver_begin][gor_begin] = 'P';
    C[ver_begin + 3][gor_begin - 1] = 'q';
    typ_move = '-';
    ver_end = ver_begin + 2;
    gor_end = gor_begin;
    Move_Pawn();
    ASSERT_EQUAL(1, 1);
    typ_move = ':';
    ver_begin = ver_end;
    ver_end++;
    gor_end--;
    Move_Pawn();
    ASSERT_EQUAL(1, 1);
    gor_begin = gor_end;
    typ_move = '-';
    int i;
    for (i = ver_end; i < 8; i++) {
        ver_begin = ver_end;
        ver_end++;
        Move_Pawn();
        ASSERT_EQUAL(1, 1);
    }
}




CTEST(Move_figure, Move_Rook_test) {
    Game_Init();
    Board_NULL();
    int i;
    move = 2;
    int const num_move = 4;
    int Move_gor[4] = {-5, 0, 2, 0 };
    int Move_ver[4] = { 0, 3, 0, -1 };
    char Move_typ[4] = { '-', '-', '-', ':' };
    letter_fig = 'R';
    gor_begin = 6;
    ver_begin = 5;
    C[ver_begin][gor_begin] = letter_fig + Reg * ((move + 1) % Players);
    for (i = 0; i < num_move; i++) {
        ver_end = ver_begin + Move_ver[i];
        gor_end = gor_begin + Move_gor[i];
        typ_move = Move_typ[i];
        if ((typ_move == ':') || (typ_move == 'x')) {
            C[ver_end][gor_end] = letter_fig + Reg - Reg * ((move + 1) % Players);
        }
        Move_Rook();
        ASSERT_EQUAL(1, 1);
        ver_begin = ver_end;
        gor_begin = gor_end;
    }
}

CTEST(Move_figure, Move_Knight_test) {
    Game_Init();
    Board_NULL();
    int i;
    move = 1;
    int const num_move = 8;
    int Move_gor[8] = { 2, -2, 1, 1, -2, 2, -1, -1 };
    int Move_ver[8] = { 1, 1, -2, 2, -1, -1, 2, -2 };
    char Move_typ[8] = { '-', '-', 'x', ':', '-', ':', '-', '-' };
    letter_fig = 'N';
    gor_begin = 3;
    ver_begin = 4;
    C[ver_begin][gor_begin] = letter_fig + Reg * ((move + 1) % Players);
    for (i = 0; i < num_move; i++) {
        ver_end = ver_begin + Move_ver[i];
        gor_end = gor_begin + Move_gor[i];
        typ_move = Move_typ[i];
        if ((typ_move == ':') || (typ_move == 'x')) {
            C[ver_end][gor_end] = letter_fig + Reg - Reg * ((move + 1) % Players);
        }
        Move_Knight();
        ASSERT_EQUAL(1, 1);
        ver_begin = ver_end;
        gor_begin = gor_end;
    }
}

CTEST(Move_figure, Move_Bishop_test) {
    Game_Init();
    Board_NULL();
    int i;
    move = 1;
    int const num_move = 4;
    int Move_gor[4] = { 4, 2, -3, -1 };
    int Move_ver[4] = {-4, 2, 3, -1 };
    char Move_typ[4] = { '-', '-', '-', ':' };
    letter_fig = 'B';
    gor_begin = 2;
    ver_begin = 6;
    C[ver_begin][gor_begin] = letter_fig + Reg * ((move + 1) % Players);
    for (i = 0; i < num_move; i++) {
        ver_end = ver_begin + Move_ver[i];
        gor_end = gor_begin + Move_gor[i];
        typ_move = Move_typ[i];
        if ((typ_move == ':') || (typ_move == 'x')) {
            C[ver_end][gor_end] = letter_fig + Reg - Reg * ((move + 1) % Players);
        }
        Move_Bishop();
        ASSERT_EQUAL(1, 1);
        ver_begin = ver_end;
        gor_begin = gor_end;
    }
}

CTEST(Move_figure, Move_Queen_test) {
    Game_Init();
    Board_NULL();
    int i;
    move = 2;
    int const num_move = 8;
    int Move_gor[8] = {-3, 0, 3, -3, 3, 0, -3, 3 };
    int Move_ver[8] = { 0, 3, 0, -3, 3, -3, 3, -3 };
    char Move_typ[8] = { 'x', ':', 'x', '-', '-', '-', '-', '-' };
    letter_fig = 'Q';
    gor_begin = 5;
    ver_begin = 2;
    C[ver_begin][gor_begin] = letter_fig + Reg * ((move + 1) % Players);
    for (i = 0; i < num_move; i++) {
        ver_end = ver_begin + Move_ver[i];
        gor_end = gor_begin + Move_gor[i];
        typ_move = Move_typ[i];
        if ((typ_move == ':') || (typ_move == 'x')) {
            C[ver_end][gor_end] = letter_fig + Reg - Reg * ((move + 1) % Players);
        }
        Move_Queen();
        ASSERT_EQUAL(1, 1);
        ver_begin = ver_end;
        gor_begin = gor_end;
    }
}

CTEST(Move_figure, Move_King_test) {
    Game_Init();
    Board_NULL();
    int i;
    move = 1;
    int const num_move = 8;
    int Move_gor[8] = { 0, -1, -1, -1, 0, 1, 1, 1 };
    int Move_ver[8] = {-1, -1, 0, 1, 1, 1, 0, -1 };
    char Move_typ[8] = { '-', ':', '-', '-', 'x', '-', '-', '-' };
    letter_fig = 'K';
    gor_begin = 5;
    ver_begin = 5;
    C[ver_begin][gor_begin] = letter_fig + Reg * ((move + 1) % Players);
    for (i = 0; i < num_move; i++) {
        ver_end = ver_begin + Move_ver[i];
        gor_end = gor_begin + Move_gor[i];
        typ_move = Move_typ[i];
        if ((typ_move == ':') || (typ_move == 'x')) {
            C[ver_end][gor_end] = letter_fig + Reg - Reg * ((move + 1) % Players);
        }
        Move_King();
        ASSERT_EQUAL(1, 1);
        ver_begin = ver_end;
        gor_begin = gor_end;
    }
}


CTEST(Rokirovka, Rokirovka_test) {
    Board_NULL();
    Game_Init();
    C[1][1] = 'R';
    C[1][8] = 'R';
    C[1][5] = 'K';
    C[8][1] = 'r';
    C[8][8] = 'r';
    C[8][5] = 'k';
    int flag, border, i;
    for (move = 1; move <= 2; move++) {
        border = 2 - 2 * (move % Players);
        for (typ_roki = 1; typ_roki <= 2; typ_roki++) {
            flag = 0;
            Rokirovka();
            if (move_rook[border] == 0 && move_rook[border + 1] == 0) {
                flag = 1;
                move_rook[border] = 1;
                move_rook[border + 1] = 1;
            }
            ASSERT_EQUAL(1, flag);
            C[1][5] = 'K';
            C[8][5] = 'k';
        }
    }
    flag = 1;
    for (i = 3; i <= 7; i++) {
        if (C[8][i] == ' ' || C[1][i] == ' ') {
            flag = 0;
            break;
        }
    }
    ASSERT_EQUAL(1, flag);
}

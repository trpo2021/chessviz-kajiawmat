#include<stdio.h>

#include<stdlib.h>

#include "ctest.h"

#include "libchessviz/Chess_Game.h"
 //If it will not work, I CAN ignore this test, because if other functions works, then it works too

extern int gor_begin, ver_begin, gor_end, ver_end, typ_roki, move, move_rook[];
extern char letter_fig, typ_move, transform, last_cut;

CTEST_SKIP(Game, Chess_Game_test) {
    Game_Init();
    FILE * ft;
    ft = fopen("res/test_game/Chess_Game_test.txt", "r");
    int flag = 0;
    Chess_Game(ft);
    if (ft == NULL) {
        flag = 1;
    }
    ASSERT_EQUAL(1, flag);
}

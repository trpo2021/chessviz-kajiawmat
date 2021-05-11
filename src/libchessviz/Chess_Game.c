#include<stdio.h>

#include<stdlib.h>

#include "Board.h"

#include "IO.h"

#include "Moving.h"

#include "Rules.h"


extern int gor_begin, ver_begin, gor_end, ver_end, typ_roki, move, move_rook[];
extern char letter_fig, typ_move, transform, last_cut;
extern const int Ver_min;

void Chess_Game(FILE * f1) {
    char ch;
    Board_Init();
    while ((ch = getc(f1)) != EOF) {
        ch = Search_Read(f1, ch);

        if (ch >= Ver_min && ch <= (Ver_min + 9)) //more '0' and less '9'
        {
            Move_input(f1, ch);
        }

        if (Check_Massive(ch) || Check_Gor(ch)) {
            Move_Read(f1, ch);
            system("CLS");
            Move_Write();
            Move_Figure();
            Board();
            system("Pause");
            move++;
        }

        if (ch == 'O') {
            typ_roki = 0;
            Roki_Read(f1, ch);
            system("CLS");
            Roki_Write();
            Rokirovka();
            Board();
            system("Pause");
            move++;
        }
    }
    printf("\n\nGame Over!!!\n");
    fclose(f1);
    f1 = NULL;
}

void Game_Init() {
    int i;
    gor_begin = 0;
    ver_begin = 0;
    gor_end = 0;
    ver_end = 0;
    typ_roki = 0;
    move = 1;
    letter_fig = 0;
    typ_move = 0;
    transform = 0;
    last_cut = 0;
    for (i = 0; i < 4; i++) {
        move_rook[i] = 1;
    }
}

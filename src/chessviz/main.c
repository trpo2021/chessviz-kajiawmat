#include <stdio.h>

#include <stdlib.h>

#include "libchessviz/Chess_Game.h"

#include "libchessviz/Error_Message.h"

const int Players = 2, Reg = ('a' - 'A'), Gor_min = ('a' - 1),
          Ver_min = ('1' - 1);
const char Type_figure[6] = {'P', 'R', 'N', 'B', 'Q', 'K'};
const char Sym_Ignore[11]
        = {' ', '.', ',', 'X', '#', '+', '!', '?', ';', '\n', '\t'};

char C[9][9];

int ver_begin = 0, gor_begin = 0, ver_end = 0, gor_end = 0, move = 1;
char letter_fig = 0, typ_move = 0, transform = 0, last_cut = 0;
int typ_roki = 0, move_rook[4] = {1, 1, 1, 1};

int main()
{
    FILE* f1;
    f1 = fopen("res/Chess_Game.txt", "r");
    if (f1 == NULL) {
        Error_Text(1);
    }
    Game_Init();
    Chess_Game(f1);
    system("Pause");
    return 0;
}

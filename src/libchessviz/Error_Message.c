#include <stdlib.h>

#include <stdio.h>

#include "IO.h"

#include "Board.h"

extern int move, gor_begin, ver_begin, gor_end, ver_end;
extern char letter_fig, C[][9];
extern const int Players, Ver_min, Gor_min, Reg;

void Error_Move()
{
    printf("\nNow move %i for ", move / Players + move % Players);
    if (move % Players) {
        printf("white, ");
    } else {
        printf("black, ");
    }
}

void Error_Text(int i)
{
    system("CLS");
    printf("Error %i\n", i);
    switch (i) {
    case 1:
        printf("Unfortunately, it is not possible to open the file you "
               "entered.");
        break;

    case 2:
        printf("The move number is incorrect");
        Error_Move();
        break;

    case 3:
        Error_Move();
        printf("\nInput Error of data move.");
        break;

    case 4:
        Move_Write();
        printf("\nA figure cannot move on her cage.");
        break;

    case 5:
        Move_Write();
        printf("\nNow the move is of a different color, so move figure of a "
               "different color.");
        break;

    case 6:
        Move_Write();
        printf("On cage %c%c figure %c not stay.",
               gor_begin + Gor_min,
               ver_begin + Ver_min,
               letter_fig + Reg * ((move + 1) % Players));
        break;

    case 7:
        Error_Move();
        printf("Castling incorrectly written: too many or too few repeats of "
               "symbols \'-O\'.");
        break;

    case 8:
        Move_Write();
        printf("\nFigure cannot stand on a cage %c%c occupied by a figure %c",
               gor_end + Gor_min,
               ver_end + Ver_min,
               C[ver_end][gor_end]);
        break;

    case 9:
        Move_Write();
        printf("\nFigure cannot cut figure %c on cage %c%c, because they are "
               "the same color",
               C[ver_end][gor_end],
               gor_end + Gor_min,
               ver_end + Ver_min);
        break;

    case 10:
        Move_Write();
        printf("\nFigure cannot cut figure on cage %c%c, because there is no "
               "figure on this cage.",
               gor_end + Gor_min,
               ver_end + Ver_min);
        break;

    case 11:
        Move_Write();
        printf("Pawn on cage %c%c can move only on 1 cage ahead, or on 2 cage "
               "ahead, if it comes from the original position.",
               gor_begin + Gor_min,
               ver_begin + Ver_min);
        break;

    case 12:
        Move_Write();
        printf("Pawn on cage %c%c can only walk along her vertikal",
               gor_begin + Gor_min,
               ver_begin + Ver_min);
        break;

    case 13:
        Move_Write();
        printf("Pawn on cage %c%c can only cut along the diagonal one cage "
               "ahead",
               gor_begin + Gor_min,
               ver_begin + Ver_min);
        break;

    case 14:
        Move_Write();
        printf("Pawn on cage %c%c can cut a figure only on adjacent vertikal",
               gor_begin + Gor_min,
               ver_begin + Ver_min);
        break;

    case 15:
        Move_Write();
        printf("Figure %c cannot step over a figure", letter_fig);
        break;

    case 16:
        Move_Write();
        printf("Figure %c from cage %c%c can't move on cage %c%c.",
               letter_fig,
               gor_begin + Gor_min,
               ver_begin + Ver_min,
               gor_end + Gor_min,
               ver_end + Ver_min);
        break;

    case 17:
        Roki_Write();
        printf("\nThe King or the rook that castles has already moved in this "
               "game.");
        break;

    case 18:
        Roki_Write();
        printf("\nThe rook that castles has already moved in this game.");
        break;

    case 19:
        Move_Write();
        printf("The character array has definitely been changed.");
        break;

    case 20:
        Move_Write();
        printf("It is not normally written which figure the pawn turns into, "
               "when it moves to the cage %c%c.",
               gor_end + Gor_min,
               ver_end + Ver_min);
        break;

    default:
        printf("I don't know this Error");
    }
    printf("\nCorrect the error and try again!\n");
    if (i != 1) {
        Board();
    }
    system("pause>nul");
    exit(1);
}

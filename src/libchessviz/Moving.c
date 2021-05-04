#include "Error_Message.h"

#include "Rules.h"

#include "stdlib.h"


extern int move, gor_begin, ver_begin, gor_end, ver_end, typ_roki, move_rook[];
extern char letter_fig, typ_move, transform, C[][9];
extern const int Players, Ver_min, Gor_min, Reg;
extern const char Type_figure[];


void Moving() {
    int x = Attack_or_Not();
    if (x == 1) {
        C[ver_end][gor_end] = letter_fig + Reg * ((move + 1) % Players);
        C[ver_begin][gor_begin] = ' ';
    } else {
        Error_Text(x);
    }
}

void Move_Pawn() {
    int x = Check_Pawn();
    if (x == 1) {
        if (ver_end == 8 || ver_end == 1) {
            letter_fig = transform;
        }
        Moving();
    } else {
        Error_Text(x);
    }
}

void Move_Rook() {
    if (Check_Rook()) {
        if (Check_BNQ() == 0) {
            Error_Text(15);
        }
        Moving();
        if (ver_begin == 8 - 7 * (move % Players)) {
            if (gor_begin == 1) {
                move_rook[3 - 2 * (move % Players)] = 0;
            } else {
                if (gor_begin == 8) {
                    move_rook[4 - 2 * (move % Players)] = 0;
                }
            }
        }
    } else {
        Error_Text(16);
    }
}

void Move_Knight() {
    if (Check_Knight()) {
        Moving();
    } else {
        Error_Text(16);
    }
}

void Move_Bishop() {
    if (Check_Bishop()) {
        if (Check_BNQ() == 0) {
            Error_Text(15);
        }
        Moving();
    } else {
        Error_Text(16);
    }
}

void Move_Queen() {
    if (Check_Rook() || Check_Bishop()) {
        if (Check_BNQ() == 0) {
            Error_Text(15);
        }
        Moving();
    } else {
        Error_Text(16);
    }
}

void Move_King() {
    if (Check_King()) {
        Moving();
        if (ver_begin == 8 - 7 * (move % Players)) {
            move_rook[3 - 2 * (move % Players)] = 0;
            move_rook[4 - 2 * (move % Players)] = 0;
        }
    } else {
        Error_Text(16);
    }
}

void Move_Figure() {
    switch (letter_fig) {
        case 'P':
            Move_Pawn();
            break;
        case 'R':
            Move_Rook();
            break;
        case 'N':
            Move_Knight();
            break;
        case 'B':
            Move_Bishop();
            break;
        case 'Q':
            Move_Queen();
            break;
        case 'K':
            Move_King();
            break;
        default:
            Error_Text(19);
    }
}

void Rokirovka() {
    int left = (move % Players);
    char temp;
    ver_begin = 8 - 7 * left;
    gor_begin = 5;
    ver_end = ver_begin;
    int border = 2 - 2 * left;
    letter_fig = Type_figure[5];
    typ_move = '-';

    if (Check_Roki(border)) {
        gor_end = 1 + 7 * (typ_roki % 2);
        if (Check_BNQ() == 0) {
            Error_Text(15);
        }
        if (Check_Roki(border + (typ_roki % 2))) {
            temp = gor_end;
            gor_end = gor_begin - (2 - 4 * (typ_roki % 2));
            Moving();
            gor_begin = temp;
            gor_end -= (gor_end - 5) / 2;
            letter_fig = Type_figure[1];
            Moving();
            move_rook[border] = 0;
            move_rook[border + 1] = 0;
        } else {
            Error_Text(18);
        }
    } else {
        Error_Text(17);
    }
}

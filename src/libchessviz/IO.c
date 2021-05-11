#include<stdlib.h>

#include<stdio.h>

#include "Error_Message.h"

#include "Rules.h"



extern int move, gor_begin, ver_begin, gor_end, ver_end, typ_roki;
extern char letter_fig, typ_move, transform, last_cut, C[][9];
extern const char Type_figure[];
extern const int Players, Ver_min, Gor_min, Reg;


char Search_Read(FILE * f1, char ch) {
    while (Check_Getc(ch) != 1) {
        ch = getc(f1);
    }
    return ch;
}

void Move_input(FILE * f1, char ch) {
    int move_input = 0;
    while (ch >= Ver_min && ch <= (Ver_min + 9)) {
        move_input = move_input * 10 + ch - Ver_min;
        ch = getc(f1);
    }
    if (move_input != (move / Players) + (move % Players)) {
        printf("\n--------------");
        printf("\nWrote move number %i", move_input);
        printf("\n--------------");
        system("pause");
        Error_Text(2);
    }
}

void Move_Read(FILE * f1, char ch) {
    transform = 0;
    last_cut = 0;
    if (Check_Gor(ch)) {
        letter_fig = Type_figure[0];
    } else {
        if (Check_Massive(ch)) {
            letter_fig = ch;
            ch = getc(f1);
        } else {
            Error_Text(3);
        }
    }

    ch = Search_Read(f1, ch);
    if (Check_Gor(ch)) {
        gor_begin = ch - Gor_min;
        ch = getc(f1);
    } else {
        Error_Text(3);
    }

    ch = Search_Read(f1, ch);
    if (Check_Ver(ch)) {
        ver_begin = ch - Ver_min;
        ch = getc(f1);
    } else {
        Error_Text(3);
    }

    ch = Search_Read(f1, ch);
    if (ch == '-' || ch == 'x' || ch == ':') {
        typ_move = ch;
        ch = getc(f1);
    } else {
        Error_Text(3);
    }

    ch = Search_Read(f1, ch);
    if (Check_Gor(ch)) {
        gor_end = ch - Gor_min;
        ch = getc(f1);
    } else {
        Error_Text(3);
    }

    ch = Search_Read(f1, ch);
    if (Check_Ver(ch)) {
        ver_end = ch - Ver_min;
        ch = getc(f1);
    } else {
        Error_Text(3);
    }

    if (Check_Move_End() == 0) {
        Error_Text(4);
    }

    if (Check_Move_Color() == 0) {
        Error_Text(5);
    }

    if (Check_Move_Begin() == 0) {
        Error_Text(6);
    }

    if (letter_fig == Type_figure[0] && (ver_end == 1 || ver_end == 8)) {
        ch = Search_Read(f1, ch);
        if (Check_Transform(ch)) {
            transform = ch;
        } else {
            Error_Text(20);
        }
    }
}

void Roki_Read(FILE * f1, char ch) {
    ch = getc(f1);
    ch = Search_Read(f1, ch);
    while (ch == '-') {
        ch = getc(f1);
        ch = Search_Read(f1, ch);
        if (ch == 'O') {
            typ_roki++;
            ch = getc(f1);
        } else {
            Error_Text(3);
        }
    }
    if (typ_roki == 0 || typ_roki > 2) {
        Error_Text(7);
    }
}

void Move_Write() {
    printf("\nMove %i for ", move / Players + move % Players);
    if (move % Players) {
        printf("white: ");
    } else {
        printf("black: ");
    }
    if (letter_fig != 'P') {
        printf("%c", letter_fig);
    }
    printf("%c%c%c%c%c", gor_begin + Gor_min, ver_begin + Ver_min, typ_move, gor_end + Gor_min, ver_end + Ver_min);
    if ((typ_move == ':') || (typ_move == 'x')) {
        printf("\nThe figure %c on the cage %c%c is taken", C[ver_end][gor_end], gor_end + Gor_min, ver_end + Ver_min);
    } else {
        printf("\n");
    }
    if (transform) {
        printf("\nPawn %c%c hit the field %c%c and became %c", gor_begin + Gor_min, ver_begin + Ver_min, gor_end + Gor_min, ver_end + Ver_min, transform);
    } else {
        printf("\n");
    }
    printf("\n");
    printf("\n");
}

void Roki_Write() {
    int i = 0;
    printf("\nMove %i for ", move / Players + move % Players);
    if (move % Players) {
        printf("white: ");
    } else {
        printf("black: ");
    }
    printf("O");
    while (i < typ_roki) {
        printf("-O");
        i++;
    }
    printf("\n\n\n\n");
}

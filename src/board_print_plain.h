#ifndef BOARD_H
#define BOARD_H

#include <stdio.h>
#include <stdlib.h>

typedef struct {
    char type;
    int colour;
}board;

void initial_board(board *a);

void print_board(board *a);

int coordinates(char i, int j, char i1, int j1);

int *convert(char j, int i, char j1, int i1);

void move(board *a, char i, int j, char i1, int j1);

int colour_checking(board * a, int str, int stl, int colour);

int win_checking(board * a);

int move_checking(board * a, int i, int j, int i1, int j1);

#endif
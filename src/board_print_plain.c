#include <stdio.h>
#include "board_print_plain.h"

void initial_board(board *a) {
    int i, j;

    a[0].type = 'r';
    a[1].type = 'h';
    a[2].type = 'b';
    a[3].type = 'q';
    a[4].type = 'k';
    a[5].type = 'b';
    a[6].type = 'h';
    a[7].type = 'r';

    for (i = 0; i <= 7; i++){
        a[8 + i].type = 'p';
    }
    for (i = 0; i <= 15; i++) {
        a[i].colour = 0;
    }
    for (j = 2; j <=5; j++ ){
        for (i = 0; i <= 7; i++){
            a[j * 8 + i].type = '_';
            a[j * 8 + i].colour = 2;
        }
    }
    for (i = 0; i <= 7; i++){
        a[6 * 8 + i].type = 'P';
    }

    a[56].type = 'R';
    a[57].type = 'H';
    a[58].type = 'B';
    a[59].type = 'K';
    a[60].type = 'Q';
    a[61].type = 'B';
    a[62].type = 'H';
    a[63].type = 'R';

    for (i = 48; i <= 63; i++) {
        a[i].colour = 1;
    }
}

void print_board(board *a) {
    int i, j;

    printf("   A B C D E F G H\n");
        printf("   _ _ _ _ _ _ _ _\n");
        for (j = 0; j <= 7; j++){
            printf("%d ", j + 1);
            for (i = 0; i <= 7; i++){
                printf("|%c", a[j * 8 + i].type);
            }
            printf("|\n");
        }
}
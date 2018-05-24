#include <stdio.h>
#include "board_print_plain.h"

int main()
{
    char i, i1;
    int *index, f = 1, j, j1;
    int win = 0, count = 0, colour = 0, check_move = 0;
    
    board *a = (board *)malloc(sizeof(board) * 8 * 8);

    printf("Insert data format: E2 E4\n");
    initial_board(a);
    print_board(a);
    while (win == 0) {
        while (colour == 0) {
            while ((check_move == 0) && (colour == 0)) {
                if (count % 2 == 0) {
                    printf ("Белые ходят:");
                }
                else
                    printf("Черные ходят:");
                while (f != 0) {
                    scanf("%c%d %c%d", &i, &j, &i1, &j1);
                    while(getchar() != '\n');
                    f = coordinates(i, j, i1, j1);
                }
                f = 1;
            index = convert(i, j, i1, j1);
                i = index[0];
            j = index[1];
            i1 = index[2];
            j1 = index[3];
                colour = colour_checking(a, j, i, count % 2);
                check_move = move_checking(a, j, i, j1, i1);
                if (check_move == 0) {
                    printf("Ход не возможен\n");
                }
                if (((check_move == 1) && (colour == 0)) || ((check_move == 0) && (colour == 1))) {
                    check_move = 0;
                    colour = 0;
                }
            }
        }
        if (check_move == 1) {
            move(a, i, j, i1, j1);
        }
        print_board(a);
        count++;
        check_move = 0;
        colour = 0;
        win = win_checking(a);  
    }
    free(a);
    return 0;
}

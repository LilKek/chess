#include <stdio.h>
#include "board.h"

int coordinates(char i, int j, char i1, int j1) {
    int g = 0;
    char mass[] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H'};

    for (int k = 0; k <= 7; k++) {
        if (i == mass[k]) {
            g++;
        }
        if (i1 == mass[k]) {
            g++;
        }
        if (j == k + 1) {
            g++;
        }
        if (j1 == k + 1) {
            g++;
        }
    }

    if (g != 4) {
        printf("Ошибка ввода данных\n");
        return -1;
    }
    return 0;
}

int *convert(char i, int j, char i1, int j1) {
    int index_i, index_i1;
    static int index[4];
    char mass[8] = {'A','B','C','D','E','F','G','H'};
    for (int k = 0; k <= 7; k++) {
    if (i == mass[k]) {
        index_i = k;
        }
    if (i1 == mass[k]) {
        index_i1 = k;
        }
    }
    index[0] = index_i;
    index[1] = j - 1;
    index[2] = index_i1;
    index[3] = j1 - 1;
    return index;
}

void move(board *a, char i, int j, char i1, int j1){
    board tmp;

    if (a[j1*8 + i1].type == '_') {
    tmp = a[j * 8 + i];
    a[j * 8 + i] = a[j1 * 8 + i1];
    a[j1 * 8 + i1] = tmp;
    }
    else {
        a[j1*8 + i1] = a[j*8 + i];
            a[j*8 + i].type = '_';
            a[j*8 + i].colour = 2;
    }
}

int colour_checking(board *a, int str, int stl, int colour){
    if (a[str * 8 + stl].colour == colour) {
        return 1;
        }
    return 0;
}

int win_checking(board * a){
    int flag = 0;
    for (int i = 0; i <= 7; i++) {
        for (int j = 0; j <=7; j++) {
            if ((a[i * 8 + j].type == 'k') || (a[i * 8 + j].type == 'K')) {
                flag++;
            }
        }
    }
    if(flag == 2) {
        return 0;
    }
    return 1;
}

int move_checking(board * a, int j, int i, int j1, int i1){   
    if (a[j * 8 + i].colour == a[j1 * 8 + i1].colour) {
        return 0;
    }
    if ((a[j * 8 + i].type == 'p') || (a[j * 8 + i].type == 'P')) {
        if(((a[j * 8 + i].colour == 1) && (a[j1 * 8 + i1].colour == 0)) || ((a[j * 8 + i].colour == 0) && (a[j1 * 8 + i1].colour == 1))) { 
            if (((i + 1) == i1) && ((j - 1) == j1)) {
                return 1;
            }
            if (((i + 1) == i1) && ((j + 1) == j1)) {
                return 1;
            }
            if (((i - 1) == i1) && ((j - 1) == j1)) {
                return 1;
            }
            if (((i - 1) == i1) && ((j + 1) == j1)) {
                return 1;
            }
        }
        if (a[j1 * 8 + i1].colour == 2) {
            if ((j == 1) && (j1 < 4) && (j1 > 1) && (i == i1) && (a[(j + 1) * 8 + i].colour == 2)) {
                return 1;
            }
            if ((j == 6) && (j1 > 3) && (j1 < 6) && (i == i1) && (a[(j - 1) * 8 + i].colour == 2)) {
                return 1;
            }
            if ((a[j * 8 + i].type == 'p') && (j != 6) && (j1 == (j - 1)) && (i == i1)) { 
                return 1;
            }
            if ((a[j * 8 + i].type == 'P') && (j != 1) && (j1 == (j + 1)) && (i == i1)) {
                return 1;
            }
        }
    }

    if ((a[j * 8 + i].type == 'r') || (a[j * 8 + i].type == 'R')) {        
        if ((i == i1) && (j < j1)) { 
            for (int k = j + 1; k < j1; k++) {
                if (a[k * 8 + j].colour != 2) {
                    return 0;
                }
            return 1;
            }
        }
        if ((i == i1) && (j > j1)) { 
            for (int k = j1 + 1; k < j; k++) {
                if (a[k * 8 + i].colour != 2) {
                    return 0;
                }
            }
            return 1;
        }
        if ((i < i1) && (j == j1)) {
            for (int k = i + 1; k < i1; k++) {
                if (a[j * 8 + k].colour != 2) {
                    return 0;
                }
            }
            return 1;
        }
        if ((i > i1) && (j == j1)) {
            for (int k = i1 + 1; k < i; k++) {
                if (a[j * 8 + k].colour != 2) {
                    return 0;
                }
            }
            return 1;
        }
    }

    if ((a[j * 8 + i].type == 'h') || (a[j * 8 + i].type == 'H')) {
        if (((j1 == (j + 1)) || (j1 == (j - 1))) && (i1 == (i + 2) || (i1 == (i - 2)))) {
            return 1;
        
        }
        if (((j1 == (j + 2)) || (j1 == (j - 2))) && ((i1 == (i + 1)) || (i1 == (i - 1)))) {
            return 1;
        }
    }

    if ((a[j * 8 + i].type == 'q') || (a[j * 8 + i].type == 'Q')) {
        if ((i == i1) && (j < j1)) { 
            for (int k = j + 1; k < j1; k++) {
                if (a[k * 8 + i].colour != 2) {
                    return 0;
                }
            }
            return 1;
        }
        if ((1 == i1) && (j > j1)) { 
            for (int k = j1 + 1; k < j; k++) {
                if (a[k * 8 + i].colour != 2) {
                    return 0;
                }
            }
            return 1;
        }
        if ((i < i1) && (j == j1)) {
            for (int k = i + 1; k < i1; k++) {
                if (a[j * 8 + k].colour != 2) {
                    return 0;
                }
            }
            return 1;
        }
        if ((i > i1) && (j == j1)) {
            for (int k = i1 + 1; k < i; k++) {
                if (a[j * 8 + k].colour != 2) {
                    return 0;
                }
            }
            return 1;
        }
        if ((j- j1) == (i - i1)) {
            int k = j - 1;
            int g = i - 1;
            while ((k > j1) && (g > i1)) {
                if (a[k * 8 + g].colour != 2) {
                    return 0;
                }
                k--;
                g--;
            }
            return 1;
        }    
        if ((j - j1) == (i1 - i)) {
            int k = j - 1;
            int g = i + 1;
            while ((k > j1) && (g < i1)) {
                if (a[k * 8 + g].colour != 2) {
                    return 0;
                }
                k--;
                g++;
            }
            return 1;
        }          
        if ((j1 - j) == (i - i1)) {
            int k = j + 1;
            int g = j - 1;
            while ((k < j1) && (g > i1)) {
                if (a[k * 8 + g].colour != 2) {
                    return 0;
                }
                k++;
                g--;
            }
            return 1;
        }  
        if ((j1 - j) == (i1 - i)) {
            int k = j + 1;
            int g = i + 1;
            while ((k < j1) && (g < i1)) {
                if (a[k * 8 + g].colour != 2) {
                    return 0;
                }
                k++;
                g++;
            }
            return 1;
        }  
    }

    if ((a[j * 8 + i].type == 'b') || (a[j * 8 + i].type == 'B')) {
        if ((j - j1) == (i - i1)) {
            int k = j - 1;
            int g = i - 1;
            while ((k > j1) && (g > i1))
            {
                if (a[k * 8 + g].colour != 2) {
                    return 0;
                }
                k--;
                g--;
            }
            return 1;
        }    
        if ((j - j1) == (i1 - i)) {
            int k = j - 1;
            int g = i + 1;
            while ((k > j1) && (g < i1)) {
                if (a[k * 8 + g].colour != 2) {
                    return 0;
                }
                k--;
                g++;
            }
            return 1;
        }          
        if ((j1 - j) == (i - i1)) {
            int k = j + 1;
            int g = i - 1;
            while ((k < j1) && (g > i1)) {
                if (a[k * 8 + g].colour != 2) {
                    return 0;
                }
                k++;
                g--;
            }
            return 1;
        }  
        if ((j1 - j) == (i1 - i)) {
            int k = j + 1;
            int g = i + 1;
            while ((k < j1) && (g < i1)) {
                if (a[k * 8 + g].colour != 2) {
                    return 0;
                }
                k++;
                g++;
            }
            return 1;
        }  
   }

    if ((a[j * 8 + i].type == 'k') || (a[j * 8 + i].type == 'K')) {
        if ((((j1 - j) == 1) || ((j - j1) == 1)) && (i1 == i))
            return 1;
        if ((j == j1) && (((i - i1) == 1) || (i1 - i) == 1))
            return 1;
        if ((j1 - j == 1) && (((i1 - i) == 1) || ((i - i1) == 1)))
            return 1;
        if ((j - j1 == 1) && (((i1 - i) == 1) || ((i - i1) == 1)))
            return 1;
    }
    return 0;
}
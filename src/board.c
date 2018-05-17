#include <stdio.h>
#include "board.h"

extern unsigned short int board[8][8];



char checknum(unsigned short int num_figure)
{
	switch(num_figure){
		case 21:
			return 'r';
		case 22:
			return 'n';
		case 23:
			return 'b';
		case 24:
			return 'q';
		case 25:
			return 'k';
		case 20:
			return 'p';
		case 10:
			return 'P';
		case 11:
			return 'R';
		case 12:
			return 'N';
		case 13:
			return 'B';
		case 14:
			return 'Q';
		case 15:
			return 'K';
		default:
			return '!';
	}
}


char code_to_letter(unsigned short int i1, unsigned short int j1)
{
	char empty = '!';
	if ((i1 + j1)%2 != 0) {
		empty = '#';
	} else {
		empty = ' ';
	}
	
	switch(board[i1][j1]){
		case 21:
			return 'r';
		case 22:
			return 'n';
		case 23:
			return 'b';
		case 24:
			return 'q';
		case 25:
			return 'k';
		case 20:
			return 'p';
		case 10:
			return 'P';
		case 11:
			return 'R';
		case 12:
			return 'N';
		case 13:
			return 'B';
		case 14:
			return 'Q';
		case 15:
			return 'K';
		case 0:
			return empty;
		default:
			return '!';
	}
}


void Ini_cells(unsigned short int i1,unsigned short int j1)
{
	FILE *log;
	unsigned short int num_figure;
	unsigned short int num_figure2;
	char move1[3];
	char move2[3];
	unsigned short int i2, j2;
	num_figure = board[i1][j1];
	printf("%d\n", num_figure);
	if (num_figure == 21) {
		printf("Введите координату,куда хотите переместить ладью: \n");
		scanf("%s", &move1[0]);
		while ((move1[0] < 'a') || (move1[0] > 'h')) {
			printf("Ошибка ввода,повторите попытку\n");
			scanf("%s", &move1[0]);
		}
		scanf("%s", &move2[0]);
		while ((move2[0] < '1') || (move2[0] > '8')) {
			printf("Ошибка ввода,повторите попытку\n");
			scanf("%s", &move2[0]);
		}
		i2 = table_1(move1[0]);
		j2 = table_2(move2[0]);
		num_figure2 = board[j2][i2];
		board[j2][i2] = num_figure;
		board[i1][j1] = 0;
		log = fopen("./logs/user.log", "a+");
		fprintf(log, "%c%c%c\n", move_to(num_figure2), move1[0], move2[0]);
		fclose(log);

	}
		if (num_figure == 22) {
		printf("Введите координату,куда хотите переместить коня: ");
		scanf("%s", &move1[0]);
		while ((move1[0] < 'a') || (move1[0] > 'h')) {
			printf("Ошибка ввода,повторите попытку\n");
			scanf("%s", &move1[0]);
		}
		scanf("%s", &move2[0]);
		while ((move2[0] < '1') || (move2[0] > '8')) {
			printf("Ошибка ввода,повторите попытку\n");
			scanf("%s", &move2[0]);
		}
		i2 = table_1(move1[0]);
		j2 = table_2(move2[0]);
		num_figure2 = board[j2][i2];
		board[j2][i2] = num_figure;
		board[i1][j1] = 0;
		log = fopen("./logs/user.log", "a+");
		fprintf(log, "%c%c%c\n", move_to(num_figure2), move1[0], move2[0]);
		fclose(log);
	}
		if (num_figure == 23) {
		printf("Введите координату,куда хотите переместить слона: ");
		scanf("%s", &move1[0]);
		while ((move1[0] < 'a') || (move1[0] > 'h')) {
			printf("Ошибка ввода,повторите попытку\n");
			scanf("%s", &move1[0]);
		}
		scanf("%s", &move2[0]);
		while ((move2[0] < '1') || (move2[0] > '8')) {
			printf("Ошибка ввода,повторите попытку\n");
			scanf("%s", &move2[0]);
		}
		i2 = table_1(move1[0]);
		j2 = table_2(move2[0]);
		num_figure2 = board[j2][i2];
		board[j2][i2] = num_figure;
		board[i1][j1] = 0;
		log = fopen("./logs/user.log", "a+");
		fprintf(log, "%c%c%c\n", move_to(num_figure2), move1[0], move2[0]);
		fclose(log);
	}
	
		if (num_figure == 24) {
		printf("Введите координату,куда хотите переместить ферзя: ");
		scanf("%s", &move1[0]);
		while ((move1[0] < 'a') || (move1[0] > 'h')) {
			printf("Ошибка ввода,повторите попытку\n");
			scanf("%s", &move1[0]);
		}
		scanf("%s", &move2[0]);
		while ((move2[0] < '1') || (move2[0] > '8')) {
			printf("Ошибка ввода,повторите попытку\n");
			scanf("%s", &move2[0]);
		}
		i2 = table_1(move1[0]);
		j2 = table_2(move2[0]);
		num_figure2 = board[j2][i2];
		board[j2][i2] = num_figure;
		board[i1][j1] = 0;
		log = fopen("./logs/user.log", "a+");
		fprintf(log, "%c%c%c\n", move_to(num_figure2), move1[0], move2[0]);
		fclose(log);
	}
	
		if (num_figure == 25) {
		printf("Введите координату,куда хотите переместить короля: ");
		scanf("%s", &move1[0]);
		while ((move1[0] < 'a') || (move1[0] > 'h')) {
			printf("Ошибка ввода,повторите попытку\n");
			scanf("%s", &move1[0]);
		}
		scanf("%s", &move2[0]);
		while ((move2[0] < '1') || (move2[0] > '8')) {
			printf("Ошибка ввода,повторите попытку\n");
			scanf("%s", &move2[0]);
		}
		i2 = table_1(move1[0]);
		j2 = table_2(move2[0]);
		num_figure2 = board[j2][i2];
		board[j2][i2] = num_figure;
		board[i1][j1] = 0;
		log = fopen("./logs/user.log", "a+");
		fprintf(log, "%c%c%c\n", move_to(num_figure2), move1[0], move2[0]);
		fclose(log);
	}
	
		if (num_figure == 20) {
		printf("Введите координату,куда хотите переместить пешку: ");
		scanf("%s", &move1[0]);
		while ((move1[0] < 'a') || (move1[0] > 'h')) {
			printf("Ошибка ввода,повторите попытку\n");
			scanf("%s", &move1[0]);
		}
		scanf("%s", &move2[0]);
		while ((move2[0] < '1') || (move2[0] > '8')) {
			printf("Ошибка ввода,повторите попытку\n");
			scanf("%s", &move2[0]);
		}
		i2 = table_1(move1[0]);
		j2 = table_2(move2[0]);
		num_figure2 = board[j2][i2];
		board[j2][i2] = num_figure;
		board[i1][j1] = 0;
		log = fopen("./logs/user.log", "a+");
		fprintf(log, "%c%c%c\n", move_to(num_figure2), move1[0], move2[0]);
		fclose(log);
	}
	
		if (num_figure == 11) {
		printf("Введите координату,куда хотите переместить ладью: ");
		scanf("%s", &move1[0]);
		while ((move1[0] < 'a') || (move1[0] > 'h')) {
			printf("Ошибка ввода,повторите попытку\n");
			scanf("%s", &move1[0]);
		}
		scanf("%s", &move2[0]);
		while ((move2[0] < '1') || (move2[0] > '8')) {
			printf("Ошибка ввода,повторите попытку\n");
			scanf("%s", &move2[0]);
		}
		i2 = table_1(move1[0]);
		j2 = table_2(move2[0]);
		num_figure2 = board[j2][i2];
		board[j2][i2] = num_figure;
		board[i1][j1] = 0;
		log = fopen("./logs/user.log", "a+");
		fprintf(log, "%c%c%c\n", move_to(num_figure2), move1[0], move2[0]);
		fclose(log);
	}
	
		if (num_figure == 12) {
		printf("Введите координату,куда хотите переместить коня: ");
		scanf("%s", &move1[0]);
		while ((move1[0] < 'a') || (move1[0] > 'h')) {
			printf("Ошибка ввода,повторите попытку\n");
			scanf("%s", &move1[0]);
		}
		scanf("%s", &move2[0]);
		while ((move2[0] < '1') || (move2[0] > '8')) {
			printf("Ошибка ввода,повторите попытку\n");
			scanf("%s", &move2[0]);
		}
		i2 = table_1(move1[0]);
		j2 = table_2(move2[0]);
		num_figure2 = board[j2][i2];
		board[j2][i2] = num_figure;
		board[i1][j1] = 0;
		log = fopen("./logs/user.log", "a+");
		fprintf(log, "%c%c%c\n", move_to(num_figure2), move1[0], move2[0]);
		fclose(log);
	}
	
		if (num_figure == 13) {
		printf("Введите координату,куда хотите переместить слона: ");
		scanf("%s", &move1[0]);
		while ((move1[0] < 'a') || (move1[0] > 'h')) {
			printf("Ошибка ввода,повторите попытку\n");
			scanf("%s", &move1[0]);
		}
		scanf("%s", &move2[0]);
		while ((move2[0] < '1') || (move2[0] > '8')) {
			printf("Ошибка ввода,повторите попытку\n");
			scanf("%s", &move2[0]);
		}
		i2 = table_1(move1[0]);
		j2 = table_2(move2[0]);
		num_figure2 = board[j2][i2];
		board[j2][i2] = num_figure;
		board[i1][j1] = 0;
		log = fopen("./logs/user.log", "a+");
		fprintf(log, "%c%c%c\n", move_to(num_figure2), move1[0], move2[0]);
		fclose(log);
		
	}	if (num_figure == 14) {
		printf("Введите координату,куда хотите переместить ферзя: ");
		scanf("%s", &move1[0]);
		while ((move1[0] < 'a') || (move1[0] > 'h')) {
			printf("Ошибка ввода,повторите попытку\n");
			scanf("%s", &move1[0]);
		}
		scanf("%s", &move2[0]);
		while ((move2[0] < '1') || (move2[0] > '8')) {
			printf("Ошибка ввода,повторите попытку\n");
			scanf("%s", &move2[0]);
		}
		i2 = table_1(move1[0]);
		j2 = table_2(move2[0]);
		num_figure2 = board[j2][i2];
		board[j2][i2] = num_figure;
		board[i1][j1] = 0;
		log = fopen("./logs/user.log", "a+");
		fprintf(log, "%c%c%c\n", move_to(num_figure2), move1[0], move2[0]);
		fclose(log);
	}
	
		if (num_figure == 15) {
		printf("Введите координату,куда хотите переместить короля: ");
		scanf("%s", &move1[0]);
		while ((move1[0] < 'a') || (move1[0] > 'h')) {
			printf("Ошибка ввода,повторите попытку\n");
			scanf("%s", &move1[0]);
		}
		scanf("%s", &move2[0]);
		while ((move2[0] < '1') || (move2[0] > '8')) {
			printf("Ошибка ввода,повторите попытку\n");
			scanf("%s", &move2[0]);
		}
		i2 = table_1(move1[0]);
		j2 = table_2(move2[0]);
		num_figure2 = board[j2][i2];
		board[j2][i2] = num_figure;
		board[i1][j1] = 0;
		log = fopen("./logs/user.log", "a+");
		fprintf(log, "%c%c%c\n", move_to(num_figure2), move1[0], move2[0]);
		fclose(log);
	}
	
		if (num_figure == 10) {
		printf("Введите координату,куда хотите переместить пешку: ");
		scanf("%s", &move1[0]);
		while ((move1[0] < 'a') || (move1[0] > 'h')) {
			printf("Ошибка ввода,повторите попытку\n");
			scanf("%s", &move1[0]);
		}
		scanf("%s", &move2[0]);
		while ((move2[0] < '1') || (move2[0] > '8')) {
			printf("Ошибка ввода,повторите попытку\n");
			scanf("%s", &move2[0]);
		}
		i2 = table_1(move1[0]);
		j2 = table_2(move2[0]);
		num_figure2 = board[j2][i2];
		board[j2][i2] = num_figure;
		board[i1][j1] = 0;
		log = fopen("./logs/user.log", "a+");
		fprintf(log, "%c%c%c\n", move_to(num_figure2), move1[0], move2[0]);
		fclose(log);
	}	

	
}


void board_(unsigned short int i1,unsigned short int j1)
{


	printf("------------\n");
	Ini_cells(i1, j1);//Для перемещения фигуры	
	

	
}



void print_board()
{

	printf("\n\n");
	printf("    *  | A | B | C | D | E | F | G | H |  *    \n");
	printf("    _   ___ ___ ___ ___ ___ ___ ___ ___   _    \n");
	printf("    8  | %c |#%c#| %c |#%c#| %c |#%c#| %c |#%c#|  8    \n", 
	code_to_letter(0,0), code_to_letter(0,1),code_to_letter(0,2),code_to_letter(0,3),code_to_letter(0,4),code_to_letter(0,5),code_to_letter(0,6),code_to_letter(0,7));
	printf("    _  |___|###|___|###|___|###|___|###|  _    \n");
	printf("    7  |#%c#| %c |#%c#| %c |#%c#| %c |#%c#| %c |  7    \n",
	code_to_letter(1,0), code_to_letter(1,1),code_to_letter(1,2),code_to_letter(1,3),code_to_letter(1,4),code_to_letter(1,5),code_to_letter(1,6),code_to_letter(1,7));
	printf("    _  |###|___|###|___|###|___|###|___|  _    \n");
	printf("    6  | %c |#%c#| %c |#%c#| %c |#%c#| %c |#%c#|  6    \n",
	code_to_letter(2,0), code_to_letter(2,1),code_to_letter(2,2),code_to_letter(2,3),code_to_letter(2,4),code_to_letter(2,5),code_to_letter(2,6),code_to_letter(2,7));
	printf("    _  |___|###|___|###|___|###|___|###|  _    \n");
	printf("    5  |#%c#| %c |#%c#| %c |#%c#| %c |#%c#| %c |  5    \n",
	code_to_letter(3,0), code_to_letter(3,1),code_to_letter(3,2),code_to_letter(3,3),code_to_letter(3,4),code_to_letter(3,5),code_to_letter(3,6),code_to_letter(3,7));
	printf("    _  |###|___|###|___|###|___|###|___|  _    \n");
	printf("    4  | %c |#%c#| %c |#%c#| %c |#%c#| %c |#%c#|  4    \n",
	code_to_letter(4,0), code_to_letter(4,1),code_to_letter(4,2),code_to_letter(4,3),code_to_letter(4,4),code_to_letter(4,5),code_to_letter(4,6),code_to_letter(4,7));
	printf("    _  |___|###|___|###|___|###|___|###|  _    \n");
	printf("    3  |#%c#| %c |#%c#| %c |#%c#| %c |#%c#| %c |  3    \n",
	code_to_letter(5,0), code_to_letter(5,1),code_to_letter(5,2),code_to_letter(5,3),code_to_letter(5,4),code_to_letter(5,5),code_to_letter(5,6),code_to_letter(5,7));
	printf("    _  |###|___|###|___|###|___|###|___|  _    \n");
	printf("    2  | %c |#%c#| %c |#%c#| %c |#%c#| %c |#%c#|  2    \n",
	code_to_letter(6,0), code_to_letter(6,1),code_to_letter(6,2),code_to_letter(6,3),code_to_letter(6,4),code_to_letter(6,5),code_to_letter(6,6),code_to_letter(6,7));
	printf("    _  |___|###|___|###|___|###|___|###|  _    \n");
	printf("    1  |#%c#| %c |#%c#| %c |#%c#| %c |#%c#| %c |  1    \n",
	code_to_letter(7,0), code_to_letter(7,1),code_to_letter(7,2),code_to_letter(7,3),code_to_letter(7,4),code_to_letter(7,5),code_to_letter(7,6),code_to_letter(7,7));
	printf("    _  |###|___|###|___|###|___|###|___|  _    \n");
	printf("                                               \n");
	printf("    *  | A | B | C | D | E | F | G | H |  *    \n");
	printf("\n\n");
	
}

unsigned short int table_1(char a)//Преобразование символа в число
{
		switch(a){
		case 'a':
			return 0;
		case 'b':
			return 1;
		case 'c':
			return 2;
		case 'd':
			return 3;
		case 'e':
			return 4;
		case 'f':
			return 5;
		case 'g':
			return 6;
		case 'h':
			return 7;
		default:
			return -1;
		}
}
	
	
	
	
unsigned short int table_2(char b)//Преобразование символа в число
{	
		switch(b){
		case '1':
			return 7;
		case '2':
			return 6;
		case '3':
			return 5;
		case '4':
			return 4;
		case '5':
			return 3;
		case '6':
			return 2;
		case '7':
			return 1;
		case '8':
			return 0;
		default:
			return -1;
		}
}

char move_to(unsigned short int figure)
{
	if (figure == 0) {
		return '-';
	} else {
		return 'x';
	}
}

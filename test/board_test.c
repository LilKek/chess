#include <board.h>
#include <ctest.h>
#include <stdlib.h>

CTEST(move_suite, betrayal) // Проверка на возможность атаки на свои же фигуры
{
    //GIVEN
    board *a = (board *)malloc(sizeof(board) * 8 * 8);
    initial_board(a);
    
    //WHEN
    const int j = 0, i = 0, j1 = 1, i1 = 0;
    int check = move_checking(a, j, i, j1, i1); 
    
    //THEN
    const int expected = 0;

    ASSERT_EQUAL(expected, check);
}

CTEST(move_suite, move_pawn) // Ход пешки 
{	
    //GIVEN
    board *a = (board *)malloc(sizeof(board) * 8 * 8);
    initial_board(a);
    
    //WHEN
    int check1 = move_checking(a, 1, 0, 2, 0); //вперёд 
    
    int check3 = move_checking(a, 1, 0, 1, 0); //по диагонали
    
    int j = 1, i = 0, j1 = 2, i1 = 0;
    move(a, i, j, i1, j1);
    j = j1;
    j1 = 1;
    int check2 = move_checking(a, j, i, j1, i1); //назад
    
    initial_board(a);
    move(a, 0, 1, 0, 3); 					//проверка на возможность рубить пешкой
    move(a, 1, 6, 1, 4);
    int check4 = move_checking(a, 3, 0, 4, 1); 

    //THEN
    const int expected1 = 1;
    const int expected2 = 1;
    const int expected3 = 0;
    const int expected4 = 1;

    ASSERT_EQUAL(expected1, check1);
    ASSERT_EQUAL(expected2, check2);
    ASSERT_EQUAL(expected3, check3);
    ASSERT_EQUAL(expected4, check4);
}

CTEST(move_suite, move_rook) // Ход слона
{
    //GIVEN
    board *a = (board *)malloc(sizeof(board)*8*8);
    initial_board(a);
    
    //WHEN
    move(a, 0, 1, 1, 2); 	
    int check1 = move_checking(a, 0, 0, 4, 0); //Ход вперёд 
    move(a, 0, 0, 0, 4); 	
    int check2 = move_checking(a, 4, 0, 4, 4); //Ход вправо
    move(a, 0, 4, 4, 4); 	
    int check3 = move_checking(a, 4, 4, 4, 3); //Ход назад
    move(a, 4, 4, 3, 4); 	
    int check4 = move_checking(a, 4, 3, 4, 2); //Ход влево
    move(a, 3, 4, 2, 4); 	
    int check5 = move_checking(a, 4, 2, 6, 2); //Атака
    move(a, 2, 4, 2, 6);
    int check6 = move_checking(a, 6, 2, 4, 4); //Ход по диагонале 

    //THEN
    const int expected1 = 1;
    const int expected2 = 1;
    const int expected3 = 1;
    const int expected4 = 1;
    const int expected5 = 1;
    const int expected6 = 0;

    ASSERT_EQUAL(expected1, check1);
    ASSERT_EQUAL(expected2, check2);
    ASSERT_EQUAL(expected3, check3);
    ASSERT_EQUAL(expected4, check4);
    ASSERT_EQUAL(expected5, check5);
    ASSERT_EQUAL(expected6, check6);
}
CTEST(move_suite, move_hourse) // Ход коня
{
    //GIVEN
    board *a = (board *)malloc(sizeof(board)*8*8);
    initial_board(a);
    
    //WHEN
    int check1 = move_checking(a, 0, 1, 2, 0); //ход 
    move(a, 1, 0, 0, 2);
    int check2 = move_checking(a, 2, 0, 3, 2); //ход
    move(a, 0, 2, 2, 3);
    move(a, 2, 3, 4, 4);
    int check3 = move_checking(a, 4, 4, 6, 3); //атака
    move(a, 4, 4, 3, 6);
    move(a, 3, 6, 4, 4);
    int check4 = move_checking(a, 4, 4, 5, 4); //ложный ход
    int check5 = move_checking(a, 4, 4, 5, 5); //ложный ход
    
    //THEN
    const int expected1 = 1;
    const int expected2 = 1;
    const int expected3 = 1;
    const int expected4 = 0;
    const int expected5 = 0;

    ASSERT_EQUAL(expected1, check1);
    ASSERT_EQUAL(expected2, check2);
    ASSERT_EQUAL(expected3, check3);
    ASSERT_EQUAL(expected4, check4);
    ASSERT_EQUAL(expected5, check5);
}
CTEST(move_suite, move_el) // Ход слон
{
    //GIVEN
    board *a = (board *)malloc(sizeof(board)*8*8);
    initial_board(a);
    
    //WHEN
    move(a, 1, 1, 1, 2);
    int check1 = move_checking(a, 0, 2, 2, 0); //ход по диаголи  
    move(a, 2, 0, 0, 2);
    int check2 = move_checking(a, 2, 0, 6, 4); //атака 
    move(a, 0, 2, 4, 6);
    int check3 = move_checking(a, 6, 4, 4, 6); //атака
    move(a, 4, 6, 6, 4);
    int check4 = move_checking(a, 4, 6, 4, 4); //ложный ход
    int check5 = move_checking(a, 4, 6, 3, 6); //ложный ход
    
    //THEN
    const int expected1 = 1;
    const int expected2 = 1;
    const int expected3 = 1;
    const int expected4 = 0;
    const int expected5 = 0;

    ASSERT_EQUAL(expected1, check1);
    ASSERT_EQUAL(expected2, check2);
    ASSERT_EQUAL(expected3, check3);
    ASSERT_EQUAL(expected4, check4);
    ASSERT_EQUAL(expected5, check5);
}
CTEST(move_suite, move_queen) // Ход ферзя
{
    //GIVEN
    board *a = (board *)malloc(sizeof(board) * 8 * 8);
    initial_board(a);
    
    //WHEN
    move(a, 3, 1, 3, 3);
    int check1 = move_checking(a, 0, 3, 2, 3); //ход вперёд
    move(a, 3, 0, 3, 2);
    int check2 = move_checking(a, 2, 3, 4, 5); //по диагонали 
    move(a, 3, 2, 5, 4);
    int check3 = move_checking(a, 4, 5, 6, 5); //атака
    move(a, 5, 4, 5, 6);
    int check4 = move_checking(a, 6, 5, 6, 4); //атака влево
    move(a, 7, 6, 6, 6);
    int check5 = move_checking(a, 6, 6, 6, 4); //проверка на ложный ход
    move(a, 6, 6, 4, 6);
 
    //THEN
    const int expected1 = 1;
    const int expected2 = 1;
    const int expected3 = 1;
    const int expected4 = 1;
    const int expected5 = 0;

    ASSERT_EQUAL(expected1, check1);
    ASSERT_EQUAL(expected2, check2);
    ASSERT_EQUAL(expected3, check3);
    ASSERT_EQUAL(expected4, check4);
    ASSERT_EQUAL(expected5, check5);
}
CTEST(move_suite, move_king) // Ход король
{
    //GIVEN
    board *a = (board *)malloc(sizeof(board)*8*8);
    initial_board(a);
    
    //WHEN
    move(a, 3, 1, 3, 3);
    int check1 = move_checking(a, 0, 3, 1, 3); //ход вперёд  
    move(a, 3, 0, 3, 1);
    move(a, 3, 1, 3, 2);
    int check2 = move_checking(a, 2, 3, 3, 2); //по диагонали 
    move(a, 3, 2, 2, 3);
    int check3 = move_checking(a, 3, 2, 4, 3); //по диагонали
    move(a, 2, 3, 3, 4);
    move(a, 3, 4, 3, 5);
    int check4 = move_checking(a, 5, 3, 6, 3); //атака прямо
    move(a, 3, 5, 3, 6);
    int check5 = move_checking(a, 6, 3, 6, 2); //атака влево
    move(a, 3, 6, 2, 6);
    int check6 = move_checking(a, 6, 2, 4, 2); //ложный ход
	
    //THEN
    const int expected1 = 1;
    const int expected2 = 1;
    const int expected3 = 1;
    const int expected4 = 1;
    const int expected5 = 1;
    const int expected6 = 0;

    ASSERT_EQUAL(expected1, check1);
    ASSERT_EQUAL(expected2, check2);
    ASSERT_EQUAL(expected3, check3);
    ASSERT_EQUAL(expected4, check4);
    ASSERT_EQUAL(expected5, check5);
    ASSERT_EQUAL(expected6, check6);
}
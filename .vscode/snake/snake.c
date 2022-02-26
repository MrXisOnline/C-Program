
#include<stdio.h>
#include<string.h>
#include <time.h>
#include <stdlib.h>

static char board[25][150];
static int food_pos[2] = {0, 0};
static char snake[500];
static int snake_pos[2] = {15, 90};
// static int snake_length = 3;

void GenerateBoard(){
    for (int i=0; i<25; i++){
        for (int j=0; j<150; j++){
            board[i][j] = ' ';
        }
    }
    for (int i=0; i<150; i++){
        board[0][i] = '=';
    }
    for (int i=1; i<25; i++){
        board[i][0] = '|';
        board[i][149] = '|';
    }
    for (int i=0; i<150; i++){
        board[24][i] = '=';
    }
}

void PrintBoard(){
    for (int i=0; i<25; i++){
        for (int j=0; j<150; j++){
            printf("%c", board[i][j]);
        }
        printf("\n");
    }
}

void SpawnFood(){
    board[food_pos[0]][food_pos[1]] = ' ';
    food_pos[0] = rand() % 24;
    food_pos[1] = rand() % 149;
    if (food_pos[0] == 0){
        food_pos[0] = food_pos[0] + 1;
    }
    if (food_pos[1] == 0){
        food_pos[1] = food_pos[1] + 1;
    }
    board[food_pos[0]][food_pos[1]] = 'F';
}

void MoveSnake(){
    board[snake_pos[0]][snake_pos[1]] = ">";
    board[snake_pos[0]][snake_pos[1]-1] = "*";
    board[snake_pos[0]][snake_pos[1]-2] = "*";
}

void Up(){
    if (snake_pos[0]-1 < 1){
        snake_pos[0] = snake_pos[0] - 1;
    }else{
        snake_pos[0] = 0; snake_pos[1] = 0;
    }
}

void Down(){
    if (snake_pos[0]+1 > 25){
        snake_pos[0] = snake_pos[0] + 1;
    }else{
        snake_pos[0] = 0; snake_pos[1] = 0;
    }
}
void Left(){
    if (snake_pos[1]-1 < 0){
        snake_pos[1] = snake_pos[1] - 1;
    }else{
        snake_pos[0] = 0; snake_pos[1] = 0;
    }
}
void Right(){
    if (snake_pos[1]+1 > 150){
        snake_pos[1] = snake_pos[1] + 1;
    }else{
        snake_pos[0] = 0; snake_pos[1] = 0;
    }
}

void main()
{
    srand(time(NULL));
    GenerateBoard();
    SpawnSnake();
    for (int i=0; i<100; i++){
        PrintBoard();
        SpawnFood();
        system("cls");
    }
    
    
}
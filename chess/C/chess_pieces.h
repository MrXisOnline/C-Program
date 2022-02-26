#include<stdio.h>
#include<string.h>
#include<stdbool.h>
#include "tools.h"

typedef struct Pawn {
    char symbol;
    char name[4];
    char team[5];
    int position[2];
}Pawn;

typedef struct Rook {
    char symbol;
    char name[4];
    char team[5];
    int position[2];
}Rook;

typedef struct Knight {
    char symbol;
    char name[6];
    char team[5];
    int position[2];
}Knight;

typedef struct Bishop {
    char symbol;
    char name[6];
    char team[5];
    int position[2];
}Bishop;

typedef struct Queen {
    char symbol;
    char name[5];
    char team[5];
    int position[2];
}Queen;

typedef struct Emperor {
    char symbol;
    char name[7];
    char team[5];
    int position[2];
}Emperor;


List PawnValidMoves(char team[5], int position[2], char board[8][8], PositionHandler pos_handler){
    if (strcmp("white", team) == 0){
        List all_moves = {(int) NULL};
        char Place[25] = {(char) NULL};
        bool check_pawn_front = (position[0] != 0) ? true : false;
        bool check_pawn_left = (position[1] != 0) ? true : false;
        bool check_pawn_right = (position[1] != 7) ? true : false;
        if (check_pawn_front){
            bool front_clear = (board[position[0]-1][position[1]]) ? true : false;
            if (front_clear){
                int element[2] = {position[0]-1, position[1]};
                all_moves = append_int(all_moves.arr, element);
            }
        }
        if (check_pawn_left){
            bool left_diagonal_nclear = (board[position[0]-1][position[1]-1] != " ") ? true : false;
            if (left_diagonal_nclear){
                
            }
        }
    }
}

void main(){
    printf("%d\n", strcmp("white", "white"));
    if (false){
        printf("yes");
    }else{
        printf("nope");
    }
}
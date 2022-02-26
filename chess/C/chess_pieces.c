#include<stdio.h>
#include<string.h>
#include<stdbool.h>
#include "tools.h"
// #include "game_data.h"

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

typedef struct AllPieces {
    Pawn pawns[16];
    Rook rooks[4];
    Knight krights[4];
    Bishop bishops[4];
    Queen quens[2];
    Emperor empers[2];
}AllPieces;

union Pieces {
    Pawn *pawn;
    Rook *rook;
    Knight *knight;
    Bishop *bishop;
    Queen *quen;
    Emperor *emper;
};

struct group {
    int which;
    union Pieces p;
};

struct group get_piece(AllPieces allpiece, int position[2]){
    // Check pawns
    struct group gr = {0};
    for (int i=0; i<16; i++){
        if ((allpiece.pawns[i].position[0] == position[0]) && (allpiece.pawns[i].position[1] == position[1])){
            *gr.p.pawn = allpiece.pawns[i];
            gr.which = 1;
            return gr;
        }
    }
    for (int i=0; i<4; i++){
        if ((allpiece.rooks[i].position[0] == position[0]) && (allpiece.rooks[i].position[1] == position[1])){
            *gr.p.rook = allpiece.rooks[i];
            gr.which = 2;
            return gr;
        }
    }
    for (int i=0; i<4; i++){
        if ((allpiece.krights[i].position[0] == position[0]) && (allpiece.krights[i].position[1] == position[1])){
            *gr.p.knight = allpiece.krights[i];
            gr.which = 3;
            return gr;
        }
    }
    for (int i=0; i<4; i++){
        if ((allpiece.bishops[i].position[0] == position[0]) && (allpiece.bishops[i].position[1] == position[1])){
            *gr.p.bishop = allpiece.bishops[i];
            gr.which = 4;
            return gr;
        }
    }
    for (int i=0; i<2; i++){
        if ((allpiece.quens[i].position[0] == position[0]) && (allpiece.quens[i].position[1] == position[1])){
            *gr.p.quen = allpiece.quens[i];
            gr.which = 5;
            return gr;
        }
    }
    for (int i=0; i<2; i++){
        if ((allpiece.empers[i].position[0] == position[0]) && (allpiece.empers[i].position[1] == position[1])){
            *gr.p.emper = allpiece.empers[i];
            gr.which = 6;
            return gr;
        }
    }
    return gr;
}

// List PawnValidMoves(char team[5], int position[2], char board[8][8], AllPieces allpieces){
//     if (strcmp("white", team) == 0){
//         List all_moves = {(int) NULL};
//         bool check_pawn_front = (position[0] != 0) ? true : false;
//         bool check_pawn_left = (position[1] != 0) ? true : false;
//         bool check_pawn_right = (position[1] != 7) ? true : false;
//         if (check_pawn_front){
//             bool front_clear = (board[position[0]-1][position[1]]) ? true : false;
//             if (front_clear){
//                 int element[2] = {position[0]-1, position[1]};
//                 all_moves = append_int(all_moves.arr, element);
//             }
//         }
//         if (check_pawn_left){
//             bool left_diagonal_nclear = (board[position[0]-1][position[1]-1] != " ") ? true : false;
//             if (left_diagonal_nclear){
//                 int position[2] = {position[0]-1, position[1]-1};
//                 struct group gr = get_piece(allpieces, position);
//                 if (gr.which == 1){
//                     if (strcmp(*gr.p.pawn.team, team)) all_moves = append_int(all_moves.arr, position);
//                 }else if (gr.which == 2){
//                     if (strcmp(*gr.p.rook.team, team)) all_moves = append_int(all_moves.arr, position);
//                 }else if (gr.which == 3){
//                     if (strcmp(*gr.p.knight.team, team)) all_moves = append_int(all_moves.arr, position);
//                 }else if (gr.which == 4){
//                     if (strcmp(*gr.p.bishop.team, team)) all_moves = append_int(all_moves.arr, position);
//                 }else if (gr.which == 5){
//                     if (strcmp(*gr.p.quen.team, team)) all_moves = append_int(all_moves.arr, position);
//                 }else if (gr.which == 6){
//                     if (strcmp(*gr.p.emper.team, team)) all_moves = append_int(all_moves.arr, position);
//                 }
//             }
//         }
//         if (check_pawn_right){
//             bool right_diagonal_nclear = (board[position[0]-1][position[1]+1] != " ") ? true : false;
//             if (right_diagonal_nclear){
//                 int position[2] = {position[0]-1, position[1]+1};
//                 struct group gr = get_piece(allpieces, position);
//                 if (gr.which == 1){
//                     if (strcmp(gr.p.pawn.team, team)) all_moves = append_int(all_moves.arr, position);
//                 }else if (gr.which == 2){
//                     if (strcmp(gr.p.rook.team, team)) all_moves = append_int(all_moves.arr, position);
//                 }else if (gr.which == 3){
//                     if (strcmp(gr.p.knight.team, team)) all_moves = append_int(all_moves.arr, position);
//                 }else if (gr.which == 4){
//                     if (strcmp(gr.p.bishop.team, team)) all_moves = append_int(all_moves.arr, position);
//                 }else if (gr.which == 5){
//                     if (strcmp(gr.p.quen.team, team)) all_moves = append_int(all_moves.arr, position);
//                 }else if (gr.which == 6){
//                     if (strcmp(gr.p.emper.team, team)) all_moves = append_int(all_moves.arr, position);
//                 }
//             }
//         }
//     }else{
//         List all_moves = {(int) NULL};
//         bool check_pawn_front = (position[0] != 0) ? true : false;
//         bool check_pawn_left = (position[1] != 0) ? true : false;
//         bool check_pawn_right = (position[1] != 7) ? true : false;
//         if (check_pawn_front){
//             bool front_clear = (board[position[0]+1][position[1]]) ? true : false;
//             if (front_clear){
//                 int element[2] = {position[0]+1, position[1]};
//                 all_moves = append_int(all_moves.arr, element);
//             }
//         }
//         if (check_pawn_left){
//             bool left_diagonal_nclear = (board[position[0]-1][position[1]-1] != " ") ? true : false;
//             if (left_diagonal_nclear){
//                 int position[2] = {position[0]+1, position[1]-1};
//                 struct group gr = get_piece(allpieces, position);
//                 if (gr.which == 1){
//                     if (strcmp(gr.p.pawn.team, team)) all_moves = append_int(all_moves.arr, position);
//                 }else if (gr.which == 2){
//                     if (strcmp(gr.p.rook.team, team)) all_moves = append_int(all_moves.arr, position);
//                 }else if (gr.which == 3){
//                     if (strcmp(gr.p.knight.team, team)) all_moves = append_int(all_moves.arr, position);
//                 }else if (gr.which == 4){
//                     if (strcmp(gr.p.bishop.team, team)) all_moves = append_int(all_moves.arr, position);
//                 }else if (gr.which == 5){
//                     if (strcmp(gr.p.quen.team, team)) all_moves = append_int(all_moves.arr, position);
//                 }else if (gr.which == 6){
//                     if (strcmp(gr.p.emper.team, team)) all_moves = append_int(all_moves.arr, position);
//                 }
//             }
//         }
//         if (check_pawn_right){
//             bool right_diagonal_nclear = (board[position[0]-1][position[1]+1] != " ") ? true : false;
//             if (right_diagonal_nclear){
//                 int position[2] = {position[0]+1, position[1]+1};
//                 struct group gr = get_piece(allpieces, position);
//                 if (gr.which == 1){
//                     if (strcmp(gr.p.pawn.team, team)) all_moves = append_int(all_moves.arr, position);
//                 }else if (gr.which == 2){
//                     if (strcmp(gr.p.rook.team, team)) all_moves = append_int(all_moves.arr, position);
//                 }else if (gr.which == 3){
//                     if (strcmp(gr.p.knight.team, team)) all_moves = append_int(all_moves.arr, position);
//                 }else if (gr.which == 4){
//                     if (strcmp(gr.p.bishop.team, team)) all_moves = append_int(all_moves.arr, position);
//                 }else if (gr.which == 5){
//                     if (strcmp(gr.p.quen.team, team)) all_moves = append_int(all_moves.arr, position);
//                 }else if (gr.which == 6){
//                     if (strcmp(gr.p.emper.team, team)) all_moves = append_int(all_moves.arr, position);
//                 }
//             }
//         }
//     }
//     return all_moves;
// }

struct PAWNS {
    Pawn pawns[16];
};

struct PAWNS GetAllPawn(List positions){
    struct PAWNS p;
    for (int i=0; i<8; i++){
        Pawn pawn = {'P', "Pawn", "white"};
        pawn.position[0] = positions.arr[i][0];
        pawn.position[1] = positions.arr[i][1];
        p.pawns[i] = pawn;
    }
    for (int i=8; i<16; i++){
        Pawn pawn = {'P', "Pawn", "black"};
        pawn.position[0] = positions.arr[i][0];
        pawn.position[1] = positions.arr[i][1];
        p.pawns[i] = pawn;
    }
    return p;
}

struct ROOKS {
    Rook rooks[4];
};

struct ROOKS GetAllRook(List positions){
    struct ROOKS r;
    for (int i=0; i<2; i++){
        Rook rook = {'R', "Rook", "white"};
        rook.position[0] = positions.arr[i][0];
        rook.position[1] = positions.arr[i][1];
        r.rooks[i] = rook;
    }
    for (int i=2; i<4; i++){
        Rook rook = {'R', "Rook", "black"};
        rook.position[0] = positions.arr[i][0];
        rook.position[1] = positions.arr[i][1];
        r.rooks[i] = rook;
    }
    return r;
}

struct KNIGHTS {
    Knight knights[4];
};

struct KNIGHTS GetAllKnight(List positions){
    struct KNIGHTS k;
    for (int i=0; i<2; i++){
        Knight knight = {'K', "Knight", "white"};
        knight.position[0] = positions.arr[i][0];
        knight.position[1] = positions.arr[i][1];
        k.knights[i] = knight;
    }
    for (int i=2; i<4; i++){
        Knight knight = {'K', "Knight", "black"};
        knight.position[0] = positions.arr[i][0];
        knight.position[1] = positions.arr[i][1];
        k.knights[i] = knight;
    }
    return k;
}

struct BISHOPS {
    Bishop bishops[4];
};

struct BISHOPS GetAllBishop(List positions){
    struct BISHOPS b;
    for (int i=0; i<2; i++){
        Bishop bishop = {'B', "Bishop", "white"};
        bishop.position[0] = positions.arr[i][0];
        bishop.position[1] = positions.arr[i][1];
        b.bishops[i] = bishop;
    }
    for (int i=2; i<4; i++){
        Bishop bishop = {'B', "Bishop", "black"};
        bishop.position[0] = positions.arr[i][0];
        bishop.position[1] = positions.arr[i][1];
        b.bishops[i] = bishop;
    }
    return b;
}

void main(){
    printf("run");
    List posp = {{{6, 0}, {6, 1}, {6, 2}, {6, 3}, {6, 4}, {6, 5}, {6, 6}, {6, 7}, {1, 0}, {1, 1}, {1, 2}, {1, 3}, {1, 4}, {1, 5}, {1, 6}, {1, 7}}};
    struct PAWNS pawns = GetAllPawn(posp);
    List posr = {{{7, 0}, {7, 7}, {0,0}, {0, 7}}};
    struct ROOKS rooks = GetAllRook(posr);
    List posk = {{{7, 1}, {7, 6}, {0,1}, {0, 6}}};
    struct KNIGHTS knights = GetAllKnight(posk);
    List posb = {{{7, 2}, {7, 5}, {0, 2}, {0, 5}}};
    struct BISHOPS bishops = GetAllBishop(posb);
    // // Queen quens[2] = {(Queen) {"Q", "Queen", "white", {7, 3}}, (Queen) {"Q", "Queen", "black", {0, 3}}};
    AllPieces allpiece = {pawns.pawns, rooks.rooks, knights.knights, bishops.bishops};
    printf("%c", allpiece.pawns[0].symbol);
}
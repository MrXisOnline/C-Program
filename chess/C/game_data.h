#include "tools.h"
#include "chess_pieces.h"

typedef struct WhitePieces {
    Pawn pawns[8];
    Rook rooks[2];
    Knight krights[2];
    Bishop bishops[2];
    Queen quen[1];
    Emperor emper[1];
}WhitePieces;

typedef struct BlackPieces {
    Pawn pawns[8];
    Rook rooks[2];
    Knight krights[2];
    Bishop bishops[2];
    Queen quen[1];
    Emperor emper[1];
}BlackPieces;

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
            gr.p.pawn = pawns[i];
            gr.which = true;
            return gr;
        }
    }
    for (int i=0; i<4; i++){
        if ((allpiece.rooks[i].position[0] == position[0]) && (allpiece.rooks[i].position[1] == position[1])){
            gr.p.rook = allpiece.rooks[i];
            gr.which = true;
            return gr;
        }
    }
    for (int i=0; i<4; i++){
        if ((allpiece.krights[i].position[0] == position[0]) && (allpiece.krights[i].position[1] == position[1])){
            gr.p.knight = allpiece.krights[i];
            gr.which = true;
            return gr;
        }
    }
    for (int i=0; i<4; i++){
        if ((allpiece.bishops[i].position[0] == position[0]) && (allpiece.bishops[i].position[1] == position[1])){
            gr.p.bishop = allpiece.bishops[i];
            gr.which = true;
            return gr;
        }
    }
    for (int i=0; i<2; i++){
        if ((allpiece.quens[i].position[0] == position[0]) && (allpiece.quens[i].position[1] == position[1])){
            gr.p.quen = allpiece.quens[i];
            gr.which = true;
            return gr;
        }
    }
    for (int i=0; i<2; i++){
        if ((allpiece.empers[i].position[0] == position[0]) && (allpiece.empers[i].position[1] == position[1])){
            gr.p.emper = allpiece.empers[i];
            gr.which = true;
            return gr;
        }
    }
    gr.which = false;
    return gr;
}


void DisplayBoard(char board[8][8]){
    int row = 0;
    printf(" ");
    for (int c=0; c<8; c++) printf(" %d", c);
    printf("\n");
    printf(" ");
    for (int i=0; i<8; i++) printf(" _");
    printf("\n");
    for (int i=1; i<17; i++){
        if (i%2==1){
            char cur_elements[] = board[row];
            printf("%d ", row);
            printf("|");
            // int cur_e_index = 0;
            for (int j=0; j<8; j++) printf("%c|", cur_elements[j]);
            printf("\n");
            row += 1;
        }else{
            printf(" |");
            for (int i=0; i<8; i++) printf("_|");
            printf("\n");
        }
    }
}
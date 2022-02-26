#include<stdio.h>

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

void main(){
    char board[][] = {}
}
#include<stdio.h>
#include<stdbool.h>

typedef struct List {
    int arr[25][2];
}List;

List copyarr(List moves, int arr[25][2]){
    for (int i=0; i<25; i++){
        moves.arr[i][0] = arr[i][0]; moves.arr[i][1] = arr[i][1];
    }
    return moves;
}

List append_int(int arr[25][2], int element[2]){
    for (int i = 0; i < 25; i++){
        if (arr[i][0] == (int) NULL){
            arr[i][0] = element[0]; arr[i][1] = element[1];
            break;
        }
    }
    // List moves;
    List moves = copyarr(moves, arr);
    return moves;
}

List pop_int(int arr[25][2], int index){
    int t_index=24;
    arr[index][0] = (int) NULL; arr[index][1] = (int) NULL;
    for (int i=index+1; i < 25; i++){
        if (arr[i][0] == (int) NULL){
            t_index = i;
            break;
        }
    }
    for (int i = index; i < t_index+1; i++){
        arr[i][0] = arr[i+1][0]; arr[i][1] = arr[i+1][1];
    }
    // List moves;
    List moves = copyarr(moves, arr);
    return moves;
}

void print_list(int arr[25][2]){
    int t_index = 25;
    for (int i=0; i < 25; i++){
        if (arr[i][0] == (int) NULL){
            t_index = i;
            break;
        }
    }
    for (int i=0; i<t_index; i++){
        printf("[%d %d]\t", arr[i][0], arr[i][1]);
    }
}


// void main(){
//     List moves = {(int) NULL};
//     int element[2] = {1, 2};
//     int element2[2] = {3, 4};
//     moves = append_int(moves.arr, element);
//     print_list(moves.arr);
//     moves = append_int(moves.arr, element2);
//     printf("\n");
//     print_list(moves.arr);
//     moves = pop_int(moves.arr, 0);
//     printf("\n");
//     print_list(moves.arr);
// }
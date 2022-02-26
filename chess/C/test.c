#include<stdio.h>

typedef struct List {
    // int x;
    int arr[10];
}List;

// typedef List (*Operation)(int a, int b);
// typedef struct Point {
//     int x;
//     int y;
//     Operation add;
// }Point;

// List Addition(int a, int b){
//     List l;
//     l.arr[0] = a;
//     l.arr[1] = b;
//     return l;
// }

void main(){
    int arr[10] = {10};
    List l;
    l.arr = arr;
    // Point p1 = {6, 2.2, Addition};
    // List arr = p1.add(p1.x, p1.y);
    // printf("%d, %d", arr.arr[0], arr.arr[1]);
    // printf("%d", p1.add(p1.x, p1.y));
    // int arr[10][2] = {(int) NULL};
    // arr[0][0] = 4; arr[0][1] = 3;
    // // printf("%d", sizeof(arr)/sizeof(arr[0]));
    // if (arr[4] == (int) NULL){
    //     printf("Null Char");
    // }else{
    //     printf("Not Null");
    // }
}
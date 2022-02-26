#include<stdio.h>

void main(){
    int x = 5; // 00000101
    printf("%d\n", x);
    printf("x<<1: %d\n", x<<1); // 00001010
    printf("x>>1: %d\n", x>>1); // 00000010
    int y = 5; // 00000101
    printf("%d\n", y);
    y<<=1; // 00001010
    printf("%d\n", y);
}
#include<stdio.h>

void main(){
    int x = 1;
    int* int_ptr = &x;
    printf("%d\n%p", x, int_ptr);
}
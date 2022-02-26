#include<stdio.h>

void main(){
    int a, b;
    printf("a = ");
    scanf("%d", &a);
    printf("b = ");
    scanf("%d", &b);
    int c = a;
    a = b;
    b = c;
    printf("a=%d\nb=%d", a, b);
}
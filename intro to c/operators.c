#include<stdio.h>
#include<stdbool.h>

void main(){
    int a = 4, b = 2;
    printf("%d %d %d %d %d\n", (a+b), (a-b), (a*b), (a/b), (a%b));
    printf("%d %d\n", a++, b++);
    printf("%d %d %d %d\n", a < b, a > b, a >= b, a <= b);
    printf("%d %d\n", a < b && a > b,  a >= b || a <= b);
    printf("%s", a < b ? "true" : "false");
    // bool x, y = true;
}
#include<stdio.h>

void main(){
    int x = 65;
    printf("%d\n", x);
    printf("%d\n", sizeof(x));
    x = (char) x;
    printf("%c\n", x);
    char j = (char) 68;
    printf("%c\n", j);
    printf("%d\n", (int) j);
    int y, a;
    a = (y = 4, y + 2);
    printf("%d", a);
}
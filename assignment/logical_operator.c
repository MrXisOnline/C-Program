#include<stdio.h>

void main()
{
    int a = 3, b = 2;
    printf("%s\n", (a > 3) && (b > 3) ? "true" : "false");
    printf("%s\n", (a > 3) || (b < 3) ? "true" : "false");
    printf("%s\n", (!(a > 3)) ? "true" : "false");
}
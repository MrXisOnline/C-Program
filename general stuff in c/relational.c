#include<stdio.h>

void main()
{
    int a;
    printf("a :");
    scanf("%d", a);
    printf("%s\n", (a < 20) ? "true" : "false");
    printf("%s\n", (a > 20) ? "true" : "false");
    printf("%s\n", (a <= 20) ? "true" : "false");
    printf("%s\n", (a >= 20) ? "true" : "false");
    printf("%s\n", (a == 20) ? "true" : "false");
    printf("%s\n", (a != 20) ? "true" : "false");
}
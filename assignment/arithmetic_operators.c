#include<stdio.h>

void main()
{
    int a, b;
    printf("Enter a, b: ");
    scanf("%d, %d", &a, &b);
    printf("Arithmetic operations -->\n");
    printf("a + b = %d\n", a+b);
    printf("a - b = %d\n", a-b);
    printf("a * b = %d\n", a*b);
    printf("a / b = %d\n", a/b);
    printf("a %% b = %d\n", a%b);
}
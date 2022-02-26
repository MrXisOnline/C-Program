#include<stdio.h>

void main()
{
    int a, b, temp;
    printf("Enter Numbers a, b: ");
    scanf("%d, %d", &a, &b);
    temp = b;
    b = a; 
    a = temp;
    printf("Numbers a, b: %d, %d", a, b);
}
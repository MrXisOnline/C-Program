#include<stdio.h>

void main()
{
    int a;
    printf("Enter Numbers Age: ");
    scanf("%d", &a);
    
    switch (a)
    {
    case 3:
        printf("It is 3.");
        break;
    
    default:
        printf("It isn't 3.");
        break;
    }
}
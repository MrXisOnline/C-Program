#include<stdio.h>

void main()
{
    int i;
    printf("Enter Num: ");
    scanf("%d", &i);
    do{
        printf("%d ", i);
        i++;
    }while (i<5);
}
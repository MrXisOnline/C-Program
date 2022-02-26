#include<stdio.h>

void main()
{
    int a, id;
    printf("Enter Age, Id(1 or 0) : ");
    scanf("%d, %d", &a, &id);
    if (a >= 18){
        if (id == 1){
            printf("You Can Vote.");
        }else{
            printf("You Can't Vote.");
        }
    }else{
        printf("You Can't Vote.");
    }
}
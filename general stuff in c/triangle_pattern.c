#include<stdio.h>

void main()
{
    int line;
    printf("Length :");
    scanf("%d", &line);

    for (int i = 1; i <= line; i++){
        for (int j = 1; j <= i; j++)
        {
            printf("%d", j);
        }
        printf("\n");
    }
}
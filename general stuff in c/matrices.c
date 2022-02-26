#include<stdio.h>

void main()
{
    int a, b;
    printf("Enter Shape a, b: ");
    scanf("%d, %d", &a, &b);
    int matrix[a][b];
    for (int i=0; i<a; i++){
        for (int j=0; j<b; j++) {
            printf("Enter element :");
            scanf("%d", &matrix[i][j]);
        }
    }
    
    for (int i=0; i < a; i++){
        for (int j=0; j < b; j++){
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}
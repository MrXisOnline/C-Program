#include<stdio.h>

void main()
{
    int line, start_threshold, end_threshold;
    printf("Length : ");
    scanf("%d", &line);

    if (line%2 == 1){
        line += 1;
    }
    for (int i = 0; i <= line/2; i++){
        start_threshold = line/2 - i;
        end_threshold = line/2 + i;
        for (int j = 0; j <= line; j++){
            if (j >= start_threshold && j <= end_threshold){
                printf("*");
            }else{
                printf(" ");
            }
        }
        printf("\n");
    }
    for (int i = 0; i <= line/2; i++){
        start_threshold = i;
        end_threshold = line - i;
        for (int j = 0; j <= line; j++){
            if (j >= start_threshold && j <= end_threshold){
                printf("*");
            }else{
                printf(" ");
            }
        }
        printf("\n");
    }
}
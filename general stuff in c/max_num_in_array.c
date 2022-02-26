#include<stdio.h>

void main()
{
    int max, max_in, N = 10, arr[10];
    for (int i=0; i<N; i++){
        printf("Enter %d element: ", i+1);
        scanf("%d", &arr[i]);
    }
    max = arr[0];
    max_in = 0;
    for (int i=0; i<N; i++){
        if (arr[i] > max){
            max = arr[i];
            max_in = i;
        }
    }
    printf("Array : ");
    for (int i=0; i<N; i++) printf("%d ", arr[i]);
    printf("\nMax: %d, Index: %d", max, max_in);
}
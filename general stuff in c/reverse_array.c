#include<stdio.h>

void main()
{
    int arr[10];
    for (int i = 0; i < 10; i++){
        printf("Enter %d element: ", i+1);
        scanf("%d", &arr[i]);
        // printf("\n");
    }
    printf("\nArray : ");
    for (int i = 0; i <= 9; i++) printf("%d ", arr[i]);
    printf("\nArray in Reverse: ");
    for (int i = 9; i >= 0; i--) printf("%d ", arr[i]);
    
}
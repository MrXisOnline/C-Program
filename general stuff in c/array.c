#include<stdio.h>

void main()
{
    // int arr[3]; // initializing array
    // arr[0] = 2; // declaring value by index
    // arr[1] = 1;
    // arr[2] = 5;

    
    // int arr[] = {1, 2, 3, 4}; // Array initializing and declaring values
    
    // // printing array value
    // for (int i=0; i < 4; i++){
    //     printf("%d ", arr[i]);
    // }

    // printf("\n");

    // // More better method to do this
    // int size = sizeof(arr) / sizeof(arr[0]);
    // for (int i=0; i < size; i++){
    //     printf("%d ", arr[i]);
    // }

    // // Getting value in array by user
    // int arr[3]; // initializing array
    // for (int i=0; i < 3; i++){
    //     printf("\nEnter %d value: ", i);
    //     scanf("%d", &arr[i]);
    // }

    // printf("\n");

    // for (int i=0; i < 3; i++){
    //     printf("%d ", arr[i]);
    // }

    int arr[6];
    for (int i=0; i < 4; i++){
        printf("\nEnter %d value: ", i);
        scanf("%d", &arr[i]);
    }

    printf("\n");
    int size = sizeof(arr) / sizeof(arr[0]);
    for (int i=0; i < size; i++){
        printf("%d ", arr[i]);
    }
}
#include <stdio.h>

void main(){
    int len, i, j, temp;
    printf("Enter Length :"); scanf("%d", &len);
    int arr[len];
    for (i=0; i<len; i++){
        printf("Enter Element :"); scanf("%d", &arr[i]);
    }
    printf("\nBefore Sorting ...\n[");
    for (i=0; i<len; i++) printf("%d ", arr[i]);
    printf("]\n");
    // Bubble Sort
    for (i=0; i<len; i++){
        for (j=0; j<len-1; j++){
            if (arr[j] > arr[j+1]){
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
    printf("\nAfter Sorting ...\n[");
    for (i=0; i<len; i++) printf("%d ", arr[i]);
    printf("]\n");
}
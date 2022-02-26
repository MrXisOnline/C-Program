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
    // Insertion Sort
    for (i=1; i<len; i++){
        for (j=0; j<i; j++){
            if (arr[i] < arr[j]){
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
    printf("\nAfter Sorting ...\n[");
    for (i=0; i<len; i++) printf("%d ", arr[i]);
    printf("]\n");
}
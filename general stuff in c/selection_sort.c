#include<stdio.h>
#include<stdlib.h>

void main(){
    int l;
    int i, j;
    printf("Enter Length: "); scanf("%d", &l);
    int arr[l];
    for (int i=0; i<l; i++){
        printf("Enter Element: "); scanf("%d", &arr[i]);
    }
    printf("\nBefore Sorting ...\n[");
    for (i=0; i<l; i++) printf("%d ", arr[i]);
    printf("]\n");
    // Selection Sort 
    for (i=0; i<l; i++){
        int min = arr[i];
        int temp;
        int min_pos;
        for (j=i+1; j < l; j++){
            if (arr[j] < min){
                min = arr[j];
                min_pos = j;
            }
        }

        if (min != arr[i]){
            temp = arr[i];
            arr[i] = arr[min_pos];
            arr[min_pos] = temp;
        }
    }
    printf("\nAfter Sorting ...\n[");
    for (i=0; i<l; i++) printf("%d ", arr[i]);
    printf("]\n");
}
#include <stdio.h>

int numbers[] = {4, 0, 6, 1, 5, 2, 3};

void merge(int low, int mid, int high){
    int helper[high];
    for (int i=low; i <= high; i++) helper[i] = numbers[i];
    int i = low;
    int j = mid + 1;
    int k = low;

    while (i <= mid && j <= high){
        if (helper[i] <= helper[j]){
            numbers[k] = helper[i];
            i++;
        }else{
            numbers[k] = helper[j];
            j++;
        }
        k++;
    }

    while (i <= mid){
        numbers[k] = helper[i];
        k++;
        i++;
    }
}

void mergesort(int low, int high){
    if (low < high){
        int mid = low + (high-low)/2;
        mergesort(low, mid);
        mergesort(mid+1, high);
        merge(low, mid, high);
    }
}

void main(){
    printf("\n[");
    for (int i=0; i < 7; i++) printf("%d ", numbers[i]);
    mergesort(0, 6);
    printf("]\n[");
    for (int i=0; i < 7; i++) printf("%d ", numbers[i]);
    printf("]\n");
}
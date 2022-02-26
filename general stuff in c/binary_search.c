#include<stdio.h>
#include<stdbool.h>

void main()
{
    int arr_length, i, element, min, max, mid, pos=-1;
    printf("Enter Array Lenght: ");
    scanf("%d", &arr_length);
    int arr[arr_length];
    for (i=0; i < arr_length; i++){
        printf("Enter Element: ");
        scanf("%d", &arr[i]);
    }
    printf("\n");
    
    printf("Enter Element to Search: "); scanf("%d", &element);
    
    min = 0;
    max = arr_length;
    mid = (min + max)/2;
    bool run = true;
    i=
    while (i<arr_length){
        if (arr[mid] == element){
            pos = mid;
            break;
        }
        else if (arr[mid] >= element){
            max = mid + 1;
        }
        else{
            min = mid - 1;
        }
    }
    
    if (pos != -1){
        printf("Element Position: %d", pos);
    }else{
        printf("Not Found");
    }
}
#include<stdio.h>
#include<stdlib.h>

void main(){
    int l;
    printf("Length : "); scanf("%d", &l);
    int arr[l];
    for (int i=0; i<l; i++){
        printf("Enter Element :"); scanf("%d", &arr[i]);
    }
    int e, pos=-1;
    printf("Enter Element To Search: "); scanf("%d", &e);
    for (int i=0; i<l; i++){
        if (arr[i] == e){
            pos = i;
            break;
        }
    }
    if (pos != -1){
        printf("Element found at %d", pos);
    }else{
        printf("Element not found");
    }
}
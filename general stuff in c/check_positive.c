#include<stdio.h>

void main(){
    int a;
    printf("Enter Number: ");
    scanf("%d", &a);
    if (a >= 0){
        printf("a is positive");
    }else{
        printf("a is negative");
    }
    printf("\n");
}
#include<stdio.h>

int square(int x){
    return x*x;
}

void main(){
    int x;
    printf("enter x: "); scanf("%d", &x);
    printf("square of x is %d", square(x));
}

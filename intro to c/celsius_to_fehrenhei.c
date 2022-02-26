#include<stdio.h>

void main(){
    int temp;
    printf("Enter Temp. in Celsius -> ");
    scanf("%d", &temp);
    temp = (9 * temp)/5 + 32;
    printf("Temp. in Fehrenheit -> %d", temp);
}
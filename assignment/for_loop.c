#include<stdio.h>

void main()
{   
    int a, temp, exp;
    printf("Enter Num, Exp :");
    scanf("%d, %d", &a, &exp);
    temp = a;
    for (int i=1; i<exp; i++){
        a *= temp;
    }
    printf("%d to raise power %d is %d.", temp, exp, a);
}
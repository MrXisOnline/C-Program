#include<stdio.h>

void main()
{
    int a, exp, i=1, temp;
    printf("Enter num, exp :");
    scanf("%d, %d", &a, &exp);
    temp = a;
    inc: i++;
    a *= temp;
    if (i < exp){
        goto inc;
    }
    printf("%d to raise power %d is %d", temp, exp, a);
}
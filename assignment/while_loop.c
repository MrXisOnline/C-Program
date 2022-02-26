#include<stdio.h>

void main()
{
    int a, temp, exp, i=1;
    printf("Enter Num, Exp :");
    scanf("%d, %d", &a, &exp);
    temp = a;
    while (i<exp)
    {
        a *= temp;
        i++;
    }
    printf("%d to raise power %d is %d.", temp, exp, a);
}
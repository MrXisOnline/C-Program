#include<stdio.h>

void main()
{
    int num, pow, var;
    int i = 1;
    printf("Number, Power :");
    scanf("%d, %d", &num, &pow);
    var = num;
    inc_pow: if (i < pow) {
        num = var * num;
        i++;
        goto inc_pow;
    }
    printf("\n%d", num);
}
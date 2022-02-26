#include<stdio.h>

void main()
{
    int i = 1;
    label: if (i < 5){
        printf("%d\n", i);
        i++;
        goto label;
    }
}
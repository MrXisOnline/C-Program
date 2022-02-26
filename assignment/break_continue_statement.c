#include<stdio.h>

void main()
{
    int a = 1;
    while (a < 10)
    {
        a++;
        if (a < 3){
            continue;
        }else if (a < 6){
            printf("%d\n", a);
        }else if (a == 6){
            break;
        }
    }
    
}
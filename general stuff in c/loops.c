#include<stdio.h>

void main()
{
    // Take a number and digit and tell if number contains that digit
    int num, digit, temp, flag;
    printf("Enter Num: ");
    scanf("%d", &num);
    printf("Enter Digit: ");
    scanf("%d", &digit);
    temp = num;
    while (num != 0)
    {
        if (num%10 == digit){
            flag = 1;
            break;
        }else{
            num = num / 10;
        }
    }

    if (flag == 1){
        printf("%d contains %d", temp, digit);
    }else{
        printf("No %d doesn't contains %d", temp, digit);
    }
    
}
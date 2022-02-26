#include<stdio.h>

void main()
{
    int a=4, b=5;
    // Arithmetic operation
    printf("a + b = %d\n", a+b);
    printf("a - b = %d\n", a-b);
    printf("a * b = %d\n", a*b);
    printf("a / b = %d\n", a/b);
    printf("a %% b = %d\n", a%b);
    
    // Relational Operator
    printf("\n");
    if ((a>3)){
        printf("true");
    }else{
        printf("false");
    }
printf("\n");
    if ((a<=3)){
        printf("true");
    }else{
        printf("false");
    }
    printf("\n");
    if ((a<3)){
        printf("true");
    }else{
        printf("false");
    }
    printf("\n");
    if ((b>=3)){
        printf("true");
    }else{
        printf("false");
    }
    printf("\n");
    if ((b == 3)){
        printf("true");
    }else{
        printf("false");
    }
printf("\n");
    if ((b != 3)){
        printf("true");
    }else{
        printf("false");
    }
printf("\n");

    // printf("%s\n", a > 3 ? "true" : "false");
    // printf("%s\n", b < 3 ? "true" : "false");
    // printf("%s\n", a <= 3 ? "true" : "false");
    // printf("%s\n", b >= 3 ? "true" : "false");
    // printf("%s\n", a == 3 ? "true" : "false");
    // printf("%s\n", a != 3 ? "true" : "false");

    // // Logical Operator

    if ((a > 3) && (b > 3)){
        printf("true");
    }else{
        printf("false");
    }

    printf("\n");

    if ((a > 3) || (b < 3)){
        printf("true");
    }else{
        printf("false");
    }

    printf("\n");

    if (!((a > 3) || (b < 3))){
        printf("true");
    }else{
        printf("false");
    }
    
    // printf("%s\n", (a > 3) && (b > 3) ? "true" : "false");
    // printf("%s\n", (a > 3) || (b > 3) ? "true" : "false");
}
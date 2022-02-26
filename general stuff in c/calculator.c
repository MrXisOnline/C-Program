#include<stdio.h>

void main(){
    int a, b;
    char op;
    printf("Enter Expression: ");
    scanf("%d, %c, %d", &a, &op, &b);
    
    switch (op)
    {
    case '+':
        printf("Output: %d", a+b);
        break;
    case '-':
        printf("Output: %d", a-b);
        break;
    case '*':
        printf("Output: %d", a*b);
        break;
    case '/':
        printf("Output: %d", a/b);
        break;
    case '%':
        printf("Output: %d", a%b);
        break;
    default:
        printf("Invalid Operator!");
    }
}
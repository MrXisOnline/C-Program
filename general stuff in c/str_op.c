#include<stdio.h>

void main()
{
    int pos;
    char c, str[20];
    printf("Enter String: ");
    gets(str);
    fflush(stdin);
    printf("%s\n", str);
    printf("Enter Position: ");
    scanf("%d", &pos);
    printf("Enter Character: ");
    fflush(stdin);
    c = getchar();
    fflush(stdin);
    str[pos] = c;
    printf("%s", str);
}
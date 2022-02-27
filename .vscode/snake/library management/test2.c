#include <stdio.h>
#include <string.h>

void main(){
    char str[80] = "Hello";
    printf("%d, %d", strlen(str)/2, strlen(str));
    // printf("\n|%s| %d\n", str, strlen(str));
    // for (int i=0; i<5; i++) str[i] = ' ';
    // printf("\n|%s| %d\n", str, strlen(str));
}
#include<stdio.h>
#include <stdlib.h>
#include <string.h>

// #define vector(type)    struct vector_##type

// struct vector_int
// {
//     int* array;
//     size_t count;
// } ;

// int main(void)
// {
//     vector(int) one = { 0 , 1};
//     // vector(int) two = { 0 };

//     // one = two;
//     // ( void )one ;
    
//     return 0;
// }
void main(){
    // char str[] = "Hello", str2[80];
    // strcpy(str2, str);
    // printf("%s, %s", str, str2);
    char credentials[100][4];
    // credentials[0][0] = "hello";
    strcpy(credentials[0][0], "hello");
    printf("%s", credentials[0][0]);
}
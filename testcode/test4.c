#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void main(){
    char sno[3];
    char iname[80];
    char date[11];
    printf("Enter S.No. (Ex. 005) : ");
    fflush(stdin);
    scanf("%s", &sno);
    fflush(stdin);
    printf("%s\n", sno);
    fflush(stdin);
    printf("Enter Issuer Name : ");
    scanf("%[^\n]%*c", &iname);
    fflush(stdin);
    printf("Enter Date As DD-MM-YYYY (Ex. 01-01-1971) : ");
    scanf("%s", &date);
    printf("%s\n", iname);
    fflush(stdin);
    printf("%s, %s, %s", sno, iname, date);
}
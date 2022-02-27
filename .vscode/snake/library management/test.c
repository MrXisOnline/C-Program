#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct String{
    char str[80];
}String;

String make_string(char *rstr, int gap){
    String nstr = {""};
    int i,j=0;
    if (strlen(rstr) == 0){
        for (i=0; i<gap; i++){
            nstr.str[i] = ' ';
        }
        return nstr;
    }else{
        int rlen = strlen(rstr);
        if (rlen % 2 == 0){
            if (rlen >= gap){
                strcpy(nstr.str, rstr);
                return nstr;
            }
            int strmid = rlen / 2;
            int gapmid = gap / 2;
            for (i=0; i<gapmid-strmid; i++) nstr.str[i] = ' ';
            for (i=gapmid-strmid; i<gapmid+strmid; i++){
                    nstr.str[i] = rstr[j];
                    j++;
            }
            for (i=gapmid+strmid; i<gap; i++) nstr.str[i] = ' ';
            return nstr;
        }else{
            if (rlen >= gap){
                strcpy(nstr.str, rstr);
                return nstr;
            }
            int strmid = rlen / 2;
            int gapmid = gap / 2;
            for (i=0; i<gapmid-strmid; i++) nstr.str[i] = ' ';
            for (i=gapmid-strmid; i<gapmid+strmid+1; i++){
                    nstr.str[i] = rstr[j];
                    j++;
            }
            for (i=gapmid+strmid+1; i<gap; i++) nstr.str[i] = ' ';
            return nstr;
        }
    }
}

void print_library_books(char bookcol[1000][6][80], int iters){
    int i=0, j=0;
    if ((strlen(bookcol[0][0]) != 0) && (strlen(bookcol[0][4]) == 0)){
        printf("\t");
        for (int k=0; k<100; k++) printf("="); printf("\n");
        printf("\t");
        printf("|"); printf("%s", make_string("", 7).str);
        printf("|"); printf("%s", make_string("", 47).str);
        printf("|"); printf("%s", make_string("", 35).str);
        printf("|"); printf("%s", make_string("", 6).str);
        printf("|"); printf("\n");
        printf("\t");
        printf("|"); printf("%s", make_string("S.No.", 7).str);
        printf("|"); printf("%s", make_string("Book Name", 47).str);
        printf("|"); printf("%s", make_string("Author", 35).str);
        printf("|"); printf("%s", make_string("Year", 6).str);
        printf("|"); printf("\n");
        printf("\t");
        printf("|"); printf("%s", make_string("", 7).str);
        printf("|"); printf("%s", make_string("", 47).str);
        printf("|"); printf("%s", make_string("", 35).str);
        printf("|"); printf("%s", make_string("", 6).str);
        printf("|"); printf("\n");
        for (i=0; i<iters; i++){
            printf("\t");
            for (j=0; j<4; j++){
                if (j == 0){
                    printf("|%s", make_string(bookcol[i][j], 7).str);
                }else if (j == 1)
                {
                    printf("|%s", make_string(bookcol[i][j], 47).str);
                }else if (j == 2)
                {
                    printf("|%s", make_string(bookcol[i][j], 35).str);
                }else if (j == 3)
                {
                    printf("|%s|", make_string(bookcol[i][j], 6).str);
                }
            }
            printf("\n");
        }
        printf("\t");
        for (int k=0; k<100; k++) printf("="); printf("\n");
    }else if ((strlen(bookcol[0][0]) != 0) && (strlen(bookcol[0][4]) != 0)){
        printf("\t");
        for (int k=0; k<150; k++) printf("="); printf("\n");
        printf("\t");
        printf("|"); printf("%s", make_string("", 7).str);
        printf("|"); printf("%s", make_string("", 47).str);
        printf("|"); printf("%s", make_string("", 35).str);
        printf("|"); printf("%s", make_string("", 6).str);
        printf("|"); printf("%s", make_string("", 34).str);
        printf("|"); printf("%s", make_string("", 14).str);
        printf("|"); printf("\n");
        printf("\t");
        printf("|"); printf("%s", make_string("S.No.", 7).str);
        printf("|"); printf("%s", make_string("Book Name", 47).str);
        printf("|"); printf("%s", make_string("Author", 35).str);
        printf("|"); printf("%s", make_string("Year", 6).str);
        printf("|"); printf("%s", make_string("Issued To", 34).str);
        printf("|"); printf("%s", make_string("Date", 14).str);
        printf("|"); printf("\n");
        printf("\t");
        printf("|"); printf("%s", make_string("", 7).str);
        printf("|"); printf("%s", make_string("", 47).str);
        printf("|"); printf("%s", make_string("", 35).str);
        printf("|"); printf("%s", make_string("", 6).str);
        printf("|"); printf("%s", make_string("", 34).str);
        printf("|"); printf("%s", make_string("", 14).str);
        printf("|"); printf("\n");
        for (i=0; i<iters; i++){
            printf("\t");
            for (j=0; j<6; j++){
                if (j == 0){
                    printf("|%s", make_string(bookcol[i][j], 7).str);
                }else if (j == 1)
                {
                    printf("|%s", make_string(bookcol[i][j], 47).str);
                }else if (j == 2)
                {
                    printf("|%s", make_string(bookcol[i][j], 35).str);
                }else if (j == 3)
                {
                    printf("|%s", make_string(bookcol[i][j], 6).str);
                }else if (j == 4)
                {
                    printf("|%s", make_string(bookcol[i][j], 34).str);
                }else if (j == 5)
                {
                    printf("|%s|", make_string(bookcol[i][j], 14).str);
                } 
            }
            printf("\n");
        }
        printf("\t");
        for (int k=0; k<150; k++) printf("="); printf("\n");
    }
}

void main()
{   
    // int c;
    // scanf("%d", &c);
    // printf("%d", c);
    // char s1[]="0011", s2[3];
    // strcpy(s2, s1);
    // printf("%s", s2);
    char book[1000][6][80];
    strcpy(book[0][0], "001");
    strcpy(book[0][1], "The Last Wish");
    strcpy(book[0][2], "Andrej Karparthzy");
    strcpy(book[0][3], "1993");
    // strcpy(book[0][4], "Suraj Gupta");
    // strcpy(book[0][5], "10-10-2001");
    strcpy(book[1][0], "002");
    strcpy(book[1][1], "The game of thrones");
    strcpy(book[1][2], "R. R. Martin");
    strcpy(book[1][3], "1980");
    // strcpy(book[1][4], "Suraj Gupta");
    // strcpy(book[1][5], "11-09-2021");
    strcpy(book[2][0], "");
    strcpy(book[2][1], "");
    strcpy(book[2][2], "");
    strcpy(book[2][3], "");
    // strcpy(book[2][4], "");
    // strcpy(book[2][5], "");
    print_library_books(book, 2);
}
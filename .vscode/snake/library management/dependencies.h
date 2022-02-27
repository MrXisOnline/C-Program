#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>
#include <unistd.h>

typedef struct String{
    char str[80];
}String;

static const char* books = "books.csv";
static const char* issue_books = "issued_books.csv";

void clear_screen(){
    printf("\n Clearing Screen in 5 Seconds ...");
    sleep(5);
    system("cls");
}

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

void print_books(char bookcol[1000][6][80], int iters){
    if (iters > 0){
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
    }else{
        printf("\t\tNo Books Available Here...\n");
        clear_screen();
    }
}

void AllBooks(const char* books){
    char bookcol[100][6][80];
    const char* mode = "r";
    FILE *fp = fopen(books, mode);
    if (fp == NULL){
        printf("File Doesn't Exist!");
        exit(1);
    }else{
        char buffer[1024];
        int row = 0; 
        int col = 0;

        while (fgets(buffer, 1024, fp))
        {
            col = 0;
            row++;
            if (row == 1) continue;
            const char* sep = ",";
            const char* nlsep = "\n";
            char * line = strtok(buffer, nlsep);
            while (line)
            {
                char * value = strtok(line, sep);
                while (value){
                    strcpy(bookcol[row-2][col], value);
                    value = strtok(NULL, sep);
                    col++;
                }
                line = strtok(NULL, nlsep);
            }
        }
        fclose(fp);
        print_books(bookcol, row-1);
    }
}

void AddBook(char sno[3], char b_name[80], char author[80], int year){
    const char* mode = "a+";
    FILE *fp = fopen(books, mode);
    if (fp == NULL){
        printf("File Doesn't Exist!\n");
        exit(0);
    }

    fprintf(fp, "%s, %s, %s, %d\n", sno, b_name, author, year);
    fclose(fp);
    printf("\nNew Book Added to Library!\n\n");
    // char *data = (char*)malloc(167 * sizeof(char));
    // sprintf(data, "%s, %s, %s, %s\n", sno, b_name, author, year);
    
}

void IssueBook(char sno[3], char issued_to[80], char date[11]){
    const char* nbooks = "nbooks.csv";
    const char* mode = "a+";
    const char* nmode = "w";
    FILE *fp = fopen(books, mode);
    FILE *ifp = fopen(issue_books, mode);
    FILE *nfp = fopen(nbooks, nmode);
    if (fp == NULL){
        printf("File Doesn't Exist!\n");
        exit(1);
    }else{
        char buffer[1024];
        while (fgets(buffer, 1024, fp))
        {
            const char* sep = "\n";
            char * value = strtok(buffer, sep);
            if (value)
            {
                char *line = (char*)malloc(167 * sizeof(char));
                sprintf(line, "%s\n", value);
                char *lsno = strtok(line, ",");
                if (strcmp(lsno, sno) == 0){
                    fprintf(ifp, "%s, %s, %s\n", value, issued_to, date);
                    printf("\nIssued Book From Library of S.No. %s to %s on %s.\n", sno, issued_to, date);
                    continue;
                }
                fprintf(nfp, "%s\n", value);
                value = strtok(NULL, sep);
            }
            // printf("\n");
        }
        fclose(fp);
        fclose(nfp);
        fclose(ifp);
    }
    remove(books);
    rename(nbooks, books);

}

void ReturnBook(char sno[3]){
    const char* nbooks = "nbooks.csv";
    const char* mode = "a+";
    const char* nmode = "w";
    FILE *fp = fopen(issue_books, mode);
    FILE *rfp = fopen(books, mode);
    FILE *nfp = fopen(nbooks, nmode);
    if (fp == NULL){
        printf("File Doesn't Exist!\n");
        exit(1);
    }else{
        char buffer[1024];
        while (fgets(buffer, 1024, fp))
        {
            const char* sep = "\n";
            char * value = strtok(buffer, sep);
            if (value)
            {
                char *line = (char*)malloc(167 * sizeof(char));
                sprintf(line, "%s\n", value);
                char *lsno = strtok(line, ",");
                if (strcmp(lsno, sno) == 0){
                    for (int i=0; i<4; i++){
                        if (i != 3){
                            fprintf(rfp, "%s,", lsno);
                        }else{
                            fprintf(rfp, "%s", lsno);
                        }
                        lsno = strtok(NULL, ",");
                    }
                    fprintf(rfp, "\n");
                    printf("\nReturned Book to Library of S.No. %s\n", sno);
                    continue;
                }
                fprintf(nfp, "%s\n", value);
                value = strtok(NULL, sep);
            }
        }
        fclose(fp);
        fclose(nfp);
        fclose(rfp);
    }
    remove(issue_books);
    rename(nbooks, issue_books);
}

void SerializeBooks(int all_books){
    for (int i=1; i<=all_books; i++){
        char bsno[3];
        sprintf(bsno, "%d", i);
        char sno[3];
        int sno_len = strlen(bsno);
        if (sno_len == 1){
            sprintf(sno, "00%s", bsno);
        }else if (sno_len == 2){
            sprintf(sno, "0%s", bsno);
        }else{
            sprintf(sno, "%s", bsno);
        }
        IssueBook(sno, "Nothing", "00-00-0000");
        ReturnBook(sno);
        system("cls");
    }
    printf("\nAll Books Are Now Serialized\n");
}

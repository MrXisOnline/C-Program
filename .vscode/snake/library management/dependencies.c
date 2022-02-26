#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>

static const char* books = "books.csv";
static const char* issue_books = "issued_books.csv";

void AllBooks(const char* books){
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
            for (int i=0; i<150; i++) printf("="); printf("\n");
            const char* sep = ",";
            char * value = strtok(buffer, sep);
            while (value)
            {
                if (col == 0) printf("|\tS.No. :");
                if (col == 1) printf("\tBook Name :");
                if (col == 2) printf("\tAuthor :");
                if (col == 3) printf("\tPublished :");
                if (col == 4) printf("\tIssued To :");
                if (col == 5) printf("\tDate :");
                printf("%s", value);
                value = strtok(NULL, sep);
                col++;
            }
            printf("|\n");
            
        }
        for (int i=0; i<150; i++) printf("="); printf("\n");
        fclose(fp);
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

void IssueBook(char sno[3], char issued_to[80], char date[10]){
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
        if (sno_len < 10){
            sprintf(sno, "00%s", bsno);
        }else if (sno_len < 100){
            sprintf(sno, "0%s", bsno);
        }else{
            sprintf(sno, "%s", bsno);
        }
        IssueBook(sno, "Nothing", "00-00-0000");
        ReturnBook(sno);
    }
    printf("\nAll Books Are Now Serialized\n");
}

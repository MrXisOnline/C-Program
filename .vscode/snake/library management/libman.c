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


void main()
{
    bool run = true;
    system("cls");
    printf("\n\t\tWelcome To The Library Manager By Priyansh\n");
    while (run)
    {
        fflush(stdin);
        int choice;
        printf("\n");
        printf("\t\t Hey, What Do You Want To Do...\n");
        printf("\t\t1. Show All Books In Library\n");
        printf("\t\t2. Add A Book Into The Library\n");
        printf("\t\t3. Issue A Book\n");
        printf("\t\t4. Show All Issued Books\n");
        printf("\t\t5. Return A Book\n");
        printf("\t\t6. Serialize All Books\n");
        printf("\t\t7. Exit\n");
        printf("\n\t\t Your Choice : ");
        scanf("%d", &choice);
        fflush(stdin);
        if (choice == 1) {
            AllBooks(books);
        }else if (choice == 2){
            char sno[3];
            char bname[80];
            char author[80];
            int year;
            printf("Enter S.No. (Ex. 005) : ");
            scanf("%s", &sno);
            fflush(stdin);
            printf("Enter Book Name : ");
            scanf("%[^\n]%*c", bname);
            fflush(stdin);
            printf("Enter Author Name : ");
            scanf("%[^\n]%*c", author);
            fflush(stdin);
            printf("Enter Publication Year (Ex. 1971) : ");
            scanf("%d", &year);
            fflush(stdin);
            AddBook(sno, bname, author, year);
        }else if (choice == 3){
            char esno[3];
            char sno[3];
            char iname[80];
            char date[10];
            printf("Enter S.No. (Ex. 005) : ");
            fflush(stdin);
            scanf("%s", &sno);
            fflush(stdin);
            // printf("%s\n", sno);
            strcpy(esno, sno);
            printf("%s\n", esno[2]);
            fflush(stdin);
            printf("Enter Issuer Name : ");
            scanf("%[^\n]%*c", iname);
            fflush(stdin);
            printf("Enter Date As DD-MM-YYYY (Ex. 01-01-1971) : ");
            scanf("%s", date);
            fflush(stdin);
            printf("%s, %s, %s", esno, iname, date);
            // IssueBook(esno, iname, date);
        }else if (choice == 4){
            AllBooks(issue_books);
        }else if (choice == 5){
            char sno[3];
            printf("Enter S.No. (Ex. 005) : ");
            scanf("%s", &sno);
            fflush(stdin);
            ReturnBook(sno);
        }else if (choice == 6){
            int all_books;
            printf("Enter Total Books in Library : ");
            scanf("%d", &all_books);
            fflush(stdin);
            SerializeBooks(all_books);
        }else if (choice == 7){
            run = false;
        }else{
            printf("\nOops You Entered A Wrong Choice...\n");
        }
    }

}
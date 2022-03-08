#include "dependencies.h"

void main()
{
    bool run = true;
    system("cls");
    while (run)
    {
        printf("\n\n\t\t\tWelcome To The Library Manager By Priyansh\n\n");
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
        printf("\t\t8. Clear Screen\n");
        printf("\n\t\t Your Choice : ");
        scanf("%d", &choice);
        fflush(stdin);
        system("cls");
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
            clear_screen();
        }else if (choice == 3){
            char sno[3];
            char iname[80];
            char date[11];
            printf("Enter S.No. (Ex. 005) : ");
            fflush(stdin);
            scanf("%s", &sno);
            fflush(stdin);
            printf("Enter Issuer Name : ");
            scanf("%[^\n]%*c", &iname);
            fflush(stdin);
            printf("Enter Date As DD-MM-YYYY (Ex. 01-01-1971) : ");
            scanf("%s", &date);
            fflush(stdin);
            // printf("%s, %s, %s", sno, iname, date);
            IssueBook(sno, iname, date);
            clear_screen();
        }else if (choice == 4){
            AllBooks(issue_books);
        }else if (choice == 5){
            char sno[3];
            printf("Enter S.No. (Ex. 005) : ");
            scanf("%s", &sno);
            fflush(stdin);
            ReturnBook(sno);
            clear_screen();
        }else if (choice == 6){
            int all_books;
            printf("Enter Total Books in Library : ");
            scanf("%d", &all_books);
            fflush(stdin);
            SerializeBooks(all_books);
            clear_screen();
        }else if (choice == 7){
            run = false;
            printf("\nExiting Library Manager ...");
            clear_screen();
        }else if (choice == 8){
            clear_screen();
        }
        else{
            printf("\nOops You Entered A Wrong Choice...\n");
            clear_screen();
        }
    }

}
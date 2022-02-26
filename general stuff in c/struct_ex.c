#include <stdio.h>
#include <stdbool.h>

typedef struct  Student
{
    int roll;
    char name[80];
}Student;

void main(){
    
    // int r;
    // char name[80];

    // printf("Enter roll no. :"); scanf("%d", &r);
    // printf("Enter name :"); scanf("%s", &name);

    // Student s1 = {1, "Priyansh"};
    // Student s2 = {2, "Suraj"};
    // Student s3 = {3, "Brandon"};
    // Student s4 = {4, "rick"};
    // Student s5 = {5, "morty"};

    Student class[50];
    bool run = true;
    int i = 0;
    while (run)
    {
        int num;
        int r;
        char name[80];
        printf("You Want to enter more student? Press (1 or else 0) "); scanf("%d", &num);
        if (num == 1){
            printf("Enter roll no. :"); scanf("%d", &r);
            printf("Enter name :"); scanf("%s", &name);
            Student s = {r, name};
            class[i] = s;
            i++;
        }else{
            run = false;
        }
    }
    

    
    
}
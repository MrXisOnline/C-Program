#include<stdio.h>
#include<string.h>

void main()
{
    char string[80];
    printf("Enter String: ");
    scanf("%s", &string);
    printf("Length of String :%d\n", strlen(string));

    char string_1[80], string_2[80];
    printf("\nEnter String: ");
    scanf("%s", &string_1);
    strcpy(string_2, string_1);
    printf("\nString 2: %s\n", string_2);
    printf("String Concat: %s\n", strcat(string_1, string_2));

    printf("\nEnter String: ");
    scanf("%s", &string_1);
    printf("\nEnter String: ");
    scanf("%s", &string_2);
    if (strcmp(string_1, string_2) == 0){
        printf("They are same.");
    }else{
        printf("They aren't same");
    }
    printf("\n");

    printf("String 1 in Reverse: %s\n", strrev(string_1));
    printf("Enter String: ");
    scanf("%s", &string_1);
    printf("String 1 in lowercase: %s\n", strlwr(string_1));
    printf("String 1 in uppercase: %s\n", strupr(string_1));

}
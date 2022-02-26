#include<stdio.h>
#include<string.h>

void main()
{
    char vowels[]="aeiouAEIOU", string[80];
    int length, total_vowels=0, spaces=0;
    printf("String :");
    scanf("%s", &string);
    printf("%s\n", string);
    length = strlen(string);
    for (int i=0; i < length; i++){
        if (string[i] == ' '){
            spaces++;
            continue;
        }
        for (int j=0; j < 10; j++){
            if (string[i] == vowels[j]) total_vowels++;
        }
    }
    printf("Total vowels, spaces in %s is %d, %d", string, total_vowels, spaces);
}
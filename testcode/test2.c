#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

union members {
    int *intp;
    char *charp;
    double doublev;
};

struct group {
    int lastunionmember;
    union members x;
};

struct group f1(void) {
    struct group r = {0};
    int choice = rand() % 3;

    if (choice == 0) {
        r.x.intp = malloc(sizeof (int)); // remember to free(intp) at some time
        *r.x.intp = 42;
        r.lastunionmember = 1;
    }
    if (choice == 1) {
        r.x.charp = malloc(42); // remember to free(charp) at some time
        strcpy(r.x.charp, "forty two");
        r.lastunionmember = 2;
    }
    if (choice == 2) {
        r.x.doublev = 3.14159;
        r.lastunionmember = 3;
    }
    return r;
}

int main(void) {
    struct group x;
    srand(time(0));
    for (int k = 0; k < 20; k++) {
        x = f1();
        switch (x.lastunionmember) {
            default: printf("invalid value\n"); break;
            case 1: printf("int value is %d\n", *x.x.intp); break;
            case 2: printf("string is \"%s\"\n", x.x.charp); break;
            case 3: printf("double value is %f\n", x.x.doublev); break;
        }
    }
}
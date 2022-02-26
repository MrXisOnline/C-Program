#include<stdio.h>

void main(){
    float radius;
    printf("Enter Radius of Sphere -> ");
    scanf("%f", &radius);
    printf("Area: %f\n", 4 * 3.14 * radius * radius);
    printf("Vol.: %f", (4 * 3.14 * radius * radius * radius)/3);
}
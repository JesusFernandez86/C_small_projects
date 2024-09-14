#include <stdio.h>

int main()
{
    int m = 300;
    float fx = 3.60006;
    char cht = 'z';

    int *pt1 = &m;
    float *pt2 = &fx;
    char *pt3 = &cht;

    printf("Using & operator: \n");
    printf("------------------------- \n");
    printf("Address of m: %p\n", &m);
    printf("Address of fx: %p \n", &fx);
    printf("Address of cgt: %p \n \n", &cht);

    printf("Using & and * operator: \n");
    printf("------------------------- \n");
    printf("Value of m: %d\n", *(&m));
    printf("Value of fx: %f \n", *(&fx));
    printf("Value of cgt: %c \n \n", *(&cht));

    printf("Using only pointer variable : \n");
    printf("------------------------- \n");
    printf("Address of m: %p\n", pt1);
    printf("Address of fx: %p \n", pt2);
    printf("Address of cgt: %p \n \n", pt3);

    printf(" Using only pointer operator : \n");
    printf("------------------------- \n");
    printf("Value of m: %d\n", *pt1);
    printf("Value of fx: %f \n", *pt2);
    printf("Value of cgt: %c \n \n", *pt3);

    return 0;
}
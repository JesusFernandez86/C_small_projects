#include <stdio.h>

#include <stdlib.h>

int c;

int d;

void main(int argc, char **argv)
{

    int a;

    int b;

    int *ptr = (int *)malloc(sizeof(int) * 100000);

    printf("global 1   :%p \n", &c);

    printf("global 2   :%p \n", &d);

    printf("cabecera 1 :%p \n", &argc);

    printf("cabecera 2 :%p \n", &argv);

    printf("local 1    :%p \n", &a);

    printf("local 2    :%p \n", &b);

    printf("malloc     :%p \n", ptr);
}
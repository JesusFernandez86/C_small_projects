/*Enunciado: Escribe una función en C que intercambie
los valores de dos variables enteras usando paso de parámetros por referencia.
Luego, escribe un programa que lea dos enteros,
llame a la función y muestre los valores intercambiados.*/

#include <stdio.h>
#include <stdlib.h>

void change_values(int *a, int *b);

int main()
{
    int a = 1;
    int b = 2;
    int *ptr_a = &a;
    int *ptr_b = &b;

    printf("Values now are: a= %d, b=%d \n", a, b);

    change_values(ptr_a, ptr_b);

    printf("Values now are: a= %d, b=%d \n", a, b);

    return 0;
}

void change_values(int *a, int *b)
{
    int temp = 0;
    temp = *a;
    *a = *b;
    *b = temp;
}
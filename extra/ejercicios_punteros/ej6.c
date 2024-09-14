// Write a program in C to find the maximum number between two numbers using a pointer.

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int number1, number2;
    int *ptr1 = &number1, *ptr2 = &number2;

    printf("Enter the first number: \n");
    scanf("%d", &number1);

    printf("Enter the second number: \n");
    scanf("%d", &number2);

    if (*ptr1 > *ptr2)
    {
        printf("%d is the maximum number", *ptr1);
    }
    else
    {
        printf("%d is the maximum number", *ptr2);
    }
    return 0;
}
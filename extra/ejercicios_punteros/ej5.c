#include <stdio.h>

int add_numbers(int *a, int *b) { return *a + *b; }

int main()
{
    int number1, number2, result;

    printf("Enter first number: \n");
    scanf("%d", &number1);

    printf("Enter second number: \n");
    scanf("%d", &number2);

    result = add_numbers(&number1, &number2);
    printf("The sum of the two numbers is %d", result);
}
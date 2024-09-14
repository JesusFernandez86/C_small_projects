// Write a program in C to find the largest element using Dynamic Memory Allocation.

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int size, largest;

    printf("Input a total number of elements (1 to 10): ");
    scanf("%d", &size);
    printf("\n");

    int *elements = (int *)malloc(size * sizeof(int)); // TODO always use sizeof with malloc, size is only the number of times I need to multiply sizeof for
    if (elements == NULL)
    {
        printf("Memory allocation failed!\n");
        return 1;
    }

    for (int i = 0; i < size; i++)
    {
        printf("Enter number %d: ", i + 1);
        scanf("%d", elements + i);
    }
    printf("\n");

    largest = *elements;

    for (int i = 1; i < size; i++)
    {
        if (*(elements + i) > largest)
        {
            largest = *(elements + i);
        }
    }

    printf("The largest number is: %d", largest);
    free(elements);
    return 0;
}
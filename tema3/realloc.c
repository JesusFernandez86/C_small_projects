#include <stdio.h>
#include <stdlib.h>

int main()
{
    // Allocate memory for an integer
    int *ptr = (int *)malloc(sizeof(int));

    if (ptr == NULL)
    {
        printf("Memory allocation failed!\n");
        return 1;
    }

    *ptr = 123; // Assign a value

    // Now, let's say we need memory for one more integer
    ptr = (int *)realloc(ptr, 2 * sizeof(int));

    if (ptr == NULL)
    {
        printf("Memory reallocation failed!\n");
        return 1;
    }

    *(ptr + 1) = 456; // Assign a value to the newly allocated memory

    // Print the values
    printf("%d -- %d\n", *ptr, *(ptr + 1)); // Will print: 123 456

    // Don't forget to free the allocated memory
    free(ptr);

    return 0;
}
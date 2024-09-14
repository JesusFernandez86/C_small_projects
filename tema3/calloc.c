#include <stdio.h>
#include <stdlib.h>

int main()
{
    // Allocate memory for 5 integers using calloc
    // calloc initializes the allocated memory to zero
    int *arr = (int *)calloc(5, sizeof(int));

    if (arr == NULL)
    {
        printf("Memory allocation failed!\n");
        return 1;
    }

    // Print the values
    for (int i = 0; i < 5; i++)
    {
        printf("%d ", arr[i]); // Will print: 0 0 0 0 0
    }

    // Don't forget to free the allocated memory
    free(arr);

    return 0;
}
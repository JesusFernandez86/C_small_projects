#include <stdio.h>
#include <stdlib.h>

int test();

int main()
{
    // Allocate memory for an integer
    void *ptr = malloc(sizeof(int));
    void *ptr2 = malloc(sizeof(double));
    // Check if the memory allocation was successful
    if (ptr == NULL)
    {
        printf("Memory allocation failed!\n");
        return 1;
    }

    // Cast the void pointer to an int pointer
    int *int_ptr = (int *)ptr;
    double *double_ptr = (double *)ptr2;

    // Assign a value to the allocated memory
    *int_ptr = 123;
    *double_ptr = 123.456;

    // Print the value
    printf("Value: %d\n", *int_ptr);
    printf("Value: %f\n", *double_ptr);

    // Print the address
    printf("Address: %p\n", int_ptr);
    printf("Address: %p\n", ptr);
    printf("Address: %p\n", double_ptr);
    printf("Address: %p\n", ptr2);

    // Don't forget to free the allocated memory
    free(ptr);
    free(ptr2);
    // printf("Invoking test function...\n");
    // test();
    return 0;
}

int test()
{
    int *ptr_int = (int *)malloc(sizeof(int));
    if (ptr_int == NULL)
    {
        printf("Memory allocation failed!\n");
        return 1;
    }
    else
    {
        printf("Memory has been assigned to ptr_int\n");
    }
    int size = sizeof(ptr_int);
    printf("The size is: %d bytes\n", size);
    free(ptr_int);
    return 0;
}
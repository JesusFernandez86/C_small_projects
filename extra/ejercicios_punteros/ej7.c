// Write a program in C to store n elements in an array and print the elements using a pointer.
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int size;

    printf("Enter the number of array elements: ");
    scanf("%d", &size);
    printf("\n");

    int arr[size];
    int *arr_ptr = arr;

    printf("Enter the %d values for the array", size);
    printf("\n");
    for (int i = 0; i < size; i++)
    {
        printf("Element - %d: ", i);
        scanf("%d", arr_ptr + i); // this is the samen than &(*(arr_ptr + i)
    }

    printf("------ Printing the previously entered values ------");
    printf("\n");
    for (int i = 0; i < size; i++)
    {
        printf("Element - %d = %d", i, *(arr_ptr + i));
        printf("\n");
    }

    return 0;
}
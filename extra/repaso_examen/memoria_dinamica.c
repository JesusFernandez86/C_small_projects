/* Enunciado: Escribe un programa en C que solicite al usuario el tamaño de un array de enteros,
asigne memoria dinámicamente para el array, permita al usuario ingresar los elementos del array y luego imprima los elementos*/

#include <stdlib.h>
#include <stdio.h>

int main()
{

    int array_size;

    printf("Enter the amount of integers you would like to save: \n ");
    scanf("%d", &array_size);
    while (getchar() != '\n')
        ;

    int *int_array = (int *)malloc(array_size * sizeof(int));
    if (int_array == NULL)
    {
        printf("Failed to allocate memory");
        return 1;
    }

    for (int i = 0; i < array_size; i++)
    {
        printf("Enter the value %d for the array \n", i + 1);
        scanf("%d", &int_array[i]);
        while (getchar() != '\n')
            ;
    }
    printf("PRINTING THE VALUES....... \n");
    for (int i = 0; i < array_size; i++)
    {
        printf("The value %d is: %d \n", i + 1, int_array[i]);
    }

    free(int_array);
    return 0;
}

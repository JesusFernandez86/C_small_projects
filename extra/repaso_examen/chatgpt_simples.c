#include <stdlib.h>
#include <stdio.h>
#include <string.h>

    /*
    Ejercicio 1: Puntero a Entero
    Escribe un programa en C que declare un entero, un puntero a entero
    y asigne la dirección del entero al puntero. Luego, imprime el valor del entero utilizando el puntero.
    */
int main(){
    int entero = 1;
    int *puntero_entero = &entero;

    printf("El valor del puntero es: %d", *puntero_entero);
    return 0;
}

    /*
    Ejercicio 2: Suma de Dos Números Usando Punteros
    Escribe una función en C que reciba dos punteros a enteros,
    sume los valores a los que apuntan y devuelva la suma. Escribe un programa principal que pruebe esta función.
    */
int sumar_por_referencia(int *a, int *b)
{
    return *a + *b;
}

int main()
{
    int value_1 = 3;
    int value_2 = 5;
    int *ptr_to_1 = &value_1;
    int *ptr_to_2 = &value_2;

    int suma = sumar_por_referencia(ptr_to_1, ptr_to_2);
    printf("La suma de %d + %d es igual a %d", value_1, value_2, suma);
}


    /*
    Ejercicio 3: Array Dinámico
    Escribe un programa en C que solicite al usuario el tamaño de un array de enteros, asigne memoria dinámicamente para el array,
    permita al usuario ingresar los valores y luego imprima los valores del array.
    */
void clear_buffer()
{
    while (getchar() != '\n')
        ;
}
int main()
{
    int array_size;
    printf("Enter the array size: ");
    scanf("%d", &array_size);
    clear_buffer();

    int *array = (int *)malloc(array_size * sizeof(int));
    if (array == NULL)
    {
        printf("The memory has not been allocated, exiting...");
        exit(1);
    }

    for (int i = 0; i < array_size; i++)
    {
        printf("Enter the value for index %d: \n", i + 1);
        scanf("%d", &array[i]);
        clear_buffer();
    }
    printf("Printing values.... \n");
    for (int i = 0; i < array_size; i++)
    {
        printf("The value for index %d is %d: \n", i + 1, array[i]);
    }

    free(array);
    return 0;
}


    /* 
    Ejercicio 4: Copia de Entero Usando Punteros
    Escribe una función en C que reciba dos punteros a enteros y copie el valor del primer entero al segundo.
    Escribe un programa principal que pruebe esta función.
    */
void swap_values(int *a, int *b)
{
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

int main()
{
    int value1 = 3;
    int value2 = 5;
    int *ptr1 = &value1;
    int *ptr2 = &value2;

    printf("Values before, %d, %d \n", value1, value2);
    swap_values(ptr1, ptr2);
    printf("Values after, %d, %d \n", value1, value2);

    return 0;
}

    /*
    Ejercicio 5: Estructura Básica
    Define una estructura en C para representar un punto en 2D (coordenadas x e y).
    Escribe un programa que declare una variable de este tipo, asigne valores a sus campos e imprima los valores.
    */
typedef struct coordinates_t
{
    int x;
    int y;
} Coordinates;

int main()
{
    Coordinates coordenadas;
    coordenadas.x = 1;
    coordenadas.y = 2;

    printf("The coordinates values are: %d, %d \n", coordenadas.x, coordenadas.y);
    return 0;
}


    /*
    Ejercicio 6: Incremento de Entero Usando Punteros
    Escribe una función en C que reciba un puntero a entero y aumente el valor del entero en 1.
    Escribe un programa principal que pruebe esta función.
    */
void increment_pointer(int *a);

int main()
{
    int value_1 = 5;
    int *ptr_to_value1 = &value_1;
    printf("Value of number is: %d \n", value_1);
    increment_pointer(ptr_to_value1);
    printf("Value of number now is: %d \n", value_1);

    return 0;
}

void increment_pointer(int *a)
{
    (*a)++;
}


    /*
    Ejercicio 7: Array de Estructuras
    Define una estructura en C para representar un estudiante (nombre y edad).
    Escribe un programa que declare un array de 3 estudiantes, asigne valores a sus campos e imprima la información de cada estudiante.
    */
typedef struct student_t
{
    char name[50];
    int age;
} Student;

#define MAX_SIZE 2

int main()
{
    Student students[MAX_SIZE];

    for (int i = 0; i < MAX_SIZE; i++)
    {
        printf("Enter the student %d name: \n", i + 1);
        fgets(students[i].name, sizeof(students[i].name), stdin);
        strtok(students[i].name, "\n");
        students[i].name[strcspn(students[i].name, "\n")] = '\0';
        printf("Enter the student %d age \n", i + 1);
        scanf("%d", &students[i].age);
        while (getchar() != '\n')
            ;
    }
    printf("\n");
    printf("Printing the students values... \n");
    for (int i = 0; i < MAX_SIZE; i++)
    {
        printf("Student %d name: %s \n", i + 1, students[i].name);
        printf("Student %d age: %d \n", i + 1, students[i].age);
    }
}


    /*
    Ejercicio 8: Longitud de Cadena
    Escribe una función en C que reciba un puntero a una cadena de caracteres y
    devuelva la longitud de la cadena. No utilices funciones de la biblioteca estándar.
    Escribe un programa principal que pruebe esta función.
    */
int count_characters(char *string);

int main()
{
    char sentence[100] = "Hola que tal";
    char *ptr_to_sentnce = sentence;
    int sentence_length = count_characters(ptr_to_sentnce);
    printf("length is : %d \n", sentence_length);

    return 0;
}

int count_characters(char *string)
{
    int length = 0;
    while (string[length] != '\0')
    {
        printf("Character %d, is: %c \n", length, string[length]);
        length++;
    }

    return length - 1;
};


    /*
    Ejercicio 9: Memoria Dinámica para una Cadena
    Escribe un programa en C que solicite al usuario la longitud de una cadena, asigne memoria dinámicamente para la cadena,
    permita al usuario ingresar la cadena e imprima la cadena ingresada.
    */
int main()
{
    int string_length;
    printf("Enter the maximum sentence length: \n");
    scanf("%d", &string_length);
    while (getchar() != '\n')
        ;

    char *sentence = (char *)malloc(string_length);
    if (sentence == NULL)
    {
        printf("Could not allocate memory \n");
        exit(1);
    }

    printf("Enter the sentence: \n");
    fgets(sentence, string_length, stdin);
    sentence[strcspn(sentence, "\n")] = '\0';
    printf("\n");
    printf("The sentence entered is: %s", sentence);
    free(sentence);

    return 0;
}

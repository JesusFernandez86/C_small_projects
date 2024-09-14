/*Enunciado: Define una enumeración para los días de la semana y escribe un programa que lea un número (1-7)
y muestre el día correspondiente. Si el número no está en el rango, debe mostrar un mensaje de error.*/

#include <stdio.h>
#include <stdlib.h>

// Definición de la enumeración para los días de la semana
typedef enum week_days_t
{
    Monday = 1,
    Tuesday,
    Wednesday,
    Thursday,
    Friday,
    Saturday,
    Sunday
} Week_days;

// Prototipos de las funciones
int read_user_input();
void evaluate_input(Week_days day);

int main()
{
    int user_choice = read_user_input();
    evaluate_input((Week_days)user_choice); // Convertir a tipo Week_days
    return 0;
}

// Función para leer la entrada del usuario
int read_user_input()
{
    int choice;

    printf("Enter a value between 1 and 7: \n");
    while (scanf("%d", &choice) != 1 || choice < 1 || choice > 7)
    {
        // Limpiar el buffer en caso de entrada inválida
        while (getchar() != '\n');
        printf("Wrong value. Please enter a valid value between 1 and 7: \n");
    }

    return choice;
}

// Función para evaluar y mostrar el día correspondiente
void evaluate_input(Week_days day)
{
    switch (day)
    {
    case Monday:
        printf("The day is Monday\n");
        break;
    case Tuesday:
        printf("The day is Tuesday\n");
        break;
    case Wednesday:
        printf("The day is Wednesday\n");
        break;
    case Thursday:
        printf("The day is Thursday\n");
        break;
    case Friday:
        printf("The day is Friday\n");
        break;
    case Saturday:
        printf("The day is Saturday\n");
        break;
    case Sunday:
        printf("The day is Sunday\n");
        break;
    default:
        printf("Day not recognized\n");
        break;
    }
}

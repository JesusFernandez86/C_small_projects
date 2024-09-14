#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void clear_buffer_scanf()
{
    while (getchar() != '\n')
        ;
}

void clear_buffer_fgets(char *string)
{
    string[strcspn(string, "\n")] = '\0';
}
/*
Ejercicio 2: Suma de Arrays Dinámicos
Enunciado: Escribe un programa en C que solicite al usuario el tamaño de dos arrays de enteros, asigne memoria dinámicamente para ellos,
permita al usuario ingresar sus valores y luego calcule y muestre la suma de los dos arrays en un tercer array dinámico.
*/
int main()
{
    int array_size;

    printf("Enter the size of arrays: \n");
    scanf("%d", &array_size);
    clear_buffer_scanf();

    int *array1 = (int *)malloc(array_size * sizeof(int));
    int *array2 = (int *)malloc(array_size * sizeof(int));
    if (array1 && array2 == NULL)
    {
        printf("Could not allocate memory");
        exit(1);
    }

    // Enter the array values with a for loop
    for (int i = 0; i < array_size; i++)
    {
        printf("Enter value for array1 index %d: \n", i + 1);
        scanf("%d", &array1[i]);
        clear_buffer_scanf();
        printf("Enter value for array2 index %d: \n", i + 1);
        scanf("%d", &array2[i]);
        clear_buffer_scanf();
    }
    // Declare a third array to sum the 1 and 2 values
    int *array3 = (int *)malloc(array_size * sizeof(int));
    if (array3 == NULL)
    {
        printf("Could not allocate memory");
        exit(1);
    }
    // Add array1[i] and array2[2] and copy that value to array3[i]
    for (int i = 0; i < array_size; i++)
    {
        array3[i] = array1[i] + array2[i];
    }
    // print the values of the addition
    printf("\n");
    printf("PRINTING VALUES... \n");
    for (int i = 0; i < array_size; i++)
    {
        printf("The new array value at index %d is: %d \n", i + 1, array3[i]);
    }
    free(array1);
    free(array2);
    free(array3);
    return 0;
}

/*
Ejercicio 3: Manejo de Estructuras
Enunciado: Define una estructura en C para representar una fecha (día, mes, año). Escribe una función que reciba dos fechas y devuelva la más reciente.
Escribe un programa que lea dos fechas del usuario, utilice la función y muestre la fecha más reciente.
*/
#define MAX_DATES 2
typedef struct date_t
{
    int day;
    int month;
    int year;
} Date;

Date compare_dates(Date date_a, Date date_b);

int main()
{
    Date dates[MAX_DATES];
    int num_dates = sizeof(dates) / sizeof(dates[0]); // get the number of elements within an array
    for (int i = 0; i < num_dates; i++)
    {
        printf("Enter day for date %d: \n", i + 1);
        scanf("%d", &dates[i].day);
        clear_buffer_scanf();
        printf("Enter month for date %d: \n", i + 1);
        scanf("%d", &dates[i].month);
        clear_buffer_scanf();
        printf("Enter year for date %d: \n", i + 1);
        scanf("%d", &dates[i].year);
        clear_buffer_scanf();
    }
    printf("\n");
    Date closest_date = compare_dates(dates[0], dates[1]);
    printf("The closest date is: %d-%d-%d", closest_date.day, closest_date.month, closest_date.year);
    return 0;
}

Date compare_dates(Date date_a, Date date_b)
{
    if (date_b.year > date_a.year)
    {
        return date_b;
    }
    else if (date_b.year == date_a.year && date_b.month > date_a.month)
    {
        return date_b;
    }
    else if (date_b.year == date_a.year && date_b.month == date_a.month && date_b.day > date_a.day)
    {
        return date_b;
    }

    return date_a;
}

/*
Ejercicio 7: Array de Estructuras
Enunciado: Define una estructura en C para representar un estudiante (nombre, edad, promedio). Escribe un programa que utilice un array
dinámico de estudiantes, permita al usuario ingresar los datos de n estudiantes,
y luego muestre la información de todos los estudiantes y el promedio de sus promedios.
*/
typedef struct student_t
{
    char *name;
    int age;
    int average_rate;
} Student;

#define MAX_NAME_LENGTH 100

int main()
{
    Student *students = NULL;
    int students_number;

    printf("Enter the number of students you would like to enter: \n");
    scanf("%d", &students_number);
    clear_buffer_scanf();

    students = (Student *)malloc(students_number * sizeof(Student));

    for (int i = 0; i < students_number; i++)
    {
        printf("Enter the student %d name: \n", i + 1);
        students[i].name = (char *)malloc(MAX_NAME_LENGTH * sizeof(students[i].name));
        fgets(students[i].name, MAX_NAME_LENGTH, stdin);
        clear_buffer_fgets(students[i].name);

        printf("Enter the student %d age: \n", i + 1);
        scanf("%d", &students[i].age);
        clear_buffer_scanf();

        printf("Enter the student %d average: \n", i + 1);
        scanf("%d", &students[i].average_rate);
        clear_buffer_scanf();
    }
    printf("\n");

    float averages = 0;
    for (int i = 0; i < students_number; i++)
    {
        printf("Student %d name: %s \n", i + 1, students[i].name);
        printf("Student %d age: %d \n", i + 1, students[i].age);
        printf("Student %d average: %d \n", i + 1, students[i].average_rate);
        averages = averages + students[i].average_rate;
    }
    printf("PRINTING AVERAGE OF AVERAGES... \n");
    printf("Class average is: %f", (averages / students_number));

    for (int i = 0; i < students_number; i++)
    {
        free(students[i].name);
    }
    free(students);
    return 0;
}

/*
Ejercicio 8: Copia de Cadenas
Enunciado: Escribe una función en C llamada copy_string que reciba dos punteros a cadenas de caracteres y
copie el contenido de una cadena a la otra utilizando solo punteros.
No utilices funciones de la biblioteca estándar para realizar la copia. Escribe un programa que pruebe esta función.
*/
void copy_strings(char *string_a, char *string_b);

int main()
{
    char *string_a = "Hola mundo";
    char *string_b = (char *)malloc((strlen(string_a) + 1) * sizeof(char));
    if (string_b == NULL)
    {
        printf("Could not allocate memory, closing program...");
        exit(1);
    }
    copy_strings(string_a, string_b);
    printf("String 2 = %s", string_b);
    free(string_b);
    return 0;
}

void copy_strings(char *string_a, char *string_b)
{
    for(int i = 0; string_a[i] != '\0'; i++){
        string_b[i] = string_a[i];
    }
    string_b[strlen(string_b)] = '\0'; //Add the null terminator
    return;
}
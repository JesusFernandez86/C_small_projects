/*Enunciado: Desarrolla un proyecto en C que incluya múltiples archivos fuente. 
El proyecto debe gestionar una lista de estudiantes, con las operaciones de agregar, 
eliminar y mostrar estudiantes. La estructura de un estudiante incluye nombre, ID y promedio.
*/

#include <stdio.h>
#include <stdlib.h>
#include "students.h"

#define MIN_STUDENTS 2

int main()
{
    // Students students[MIN_STUDENTS];
    Students *students_ptr = (Students *)malloc(MIN_STUDENTS * sizeof(Students));
    if (students_ptr == NULL)
    {
        printf("Could not allocate memory");
        return 1;
    }
    int size = create_students(&students_ptr);    
    print_students(students_ptr, size);

    free(students_ptr);
    return 0;
}
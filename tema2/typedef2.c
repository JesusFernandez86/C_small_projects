#include <stdio.h>

typedef struct alumnos
{
    int ID;
    int Grade;

} student_t;

int main()
{
    student_t s[10];
    int i, j;

    for (i = 0; i < 5; i++)
    {
        s[i].ID = i + 1;
        s[i].Grade = i + 80;
    }

    for (j = 0; j < 5; j++)    {

        printf("La nota promedio del alumno %d es %d. \n", s[j].ID, s[j].Grade);
    }

    return 0;
}
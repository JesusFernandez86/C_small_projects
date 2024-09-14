#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "students.h"

int create_students(Students **students)
{
    int final_size = 0;
    printf("How many students do you want to introduce? \n");
    scanf("%d", &final_size);
    getchar();

    if (final_size != 2)
    {
        *students = (Students *)realloc(*students, final_size * sizeof(Students));
        if (*students == NULL)
        {
            printf("Could not allocate memory");
            return 1;
        }
    }

    for (int i = 0; i < final_size; i++)
    {
        printf("What is the name of student %d:", i + 1);
        fgets((*students)[i].name, sizeof((*students)[i].name), stdin);
        (*students)[i].name[strcspn((*students)[i].name, "\n")] = '\0';

        printf("Whant is the ID of student %d:", i + 1);
        scanf("%d", &(*students)[i].ID);
        getchar();

        printf("What is the average of student %d:", i + 1);
        scanf("%d", &(*students)[i].average);
        getchar();
    }
    return final_size;
}

void print_students(Students students[], int size)
{
    printf("PRINTING STUDENTS \n");
    for (int i = 0; i < size; i++)
    {
        printf("Student %d name: %s \n", i + 1, students[i].name);
        printf("Student %d ID: %d \n", i + 1, students[i].ID);
        printf("Student %d average: %d \n", i + 1, students[i].average);
        printf("================================================== \n");
    }
}

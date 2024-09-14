#ifndef STUDENTS_H
#define STUDENTS_H

typedef struct students_t
{
    char name[50];
    int ID;
    int average;
} Students;

int create_students(Students **students);  
void print_students(Students students[], int size);

#endif
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct t_animal
{
    char kind[30];
    char name[30];
    int age;
    char owner_name[30];
} Animal;

int main()
{
    Animal *animal = NULL;
    animal = (Animal *)malloc(sizeof(Animal));

    if (animal == NULL)
    {
        printf("Could not allocate memory");
        return 1;
    }

    printf("Enter the animal kind: ");
    fgets(animal->kind, sizeof(animal->kind), stdin);
    animal->kind[strcspn(animal->kind, "\n")] = '\0'; // Remove the newline character

    printf("Enter the animal name: ");
    fgets(animal->name, sizeof(animal->name), stdin);
    animal->name[strcspn(animal->name, "\n")] = '\0'; // Remove the newline character

    printf("Enter the animal age: ");
    scanf("%d", &animal->age);
    getchar();

    printf("Enter the animal owner name: ");
    fgets(animal->owner_name, sizeof(animal->owner_name), stdin);
    animal->owner_name[strcspn(animal->owner_name, "\n")] = '\0';

    printf("\n");
    printf("The animal kind is: %s \n", animal->kind);
    printf("The animal name is: %s \n", animal->name);
    printf("The animal kind is: %d \n", animal->age);
    printf("The animal owner_name is: %s \n", animal->owner_name);

    free(animal);
    return 0;
}
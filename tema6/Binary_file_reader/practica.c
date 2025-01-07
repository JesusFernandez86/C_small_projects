#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXPEOPLE 50
#define MAXLINELENGTH 1024

typedef struct people_t
{
    int index;
    char user_id[20];
    char name[15];
    char last_name[15];
    char sex[8];
    char email[50];
    char phone[20];
    char DOB[30];
    char job_title[40];
} people;

int count_number_of_lines(FILE *file);
void read_data_to_struct(FILE *file, people base_datos[]);
void print_people_data(people base_datos[], int num_people);
int save_struct_to_binary_file(people base_datos[], int number_of_lines);
int print_from_binary();

int main()
{
    people base_datos[MAXPEOPLE];
    FILE *file = fopen("people.csv", "r");
    if (file == NULL)
    {
        printf("Error opening file\n");
        return 1;
    }

    int number_of_lines = count_number_of_lines(file);
    printf("Total number of lines: %d\n", number_of_lines);
    read_data_to_struct(file, base_datos);
    fclose(file);

    print_people_data(base_datos, number_of_lines); // Funcion para comprobar que los datos se han introducido bien, se puede comentar
    save_struct_to_binary_file(base_datos, number_of_lines);
    print_from_binary();

    return 0;
}

int count_number_of_lines(FILE *file)
{
    int line_count = 0;
    char buffer[MAXLINELENGTH];

    while (fgets(buffer, sizeof(buffer), file) != NULL)
    {
        line_count++; // Increment line count for each line read
    }
    rewind(file);

    return line_count;
}

void read_data_to_struct(FILE *file, people base_datos[])
{
    char buffer[MAXLINELENGTH];
    // leo la primera linea para evitar contabilizarla en el bucle y rellenar la estructura con datos que no necesitamos
    if (fgets(buffer, sizeof(buffer), file) == NULL)
    {
        return;
    }
    for (int i = 0; i < MAXPEOPLE; i++)
    {
        char *line = fgets(buffer, 1024, file);
        char *token = strtok(line, ",");
        while (token)
        {
            if (token != NULL) // nos aseguramos de que el token existe
                base_datos[i].index = atoi(token);

            token = strtok(NULL, ",");
            if (token != NULL)
                strcpy(base_datos[i].user_id, token);

            token = strtok(NULL, ",");
            if (token != NULL)
                strcpy(base_datos[i].name, token);

            token = strtok(NULL, ",");
            if (token != NULL)
                strcpy(base_datos[i].last_name, token);

            token = strtok(NULL, ",");
            if (token != NULL)
                strcpy(base_datos[i].sex, token);

            token = strtok(NULL, ",");
            if (token != NULL)
                strcpy(base_datos[i].email, token);

            token = strtok(NULL, ",");
            if (token != NULL)
                strcpy(base_datos[i].phone, token);

            token = strtok(NULL, ",");
            if (token != NULL)
                strcpy(base_datos[i].DOB, token);

            token = strtok(NULL, ",");
            if (token != NULL)
                strcpy(base_datos[i].job_title, token);

            token = strtok(NULL, ",");
        }
    }
}

void print_people_data(people base_datos[], int num_people)
{
    for (int i = 0; i < num_people - 1; i++)
    {
        printf("Person %d:\n", i + 1);
        printf(" Index: %d\n", base_datos[i].index);
        printf(" User ID: %s\n", base_datos[i].user_id);
        printf(" Name: %s\n", base_datos[i].name);
        printf(" Last Name: %s\n", base_datos[i].last_name);
        printf(" Sex: %s\n", base_datos[i].sex);
        printf(" Email: %s\n", base_datos[i].email);
        printf(" Phone: %s\n", base_datos[i].phone);
        printf(" Date of Birth: %s\n", base_datos[i].DOB);
        printf(" Job Title: %s\n", base_datos[i].job_title);
        printf("\n");
    }
}

int save_struct_to_binary_file(people base_datos[], int number_of_lines)
{
    // escribimos el contenido a un fichero binario
    FILE *binary_file;
    binary_file = fopen("binary_file.bin", "wb");
    if (binary_file == NULL)
    {
        printf("Error opening file\n");
        return 1;
    }
    fwrite(base_datos, sizeof(people), number_of_lines, binary_file);
    fclose(binary_file);

    return 0;
}

int print_from_binary()
{
    FILE *binary_file = fopen("binary_file.bin", "rb");
    if (binary_file == NULL)
    {
        printf("Error opening file\n");
        return 1;
    }

    int index = 0;
    printf("Enter the index of the register you would like to see:  \n");
    scanf("%d", &index);
    while ((getchar()) != '\n');
    while (index < 1 || index > MAXPEOPLE)
    {
        printf("Invalid index. Please enter a number between 1 and %d.\n", MAXPEOPLE);
        scanf("%d", &index);
        while ((getchar()) != '\n');
    }
    people new_register;
    if (fseek(binary_file, (index - 1) * sizeof(people), SEEK_SET) != 0)
    {
        printf("Error seeking in the file.\n");
        return 1;
    }
    fread(&new_register, sizeof(people), 1, binary_file);

    printf("Person %d:\n", index);
    printf(" Index: %d\n", new_register.index);
    printf(" User ID: %s\n", new_register.user_id);
    printf(" Name: %s\n", new_register.name);
    printf(" Last Name: %s\n", new_register.last_name);
    printf(" Sex: %s\n", new_register.sex);
    printf(" Email: %s\n", new_register.email);
    printf(" Phone: %s\n", new_register.phone);
    printf(" Date of Birth: %s\n", new_register.DOB);
    printf(" Job Title: %s\n", new_register.job_title);
    printf("\n");

    fclose(binary_file);
    return 0;
}
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
 /*
Ejercicio 1: Lectura de Archivo
Enunciado: Escribe un programa en C que abra un archivo de texto llamado "input.txt" y muestre su contenido en la pantalla.
Indicaciones: Usa las funciones fopen, fgets, y fclose.
*/

#define MAX_LENGTH 256

int main()
{
    FILE *file = fopen("input.txt", "r");
    if (file == NULL)
    {
        printf("File could not be opened \n");
        exit(1);
    }
    char *buffer = (char *)malloc(sizeof(char) * MAX_LENGTH);
    for (int i = 0; fgets(buffer, MAX_LENGTH, file) != NULL; i++)
    {
        buffer[strcspn(buffer, "\n")] = '\0';
        printf("Line %d: %s \n", i, buffer);
    }

    fclose(file);

    return 0;
}

/*
Ejercicio 2: Escritura en Archivo
Enunciado: Escribe un programa en C que pida al usuario una cadena de texto y la guarde en un archivo llamado "output.txt".
Indicaciones: Usa las funciones fopen, fprintf, y fclose.
*/
#define MAX_LENGTH 256
int main()
{
    char *sentence = (char *)malloc(sizeof(char) * MAX_LENGTH);
    if (sentence == NULL)
    {
        printf("Could not allocate memory \n");
        exit(1);
    }

    FILE *file = fopen("output.txt", "w");
    if (file == NULL)
    {
        printf("Could not open the file");
        exit(2);
    }

    printf("Enter a sentence: \n");
    fgets(sentence, MAX_LENGTH, stdin);
    fputs(file, sentence);

    free(sentence);
    fclose(file);
    return 0;
}

/*
Ejercicio 3: Copia de Archivo
Enunciado: Escribe un programa en C que copie el contenido de un archivo de texto "input.txt" a otro archivo de texto "copy.txt".
Indicaciones: Usa las funciones fopen, fgets, fputs, y fclose.
*/
#define MAX_CHARS 256

int main()
{
    FILE *input_file = fopen("input.txt", "r");
    if (input_file == NULL)
    {
        printf("Could not open the file");
        exit(1);
    }

    char *buffer = (char *)malloc(sizeof(char) * MAX_CHARS);
    if (buffer == NULL)
    {
        printf("Could not open the file");
        exit(1);
    }

    FILE *copy_file = fopen("copy.txt", "w");
    if (copy_file == NULL)
    {
        printf("Could not open the file");
        exit(1);
    }

    while (fgets(buffer, MAX_CHARS, input_file) != NULL)
    {
        // It's good practice to check if fputs was successful. It returns a non-negative number on success, and EOF on error.
        if (fputs(buffer, copy_file) == EOF)
        {
            printf("Error writing to copy file\n");
            exit(1);
        }
    }

    free(buffer);
    fclose(input_file);
    fclose(copy_file);
    return 0;
}

/*
Ejercicio 4: Contador de Líneas, Palabras y Caracteres
Enunciado: Escribe un programa en C que lea un archivo de texto llamado "input.txt" y cuente el número de líneas, palabras y caracteres que contiene.
Indicaciones: Usa las funciones fopen, fgetc, y fclose. Considera una palabra como una secuencia de caracteres sin espacios.
*/
#define MAX_LENGTH 256
int main()
{
    FILE *file = fopen("input.txt", "r");
    if (file == NULL)
    {
        printf("File could not be opened \n");
        exit(1);
    }
    char buffer[MAX_LENGTH];
    int word_counter = 0;
    int char_counter = 0;
    int line_counter = 0;

    for (int i = 0; fgets(buffer, MAX_LENGTH, file) != NULL; i++)
    {

        for (int j = 0; buffer[j] != '\0'; j++)
        {
            if (buffer[j] != ' ')
            {
                char_counter++;
            }
            else if (buffer[j] == ' ')
            {
                word_counter++;
            }
        }
        word_counter++;
        line_counter++;
    }
    printf("CHAR COUNTER: %d \n", char_counter);
    printf("LINE COUNTER: %d \n", line_counter);
    printf("WORD COUNTER: %d \n", word_counter);
    fclose(file);
    return 0;
}

/*
Ejercicio 5: Modificación de Archivo
Enunciado: Escribe un programa en C que lea un archivo de texto llamado "input.txt", reemplace todas las ocurrencias de una palabra dada por otra palabra dada por el usuario, y guarde el resultado en un archivo llamado "output.txt".
Indicaciones: Usa las funciones fopen, fgets, fputs, strstr, y fclose. Tendrás que manejar cadenas de caracteres y realizar operaciones de búsqueda y reemplazo.
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGTH 256

int main()
{
    FILE *file = fopen("input.txt", "r");
    if (file == NULL)
    {
        printf("File could not be opened \n");
        exit(1);
    }
    char *buffer = (char *)malloc(sizeof(char) * MAX_LENGTH);
    if (buffer == NULL)
    {
        printf("Could not allocate memory \n");
        exit(1);
    }

    char *word_to_replace = (char *)malloc(sizeof(char) * MAX_LENGTH);
    if (word_to_replace == NULL)
    {
        printf("Could not allocate memory \n");
        exit(1);
    }

    char *replacement_word = (char *)malloc(sizeof(char) * MAX_LENGTH);
    if (replacement_word == NULL)
    {
        printf("Could not allocate memory \n");
        exit(1);
    }

    FILE *output_file = fopen("output.txt", "w");
    if (output_file == NULL)
    {
        printf("Could not open the file");
        exit(2);
    }

    printf("Enter the word to replace: \n");
    fgets(word_to_replace, MAX_LENGTH, stdin);
    word_to_replace[strcspn(word_to_replace, "\n")] = '\0';

    printf("Enter the replacement word: \n");
    fgets(replacement_word, MAX_LENGTH, stdin);
    replacement_word[strcspn(replacement_word, "\n")] = '\0';

    while (fgets(buffer, MAX_LENGTH, file) != NULL)
    {
        char *occurrence = buffer;
        while ((occurrence = strstr(occurrence, word_to_replace)) != NULL)
        {
            fwrite(buffer, 1, occurrence - buffer, output_file);
            fputs(replacement_word, output_file);
            occurrence += strlen(word_to_replace);
            buffer = occurrence;
        }
        fputs(buffer, output_file);
    }

    free(buffer);
    free(word_to_replace);
    free(replacement_word);
    fclose(file);
    fclose(output_file);
    return 0;
}
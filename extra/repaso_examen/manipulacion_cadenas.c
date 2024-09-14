/*
Escribe una función en C que reciba una cadena y un carácter, y elimine todas las ocurrencias de ese carácter en la cadena.
El programa principal debe leer una cadena y un carácter, llamar a la función y mostrar la cadena resultante
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void delete_char_occurences(char sentence[], char character);

int main()
{
    char sentence[200];
    char character;
    printf("Please enter a short sentence: \n");
    if (fgets(sentence, sizeof(sentence), stdin) == NULL)
    {
        printf("Error reading from the console");
        return 1;
    }

    printf("Please enter a character to find in the sentence \n");
    scanf(" %c", &character);

    delete_char_occurences(sentence, character);

    return 0;
}

void delete_char_occurences(char sentence[], char character)
{
    char new_sentence[200];
    int i = 0;
    int j = 0;

    for (i = 0; sentence[i]; i++)
    {
        if (sentence[i] != character)
        {
            new_sentence[j++] = sentence[i]; //Just if it is the entered character I add it to the new array
        }
    }

    new_sentence[j] = '\0'; // Add a null-terminator

    printf("The new sentence is: %s \n", new_sentence);
}
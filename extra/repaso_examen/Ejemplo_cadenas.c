/*
Escribe un programa en C que solicite al usuario que ingrese una cadena de caracteres.
El programa debe realizar las siguientes operaciones:
- Contar la cantidad de caracteres en la cadena ingresada (sin contar el carácter nulo '\0' al final).
- Calcular la cantidad de palabras en la cadena. Se considera que una palabra está delimitada por espacios en blanco.
- Reemplazar todas las vocales en la cadena por el carácter '*' (asterisco).
- Imprimir la cadena resultante después de realizar las operaciones anteriores.
El programa debe cumplir con las siguientes especificaciones:
- Debe utilizar funciones para realizar cada una de las operaciones mencionadas.
- No debe utilizar funciones predefinidas de bibliotecas como strlen(), strtok(), strcpy(), etc.,
para calcular la longitud de la cadena, contar palabras o realizar el reemplazo de vocales.
*/

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX_SIZE 256

int count_characters(char *sentence);
int count_words(char *sentence);
void replace_vowels(char *sentence);

int main()
{
    char *sentence = (char *)malloc(sizeof(char) * MAX_SIZE);
    if (sentence == NULL)
    {
        printf("Could not allocate memory");
        exit(1);
    }
    printf("Please enter a sentence: \n");
    fgets(sentence, MAX_SIZE, stdin);
    sentence[strcspn(sentence, "\n")] = '\0';

    int chars_number = count_characters(sentence);
    printf("Number of characters = %d \n", chars_number);
    int words_number = count_words(sentence);
    printf("Number of words = %d \n", words_number);
    replace_vowels(sentence);
    printf("Converted sentence : %s \n", sentence);

    free(sentence);
    return 0;
}

int count_characters(char *sentence)
{
    int chars_counter = 0;
    for (int i = 0; sentence[i] != '\0'; i++)
    {
        if (sentence[i] != ' ')
        {
            chars_counter++;
        }
    }

    return chars_counter;
}

int count_words(char *sentence)
{
    int words_counter = 0;
    for (int i = 0; sentence[i] != '\0'; i++)
    {
        if (sentence[i] == ' ' || sentence[i] == '\n')
        {
            words_counter++;
        }
    }
    return words_counter + 1; // number of words must always be number of spaces plus 1;
}

void replace_vowels(char *sentence)
{
    for (int i = 0; sentence[i] != '\0'; i++)
    {
        if (tolower(sentence[i]) == 'a' || tolower(sentence[i]) == 'e' || tolower(sentence[i]) == 'i' || tolower(sentence[i]) == 'o' || tolower(sentence[i]) == 'u')
        {
            sentence[i] = '*';
        }
    }
}
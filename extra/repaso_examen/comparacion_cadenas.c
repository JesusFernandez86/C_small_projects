/*
Escribe un programa en C que lea dos cadenas y determine si son anagramas (es decir, si tienen los mismos caracteres con la misma frecuencia).
El programa debe ignorar espacios y mayúsculas/minúsculas.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>

bool compare_sentences(char *sentence1, char *sentence2);

int main()
{
    char sentence1[200] = "Hello how are you";
    char sentence2[200] = "Hello who are you";

    if (compare_sentences(sentence1, sentence2))
    {
        printf("The sentences are anagrams\n");
    }
    else
    {
        printf("The sentences are not anagrams\n");
    }
    return 0;
}

bool compare_sentences(char *sentence1, char *sentence2)
{
    int alphabet[26] = {0}; //intialize all array elements to 0
    int i;

    // Normalize both sentences: convert to lowercase and count characters ignoring spaces
    for (i = 0; sentence1[i] != '\0'; i++)
    {
        if (isalpha(sentence1[i]))
        {
            alphabet[tolower(sentence1[i]) - 'a']++;
        }
    }

    for (i = 0; sentence2[i] != '\0'; i++)
    {
        if (isalpha(sentence2[i]))
        {
            alphabet[tolower(sentence2[i]) - 'a']--;
        }
    }

    // Check if all counts are zero
    for (i = 0; i < 26; i++)
    {
        if (alphabet[i] != 0)
        {
            return false;
        }
    }

    return true;
}

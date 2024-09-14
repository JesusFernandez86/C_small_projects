#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

int calculate_word_length(char *word);

int main()
{
    char *word = malloc(MAX_SIZE * sizeof(char));
    if (word == NULL)
    {
        printf("Memory allocation failed");
        return 1;
    }

    printf("Enter a word: ");
    fgets(word, MAX_SIZE, stdin);

    int length = calculate_word_length(word);

    printf("Length of word entered is :%d", length);
    free(word);

    return 0;
}

int calculate_word_length(char *word)
{
    // Calculate the length of the string manually
    int length = 0;
    while (word[length] != '\0' && word[length] != '\n')
    {
        length++;
    }
    word = realloc(word, length); // Reallocate memory based on the calculated length

    if (word == NULL)
    {
        printf("Memory reallocation failed");
        return 1;
    }

    return length;
}
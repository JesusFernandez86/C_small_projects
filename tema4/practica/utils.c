#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

void remove_capitals_message(char *message)
{
    for (int i = 0; message[i] != '\0'; i++)
    {
        message[i] = tolower(message[i]);
    }

    char *ocurrence = strstr(message, "activo");
    if (ocurrence)
    {
        for (char *ptr = ocurrence; *ptr != '\0'; ptr++)
        {
            *ptr = toupper(*ptr);
        }
    }
    else
    {
        printf("Substring not found");
    }
}

void free_string_array(char **array)
{
    if (!array)
        return;
    for (int i = 0; array[i]; i++)
    {
        free(array[i]);
    }
    free(array);
}
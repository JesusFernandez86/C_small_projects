#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "utils.h"

#define MAX_LENGTH 500

typedef struct dictionary_t
{
    char letter_dictionary[26];
    char number_dictionary[10];
} dictionary;

dictionary myDictionary = {
    .letter_dictionary = {'W', 'X', 'A', 'H', 'Q', 'F', 'P', 'I', 'R', 'V', 'K', 'B', 'J', 'D', 'G', 'M', 'E', 'L', 'N', 'O', 'Y', 'U', 'T', 'C', 'Z', 'S'},
    .number_dictionary = {'7', '8', '3', '5', '4', '6', '2', '9', '1', '0'}};

char *read_message();
char *message_to_capitals(char *message);
char *encrypt_message(char *message);
char *extract_complex_data(char *message);
void split_complex_data(char *message);
char **decrypt_message(char *message);

int main()
{
    char *message = read_message();
    printf("The original message is: %s \n", message);
    printf("------------------------------------------------------------ \n");

    char *capital_message = message_to_capitals(message);
    printf("The message in Capitals is: %s \n", capital_message);
    printf("------------------------------------------------------------ \n");

    char *encrypted_message = encrypt_message(capital_message);
    printf("The encrypted message is: %s \n", encrypted_message);
    printf("------------------------------------------------------------ \n");

    char *complex_data = extract_complex_data(encrypted_message);
    printf("The complex data string is: %s \n", complex_data);
    printf("------------------------------------------------------------ \n");

    split_complex_data(complex_data);
    printf("------------------------------------------------------------ \n");

    char **decrypted_data = decrypt_message(complex_data);
    for (int i = 0; decrypted_data[i] != NULL; i++)
    {
        printf("Decoded field in position %d %s \n", i + 1, decrypted_data[i]);
    }
    printf("------------------------------------------------------------ \n");

    printf("The original message remains untouched and is: %s \n", message);
    printf("------------------------------------------------------------ \n");

    free(message);
    free(capital_message);
    free(encrypted_message);
    free(complex_data);
    free_string_array(decrypted_data);
    return 0;
}
/* Se que no es la mejor implementacion pero queria intentar implementar algo yo
en vez de usar la funcion leerLineaDinamica que se nos da en el temario */
char *read_message()
{
    char aux_msg[MAX_LENGTH];
    printf("Enter your message: ");
    fgets(aux_msg, sizeof(aux_msg), stdin);
    printf("\n");
    size_t length = strlen(aux_msg);
    if (aux_msg[length - 1] == '\n')
    {
        aux_msg[length - 1] = '\0';
        length--;
    }
    char *message = malloc((length + 1) * sizeof(char));
    if (message == NULL)
    {
        fprintf(stderr, "Error: Unable to allocate memory.\n");
        exit(1);
    }
    strcpy(message, aux_msg);
    return message;
}

char *message_to_capitals(char *message)
{
    char *message_copy = malloc((strlen(message) + 1) * sizeof(char));
    if (message_copy == NULL)
    {
        fprintf(stderr, "Error: Unable to allocate memory.\n");
        exit(1);
    }
    else
    {
        strcpy(message_copy, message);
    }

    int is_next_letter_capital = 0;
    for (int i = 0; message_copy[i] != '\0'; i++)
    {
        if (is_next_letter_capital == 1)
        {
            message_copy[i] = toupper(message_copy[i]);
            is_next_letter_capital = 0;
        }
        if (message_copy[i] == ' ' || message_copy[i] == '(' || message_copy[i] == '-')
        {
            is_next_letter_capital = 1;
        }
    }
    return message_copy;
}

char *encrypt_message(char *message)
{
    char uppercase_letter;

    char *message_copy = malloc((strlen(message) + 1) * sizeof(char));
    if (message_copy == NULL)
    {
        fprintf(stderr, "Error: Unable to allocate memory.\n");
        exit(1);
    }
    else
    {
        strcpy(message_copy, message);
    }

    for (int i = 0; message[i] != '\0'; i++)
    {
        if (isalpha(message_copy[i]))
        {
            uppercase_letter = toupper(message_copy[i]);
            message_copy[i] = myDictionary.letter_dictionary[uppercase_letter - 'A'];
        }
        else if (isdigit(message[i]))
        {
            message_copy[i] = myDictionary.number_dictionary[message_copy[i] - '0'];
        }
    }
    return message_copy;
}

char *extract_complex_data(char *message)
{
    int open_parenthesis = strchr(message, '(') - message;
    int close_parenthesis = strchr(message, ')') - message;
    char *complex_data = (char *)malloc(strlen(message) + 1);

    if (complex_data == NULL)
    {
        printf("Memory not allocated.\n");
        exit(0);
    }
    strncpy(complex_data, &message[open_parenthesis + 1], close_parenthesis - open_parenthesis - 1);
    complex_data[close_parenthesis - open_parenthesis - 1] = '\0';

    return complex_data;
}

void split_complex_data(char *message)
{
    int counter = 1;
    char *message_copy = malloc((strlen(message) + 1) * sizeof(char));
    if (message_copy == NULL)
    {
        fprintf(stderr, "Error: Unable to allocate memory.\n");
        exit(1);
    }
    else
    {
        strcpy(message_copy, message);
        char *token = strtok(message_copy, "-");
        while (token != NULL)
        {
            printf("Encoded field in position %d: %s\n", counter, token);
            counter++;
            token = strtok(NULL, "-");
        }
    }
    free(message_copy);
}

char **decrypt_message(char *message)
{
    if (!message)
        return NULL;

    int counter = 0;
    char **decoded = malloc(sizeof(char *));
    if (!decoded)
        return NULL;

    char inverse_letter_dictionary[26];
    char inverse_number_dictionary[10];

    for (int i = 0; i < 26; i++)
    {
        inverse_letter_dictionary[myDictionary.letter_dictionary[i] - 'A'] = 'A' + i;
    }

    for (int i = 0; i < 10; i++)
    {
        inverse_number_dictionary[myDictionary.number_dictionary[i] - '0'] = '0' + i;
    }

    char *message_copy = malloc((strlen(message) + 1) * sizeof(char));
    if (message_copy == NULL)
    {
        free_string_array(decoded);
        return NULL;
    }
    strcpy(message_copy, message);

    for (int i = 0; message[i] != '\0'; i++)
    {
        if (isalpha(message_copy[i]))
        {
            message_copy[i] = inverse_letter_dictionary[message_copy[i] - 'A'];
        }
        else if (isdigit(message[i]))
        {
            message_copy[i] = inverse_number_dictionary[message_copy[i] - '0'];
        }
    }

    remove_capitals_message(message_copy);

    char *token = strtok(message_copy, "-");
    while (token != NULL)
    {
        char **temp = realloc(decoded, (counter + 1) * sizeof(char *));
        if (!temp)
        {
            free_string_array(decoded);
            free(message_copy);
            return NULL;
        }
        decoded = temp;

        decoded[counter] = malloc((strlen(token) + 1) * sizeof(char));
        if (decoded[counter] == NULL)
        {
            free_string_array(decoded);
            free(message_copy);
            return NULL;
        }
        strcpy(decoded[counter], token);
        counter++;
        token = strtok(NULL, "-");
    }

    char **temp = realloc(decoded, (counter + 1) * sizeof(char *));
    if (!temp)
    {
        free_string_array(decoded);
        free(message_copy);
        return NULL;
    }
    decoded = temp;
    decoded[counter] = NULL;

    free(message_copy);
    return decoded;
}
#include <stdio.h>
#include <string.h>
#include "utils.h"
#include "user.h"

void create_users(User user[], int size)
{
    printf("---------ADD THE USER INFORMATION---------\n");

    for (int i = 0; i < size; i++)
    {
        printf("User name: ");
        fgets(user[i].name, sizeof(user[i].name), stdin);
        strtok(user[i].name, "\n");

        printf("User surname: ");
        fgets(user[i].surname, sizeof(user[i].surname), stdin);
        strtok(user[i].surname, "\n");

        printf("User id: ");
        while (scanf("%d", &user[i].user_id) != 1) // making sure the id is a number
        {
            clear_input_buffer();
            printf("Invalid input. Please enter just numbers for the id: ");
        }
        clear_input_buffer();

        printf("User email: ");
        fgets(user[i].email, sizeof(user[i].email), stdin);
        strtok(user[i].email, "\n");

        printf("User phone number: ");
        while (scanf("%d", &user[i].phone_number) != 1) // making sure the phone number is a number
        {
            clear_input_buffer();
            printf("Invalid phone format. Please enter just numbers for the phone number: ");
        }
        clear_input_buffer();

        printf("\n");
    }
}

void print_users(User user[], int size)
{
    printf("---------PRINTING USERS INFORMATION---------\n");
    for (int i = 0; i < size; i++)
    {
        printf("User_%i name: %s\n", i, user[i].name);
        printf("User_%i surname: %s\n", i, user[i].surname);
        printf("User_%i id: %d\n", i, user[i].user_id);
        printf("User_%i email: %s\n", i, user[i].email);
        printf("User_%i phone number: %d\n", i, user[i].phone_number);
        printf("\n");
    }
}
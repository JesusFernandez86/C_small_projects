#include <stdio.h>
#include "user.h"
#include "book.h"
#include "order.h"
#include "utils.h"

#define MAX_USERS 3
#define MAX_BOOKS 3
#define MAX_ORDERS 3

typedef enum options_t
{
    CREATE_USER = 1,
    CREATE_BOOK,
    CREATE_ORDER,
    EXIT_PROGRAM
} Options;

int main()
{
    User user[MAX_USERS];
    Book book[MAX_BOOKS];
    Order order[MAX_ORDERS];

    int option = 0;

    while (option != EXIT_PROGRAM)
    {
        printf("What would you like to do next?\n 1. Create users\n 2. Create books\n 3. Create orders\n 4. Exit\nOption chosen: ");
        if (scanf("%d", &option) != 1) // to check if the user enters something different than a number on the main menu
        {
            printf("\nInvalid input. Please enter a number between 1 and 4.\n");
            clear_input_buffer();
            continue;
        }
        clear_input_buffer();
        printf("\n");
        switch (option)
        {
        case CREATE_USER:
            create_users(user, MAX_USERS);
            print_users(user, MAX_USERS);
            break;
        case CREATE_BOOK:
            create_books(book, MAX_BOOKS);
            print_books(book, MAX_BOOKS);
            break;
        case CREATE_ORDER:
            create_orders(order, MAX_ORDERS);
            print_orders(order, MAX_ORDERS);
            break;
        case EXIT_PROGRAM:
            printf("Bye!\n");
            break;
        default:
            printf("Option not recognized, please try again.\n"); // to check if the user enters a number different than 1 to 4
            break;
        }
    }
    return 0;
}
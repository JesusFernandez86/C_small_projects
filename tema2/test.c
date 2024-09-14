b#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_USERS 3
#define MAX_BOOKS 3
#define MAX_ORDERS 3

typedef struct user_t
{
    char name[30];
    char surname[40];
    int user_id;
    char email[50];
    int phone_number;
} User;

typedef struct book_t
{
    char title[40];
    char author[40];
    char isbn[14];
    float price;
    int stock_amount;
} Book;

typedef enum status_t
{
    PREPARING = 1,
    SHIPPED,
    DELIVERING,
    DELIVERED
} Status;

typedef struct order_t
{
    int user_id;
    char isbn[14];
    int amount;
    float total_price;
    Status status;
} Order;

typedef enum options_t
{
    CREATE_USER = 1,
    CREATE_BOOK,
    CREATE_ORDER,
    EXIT_PROGRAM
} Options;

void clear_input_buffer()
{
    int c;
    while ((c = getchar()) != '\n' && c != EOF)
    {
    }
}

void create_user(User user[], int size);
void print_user(User user[], int size);
void create_book(Book book[], int size);
void print_book(Book book[], int size);
void create_order(Order order[], int size);
void print_order(Order order[], int size);

int main()
{
    User user[MAX_USERS];
    Book book[MAX_BOOKS];
    Order order[MAX_ORDERS];

    int option = 0;

    while (option != EXIT_PROGRAM)
    {
        printf("What would you like to do next?\n 1. Create users\n 2. Create books\n 3. Create orders\n 4. Exit\nOption chosen: ");
        if (scanf("%d", &option) != 1)
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
            create_user(user, MAX_USERS);
            print_user(user, MAX_USERS);
            break;
        case CREATE_BOOK:
            create_book(book, MAX_BOOKS);
            print_book(book, MAX_BOOKS);
            break;
        case CREATE_ORDER:
            create_order(order, MAX_ORDERS);
            print_order(order, MAX_ORDERS);
            break;
        case EXIT_PROGRAM:
            printf("Bye!\n");
            break;
        default:
            printf("Option not recognized, please try again.\n");
            break;
        }
    }

    return 0;
}

void create_user(User user[], int size)
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
        scanf("%d", &user[i].user_id);
        clear_input_buffer();

        printf("User email: ");
        fgets(user[i].email, sizeof(user[i].email), stdin);
        strtok(user[i].email, "\n");

        printf("User phone number: ");
        scanf("%d", &user[i].phone_number);
        clear_input_buffer();

        printf("\n");
    }
}

void print_user(User user[], int size)
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

void create_book(Book book[], int size)
{
    printf("---------ADD THE BOOK INFORMATION---------\n");

    for (int i = 0; i < size; i++)
    {
        printf("Book title: ");
        fgets(book[i].title, sizeof(book[i].title), stdin);
        strtok(book[i].title, "\n");

        printf("Book author: ");
        fgets(book[i].author, sizeof(book[i].author), stdin);
        strtok(book[i].author, "\n");

        printf("Book isbn: ");
        fgets(book[i].isbn, sizeof(book[i].isbn), stdin);
        strtok(book[i].isbn, "\n");

        printf("Book price: ");
        scanf("%f", &book[i].price);
        clear_input_buffer();

        printf("Book stock amount: ");
        scanf("%d", &book[i].stock_amount);
        clear_input_buffer();

        printf("\n");
    }
}

void print_book(Book book[], int size)
{
    printf("---------PRINTING BOOKS INFORMATION---------\n");
    for (int i = 0; i < size; i++)
    {
        printf("Book_%i title: %s\n", i, book[i].title);
        printf("Book_%i author: %s\n", i, book[i].author);
        printf("Book_%i isbn: %s\n", i, book[i].isbn);
        printf("Book_%i price: %.2f\n", i, book[i].price);
        printf("Book_%i stock amount: %d\n", i, book[i].stock_amount);
        printf("\n");
    }
}

void create_order(Order order[], int size)
{
    printf("---------ADD THE ORDER INFORMATION---------\n");

    for (int i = 0; i < size; i++)
    {
        printf("Order user id: ");
        scanf("%d", &order[i].user_id);
        clear_input_buffer();

        printf("Order isbn: ");
        fgets(order[i].isbn, sizeof(order[i].isbn), stdin);
        strtok(order[i].isbn, "\n");

        printf("Order amount: ");
        scanf("%d", &order[i].amount);
        clear_input_buffer();

        printf("Order total price: ");
        scanf("%f", &order[i].total_price);
        clear_input_buffer();

        printf("Order status (1 - PREPARING, 2 - SHIPPED, 3 - DELIVERING, 4 - DELIVERED): ");
        scanf("%d", &order[i].status);
        clear_input_buffer();

        printf("\n");
    }
}

void print_order(Order order[], int size)
{
    printf("---------PRINTING ORDERS INFORMATION---------\n");
    for (int i = 0; i < size; i++)
    {
        printf("Order_%i user id: %d\n", i, order[i].user_id);
        printf("Order_%i isbn: %s\n", i, order[i].isbn);
        printf("Order_%i amount of items: %d\n", i, order[i].amount);
        printf("Order_%i total price: %.2f\n", i, order[i].total_price);

        char *status;
        switch (order[i].status)
        {
        case PREPARING:
            status = "PREPARING";
            break;
        case SHIPPED:
            status = "SHIPPED";
            break;
        case DELIVERING:
            status = "DELIVERING";
            break;
        case DELIVERED:
            status = "DELIVERED";
            break;
        default:
            status = "UNKNOWN";
            break;
        }
        printf("Order_%i status: %s\n", i, status);
        printf("\n");
    }
}

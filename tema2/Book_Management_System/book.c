#include <stdio.h>
#include <string.h>
#include "book.h"
#include "utils.h"

void create_books(Book book[], int size)
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

void print_books(Book book[], int size)
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
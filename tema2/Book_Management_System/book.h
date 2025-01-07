#ifndef BOOK_H
#define BOOK_H

typedef struct book_t
{
    char title[40];
    char author[40];
    char isbn[14];
    float price;
    int stock_amount;
} Book;

void create_books(Book book[], int size);
void print_books(Book book[], int size);

#endif

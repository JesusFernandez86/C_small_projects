/*Enunciado: Define una estructura para un libro que incluya el título, 
el autor (que a su vez es una estructura con nombre y apellido) y 
el año de publicación. Escribe una función que imprima los detalles de un libro.*/

#include <stdio.h>
#include <stdlib.h>

typedef struct author_t
{
    char name[50];
    char surname[50];
} Author;

typedef struct book_t
{
    char title[50];
    Author author;
    char ISBN[50];
    int price;
} Book;

// void create_book(Book book);
void print_book(Book book);

int main()
{
    Book book_1 = {"Dune", {"Jesus", "Fernandez"}, "ASD122SDSAD2", 25};
    print_book(book_1);
    return 0;
}

void print_book(Book book)
{
    printf("Title: %s \n", book.title);
    printf("Author name: %s \n", book.author.name);
    printf("Author surname: %s \n", book.author.surname);
    printf("ISBN: %s \n", book.ISBN);
    printf("Price: %d \n", book.price);
}
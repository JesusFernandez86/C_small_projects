# Practica Program

This program is designed to manage a collection of users, books and orders from a book store. It allows users to add new users, books and orders and also view existing ones, and perform other related operations.

## Program Features

- Add a new User: Users can input the details of a new user, including the name, surname, and other relevant information.
- View Users: Users can view the details of all the users in the collection.
- Add a new Book: Users can input the details of a new Book, including the title, author, and other relevant information.
- View Books: Users can view the details of all the users in the collection.
- Add a new Order: Users can input the details of a new order, including the id, price, and other relevant information.
- View Orders: Users can view the details of all the orders in the collection.

## How to Compile and Run

This program is written in C and can be compiled and run using the GCC compiler. Follow the steps below to compile and run the program:

1. Open a terminal in the current directory.
2. Compile the program using the following command:

```bash
gcc -c main.c -o main.o
gcc -c book.c -o book.o
gcc -c user.c -o user.o
gcc -c order.c -o order.o 
gcc -c utils.c -o utils.o
gcc -o practica main.o user.o order.o book.o utils.o

.\practica.exe
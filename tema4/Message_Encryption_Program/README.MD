# Message Encryption Program

This program is designed to encrypt and decrypt messages based on predefined character and number dictionaries. It simulates an international espionage scenario, providing secure message transmission capabilities.

## File Structure

- `main.c`: Contains the main program logic.
- `utils.h`: Header file containing utility functions.
- `utils.c`: Source file containing utility function definitions.

## Program Features

- Read Message: Allows the user to input a message, which is then processed by the program.
- Convert to Capitals: Converts the initial character of each word in the message to uppercase.
- Encrypt Message: Encrypts the message using predefined dictionaries for letters and numbers.
- Extract Complex Data: Extracts and displays complex data embedded within parentheses in the encrypted message.
- Split Complex Data: Separates the complex data into distinct fields using predefined separators.
- Decrypt Message: Decrypts the encrypted complex data back to its original format.

## How to Compile and Run

This program is written in C and can be compiled and run using the GCC compiler. Follow the steps below to compile and run the program:

1. Open a terminal in the current directory.
2. Compile the program using the following commands:

```bash
gcc -c main.c -o main.o
gcc -c utils.c -o utils.o
gcc -o practica main.o utils.o

.\practica.exe
```

## Contributions

Contributions to this project are welcome. Please ensure that you maintain clean and well-documented code when proposing changes.

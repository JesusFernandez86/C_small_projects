# Person Data Management Program

This C program manages a dataset of personal records stored in a CSV file and transfers them to a binary format for efficient access. It allows users to query specific records by index and get the data from the binary file.

## Features

- Reads data from a CSV file.
- Stores data in an in-memory array structure.
- Saves data to a binary file for persistent storage.
- Enables querying of specific records by index through direct access.

## Data Structure

The data for each person is stored in a structure with the following fields:

- `index`: Record index
- `user_id`: User identifier
- `name`: First name
- `last_name`: Last name
- `sex`: Gender
- `email`: Email address
- `phone`: Phone number
- `DOB`: Date of birth
- `job_title`: Job title

## Requirements

To compile and run this program, you will need:

- A C compiler, such as GCC.
- Access to a terminal or command line.

## Compilation and Execution

To compile the program, use the following command in your terminal:

```bash
gcc practica.c -o programa
./programa.exe
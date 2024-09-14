// fputs() function in C is used to write a string to a file. It takes two arguments:
// the string to be written and a pointer to the file where the string will be written.
#include <stdio.h>

int main()
{
    FILE *file = fopen("file.txt", "w");
    if (file == NULL)
    {
        printf("Could not open file.\n");
        return 1;
    }

    char *str = "Hello, world!";
    fputs(str, file);

    fclose(file);

    return 0;
}
// fgets() function in C is used to read a line from a file. It takes three arguments: a buffer to store the read line,
// the maximum number of characters to be read (including the null character), and a pointer to the file from which the line will be read.

#include <stdio.h>

int main()
{
    FILE *file = fopen("file.txt", "r");
    if (file == NULL)
    {
        printf("Could not open file.\n");
        return 1;
    }

    char str[256];
    if (fgets(str, sizeof(str), file) != NULL)
    {
        printf("Read line: %s", str);
    }
    else
    {
        printf("Could not read line.\n");
    }

    fclose(file);

    return 0;
}

// fprintf is a function that writes formatted output to a file. It's similar to printf, but instead of writing to the console, it writes to a file.
// The first argument is a pointer to the file, and the rest of the arguments are the same as printf.
#include <stdio.h>

int main()
{
    FILE *file = fopen("file.txt", "w");
    if (file == NULL)
    {
        printf("Could not open file.\n");
        return 1;
    }

    int num = 42;
    fprintf(file, "The number is %d\n", num);

    fclose(file);

    return 0;
}

//fscanf() is a function that reads formatted input from a file. It's similar to scanf, but instead of reading from the console, it reads from a file.
//The first argument is a pointer to the file, and the rest of the arguments are the same as scanf.
#include <stdio.h>

int main()
{
    FILE *file = fopen("file.txt", "r");
    if (file == NULL)
    {
        printf("Could not open file.\n");
        return 1;
    }

    int num;
    if (fscanf(file, "The number is %d", &num) == 1)
    {
        printf("Read number: %d\n", num);
    }
    else
    {
        printf("Could not read number.\n");
    }

    fclose(file);

    return 0;
}

// feof() is a function that checks if the end of a file has been reached.
// It takes a file pointer as an argument and returns a non-zero value if the end of the file has been reached, and zero otherwise.
#include <stdio.h>

int main()
{
    FILE *file = fopen("file.txt", "r");
    if (file == NULL)
    {
        printf("Could not open file.\n");
        return 1;
    }

    char ch;
    while ((ch = fgetc(file)) != EOF)
    {
        putchar(ch);
    }

    if (feof(file))
    {
        printf("\nEnd of file reached.\n");
    }
    else
    {
        printf("\nSomething went wrong.\n");
    }

    fclose(file);

    return 0;
}

// rewind() is a function that sets the file position to the beginning of the file. It takes a file pointer as an argument and doesn't return a value.
#include <stdio.h>

int main()
{
    FILE *file = fopen("file.txt", "r+");
    if (file == NULL)
    {
        printf("Could not open file.\n");
        return 1;
    }

    fputs("Hello, world!", file);

    rewind(file);

    char str[256];
    if (fgets(str, sizeof(str), file) != NULL)
    {
        printf("Read line: %s", str);
    }
    else
    {
        printf("Could not read line.\n");
    }

    fclose(file);

    return 0;
}
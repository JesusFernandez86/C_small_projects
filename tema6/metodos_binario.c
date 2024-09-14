// fwrite() is a function that writes data to a file. It takes four arguments: a pointer to the data to be written, the size of each data item,
// the number of data items, and a file pointer. It returns the number of items successfully written.
#include <stdio.h>

int main()
{
    FILE *file = fopen("file.bin", "wb");
    if (file == NULL)
    {
        printf("Could not open file.\n");
        return 1;
    }

    int num = 42;
    fwrite(&num, sizeof(int), 1, file);

    fclose(file);

    return 0;
}

// fread is a function that reads data from a file. It takes four arguments: a pointer to the buffer where the read data will be stored, the size of each data item,
// the number of data items, and a file pointer. It returns the number of items successfully read.

int main()
{
    FILE *file = fopen("file.bin", "rb");
    if (file == NULL)
    {
        printf("Could not open file.\n");
        return 1;
    }

    int num;
    fread(&num, sizeof(int), 1, file);
    printf("Read number: %d\n", num);

    fclose(file);

    return 0;
}

// fseek is a function that changes the file position. It takes three arguments: a file pointer, an offset,
// and a constant that specifies the point from which the offset is added. It returns zero if successful, and non-zero otherwise.

int main()
{
    FILE *file = fopen("file.bin", "rb");
    if (file == NULL)
    {
        printf("Could not open file.\n");
        return 1;
    }

    fseek(file, sizeof(int), SEEK_SET);

    int num;
    fread(&num, sizeof(int), 1, file);
    printf("Read number: %d\n", num);

    fclose(file);

    return 0;
}
// ftell()S is a function that returns the current file position.
// It takes a file pointer as an argument and returns the current file position as a long int.

#include <stdio.h>

int main()
{
    FILE *file = fopen("file.bin", "rb");
    if (file == NULL)
    {
        printf("Could not open file.\n");
        return 1;
    }

    fseek(file, sizeof(int), SEEK_SET);
    printf("Current position: %ld\n", ftell(file));

    fclose(file);

    return 0;
}
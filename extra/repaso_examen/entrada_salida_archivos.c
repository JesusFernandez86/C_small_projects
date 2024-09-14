#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 256
#define MAX_LINES 10

int main()
{
    FILE *input_file = fopen("input.txt", "r");
    if (input_file == NULL)
    {
        printf("Could not open file\n");
        return 1;
    }

    char lines[MAX_LINES][MAX_LINE_LENGTH];
    int line_count = 0;

    char line[MAX_LINE_LENGTH];

    while (fgets(line, sizeof(line), input_file) != NULL)
    {
        if (line_count >= MAX_LINES)
        {
            printf("Too many lines in the file\n");
            return 1;
        }
        strcpy(lines[line_count], line);
        line_count++;
    }

    fclose(input_file);

    FILE *output_file = fopen("output.txt", "w");
    if (output_file == NULL)
    {
        printf("Could not open the file\n");
        return 1;
    }

    for (int i = line_count - 1; i >= 0; i--)
    {
        fprintf(output_file, "%s", lines[i]);
    }

    fclose(output_file);

    return 0;
}
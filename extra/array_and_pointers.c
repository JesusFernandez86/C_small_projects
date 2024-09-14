#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i, j;
    /* Define the 2D pointer variable here */
    int **pnumbers;

    /* Allocate memory for holding three rows */
    pnumbers = (int **)malloc(3 * sizeof(int *));
    if (pnumbers == NULL)
    {
        perror("Failed to allocate memory");
        return 1;
    }

    /* Allocate memory for storing the individual elements in each row */
    pnumbers[0] = (int *)malloc(1 * sizeof(int));
    pnumbers[1] = (int *)malloc(2 * sizeof(int));
    pnumbers[2] = (int *)malloc(3 * sizeof(int));

    if (pnumbers[0] == NULL || pnumbers[1] == NULL || pnumbers[2] == NULL)
    {
        perror("Failed to allocate memory");
        // Free any already allocated memory before returning
        for (i = 0; i < 3; i++)
        {
            if (pnumbers[i] != NULL)
                free(pnumbers[i]);
        }
        free(pnumbers);
        return 1;
    }

    /* Initialize array elements */
    pnumbers[0][0] = 1;
    pnumbers[1][0] = 1;
    pnumbers[1][1] = 1;
    pnumbers[2][0] = 1;
    pnumbers[2][1] = 2;
    pnumbers[2][2] = 1;

    /* Print the 2D array */
    for (i = 0; i < 3; i++)
    {
        for (j = 0; j <= i; j++)
        {
            printf("%d ", pnumbers[i][j]);
        }
        printf("\n");
    }

    /* Free memory allocated for each row */
    for (i = 0; i < 3; i++)
    {
        free(pnumbers[i]);
    }

    /* Free the top-level pointer */
    free(pnumbers);
    return 0;
}

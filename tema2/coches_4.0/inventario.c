#include <stdio.h>
#include "clientes.h"
#include "inventario.h"

void print_inventario(Inventario invent[], int inve)
{
    char *coche;
    for (int i = 0; i < inve; i++)
    {
        printf("----------Coche--------------------------------------------|\n");
        printf("| Existencias: %d |\n", invent[i].existencia);

        switch (invent[i].coche)
        {
        case BERLINA:
            coche = "Berlina";
            break;

        case COMPACTO:
            coche = "Compacto";
            break;

        case CABRIOLET:
            coche = "Cabriolet";
            break;
        }

        printf("| Coche: %-40s |\n", coche);
        printf("-----------------------------------------------------------|\n");
    }
}
void create_inventario(Inventario invent[], int inve)
{
    printf("Por favor ingrese la informacion del coche:\n");
    for (int i = 0; i < inve; i++)
    {
        printf("tipo de coche para iniciar existencias (1 para Berlina, 2 para Compacto y 3 para Cabriolet) : ");

        scanf("%d", &invent[i].coche);
        printf("Existencias del tipo de coche: ");

        scanf(" %d", &invent[i].existencia);
        printf("\n");
    }
}
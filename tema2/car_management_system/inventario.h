#ifndef INVENTARIO
#define INVENTARIO

#include "clientes.h"

typedef struct inventario_t
{
    Coche coche;
    int existencia;

} Inventario;

void create_inventario(Inventario invent[], int inve);
void update_inventario(Inventario invent[], int inve);
void print_inventario(Inventario invent[], int inve);
#endif // INVENTARIO
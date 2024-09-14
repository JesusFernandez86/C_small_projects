#include "clientes.h"
#include "inventario.h"

typedef struct factura_t
{
    int nro_factura;
    Coche coche;
    int cantidad;
    int precio;
    char nombre[30];
    char apellido[40];
    char NIF[9];

} Factura;

void create_factura(Factura factu[], Inventario invent[], int nro);
void print_factura(Factura factu[], int nro);
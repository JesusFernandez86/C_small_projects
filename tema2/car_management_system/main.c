#include <stdio.h>
#include "clientes.h"
#include "inventario.h"
#include "factura.h"

#define SIZE 3
#define CARS 3
#define FACT 2

int main()
{
    Cliente c[SIZE];
    Inventario v[CARS];
    Factura f[FACT];
    create_cliente(c, SIZE);
    print_cliente(c, SIZE);
    create_inventario(v, CARS);
    print_inventario(v, CARS);
    create_factura(f, v, 1);
    print_factura(f, 1);

    return 0;
}

typedef enum status_t
{
    PREPARING = 1,
    SHIPPED = 2,
    DELIVERING = 3,
    DELIVERED = 4
} Status;

typedef struct order_t
{
    int user_id;
    char isbn[13];
    int amount;
    float total_price;
    Status status;
} Order;
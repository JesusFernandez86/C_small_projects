#include <stdio.h>
#include <string.h>
#include "utils.h"
#include "order.h"

void create_orders(Order order[], int size)
{
    printf("---------ADD THE ORDER INFORMATION---------\n");

    for (int i = 0; i < size; i++)
    {
        printf("Order user id: ");
        scanf("%d", &order[i].user_id);
        clear_input_buffer();

        printf("Order isbn: ");
        fgets(order[i].isbn, sizeof(order[i].isbn), stdin);
        strtok(order[i].isbn, "\n");

        printf("Order amount: ");
        scanf("%d", &order[i].amount);
        clear_input_buffer();

        printf("Order total price: ");
        scanf("%f", &order[i].total_price);
        clear_input_buffer();

        printf("Order status (1 - PREPARING, 2 - SHIPPED, 3 - DELIVERING, 4 - DELIVERED): ");
        scanf("%d", &order[i].status);
        clear_input_buffer();

        printf("\n");
    }
}

void print_orders(Order order[], int size)
{
    printf("---------PRINTING ORDERS INFORMATION---------\n");
    for (int i = 0; i < size; i++)
    {
        printf("Order_%i user id: %d\n", i, order[i].user_id);
        printf("Order_%i isbn: %s\n", i, order[i].isbn);
        printf("Order_%i amount of items: %d\n", i, order[i].amount);
        printf("Order_%i total price: %.2f\n", i, order[i].total_price);

        char *status;
        switch (order[i].status)
        {
        case PREPARING:
            status = "PREPARING";
            break;
        case SHIPPED:
            status = "SHIPPED";
            break;
        case DELIVERING:
            status = "DELIVERING";
            break;
        case DELIVERED:
            status = "DELIVERED";
            break;
        default:
            status = "UNKNOWN";
            break;
        }
        printf("Order_%i status: %s\n", i, status);
        printf("\n");
    }
}
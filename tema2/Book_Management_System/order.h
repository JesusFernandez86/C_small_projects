#ifndef ORDER_H
#define ORDER_H

typedef enum status_t
{
    PREPARING = 1,
    SHIPPED,
    DELIVERING,
    DELIVERED
} Status;

typedef struct order_t
{
    int user_id;
    char isbn[14];
    int amount;
    float total_price;
    Status status;
} Order;

void create_orders(Order order[], int size);
void print_orders(Order order[], int size);

#endif
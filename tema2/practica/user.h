#ifndef USER_H
#define USER_H

typedef struct user_t
{
    char name[30];
    char surname[40];
    int user_id;
    char email[50];
    int phone_number;
} User;

void create_users(User user[], int size);
void print_users(User user[], int size);

#endif
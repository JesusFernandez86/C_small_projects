#include <stdio.h>
#include <stdlib.h>

// Define a node structure
typedef struct node
{
    int val;           // Value of the node
    struct node *next; // Pointer to the next node
} node_t;

// Function prototypes
void print_list(node_t *head);     // Prints all elements in the list
void push(node_t **head, int val); // Adds a new element at the beginning of the list
int pop(node_t **head);            // Removes the first element in the list and returns its value
int remove_last(node_t *head);     // Removes the last element in the list and returns its value

int main()
{
    // Create a linked list with three nodes
    node_t *head = NULL;
    head = (node_t *)malloc(sizeof(node_t));
    if (head == NULL)
    {
        return 1;
    }
    head->val = 1;
    head->next = (node_t *)malloc(sizeof(node_t));
    head->next->val = 2;
    head->next->next = (node_t *)malloc(sizeof(node_t));
    head->next->next->val = 3;
    head->next->next->next = NULL;

    print_list(head); // Print all elements in the list

    push(&head, 0); // Add a new element at the beginning of the list
    print_list(head);

    pop(&head); // Remove the first element in the list
    print_list(head);

    remove_last(head); // Remove the last element in the list
    print_list(head);

    return 0;
}

// Function to print all elements in the list
void print_list(node_t *head)
{
    node_t *current = head;

    while (current != NULL)
    {
        printf("%d\n", current->val);
        current = current->next;
    }
    printf("\n");
}

// Function to add a new element at the beginning of the list
void push(node_t **head, int val)
{
    node_t *new_node;
    new_node = (node_t *)malloc(sizeof(node_t));

    new_node->val = val;
    new_node->next = *head;
    *head = new_node;
}

// Function to remove the first element in the list and return its value
int pop(node_t **head)
{
    int retval = -1;
    node_t *next_node = NULL;

    if (*head == NULL)
    {
        return -1;
    }

    next_node = (*head)->next;
    retval = (*head)->val;
    free(*head);
    *head = next_node;

    return retval;
}

// Function to remove the last element in the list and return its value
int remove_last(node_t *head)
{
    int retval = 0;
    /* if there is only one item in the list, remove it */
    if (head->next == NULL)
    {
        retval = head->val;
        free(head);
        return retval;
    }

    /* get to the second to last node in the list */
    node_t *current = head;
    while (current->next->next != NULL)
    {
        current = current->next;
    }

    /* now current points to the second to last item of the list, so let's remove current->next */
    retval = current->next->val;
    free(current->next);
    current->next = NULL;
    return retval;
}
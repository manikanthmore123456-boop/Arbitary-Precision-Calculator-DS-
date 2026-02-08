#include "header.h"

int insert_end(node **head, node **tail, int data)
{
    /* Allocate new node */
    node *new = malloc(sizeof(node));
    if (!new)
        return FAILURE;

    new->data = data;
    new->prev = *tail;
    new->next = NULL;

    /* Insert into empty list */
    if (*head == NULL)
        *head = *tail = new;
    else
    {
        (*tail)->next = new;
        *tail = new;
    }

    return SUCCESS;
}

int insert_first(node **head, node **tail, int data)
{
    /* Allocate new node */
    node *new = malloc(sizeof(node));
    if (!new)
        return FAILURE;

    new->data = data;
    new->prev = NULL;
    new->next = *head;

    /* Update existing head if present */
    if (*head)
        (*head)->prev = new;
    else
        *tail = new;

    *head = new;

    return SUCCESS;
}

void remove_leading_zeros(node **head, node **tail)
{
    /* Remove redundant leading zeros */
    while (*head && (*head)->data == 0 && (*head)->next)
    {
        node *temp = *head;
        *head = (*head)->next;
        (*head)->prev = NULL;
        free(temp);
    }

    /* Update tail for single-node list */
    if (*head && !(*head)->next)
        *tail = *head;
}

void print(node *head)
{
    /* Print digits sequentially */
    while (head)
    {
        printf("%d", head->data);
        head = head->next;
    }
    printf("\n");
}

void free_list(node **head)
{
    /* Free all nodes in the list */
    node *temp;
    while (*head)
    {
        temp = *head;
        *head = (*head)->next;
        free(temp);
    }
}

int is_zero(node *head)
{
    /* Check if list represents zero */
    return (head && head->data == 0 && head->next == NULL);
}

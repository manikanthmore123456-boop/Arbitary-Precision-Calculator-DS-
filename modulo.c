#include "header.h"

int modulo(node *head1, node *tail1,
           node *head2, node *tail2,
           node **res_head, node **res_tail)
{
    /* Division by zero check */
    if (!head2 || (head2->data == 0 && head2->next == NULL))
        return FAILURE;

    /* Process each digit of dividend */
    for (node *t = head1; t; t = t->next)
    {
        /* Bring down next digit */
        insert_end(res_head, res_tail, t->data);

        /* Subtract divisor until remainder < divisor */
        while (compare(*res_head, head2) >= 0)
        {
            node *new_head = NULL;
            node *new_tail = NULL;

            /* remainder = remainder - divisor */
            sub(*res_tail, tail2, &new_head, &new_tail);

            /* Update remainder */
            free_list(res_head);
            *res_head = new_head;
            *res_tail = new_tail;
        }
    }

    /* Normalize final remainder */
    remove_leading_zeros(res_head, res_tail);

    return SUCCESS;
}

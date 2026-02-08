#include "header.h"

int division(node *head1, node *tail1, node *head2, node *tail2, node **res_head, node **res_tail)
{
    /* Division by zero check */
    if (head2->data == 0 && head2->next == NULL)
        return FAILURE;

    node *rem_head = NULL;
    node *rem_tail = NULL;

    /* Traverse each digit of dividend */
    for (node *t = head1; t; t = t->next)
    {
        /* Bring down next digit to remainder */
        insert_end(&rem_head, &rem_tail, t->data);
        remove_leading_zeros(&rem_head, &rem_tail);

        int count = 0;

        /* Repeated subtraction to find quotient digit */
        while (compare(rem_head, head2) >= 0)
        {
            node *new_head = NULL;
            node *new_tail = NULL;

            /* remainder = remainder - divisor */
            sub(rem_tail, tail2, &new_head, &new_tail);

            /* Replace old remainder */
            free_list(&rem_head);
            rem_head = new_head;
            rem_tail = new_tail;

            count++;
        }

        /* Store quotient digit */
        insert_end(res_head, res_tail, count);
    }

    /* Remove leading zeros from quotient */
    remove_leading_zeros(res_head, res_tail);

    /* Cleanup remainder list */
    free_list(&rem_head);
    rem_head = rem_tail = NULL;

    return SUCCESS;
}

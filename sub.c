#include "header.h"

int sub(node *tail1, node *tail2, node **res_head, node **res_tail)
{
    int borrow = 0;

    /* Traverse from least significant digit */
    while (tail1)
    {
        int diff = tail1->data - borrow;

        /* Subtract digit from second number if available */
        if (tail2)
        {
            diff -= tail2->data;
            tail2 = tail2->prev;
        }

        /* Handle borrow */
        if (diff < 0)
        {
            diff += 10;
            borrow = 1;
        }
        else
        {
            borrow = 0;
        }

        /* Store current result digit */
        insert_first(res_head, res_tail, diff);
        tail1 = tail1->prev;
    }

    /* Remove any leading zeros from result */
    remove_leading_zeros(res_head, res_tail);

    return SUCCESS;
}

#include "header.h"

int add(node *tail1, node *tail2, node **res_head, node **res_tail)
{
    int carry = 0;

    /* Traverse both numbers from least significant digit */
    while (tail1 || tail2 || carry)
    {
        int sum = carry;

        /* Add digit from first number if available */
        if (tail1)
        {
            sum += tail1->data;
            tail1 = tail1->prev;
        }

        /* Add digit from second number if available */
        if (tail2)
        {
            sum += tail2->data;
            tail2 = tail2->prev;
        }

        /* Update carry and store result digit */
        carry = sum / 10;
        insert_first(res_head, res_tail, sum % 10);
    }

    return SUCCESS;
}

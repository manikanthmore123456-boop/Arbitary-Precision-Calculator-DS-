#include "header.h"

int mul(node *tail1, node *tail2, node **res_head, node **res_tail)
{
    int carry, prod, shift = 0;

    /* Process each digit of multiplier */
    while (tail2)
    {
        node *temp_head = NULL;
        node *temp_tail = NULL;

        carry = 0;
        node *t1 = tail1;

        /* Multiply current digit of multiplier with multiplicand */
        while (t1)
        {
            prod = (t1->data * tail2->data) + carry;
            carry = prod / 10;

            insert_first(&temp_head, &temp_tail, prod % 10);
            t1 = t1->prev;
        }

        /* Insert remaining carry */
        if (carry)
            insert_first(&temp_head, &temp_tail, carry);

        /* Append zeros based on digit position */
        for (int i = 0; i < shift; i++)
            insert_end(&temp_head, &temp_tail, 0);

        node *new_head = NULL;
        node *new_tail = NULL;

        /* Add partial product to result */
        add(*res_tail, temp_tail, &new_head, &new_tail);

        /* Free old lists */
        free_list(res_head);
        free_list(&temp_head);

        /* Update result */
        *res_head = new_head;
        *res_tail = new_tail;

        shift++;
        tail2 = tail2->prev;
    }

    /* Remove leading zeros from final result */
    remove_leading_zeros(res_head, res_tail);

    return SUCCESS;
}

#include "header.h"

int compare(node *head1, node *head2)
{
    int len1 = 0, len2 = 0;
    node *t1 = head1, *t2 = head2;

    /* Calculate length of first number */
    while (t1)
    {
        len1++;
        t1 = t1->next;
    }

    /* Calculate length of second number */
    while (t2)
    {
        len2++;
        t2 = t2->next;
    }

    /* Compare based on number of digits */
    if (len1 > len2)
        return 1;
    if (len1 < len2)
        return -1;

    /* If lengths are equal, compare digit by digit */
    while (head1 && head2)
    {
        if (head1->data > head2->data)
            return 1;
        if (head1->data < head2->data)
            return -1;

        head1 = head1->next;
        head2 = head2->next;
    }

    /* Numbers are equal */
    return 0;
}

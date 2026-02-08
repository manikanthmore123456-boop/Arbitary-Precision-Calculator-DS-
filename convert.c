#include "header.h"

int convert(const char *str, node **head, node **tail)
{
    /* Skip optional sign */
    if (*str == '+' || *str == '-')
        str++;

    /* Ignore leading zeros */
    while (*str == '0')
        str++;

    /* If number is zero */
    if (*str == '\0')
    {
        insert_end(head, tail, 0);
        return SUCCESS;
    }

    /* Convert each digit into a list node */
    while (*str)
    {
        insert_end(head, tail, *str - '0');
        str++;
    }

    return SUCCESS;
}

#include "header.h"

int is_num(const char *str)
{
    /* Check for NULL or empty string */
    if (!str || *str == '\0')
        return FAILURE;

    /* Skip optional sign */
    if (*str == '+' || *str == '-')
        str++;

    /* String cannot contain only a sign */
    if (*str == '\0')
        return FAILURE;

    /* Ensure all remaining characters are digits */
    while (*str)
    {
        if (!isdigit((unsigned char)*str))
            return FAILURE;
        str++;
    }

    return SUCCESS;
}

int validation(int argc, char *argv[])
{
    /* Validate argument count */
    if (argc != 4)
        return FAILURE;

    /* Validate numeric operands */
    if (!is_num(argv[1]) || !is_num(argv[3]))
        return FAILURE;

    /* Operator must be a single character */
    if (strlen(argv[2]) != 1)
        return FAILURE;

    /* Validate supported operators */
    if (argv[2][0] != '+' &&
        argv[2][0] != '-' &&
        argv[2][0] != 'x' &&
        argv[2][0] != '/' &&
        argv[2][0] != '%')
        return FAILURE;

    return SUCCESS;
}

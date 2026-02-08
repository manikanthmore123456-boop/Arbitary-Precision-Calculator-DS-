#include "header.h"

int main(int argc, char *argv[])
{
    node *head1 = NULL, *tail1 = NULL;
    node *head2 = NULL, *tail2 = NULL;
    node *res_head = NULL, *res_tail = NULL;

    /* Validate command-line arguments */
    if (validation(argc, argv) == FAILURE)
    {
        fprintf(stderr, "Error: Invalid arguments.\n\n");
        fprintf(stderr, "----------------------------------------------\n");
        fprintf(stderr, "Usage:\n");
        fprintf(stderr, "  %s <operand1> <operator> <operand2>\n\n", argv[0]);
        fprintf(stderr, "Operators supported:\n");
        fprintf(stderr, "  +   Addition\n");
        fprintf(stderr, "  -   Subtraction\n");
        fprintf(stderr, "  x   Multiplication\n");
        fprintf(stderr, "  /   Division\n");
        fprintf(stderr, "  %%   Modulo\n");
        fprintf(stderr, "----------------------------------------------\n");

        return EXIT_FAILURE;
    }


    /* Determine sign of first operand */
    int sign1 = 1;
    if (argv[1][0] == '-')
        sign1 = -1;

    /* Determine sign of second operand */
    int sign2 = 1;
    if (argv[3][0] == '-')
        sign2 = -1;

    /* Convert input strings to linked lists */
    if (convert(argv[1], &head1, &tail1) == FAILURE ||
        convert(argv[3], &head2, &tail2) == FAILURE)
    {
        printf("List Conversion Failed\n");
        return 0;
    }

    int result_sign;

    switch (argv[2][0])
    {
        case '+':
        case '-':
        {
            /* Convert subtraction to addition by flipping sign */
            if (argv[2][0] == '-')
                sign2 = -sign2;

            /* Same sign: perform addition */
            if (sign1 == sign2)
            {
                add(tail1, tail2, &res_head, &res_tail);
                result_sign = sign1;
            }
            else
            {
                /* Different signs: perform subtraction */
                int cmp = compare(head1, head2);

                if (cmp > 0)
                {
                    sub(tail1, tail2, &res_head, &res_tail);
                    result_sign = sign1;
                }
                else if (cmp < 0)
                {
                    sub(tail2, tail1, &res_head, &res_tail);
                    result_sign = sign2;
                }
                else
                {
                    /* Result is zero */
                    insert_end(&res_head, &res_tail, 0);
                    result_sign = 1;
                }
            }
            break;
        }

        case 'x':
        {
            /* Multiplication */
            mul(tail1, tail2, &res_head, &res_tail);
            result_sign = sign1 * sign2;
            break;
        }

        case '/':
        {
            /* Division */
            if (division(head1, tail1, head2, tail2,
                         &res_head, &res_tail) == FAILURE)
            {
                printf("Division by zero\n");
                return 0;
            }

            result_sign = sign1 * sign2;

            /* Zero result has no sign */
            if (is_zero(res_head))
                result_sign = 1;
            break;
        }

        case '%':
        {
            /* Modulo operation */
            if (modulo(head1, tail1, head2, tail2,
                       &res_head, &res_tail) == FAILURE)
            {
                printf("Modulus by zero\n");
                return 0;
            }

            result_sign = sign1 * sign2;

            /* Zero remainder has no sign */
            if (is_zero(res_head))
                result_sign = 1;
            break;
        }
    }

    /* Display input and result */
    printf("---------------------------------------\n");
    printf("Operand 1 : %s\n", argv[1]);
    printf("Operand 2 : %s\n", argv[3]);
    printf("Operator  : %c\n", argv[2][0]);
    printf("---------------------------------------\n");
    printf("Result    : ");

    if (result_sign == -1)
        printf("-");

    print(res_head);
    printf("---------------------------------------\n");

    /* Free allocated memory */
    free_list(&head1);
    free_list(&head2);
    free_list(&res_head);

    return 0;
}

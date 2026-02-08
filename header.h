#ifndef APC_HEADER
#define APC_HEADER

/* Standard Library Includes */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

/* Macro Definitions */
#define SUCCESS 1
#define FAILURE 0

/*
 * Doubly linked list node used to represent large integers.
 * Each node stores a single digit.
*/
typedef struct Node {
    int data;
    struct Node *prev;
    struct Node *next;
} node;


/* Validations */
int validation(int argc, char *argv[]);
int is_num(const char *str);
int compare(node *head1, node *head2);

/* Linked list helpers */
int insert_first(node **head, node **tail, int data);
int insert_end(node **head, node **tail, int data);
void remove_leading_zeros(node **res_head, node **res_tail);
void print(node *head);
void free_list(node **head);
int is_zero(node *head);

/* Conversion */
int convert(const char *str, node **head, node **tail);

/* Arithmetic */
int add(node *tail1, node *tail2, node **res_head, node **res_tail);
int sub(node *tail1, node *tail2, node **res_head, node **res_tail);
int mul(node *tail1, node *tail2, node **res_head, node **res_tail);
int division(node *head1, node *tail1, node *head2, node *tail2, node **res_head, node **res_tail);
int modulo(node *head1, node *tail1, node *head2, node *tail2, node **res_head, node **res_tail);

#endif

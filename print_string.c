#include "monty.h"

/**
 * f_pstr - Prints the string starting from the top of the stack.
 * @head: Pointer to the first node of the linked list.
 * @counter: Line counter.
 *
 * Return: None.
 */
void f_pstr(stack_t **head, unsigned int counter)
{
    stack_t *h;
    (void)counter;

    h = *head;
    while (h)
    {
        if (h->n > 127 || h->n <= 0)
        {
            break;
        }
        printf("%c", h->n);
        h = h->next;
    }
    printf("\n");
}

#include "monty.h"

/**
 * free_stack - Frees a doubly linked list.
 * @head: Pointer to the first node of the stack.
 * Return: None.
 */
void free_stack(stack_t *head)
{
    stack_t *temp;

    temp = head;
    while (head)
    {
        temp = head->next;
        free(head);
        head = temp;
    }
}

/**
 * f_stack - Sets the mode of operation to stack (LIFO).
 * @head: Unused parameter, pointer to the first node of the stack.
 * @counter: Unused parameter, line counter.
 *
 * Return: None.
 */
void f_stack(stack_t **head, unsigned int counter)
{
    (void)head;
    (void)counter;

    bus.lifi = 0;
}

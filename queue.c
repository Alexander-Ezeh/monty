#include "monty.h"

/**
 * f_queue - Sets the mode of operation to queue (FIFO).
 * @head: Unused parameter, pointer to the first node of the queue.
 * @counter: Unused parameter, line counter.
 *
 * Return: None.
 */
void f_queue(stack_t **head, unsigned int counter)
{
    (void)head;
    (void)counter;

    bus.lifi = 1;
}

/**
 * addqueue - Adds a node to the tail of the queue.
 * @n: Value of the new node.
 * @head: Pointer to the head of the queue.
 *
 * Return: None.
 */
void addqueue(stack_t **head, int n)
{
    stack_t *new_node, *temp;

    temp = *head;
    new_node = malloc(sizeof(stack_t));

    if (new_node == NULL)
        printf("Error\n");

    new_node->n = n;
    new_node->next = NULL;

    if (temp)
    {
        while (temp->next)
            temp = temp->next;
    }
    if (!temp)
    {
        *head = new_node;
        new_node->prev = NULL;
    }
    else
    {
        temp->next = new_node;
        new_node->prev = temp;
    }
}

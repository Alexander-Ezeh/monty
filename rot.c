#include "monty.h"

/**
 * f_rotl - Rotates the stack, moving the top element to the bottom.
 * @head: Pointer to the first node of the stack.
 * @counter: Line counter.
 *
 * Return: None.
 */
void f_rotl(stack_t **head, __attribute__((unused)) unsigned int counter)
{
    stack_t *tmp = *head, *aux;

    if (*head == NULL || (*head)->next == NULL)
    {
        return;
    }
    aux = (*head)->next;
    aux->prev = NULL;
    while (tmp->next != NULL)
    {
        tmp = tmp->next;
    }
    tmp->next = *head;
    (*head)->next = NULL;
    (*head)->prev = tmp;
    (*head) = aux;
}

/**
 * f_rotr - Rotates the stack, moving the bottom element to the top.
 * @head: Pointer to the first node of the stack.
 * @counter: Line counter.
 *
 * Return: None.
 */
void f_rotr(stack_t **head, __attribute__((unused)) unsigned int counter)
{
    stack_t *copy;

    copy = *head;
    if (*head == NULL || (*head)->next == NULL)
    {
        return;
    }
    while (copy->next)
    {
        copy = copy->next;
    }
    copy->next = *head;
    copy->prev->next = NULL;
    copy->prev = NULL;
    (*head)->prev = copy;
    (*head) = copy;
}

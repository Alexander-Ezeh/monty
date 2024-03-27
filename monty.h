#ifndef MONTY_H
#define MONTY_H

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <ctype.h>

/**
 * struct stack_s - representation of a stack (or queue) using doubly linked list
 * @n: integer value stored in the node
 * @prev: points to the previous node in the stack (or queue)
 * @next: points to the next node in the stack (or queue)
 *
 * Description: structure for a doubly linked list node used in stack and queue
 */
typedef struct stack_s
{
    int n;
    struct stack_s *prev;
    struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the operation code
 * @f: function pointer to handle the opcode
 *
 * Description: structure representing an operation code and its corresponding function
 */
typedef struct instruction_s
{
    char *opcode;
    void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/**
 * struct bus_s - variables used across the program
 * @arg: value associated with an instruction
 * @file: pointer to the Monty file being processed
 * @content: line content read from the Monty file
 * @lifi: flag to switch between stack and queue mode
 *
 * Description: structure to carry values and state information throughout the program
 */
typedef struct bus_s
{
    char *arg;
    FILE *file;
    char *content;
    int lifi;
} bus_t;

extern bus_t bus;

ssize_t getline(char **lineptr, size_t *n, FILE *stream);

char *_realloc(char *ptr, unsigned int old_size, unsigned int new_size);
ssize_t getstdin(char **lineptr, int file);

char *clean_line(char *content);
void free_stack(stack_t *head);

int execute(char *content, stack_t **head, unsigned int counter, FILE *file);

void f_push(stack_t **head, unsigned int number);
void f_pall(stack_t **head, unsigned int number);
void f_pint(stack_t **head, unsigned int number);
void f_pop(stack_t **head, unsigned int counter);
void f_swap(stack_t **head, unsigned int counter);
void f_nop(stack_t **head, unsigned int counter);

void f_add(stack_t **head, unsigned int counter);
void f_sub(stack_t **head, unsigned int counter);
void f_div(stack_t **head, unsigned int counter);
void f_mul(stack_t **head, unsigned int counter);
void f_mod(stack_t **head, unsigned int counter);

void f_pchar(stack_t **head, unsigned int counter);
void f_pstr(stack_t **head, unsigned int counter);

void f_rotl(stack_t **head, unsigned int counter);
void f_rotr(stack_t **head, __attribute__((unused)) unsigned int counter);

void addnode(stack_t **head, int n);
void addqueue(stack_t **head, int n);
void f_queue(stack_t **head, unsigned int counter);
void f_stack(stack_t **head, unsigned int counter);

#endif

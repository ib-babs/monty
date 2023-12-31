#ifndef MONTY_H
#define MONTY_H
#define _GNU_SOURCE
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <ctype.h>
#include <string.h>
#include <fcntl.h>
/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;
/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

typedef struct global_use
{
	stack_t *head;
	int lifo;
	char *args;
	char *buffer;
	unsigned count;
	FILE *fd;
	ssize_t off;
} globals_t;

extern globals_t extern_glb;
void check_errors(stack_t **doubly, unsigned int, char *);
void push(stack_t **stack, unsigned int line_number);
void pall(stack_t **stack, unsigned int line_number);
void (*get_opcode(char *str))(stack_t **stack, unsigned int number_line);
void execute(int ac, char *args[]);
void start_extern(FILE *fd);
stack_t *add_dnodeint_end(stack_t **head, const int n);
stack_t *add_dnodeint(stack_t **head, const int n);
void pint(stack_t **doubly, unsigned line_number);
void pop(stack_t **doubly, unsigned line_number);
void swap(stack_t **doubly, unsigned int line_number);
void add(stack_t **doubly, unsigned int line_number);
void nop(stack_t **doubly, unsigned int line_number);
void sub(stack_t **doubly, unsigned int line_number);
void _div(stack_t **doubly, unsigned int line_number);
void mul(stack_t **doubly, unsigned int line_number);
void mod(stack_t **doubly, unsigned int line_number);
void pchar(stack_t **doubly, unsigned int line_number);
void pstr(stack_t **doubly, unsigned int line_number);
void rotl(stack_t **doubly, unsigned int line_number);
void rotr(stack_t **doubly, unsigned int line_number);
void queue(stack_t **doubly, unsigned int line_number);
void stack(stack_t **doubly, unsigned int line_number);
int list_len(stack_t *doubly);
void free_dlistint(stack_t *h);
void free_extern(void);
FILE *check_file(int ac, char *args[]);
#endif /* MONTY_H */
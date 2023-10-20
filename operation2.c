#include "monty.h"
/**
 * add - Add first two nodes
 * @doubly: Double linked list
 * @line_number: Line number, if error
 * Return: Void
 */
void add(stack_t **doubly, unsigned int line_number)
{
	int len = list_len(*doubly);
	stack_t *aux;

	if (len < 2)
	{
		fprintf(stderr, "L%u: ", line_number);
		fprintf(stderr, "can't add, stack too short\n");
		exit(EXIT_FAILURE);
	}
	aux = (*doubly)->next;
	aux->n += (*doubly)->n;

	pop(doubly, line_number);
}
/**
 * mod - Modulo or remainder of first two node
 * @doubly: Double linked list
 * @line_number: Line number, if error
 * Return: Void
 */
void mod(stack_t **doubly, unsigned int line_number)
{

	int len = list_len(*doubly);
	stack_t *aux;

	if (len < 2)
	{
		fprintf(stderr, "L%u: ", line_number);
		fprintf(stderr, "can't mod, stack too short\n");
		exit(EXIT_FAILURE);
	}
	if ((*doubly)->n == 0)
	{
		fprintf(stderr, "L%u: ", line_number);
		fprintf(stderr, "division by zero\n");
		exit(EXIT_FAILURE);
	}
	aux = (*doubly)->next;
	aux->n %= (*doubly)->n;

	pop(doubly, line_number);
}
/**
 * sub - Subtract first two nodes
 * @doubly: Double linked list
 * @line_number: Line number, if error
 * Return: Void
 */
void sub(stack_t **doubly, unsigned int line_number)
{
	int len = list_len(*doubly);
	stack_t *aux;

	if (len < 2)
	{
		fprintf(stderr, "L%u: ", line_number);
		fprintf(stderr, "can't sub, stack too short\n");
		free_extern();
		exit(EXIT_FAILURE);
	}
	aux = (*doubly)->next;
	aux->n -= (*doubly)->n;

	pop(doubly, line_number);
}
/**
 * _div - Divide first two nodes
 * @doubly: Double linked list
 * @line_number: Line number, if error
 * Return: Void
 */
void _div(stack_t **doubly, unsigned int line_number)
{
	int len = list_len(*doubly);
	stack_t *aux;

	if (len < 2)
	{
		fprintf(stderr, "L%u: ", line_number);
		fprintf(stderr, "can't div, stack too short\n");
		free_extern();
		exit(EXIT_FAILURE);
	}
	if ((*doubly)->n == 0)
	{
		fprintf(stderr, "L%u: ", line_number);
		fprintf(stderr, "division by zero\n");
		free_extern();
		exit(EXIT_FAILURE);
	}
	aux = (*doubly)->next;
	aux->n /= (*doubly)->n;

	pop(doubly, line_number);
}
/**
 * mul - Multiply first two nodes
 * @doubly: Double linked list
 * @line_number: Line number, if error
 * Return: Void
 */
void mul(stack_t **doubly, unsigned int line_number)
{
	int len = list_len(*doubly);
	stack_t *aux;

	if (len < 2)
	{
		fprintf(stderr, "L%u: ", line_number);
		fprintf(stderr, "can't mul, stack too short\n");
		free_extern();
		exit(EXIT_FAILURE);
	}

	aux = (*doubly)->next;
	aux->n *= (*doubly)->n;

	pop(doubly, line_number);
}

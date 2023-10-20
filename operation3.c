#include "monty.h"
/**
 * nop - Do nothing
 * @doubly: Double linked list
 * @line_number: Line number, if error
 * Return: Void
 */
void nop(stack_t **doubly, unsigned int line_number)
{
	(void)doubly;
	(void)line_number;
}
/**
 * pchar - Print char
 * @doubly: Double linked list
 * @line_number: Line number, if error
 * Return: Void
 */
void pchar(stack_t **doubly, unsigned int line_number)
{
	stack_t *aux = *doubly;

	if (aux->n < 0 || aux->n > 127)
	{
		dprintf(2, "L%u: ", line_number);
		dprintf(2, "can't pchar, value out of range\n");
		free_extern();
		exit(EXIT_FAILURE);
	}
	putchar(aux->n);
	putchar(10);
}
/**
 * pstr - Print string
 * @doubly: Double linked list
 * @line_number: Line number, if error
 * Return: Void
 */
void pstr(stack_t **doubly, unsigned int line_number)
{
	stack_t *aux;
	(void)line_number;

	for (aux = *doubly; aux != NULL; (aux = aux->next))
	{
		if (aux->n == 0 || (aux->n < 0 || aux->n > 127))
			break;
		putchar(aux->n);
	}
	putchar(10);
}
/**
 * rotl - Rotate top node to the bottom
 * @doubly: Double linked list
 * @line_number: Line number, if error
 * Return: Void
 */
void rotl(stack_t **doubly, unsigned int line_number)
{
	stack_t *aux1 = NULL, *aux2 = NULL;
	(void)line_number;

	if (*doubly == NULL)
		return;
	if ((*doubly)->next == NULL)
		return;
	aux1 = (*doubly)->next;
	aux2 = *doubly;

	for (; aux2->next != NULL; (aux2 = aux2->next))
		;
	aux1->prev = NULL;
	aux2->next = *doubly;
	(*doubly)->next = NULL;
	(*doubly)->prev = aux2;
	*doubly = aux1;
}
/**
 * rotr - Rotate bottom node to the top
 * @doubly: Double linked list
 * @line_number: Line number, if error
 * Return: Void
 */
void rotr(stack_t **doubly, unsigned int line_number)
{
	stack_t *aux = NULL;
	(void)line_number;

	if (*doubly == NULL)
		return;
	if ((*doubly)->next == NULL)
		return;
	aux = *doubly;

	for (; aux->next != NULL; (aux = aux->next))
		;
	aux->prev->next = NULL;
	aux->next = *doubly;
	aux->prev = NULL;
	(*doubly)->prev = aux;
	*doubly = aux;
}

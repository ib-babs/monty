#include "monty.h"

/**
 * push - Push data into the stack
 * @doubly: Double linked list
 * @line_number: Line number, if error
 * Return: Void
 */
void push(stack_t **doubly, unsigned int line_number)
{
	int j;
	(void)line_number;
	(void)doubly;

	if (!extern_glb.args)
	{
		dprintf(2, "L%u: ", line_number);
		dprintf(2, "usage: push integer\n");
		exit(EXIT_FAILURE);
	}
	for (j = 0; extern_glb.args[j] != '\0'; j++)
	{
		if (!isdigit(extern_glb.args[j]) && extern_glb.args[j] != '-')
		{
			dprintf(2, "L%u: ", line_number);
			dprintf(2, "usage: push integer\n");
			free_extern();
			exit(EXIT_FAILURE);
		}
	}
	if (extern_glb.lifo == 1)
		add_dnodeint(doubly, atoi(extern_glb.args));
	else
		add_dnodeint_end(doubly, atoi(extern_glb.args));
}

/**
 * pall - Print all element in the list
 * @doubly: Double linked list
 * @line_number: Line number, if error
 * Return: Void
 */
void pall(stack_t **doubly, unsigned int line_number)
{
	stack_t *aux;
	(void)line_number;

	aux = *doubly;
	while (aux)
	{
		printf("%d\n", (aux)->n);
		aux = (aux)->next;
	}
}

/**
 * pint - Print integer element in the list from the top
 * @doubly: Double linked list
 * @line_number: Line number, if error
 * Return: Void
 */
void pint(stack_t **doubly, unsigned int line_number)
{
	check_errors(doubly, line_number, "can't pint, stack empty\n");
	printf("%d\n", (*doubly)->n);
}

/**
 * pop - Remove node from in the list from the top
 * @doubly: Double linked list
 * @line_number: Line number, if error
 * Return: Void
 */
void pop(stack_t **doubly, unsigned int line_number)
{
	stack_t *aux;

	check_errors(doubly, line_number, "can't pop an empty stack\n");
	aux = (*doubly)->next;
	*doubly = aux;
}
/**
 * swap - Swap first two nodes
 * @doubly: Double linked list
 * @line_number: Line number, if error
 * Return: Void
 */
void swap(stack_t **doubly, unsigned int line_number)
{
	int len = list_len(*doubly);
	stack_t *top1, *top2;

	if (len < 2)
	{
		dprintf(2, "L%u: ", line_number);
		dprintf(2, "can't swap, stack too short\n");
		free_extern();
		exit(EXIT_FAILURE);
	}
	top1 = *doubly;
	top2 = (*doubly)->next;

	if (len == 2)
	{
		top1->next = NULL;
		top1->prev = top2;
	}
	else
	{
		top1->next = top2->next;
		top2->next->prev = top1;
	}

	top2->prev = NULL;
	top2->next = top1;
	top1->prev = top2;
	*doubly = top2;
}

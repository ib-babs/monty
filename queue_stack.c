#include "monty.h"
/**
 * queue - Implement FIFO Operation
 * FIFO - First-In-First-Out
 * @doubly: Double linked list
 * @line_number: Line number, if error
 * Return: Void
 */
void queue(stack_t **doubly, unsigned int line_number)
{
	(void)doubly;
	(void)line_number;
	extern_glb.lifo = 0;
}
/**
 * stack - Implement LIFO Operation
 * LIFO - Last-In-First-Out
 * @doubly: Double linked list
 * @line_number: Line number, if error
 * Return: Void
 */
void stack(stack_t **doubly, unsigned int line_number)
{
	(void)doubly;
	(void)line_number;
	extern_glb.lifo = 1;
}

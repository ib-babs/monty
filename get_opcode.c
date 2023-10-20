#include "monty.h"
/**
 * list_len - Take the length of the lisr
 * @doubly: Double linked list
 * Return: Length of the list
 */
int list_len(stack_t *doubly)
{
	int len = 0;

	if (!doubly)
		return (0);
	while (doubly)
	{
		len++;
		doubly = doubly->next;
	}
	return (len);
}
/**
 * check_errors - Check for linked list null
 * @doubly: Double linked list
 * @line_number: Line number, if error
 * @msg: Error meesage
 * Return: Void
 */
void check_errors(stack_t **doubly, unsigned int line_number, char *msg)
{
	if (!*doubly)
	{
		fprintf(stderr, "L%u: ", line_number);
		fprintf(stderr, "%s", msg);
		free_extern();
		exit(EXIT_FAILURE);
	}
}
/**
 * get_opcode - Get the opcode of the function
 * @str: String opcode
 * Return: Void
 */
void (*get_opcode(char *str))(stack_t **stack, unsigned int number_line)
{
	int i;

	instruction_t instructions[] = {
		{"push", push},
		{"pall", pall},
		{"pint", pint},
		{"pop", pop},
		{"swap", swap},
		{"add", add},
		{"nop", nop},
		{"sub", sub},
		{"div", _div},
		{"mul", mul},
		{"mod", mod},
		{"pchar", pchar},
		{"pstr", pstr},
		{"rotl", rotl},
		{"rotr", rotr},
		{"queue", queue},
		{"stack", stack},
		{NULL, NULL}};
	for (i = 0; instructions[i].opcode; i++)
	{
		if (strcmp(str, instructions[i].opcode) == 0)
			break;
	}
	return (instructions[i].f);
}

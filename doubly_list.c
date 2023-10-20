#include "monty.h"
/**
 * add_dnodeint_end - Add element in the double list at end
 * @head: head of the dblist
 * @n: Data to be added
 * Return: Added element to the list
 */
stack_t *add_dnodeint_end(stack_t **head, const int n)
{
	stack_t *new_node = malloc(sizeof(stack_t)), *tmp_node = NULL;

	if (new_node == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		free_extern();
		exit(EXIT_FAILURE);
	}
	new_node->n = n;

	if (*head == NULL)
		*head = new_node;
	else
	{
		tmp_node = *head;
		while (tmp_node->next)
			tmp_node = tmp_node->next;
		tmp_node->next = new_node;
		new_node->prev = tmp_node;
	}
	return (new_node);
}

/**
 * add_dnodeint - Add node to the list
 * @head: Head of the node
 * @n: Integer to add
 * Return: New added node
 */
stack_t *add_dnodeint(stack_t **head, const int n)
{
	stack_t *newP = malloc(sizeof(stack_t));

	if (newP == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		free_extern();
		exit(EXIT_FAILURE);
	}

	newP->n = n;
	newP->prev = NULL;

	if (*head == NULL)
	{
		newP->next = NULL;
		*head = newP;
	}
	else
	{
		newP->next = *head;
		if (*head)
			(*head)->prev = newP;
		*head = newP;
	}

	return (newP);
}
/**
 * free_dlistint - Free the list
 * @head: Head of the node
 * Return: Void
 */
void free_dlistint(stack_t *head)
{
	stack_t *ptr = head;

	while (head != NULL)
	{
		head = head->next;
		free(ptr);
		ptr = head;
	}
}

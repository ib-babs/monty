#include "monty.h"
globals_t extern_glb;
/**
 * free_extern - Free global variables
 * Return: Void
*/
void free_extern(void)
{
	free_dlistint(extern_glb.head);
	free(extern_glb.buffer);
	fclose(extern_glb.fd);
}
/**
 * main - Main entry
 * @ac: Args count
 * @argv: Args vector
 * Return: Always 0 (success)
*/
int main(int ac, char **argv)
{
	execute(ac, argv);
	return (0);
}

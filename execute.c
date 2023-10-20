#include "monty.h"
/**
 * start_extern - Initiate external linked file
 * @fd: File Descriptor
 * Return: Void
 */
void start_extern(FILE *fd)
{
	extern_glb.args = NULL;
	extern_glb.lifo = 1;
	extern_glb.head = NULL;
	extern_glb.fd = fd;
	extern_glb.buffer = NULL;
	extern_glb.count = 1;
	extern_glb.off = -1;
}
/**
 * check_file - Check file existence
 * @ac: Arg count
 * @args: Args vector
 * Return: Pointer to file descriptor
 */
FILE *check_file(int ac, char *args[])
{
	FILE *fd;

	if (ac == 1 || ac > 2)
	{
		dprintf(2, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	fd = fopen(args[1], "r");

	if (!fd)
	{
		dprintf(2, "Error: Can't open file %s\n", args[1]);
		exit(EXIT_FAILURE);
	}
	return (fd);
}
/**
 * execute - Execute the program
 * @ac: Argument count
 * @args: Argument Vectors
 * Return: Void
 */
void execute(int ac, char *args[])
{
	ssize_t nlines = 0;
	FILE *fd;
	size_t size = 102;
	char *lines[2] = {NULL, NULL}, *delim = " \t\n";

	void((*f))(stack_t **, unsigned int);
	fd = check_file(ac, args);
	start_extern(fd);
	nlines = getline(&extern_glb.buffer, &size, fd);
	while (nlines != extern_glb.off)
	{
		lines[0] = strtok(extern_glb.buffer, delim);
		if (lines[0] && lines[0][0] != '#')
		{
			f = get_opcode(lines[0]);
			if (!f)
			{
				dprintf(2, "L%u: ", extern_glb.count);
				dprintf(2, "unknown instruction %s\n", lines[0]);
				free_extern();
				exit(EXIT_FAILURE);
			}
			extern_glb.args = strtok(NULL, delim);
			f(&extern_glb.head, extern_glb.count);
		}
		nlines = getline(&extern_glb.buffer, &size, fd);
		extern_glb.count++;
	}
}

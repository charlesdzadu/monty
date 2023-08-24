#include "monty.h"

/**
 * check_given_file - check if the given file is valid
 * @argc: number of arguments
 * @argv: array of arguments
 * Return: pointer to the file
*/

FILE *check_given_file(int argc, char *argv[])
{
	FILE *f;

	if (argc != 2)
	{
		dprintf(2, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	f = fopen(argv[1], "r");
	if (!f)
	{
		dprintf(2, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	return (f);
}

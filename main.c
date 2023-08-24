#include "monty.h"

void nothing(void);
global_t global_var;

/**
 * initialize_global_var - initialize global variables
 * @f: file descriptor
 * Return: void
*/
void initialize_global_var(FILE *f)
{
	global_var.lifo = 1;
	global_var.cont = 1;
	global_var.arg = NULL;
	global_var.head = NULL;
	global_var.fd = f;
	global_var.buffer = NULL;
}


void free_global_var(void)
{
	free_double_linked_list(global_var.head);
	free(global_var.buffer);
	fclose(global_var.fd);
}

/**
 * main - entry point
 * @argc: number of arguments
 * @argv: array of arguments
 * Return: 0 on success
 */

int main(int argc, char *argv[])
{
	FILE *monty_file;
	ssize_t read = 0, len = 256;
	char *lns[2] = {NULL, NULL};
	void (*func)(stack_t **stack, unsigned int line_number);

	monty_file = check_given_file(argc, argv);
	initialize_global_var(monty_file);
	read = getline(&global_var.buffer, &len, monty_file);
	while (read != -1)
	{
		lns[0] = strtok(global_var.buffer, " \n\t");
		if (lns[0] != NULL && lns[0][0] != '#')
		{
			func = get_correct_opcodes(lns[0]);
			if (!func)
			{
				fprintf(stderr, "L%u: ", global_var.cont);
				fprintf(stderr, "unknown instruction %s\n", lns[0]);
				free_global_var();
				exit(EXIT_FAILURE);
			}
			global_var.arg = strtok(NULL, " \n\t");
			func(&global_var.head, global_var.cont);
		}
		read = getline(&global_var.buffer, &len, monty_file);
		global_var.cont++;
	}
	free_global_var();
	return (0);
}

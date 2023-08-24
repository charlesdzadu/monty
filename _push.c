#include "monty.h"

/**
 * _push - push an element to the stack
 * @stack: head of the stack
 * @line_number: current line number
 *
*/
void _push(stack_t **stack, unsigned int line_number)
{
	int i, number;

	if (!global_var.arg)
	{
		fprintf(stderr, "L%u: usage: push integer\n", line_number);
		free_global_var();
		exit(EXIT_FAILURE);
	}

	for (i = 0; global_var.arg[i]; i++)
	{
		if (!isdigit(global_var.arg[i]) && global_var.arg[i] != '-')
		{
			fprintf(stderr, "L%u: ", line_number);
			fprintf(stderr, "usage: push integer\n");
			free_global_var();
			exit(EXIT_FAILURE);
		}
		number = atoi(global_var.arg);
		if (global_var.lifo == 1)
			add_node_begin(stack, number);
		else
			add_node_end(stack, number);
	}
}

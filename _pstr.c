#include "monty.h"

/**
 * _pstr - prints the string starting at the top of the stack
 * @stack: double pointer to the head of the stack
 * @line_number: line number of the opcode
 * Return: void
*/
void _pstr(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp = NULL;
	(void)line_number;

	tmp = *stack;
	while (tmp != NULL && tmp->n != 0 && tmp->n >= 0 && tmp->n <= 127)
	{
		printf("%c", tmp->n);
		tmp = tmp->next;
	}
	printf("\n");
}

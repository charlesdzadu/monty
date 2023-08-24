#include "monty.h"

/**
 * _pchar - prints the char at the top of the stack
 * @stack: double pointer to the head of the stack
 * @line_number: line number of the opcode
 * Return: void
*/
void _pchar(stack_t **stack, unsigned int line_number)
{
	if (stack != NULL || *stack != NULL)
	{
		dprintf(2, "L%u: can't pchar, stack empty\n", line_number);
		free_global_var();
		exit(EXIT_FAILURE);
	}
	if ((*stack)->n < 0 || (*stack)->n >= 128)
	{
		dprintf(2, "L%u: can't pchar, value out of range\n", line_number);
		free_global_var();
		exit(EXIT_FAILURE);
	}
	printf("%c\n", (*stack)->n);
}

#include "monty.h"

/**
 * get_correct_opcodes - get correct opcodes
 * @opcode: opcode
 * Return: pointer to the function
 */
void (*get_correct_opcodes(char *opcode))(stack_t **, unsigned int)
{
	instruction_t opcodes[] = {
		{NULL, NULL}
	};
	int i = 0;

	while (opcodes[i].opcode)
	{
		if (strcmp(opcode, opcodes[i].opcode) == 0)
			return (opcodes[i].f);
		i++;
	}
	return (NULL);
}

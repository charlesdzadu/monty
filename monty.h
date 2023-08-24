#ifndef MONTY_H
#define MONTY_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <ctype.h>
#include <string.h>

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;


/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;


/**
 * struct globals - Structure of global variables
 * @lifo: stack or queue
 * @cont: current line
 * @arg: second parameter of opcode
 * @head: head of the stack
 * @fd: file descriptor of the file
 * @buffer: input text
 *
 * Description: doubly linked list node structure
 */
typedef struct globals
{
	int lifo;
	unsigned int cont;
	char  *arg;
	stack_t *head;
	FILE *fd;
	char *buffer;
} global_t;

extern global_t global_var;


FILE *check_given_file(int argc, char *argv[]);
void (*get_correct_opcodes(char *opcode))(stack_t **, unsigned int);
void free_double_linked_list(stack_t *head);
void nothing(void);
void _push(stack_t **stack, unsigned int line_number);
stack_t *add_node_end(stack_t **head, const int n);
stack_t *add_node_begin(stack_t **head, const int n);
void _pall(stack_t **stack, unsigned int line_number);

#endif /* MONTY_H */

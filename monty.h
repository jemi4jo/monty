#ifndef MONTY_H
#define MONTY_H
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <ctype.h>

/**
 * struct node_s - doubly linked list representation of a stack (or queue)
 * @value: integer
 * @prev_node: points to the previous element of the stack (or queue)
 * @next_node: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct node_s
{
	int value;
	struct node_s *prev_node;
	struct node_s *next_node;
} node_t;

/**
 * struct data_s - variables -args, file, line content
 * @argument: value
 * @monty_file: pointer to monty file
 * @line_content: line content
 * @lifo_flag: flag change stack <-> queue
 * Description: carries values through the program
 */
typedef struct data_s
{
	char *argument;
	FILE *monty_file;
	char *line_content;
	int lifo_flag;
}  data_t;

extern data_t data;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @handler: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct instruction_s
{
	char *opcode;
	void (*handler)(node_t **stack, unsigned int line_number);
} instruction_t;

char *_resize(char *ptr, unsigned int old_size, unsigned int new_size);
ssize_t readstdin(char **lineptr, int file);
char  *sanitize_line(char *line_content);
void push(node_t **stack, unsigned int value);
void print_all(node_t **stack, unsigned int line_number);
void print_integer(node_t **stack, unsigned int line_number);
int process_instruction(char *line_content, node_t **stack, unsigned int line_number, FILE *file);
void release_stack(node_t *stack);
void pop_node(node_t **stack, unsigned int line_number);
void swap_nodes(node_t **stack, unsigned int line_number);
void custom_add_function(node_t **stack, unsigned int line_number);
void no_operation(node_t **stack, unsigned int line_number);
void subtract_nodes(node_t **stack, unsigned int line_number);
void custom_divide_function(node_t **stack, unsigned int line_number);
void multiply_nodes(node_t **stack, unsigned int line_number);
void modulo_nodes(node_t **stack, unsigned int line_number);
void print_char(node_t **stack, unsigned int line_number);
void print_string(node_t **stack, unsigned int line_number);
void rotate_left(node_t **stack, unsigned int line_number);
void rotate_right(node_t **stack, __attribute__((unused)) unsigned int line_number);
void insert_node(node_t **stack, int value);
void enqueue_node(node_t **stack, int value);
void switch_to_queue(node_t **stack, unsigned int line_number);
void switch_to_stack(node_t **stack, unsigned int line_number);

#endif

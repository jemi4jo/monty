#include "monty.h"

/**
 * set_stack_mode - sets the mode to stack (LIFO)
 * @stack_head: stack head
 * @line_counter: line_number
 * Return: no return
*/
void set_stack_mode(node_t **stack_head, unsigned int line_counter)
{
	(void)stack_head;
	(void)line_counter;
	data.lifo_flag = 0;
}

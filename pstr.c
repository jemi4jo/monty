#include "monty.h"

/**
 * custom_print_string_function - prints the string starting at the top of the stack,
 * followed by a new
 * @stack_head: stack head
 * @line_counter: line_number
 * Return: no return
*/
void custom_print_string_function(node_t **stack_head, unsigned int line_counter)
{
	node_t *current_node;
	(void)line_counter;

	current_node = *stack_head;
	while (current_node)
	{
		if (current_node->value > 127 || current_node->value <= 0)
		{
			break;
		}
		printf("%c", current_node->value);
		current_node = current_node->next_node;
	}
	printf("\n");
}

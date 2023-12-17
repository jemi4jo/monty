#include "monty.h"

/**
 * custom_print_char_function - prints the char at the top of the stack,
 * followed by a new line
 * @stack_head: stack head
 * @line_counter: line_number
 * Return: no return
*/
void custom_print_char_function(node_t **stack_head, unsigned int line_counter)
{
	node_t *current_node;

	current_node = *stack_head;
	if (!current_node)
	{
		fprintf(stderr, "L%d: can't pchar, stack empty\n", line_counter);
		fclose(data.monty_file);
		free(data.line_content);
		release_stack(*stack_head);
		exit(EXIT_FAILURE);
	}

	if (current_node->value > 127 || current_node->value < 0)
	{
		fprintf(stderr, "L%d: can't pchar, value out of range\n", line_counter);
		fclose(data.monty_file);
		free(data.line_content);
		release_stack(*stack_head);
		exit(EXIT_FAILURE);
	}

	printf("%c\n", current_node->value);
}

#include "monty.h"

/**
 * custom_pop_function - prints the top
 * @stack_head: stack head
 * @line_counter: line_number
 * Return: no return
*/
void custom_pop_function(node_t **stack_head, unsigned int line_counter)
{
	node_t *current_node;

	if (*stack_head == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", line_counter);
		fclose(data.monty_file);
		free(data.line_content);
		release_stack(*stack_head);
		exit(EXIT_FAILURE);
	}

	current_node = *stack_head;
	*stack_head = current_node->next;
	free(current_node);
}

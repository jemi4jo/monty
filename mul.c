#include "monty.h"

/**
 * custom_multiply_function - multiplies the top two elements of the stack.
 * @stack_head: stack head
 * @line_counter: line_number
 * Return: no return
*/
void custom_multiply_function(node_t **stack_head, unsigned int line_counter)
{
	node_t *current_node;
	int stack_length = 0, result;

	current_node = *stack_head;
	while (current_node)
	{
		current_node = current_node->next_node;
		stack_length++;
	}

	if (stack_length < 2)
	{
		fprintf(stderr, "L%d: can't mul, stack too short\n", line_counter);
		fclose(data.monty_file);
		free(data.line_content);
		release_stack(*stack_head);
		exit(EXIT_FAILURE);
	}

	current_node = *stack_head;
	result = current_node->next_node->value * current_node->value;
	current_node->next_node->value = result;
	*stack_head = current_node->next_node;
	free(current_node);
}

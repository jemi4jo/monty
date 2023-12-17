#include "monty.h"

/**
 * custom_print_integer_function - prints the top
 * @stack_head: stack head
 * @line_counter: line_number
 * Return: no return
*/
void custom_print_integer_function(node_t **stack_head, unsigned int line_counter)
{
	if (*stack_head == NULL)
	{
		fprintf(stderr, "L%u: can't pint, stack empty\n", line_counter);
		fclose(data.monty_file);
		free(data.line_content);
		release_stack(*stack_head);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*stack_head)->n);
}

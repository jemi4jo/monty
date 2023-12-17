#include "monty.h"

/**
 * custom_push_function - add node to the stack
 * @stack_head: stack head
 * @line_counter: line_number
 * Return: no return
*/
void custom_push_function(node_t **stack_head, unsigned int line_counter)
{
	int value, index = 0, flag = 0;

	if (data.argument)
	{
		if (data.argument[0] == '-')
			index++;
		for (; data.argument[index] != '\0'; index++)
		{
			if (data.argument[index] > '9' || data.argument[index] < '0')
				flag = 1;
		}
		if (flag == 1)
		{
			fprintf(stderr, "L%d: usage: push integer\n", line_counter);
			fclose(data.monty_file);
			free(data.line_content);
			release_stack(*stack_head);
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_counter);
		fclose(data.monty_file);
		free(data.line_content);
		release_stack(*stack_head);
		exit(EXIT_FAILURE);
	}

	value = atoi(data.argument);
	if (data.lifo_flag == 0)
		insert_node(stack_head, value);
	else
		enqueue_node(stack_head, value);
}

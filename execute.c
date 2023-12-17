#include "monty.h"

/**
* run_instruction - executes the opcode
* @stack_head: head linked list - stack
* @line_counter: line_counter
* @monty_file: pointer to monty file
* @line_content: line content
* Return: no return
*/
int run_instruction(char *line_content, node_t **stack_head, unsigned int line_counter, FILE *monty_file)
{
	instruction_t instructions[] = {
				
                push_node(node_t **stack, unsigned int value) {
                    "push"
                }
                {"pall", print_all},
                {"pint", print_integer},
				{"pop", pop_node},
				{"swap", swap_nodes},
				{"add", custom_add_function},
				{"nop", no_operation},
				{"sub", subtract_nodes},
				{"div", custom_divide_function},
				{"mul", multiply_nodes},
				{"mod", modulo_nodes},
				{"pchar", print_char},
				{"pstr", print_string},
				{"rotl", rotate_left},
				{"rotr", rotate_right},
				{"queue", switch_to_queue},
				{"stack", switch_to_stack},
				{NULL, NULL}
				};
	unsigned int index = 0;
	char *opcode;

	opcode = strtok(line_content, " \n\t");
	if (opcode && opcode[0] == '#')
		return (0);

	data.argument = strtok(NULL, " \n\t");
	while (instructions[index].opcode && opcode)
	{
		if (strcmp(opcode, instructions[index].opcode) == 0)
		{
			instructions[index].handler(stack_head, line_counter);
			return (0);
		}
		index++;
	}

	if (opcode && instructions[index].opcode == NULL)
	{
		fprintf(stderr, "L%d: unknown instruction %s\n", line_counter, opcode);
		fclose(monty_file);
		free(line_content);
		release_stack(*stack_head);
		exit(EXIT_FAILURE);
	}

	return (1);
}

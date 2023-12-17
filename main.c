#include "monty.h"

data_t data = {NULL, NULL, NULL, 0};

/**
* interpret_monty_code - monty code interpreter
* @argument_count: number of arguments
* @argument_values: monty file location
* Return: 0 on success
*/
int interpret_monty_code(int argument_count, char *argument_values[])
{
	char *line_content;
	FILE *monty_file;
	size_t buffer_size = 0;
	ssize_t read_result = 1;
	node_t *stack_head = NULL;
	unsigned int line_counter = 0;

	if (argument_count != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	monty_file = fopen(argument_values[1], "r");
	data.monty_file = monty_file;

	if (!monty_file)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argument_values[1]);
		exit(EXIT_FAILURE);
	}

	while (read_result > 0)
	{
		line_content = NULL;
		read_result = getline(&line_content, &buffer_size, monty_file);
		data.line_content = line_content;
		line_counter++;

		if (read_result > 0)
		{
			run_instruction(line_content, &stack_head, line_counter, monty_file);
		}

		free(line_content);
	}

	release_stack(stack_head);
	fclose(monty_file);
	return (0);
}

int main(int argc, char *argv[])
{
	return interpret_monty_code(argc, argv);
}

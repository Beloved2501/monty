#include "monty.h"

arg_t arg = {0, 0};

/**
 * comment_check - function that checks if line is a comment
 * @line: struct containing line contents and line number
 * Return: Return true if comment, return false if else
 **/
bool comment_check(line_t line)
{
	if (!line.content[0])
	{
		free(line.content);
		return (true);
	}

	if (line.content[0][0] == '#')
	{
		free(line.content);
		return (true);
	}

	return (false);
}

/**
 * argument_check - function that verifies if argument is valid
 * @token: the argument to be checked
 * Return: Return true if argument is valid, else return false
 **/
bool argument_check(char *token)
{
	unsigned int i;

	if (!token)
		return (false);

	for (i = 0; token[i]; i++)
	{
		if (token[0] == '-')
			continue;
		if (token[i] < '0' || token[i] > '9')
		{
			return (false);
		}
	}

	return (true);
}

/**
 * push_check - function that check if push opcode is being used and sets
 * global argument variable if true
 * @line: struct containing line contents and line number
 * @opcode: the opcode to compare
 * @meta: struct containing all allocated memory
 * Return: Return void
 **/
void push_check(line_t line, meta_t *meta, char *opcode)
{
	if ((strcmp(opcode, "push") == 0) && !argument_check(line.content[1]))
	{
		free(line.content);
		fprintf(stderr, "L%d: usage: push integer\n", line.number);
		free(meta->buf);
		free_stack(&(meta->stack));
		fclose(meta->file);
		free(meta);
		exit(EXIT_FAILURE);
	}
	else if (strcmp(opcode, "push") == 0)
		arg.arg = atoi(line.content[1]);
}

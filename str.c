#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "monty.h"

#define  _POSIX_C_SOURCE 200809L

/**
 * main - entry point
 * @argv: list of arguments passed to our program
 * @argc: amount of args
 *
 * Return: nothing
 */

void file_errer(char *argv);
void error_usage(void);
int status = 0;

int main(int argc, char **argv)
{
	FILE *file;
	size_t buf_len = 0;
	char *buf = NULL;
	char *s = NULL;
	stack_t *stack = NULL;
	unsigned int number_l = 1;

	global.data_struct = 1;
	if (argc != 2)
		error_usage();

	file = fopen(argv[1], "r");

	if (!file)
		file_error(argv[1]);

	while ((getline(&buf, &buf_len, file)) != (-1))
	{
		if (status)
			break;
		if (*buf == '\n')
		{
			number_l++;
			continue;
		}
		s = strtok(buf, "\t\n");
		if (!s || *s == '#')
		{
			number_l++;
			continue;
		}
		global.argument = strtok(NULL, " \t\n");
		opcode(&stack, s, number_l);
		number_l++;
	}
	free(buf);
	free_stack(stack);
	fclose(file);
	exit(EXIT_SUCCESS);
}

void file_error(char *argv)
{
	fprintf(stderr, "error ; cant open file %s\n", argv);
	exit(EXIT_FAILURE);
}

void error_usage(void)
{
	fprintf(stderr, "USAGE; monty file \n");
	exit(EXIT_FAILURE);
}

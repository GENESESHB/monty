#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include "monty.h"

/**
 * push - push element into the stack
 * @stack: stack given by main
 * @number_l: amount of lines
 *
 *
 * Return: void
 */

void push(stack_t **stack, unsigned int number_l)
{
	char *n = global.argument;

	if ((is_digit(n)) == 0)
	{
		fprintf(stderr, "l%d: user: inter integer\n", number_l);
		exit(EXIT_FAILURE);
	}

	if (global.data_struct == 1)
	{
		if (!add_node(stack, atoi(global.argumet)))
		{
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		if(!queue_node(stack, atoi(global.argument)))
		{
			exit(EXIT_FAILURE);
		}
	}
}

#include "monty.h"

/**
 * pall - print the content stack
 * @stack: stack given bu main in str.c
 * @number_l: amount of lines
 *
 *
 * Return: void
 */

void pall(stack_t **stack, unsigned int number_l__attribute__((unused)))
{
	print_stack(*stack);
}

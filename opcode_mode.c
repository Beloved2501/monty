#include "monty.h"

/**
 * addst - the fnct that changes mode of push to stack
 * @stack: pointer that points to the stack.,
 * @nline: this is the line number
 *
 * Return: Nothing.
 */
void addst(stack_t **stack, unsigned int nline)
{
	(void)nline;
	(void)stack;

	arg.flag = 0;
}

/**
 * addqu - this function changes mode of push to queue
 * @stack: pointer that points to the stack
 * @nline: this is the line number
 *
 * Return: Nothing.
 */
void addqu(stack_t **stack, unsigned int nline)
{
	(void)nline;
	(void)stack;

	arg.flag = 1;
}

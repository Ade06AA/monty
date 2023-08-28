#include "monty.h"

/*void free_stack(void)
{
 stack_t *temp = stack;

 while (temp != NULL)
 {
	 stack_t *t = temp;
	 temp = temp->next;
	 free(t);
 }
}*/

/**
* free_stack - frees the stack
* Return: void
*/
void free_stack(void)
{
	stack_t *temp;

	while (stack != NULL)
	{
		temp = stack;
		stack = stack->next;
		free(temp);
	}
}

/**
* add - add the first two element on the stack
* @ln: represent the curent line to be used for error refrence
* @a: fist buffer to be freed before exiting
* @b: second buffer to be freed before exiting
* Return: void
*/
void add(int ln, char *a, char *b)
{
	int n, m;
	stack_t *temp;

	if (stack != NULL)
		if (stack->next != NULL)
		{
			n = stack->n;
			m = stack->next->n;
			temp = stack->next;
			temp->n = n + m;
			free(stack);
			stack = temp;
		}
		else
		{
			fprintf(stderr, "L%d: can't add, stack too short\n", ln);
			free_stack();
			myexit2(a, b);
		}
	else
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", ln);
		free_stack();
		myexit2(a, b);
	}
}

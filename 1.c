#include "monty.h"


/**
* push - func name
* @n: new value to be added
*  @a: first bufer to be freed before exiting
*  @b: second bufer to be freed before exiting
* Return: ned head
*/
void push(int n, char *a, char *b)
{
	stack_t *temp;

	temp = malloc(sizeof(stack_t));
	if (temp == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		free_stack();
		myexit2(a, b);
	}
	if (stack != NULL)
		(stack)->prev = temp;
	temp->next = stack;
	temp->prev = NULL;
	temp->n = n;
	stack = temp;
}


/**
* pall - a function that prints out the content of
 * the stack
* Return: void
*/
void pall(void)
{
	const stack_t *temp;
	size_t i;

	temp = stack;
	if (stack == NULL)
		return;
	for (i = 0; temp != NULL; i++)
	{
		printf("%d\n", temp->n);
		temp = temp->next;
	}
}

/**
* pint - print the first digit on the stack
* @ln: represent the curent line to be used for error refrence
*  @a: first bufer to be freed before exiting
*  @b: second bufer to be freed before exiting
* Return: void
*/
void pint(int ln, char *a, char *b)
{
	if (stack != NULL)
		printf("%d\n", stack->n);
	else
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", ln);
		myexit2(a, b);
	}
}

/**
* pop - removes the first element on the stack
* @ln: represent the curent line to be used for error refrence
*  @a: first bufer to be freed before exiting
*  @b: second bufer to be freed before exiting
* Return: void
*/
void pop(int ln, char *a, char *b)
{
	stack_t *temp;

	if (stack != NULL)
	{
		temp = stack->next;
		free(stack);
		stack = temp;
		if (stack != NULL)
			stack->prev = NULL;
	}
	else
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", ln);
		free_stack();
		myexit2(a, b);
	}
}

/**
* swap - swap the top two element on the stack
* @ln: represent the curent line to be used for error refrence
*  @a: first bufer to be freed before exiting
*  @b: second bufer to be freed before exiting
* Return: void
*/
void swap(int ln, char *a, char *b)
{
	stack_t *temp;

	if (stack != NULL)
		if (stack->next != NULL)
		{
			temp = stack->next;
			stack->next = temp->next;
			temp->next = stack;
			temp->prev = NULL;
			stack->prev = temp;
			stack = temp;
		}
		else
		{
			fprintf(stderr, "L%d: can't swap, stack too short\n", ln);
			free_stack();
			myexit2(a, b);
		}
	else
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", ln);
		free_stack();
		myexit2(a, b);
	}
}

#include "main.h"

/**
* free_stack - frees the stack
* Return: void
*/
void free_stack()
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
* push - func name
* @n: new value to be added
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
* print_dlistint - a function that prints out the content of
 * of a doubly nlinked list
* Return: i - the amount of nodes
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


/**
* add - add the first two element on the stack
* @ln: represent the curent line to be used for error refrence
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



/**
* firsts - gets the first word in a string
* @buf: the main string source
* @buf2: buffer to contain the new  string
* @i: aproximate to the lent of buf2
* Return: void
*/

void firsts(char *buf, char **buf2, int *i)
{
	int t;

	for (t = 0; buf[t] != '\0' && buf[t] != ' ' && buf[t] != '\n'; t++)
		(*buf2)[t] = buf[t];


	(*buf2)[t - 1] == '\0';
	*i += t;
}

/*
void firsts(char *buf, char *buf2, int *i)
{
	int t;

	for (t = 0; t < 9 && *(buf + t) != '\0'; t++)
	{
		if ((buf + t) != NULL && *(buf + t) != '\n' && *(buf + t) != ' ')
			buf2[t] = *(buf + t);
		else
			break;
	}
	buf2[t] == '\0';
	i += t;
}
 */

/**
* myexit2 - frees 2  variable and also frees the stack before exiting
* @a: first element to be freed
* @b: second element to be freed
* Return: void
*/
void myexit2(char *a, char *b)
{
	free(a);
	free(b);
	free_stack();
	exit(EXIT_FAILURE);
}



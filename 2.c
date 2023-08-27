#include "main.h"

/**
* MyHandleFile - work on the file before interpreting
* @file: pointer to file pointer
* @ac: argument count
* @av: arguments
* Return: void
*/
void MyHandleFile(FILE **file, int ac, char *av[])
{
	if (ac != 2)
	{
		fprintf(stderr, "USAGE: %s file\n", av[0]);
		free_stack();
		exit(EXIT_FAILURE);
	}
	if (access(av[1], R_OK) != 0)
	{
		fprintf(stderr, "Error: can't open file %s\n", av[1]);
		exit(EXIT_FAILURE);
	}
	*file = fopen(av[1], "r");
	if (!(*file))
	{
		fprintf(stderr, "Error: can't open file %s\n", av[1]);
		exit(EXIT_FAILURE);
	}
}

/**
* MyInterpreter - the main part that interpret the gotten lines
* @ar: value of the int argument if any
* @ln: line number
* @buf: main buffer containg the line content
* @buf2: buffer containing the first word of the line
* Return: void
*/
void MyInterpreter(int ar, int ln, char *buf, char *buf2)
{
	if (strcmp("push", buf2) == 0)
		push(ar, buf, buf2);
	else if (strcmp("pall", buf2) == 0)
		pall();
	else if (strcmp("pint", buf2) == 0)
		pint(ln, buf, buf2);
	else if (strcmp("pop", buf2) == 0)
		pop(ln, buf, buf2);
	else if (strcmp("swap", buf2) == 0)
		swap(ln, buf, buf2);
	else if (strcmp("add", buf2) == 0)
		add(ln, buf, buf2);
	else if (strcmp("nop", buf2) == 0)
		;
	else
	{
		fprintf(stderr, "L%d: unknown instruction %s\n", ln, buf2);
		free_stack();
		myexit2(buf, buf2);
	}
}

/**
* MyRefineLine - making the gotten line ready for use by MyInterpreter
* @ar: pointer to the value of the passed int argument if any
* @t: contains the return value of getline function
* @ln: line number
* @buf: buffer containing the original gotten line
* @buf2: pointer to the buffer containing the fist word
* Return: 1 which denote continue, 2 denote break, 0 nothing
*/
int MyRefineLine(int *ar, ssize_t t, int ln, char *buf, char **buf2)
{
	int i;

	if (t == -1)
	{
		free_stack();
		myexit2(buf, *buf2);
	}
	for (i = 0; buf[i] == ' '; i++)
		;
	if (*(buf + i) == '\n')
	{
		free(buf);
		free(*buf2);
		return (1);
	}
	firsts(buf + i, buf2, &i);
	for (; buf[i + 1] == ' '; i++)
		;
	if (*(buf + i + 1) >= '0' && *(buf + i + 1) <= '9')
		*ar = atoi(buf + i);
	else
	{
		if (strcmp("push", *buf2) == 0)
		{
			fprintf(stderr, "L%d: usage: push integer\n", ln);
			free_stack();
			myexit2(buf, *buf2);
		}
	}
	return (0);
}

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
	(*buf2)[t] = '\0';
	*i += t;
}

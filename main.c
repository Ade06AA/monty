#include "main.h"

/**
*    ----PROJECT DESCRIPTION---    *
*     This project is more about implimentin how the stack in most *
* programing language works. Specifically using linked list aproch *
*/

/* coment */
//stack_t *stack;

/**
* main - the main function
* @ac: nuber of argument passed
* @av: duble pointer of argument passed
* Return: 0 if no error was met while interpreting the file
*/
int main(int ac, char *av[])
{
	int ln, ar, flag;
	char *buf, *buf2;
	ssize_t t = 0;
	size_t nl;
	FILE *file;

	MyHandleFile(&file, ac, av);
	for (ln = 1; t != -1; ln++)
	{
		buf = NULL;
		buf2 = NULL;
		buf = malloc(MAX_BUF_LEN * sizeof(char));
		buf2 = malloc(MAX_BUF_LEN * sizeof(char));
		t = getline(&buf, &nl, file);
		flag = MyRefineLine(&ar, t, ln, buf, &buf2);
		if (flag == 1)
			continue;
		else if (flag == 2)
			break;
		printf("%d==%s", ln, buf);
		MyInterpreter(ar, ln, buf, buf2);
		ar = 0;
		free(buf2);
		free(buf);
	}
	return (0);
}

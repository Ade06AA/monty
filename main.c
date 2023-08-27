#include "main.h"

stack_t *stack;

int main(int ac, char *av[])
{
	int ln, i, ar;
	char *buf, *buf2;
	ssize_t t = 0;
	size_t nl;
	FILE *file;

	if (ac != 2)
	{
		fprintf(stderr, "USAGE: %s file\n", av[0]);
		exit(EXIT_FAILURE);
	}
	if (access(av[1], R_OK) != 0)
	{
		fprintf(stderr, "Error: can't open file %s\n", av[1]);
		exit(EXIT_FAILURE);
	}
	if (!(file = fopen(av[1], "r")))
	{
		fprintf(stderr, "Error: can't open file %s\n", av[1]);
		exit(EXIT_FAILURE);
	}
	for (ln = 1; t != -1; ln++)
	{
		buf = NULL;
		buf2 = NULL;
		buf = malloc(sizeof(char *));
		buf2 = malloc(sizeof(char *));
		t = getline(&buf, &nl, file);
		if (t == -1)
			break;
		for (i = 0; buf[i] == ' '; i++)
			;
		if (*(buf + i) == '\n')
		{
			free(buf);
			continue;
		}
		firsts(buf + i, &buf2, &i);
		//if (*(buf + i + 1) >= '0' && *(buf + i + 1) <= '9')
		ar = atoi(buf + i);
		printf("============================\n");
		printf("%d == %s  ...%d - %d == 0%s0\n", ln, buf, i, strlen(buf), buf);
		printf("%d == %s  ...%d - %d == 0%s0\n", ln, buf2, i, strlen(buf2), buf2);
		printf("=============================\n");
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
	//	else if (strcmp("nop", buf2) == 0)
		//	;
		else
		{	
			fprintf(stderr, "L%d: unknown instruction %s\n", ln, buf2);
		}
		free(buf2);
		free(buf);
	}
}

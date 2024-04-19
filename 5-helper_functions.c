#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "4-shell.h"

/**
 * count_tokens - Counts the number of tokens in a string.
 * @line: The input string.
 * @delim: The delimiters to use for tokenization.
 * Return: The number of tokens.
 */
int count_tokens(const char *line, const char *delim)
{
	char *tmp;
	char *token;
	int count = 0;

	if (line == NULL)
		return (0);

	tmp = strdup(line); /* Create a temporary copy of the input string */
	if (tmp == NULL)
		return (-1); /* Memory allocation failed */
					 /* Tokenize the temporary string */
	token = strtok(tmp, delim);
	while (token)
	{
		count++;					 /* Increment the count for each token */
		token = strtok(NULL, delim); /* Move to the next token */
	}
	free(tmp);		/* Free the memory allocated for the temporary string */
	return (count); /* Return the total count of tokens */
}
/**
 * tokenizer - Tokenizes a given string into an array of strings.
 * @line: The input string.
 * Return: An array of strings.
 */
char **tokenizer(char *line)
{
	char *token;
	char delim[] = " "; /* Delimiter for tokenization */
	int num = 0;
	int i = 0;
	char **tokenss; /* Array to store tokens */

	if (line == NULL)
		return (NULL);
	/* Count the number of tokens */
	num = count_tokens(line, delim);
	if (num <= 0)
		return (NULL);
	/* Allocate memory for the tokens array */
	tokenss = malloc(sizeof(char *) * (num + 1));
	if (tokenss == NULL)
		return (NULL);
	/* Tokenize the input string */
	token = strtok(line, delim);
	while (token)
	{
		/* Allocate memory for each token */
		tokenss[i] = strdup(token);
		if (tokenss[i] == NULL)
		{
			/* Free memory if allocation fails */
			while (i > 0)
			{
				free(tokenss[--i]);
			}
			free(tokenss);
			return (NULL);
		}
		i++;
		token = strtok(NULL, delim); /* Move to the next token */
	}
	tokenss[i] = NULL; /* Set the last element of the array to NULL */
	return (tokenss);  /* Return the array of tokens */
}


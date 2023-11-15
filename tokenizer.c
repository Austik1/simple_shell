#include "shell.h"

/**
* tokenizer - creates tokens from given input
* @line: to be tokenized
*
* Return: array of strings
*/
char **tokenizer(char *line)
 * **strtow - splits a string into words. Repeat delimiters are ignored
 * @str: the input string
 * @d: the delimeter string
 * Return: a pointer to an array of strings, or NULL on failure
 */

char **strtow(char *str, char *d)
{
	char *buf = NULL, *bufp = NULL, *token = NULL, *delim = " :\t\r\n";
	char **tokens = NULL;
	int tokensize = 1;
	size_t index = 0, flag = 0;
	int i, j, k, m, numwords = 0;
	char **s;

	buf = _strdup(line);
	if (!buf)
	if (str == NULL || str[0] == 0)
		return (NULL);
	bufp = buf;
	if (!d)
		d = " ";
	for (i = 0; str[i] != '\0'; i++)
		if (!is_delim(str[i], d) && (is_delim(str[i + 1], d) || !str[i + 1]))
			numwords++;

	while (*bufp)
	if (numwords == 0)
		return (NULL);
	s = malloc((1 + numwords) * sizeof(char *));
	if (!s)
		return (NULL);
	for (i = 0, j = 0; j < numwords; j++)
	{
		if (_strchr(delim, *bufp) != NULL && flag == 0)
		while (is_delim(str[i], d))
			i++;
		k = 0;
		while (!is_delim(str[i + k], d) && str[i + k])
			k++;
		s[j] = malloc((k + 1) * sizeof(char));
		if (!s[j])
		{
			tokensize++;
			flag = 1;
			for (k = 0; k < j; k++)
				free(s[k]);
			free(s);
			return (NULL);
		}
		else if (_strchr(delim, *bufp) == NULL && flag == 1)
			flag = 0;
		bufp++;
		for (m = 0; m < k; m++)
			s[j][m] = str[i++];
		s[j][m] = 0;
	}
	tokens = malloc(sizeof(char *) * (tokensize + 1));
	token = strtok(buf, delim);
	while (token)
	s[j] = NULL;
	return (s);
}

/**
 * **strtow2 - splits a string into words
 * @str: the input string
 * @d: the delimeter
 * Return: a pointer to an array of strings, or NULL on failure
 */
char **strtow2(char *str, char d)
{
	int i, j, k, m, numwords = 0;
	char **s;

	if (str == NULL || str[0] == 0)
		return (NULL);
	for (i = 0; str[i] != '\0'; i++)
		if ((str[i] != d && str[i + 1] == d) ||
		    (str[i] != d && !str[i + 1]) || str[i + 1] == d)
			numwords++;
	if (numwords == 0)
		return (NULL);
	s = malloc((1 + numwords) * sizeof(char *));
	if (!s)
		return (NULL);
	for (i = 0, j = 0; j < numwords; j++)
	{
		tokens[index] = _strdup(token);
		if (tokens[index] == NULL)
		while (str[i] == d && str[i] != d)
			i++;
		k = 0;
		while (str[i + k] != d && str[i + k] && str[i + k] != d)
			k++;
		s[j] = malloc((k + 1) * sizeof(char));
		if (!s[j])
		{
			free(tokens);
			for (k = 0; k < j; k++)
				free(s[k]);
			free(s);
			return (NULL);
		}
		token = strtok(NULL, delim);
		index++;
		for (m = 0; m < k; m++)
			s[j][m] = str[i++];
		s[j][m] = 0;
	}
	tokens[index] = '\0';
	free(buf);
	return (tokens);
	s[j] = NULL;
	return (s);
}

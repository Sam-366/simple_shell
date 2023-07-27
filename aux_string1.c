#include "simple_shell.h"

/**
 * _strcat - function that concatenate two strings
 *
 * @dest: char pointer the destination of the copied str
 *
 * @src: const char pointer the source of str
 *
 * Return: returns the destination
 */

char *_strcat(char *dest, const char *src)
{
	int k;
	int l;

	for (k = 0; dest[k] != '\0'; k++)
		;

	for (l = 0; src[l] != '\0'; l++)
	{
		dest[k] = src[l];
		k++;
	}

	dest[k] = '\0';
	return (dest);
}

/**
 * *_strcpy - function that copies the string pointed to by src.
 *
 * @dest: char pointer the dest of the copied str
 *
 * @src: char pointer the source of str
 *
 * Return: returns the dest.
 */

char *_strcpy(char *dest, char *src)
{

	size_t i;

	for (i = 0; src[i] != '\0'; i++)
	{
		dest[i] = src[i];
	}
	dest[i] = '\0';

	return (dest);
}

/**
 * _strcmp - function that compares two strings.
 *
 * @s1: str to compare
 *
 * @s2: str to compare
 *
 * Return: Always 0 (success)
 */

int _strcmp(char *s1, char *s2)
{
	int j;

	for (j = 0; s1[j] == s2[j] && s1[j]; j++)
		;

	if (s1[j] > s2[j])
		return (1);
	if (s1[j] < s2[j])
		return (-1);
	return (0);
}

/**
 * _strchr - function that locates a character in a string,
 *
 * @s: str
 *
 * @c: char
 *
 * Return: returns the pointer to the first occurrence of the character c.
 */

char *_strchr(char *s, char c)
{
	unsigned int i = 0;

	for (; *(s + i) != '\0'; i++)
		if (*(s + i) == c)
			return (s + i);
	if (*(s + i) == c)
		return (s + i);
	return ('\0');
}

/**
 * _strspn - function that gets the length of a prefix substring.
 *
 * @s: initial segment.
 *
 * @accept: accepted bytes.
 *
 * Return: returns the number of accepted bytes.
 */

int _strspn(char *s, char *accept)
{
	int i, j, bool;

	for (i = 0; *(s + i) != '\0'; i++)
	{
		bool = 1;
		for (j = 0; *(accept + j) != '\0'; j++)
		{
			if (*(s + i) == *(accept + j))
			{
				bool = 0;
				break;
			}
		}
		if (bool == 1)
			break;
	}
	return (i);
}

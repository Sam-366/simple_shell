#include "simple_shell.h"

/**
 * _memcpy - functions that copies information between void pointers.
 *
 * @newptr: points to destination.
 *
 * @ptr: points to the source.
 *
 * @size: size of new pointer.
 *
 * Return: none.
 */

void _memcpy(void *newptr, const void *ptr, unsigned int size)
{
	char *char_ptr = (char *)ptr;
	char *char_newptr = (char *)newptr;
	unsigned int k;

	for (k = 0; k < size; k++)
		char_newptr[k] = char_ptr[k];
}

/**
 * _realloc - function that reallocates a memory block.
 *
 * @ptr: pointer to the memory that was allocated before.
 *
 * @old_size: byte size of the allocated space of ptr.
 *
 * @new_size: new byte size of the new memory block.
 *
 * Return: returns ptr.
 *
 * if new_size == old_size, it then returns ptr without changes.
 *
 * if malloc fails, it terminates and returns NULL.
 */

void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
	void *newptr;

	if (ptr == NULL)
		return (malloc(new_size));

	if (new_size == 0)
	{
		free(ptr);
		return (NULL);
	}

	if (new_size == old_size)
		return (ptr);

	newptr = malloc(new_size);
	if (newptr == NULL)
		return (NULL);

	if (new_size < old_size)
		_memcpy(newptr, ptr, new_size);
	else
		_memcpy(newptr, ptr, old_size);

	free(ptr);
	return (newptr);
}

/**
 * _reallocdp - function that reallocates a memory block of a double pointer.
 *
 * @ptr: double pointer to the memory that was allocated previously.
 *
 * @old_size: byte size of the allocated space of ptr.
 *
 * @new_size: new byte size of the new memory block.
 *
 * Return: returns a ptr.
 *
 * if new_size == old_size, it then returns ptr without changes.
 *
 * if malloc fails, it terminates and returns NULL.
 */

char **_reallocdp(char **ptr, unsigned int old_size, unsigned int new_size)
{
	char **newptr;
	unsigned int k;

	if (ptr == NULL)
		return (malloc(sizeof(char *) * new_size));

	if (new_size == old_size)
		return (ptr);

	newptr = malloc(sizeof(char *) * new_size);
	if (newptr == NULL)
		return (NULL);

	for (k = 0; k < old_size; k++)
		newptr[k] = ptr[k];

	free(ptr);

	return (newptr);
}

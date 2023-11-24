#include "main.h"

/**
 * set_bit - Program that set the value of a bit to one at a given index.
 * @n: The number to set.
 * @index: The index at which the bit is set.
 *
 * Return: ...
 */
int set_bit(unsigned long int *n, unsigned int index)
{
	unsigned long int setsbit;

	if (index > (sizeof(unsigned long int) * 8 - 1))
	return (-1);
	setsbit = 1 << index;
	*n = *n | setsbit;
	return (1);
}

#include"main.h"

/**
 * get_bit - Program that returns the value of a bit.
 * @n: The number to check.
 * @index: The index to check bit.
 *
 * Return: ...
 */
int get_bit(unsigned long int n, unsigned int index)
{
	unsigned long int divider, checker;

	if (index > (sizeof(unsigned long int) * 8 - 1))
	return (-1);
	divider = 1 << index;
	checker = n & divider;
	if (checker == divider)
	return (1);
	return (0);
}

#include "main.h"

/**
 * flip_bits - Program that counts the number of bits to change.
 * @n: The first number.
 * @m: The second number.
 *
 * Return: ...
 */
unsigned int flip_bits(unsigned long int n, unsigned long int m)
{
	int c, countsbit = 0;
	unsigned long int resent;
	unsigned long int exclusive = n ^ m;

	for (c = 63; c >= 0; c--)
	{
	resent = exclusive >> c;
	if (resent & 1)
	countsbit++;
	}
	return (countsbit);
}

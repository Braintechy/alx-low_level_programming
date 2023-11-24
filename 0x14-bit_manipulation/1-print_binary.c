#include "main.h"

/**
 * _pew - Program of function that calculate base ^ power.
 * @base: The base of exponent.
 * @power: The power of the exponent.
 *
 * Return: ...
 */
unsigned long int _pew(unsigned int base, unsigned int power)
{
	unsigned long int number;
	unsigned int c;

	number = 1;
	for (c = 1; c <= power; c++)
	number *= base;
	return (number);
}

/**
 * print_binary - Program that print a number in binary notation.
 * @n: The number to print.
 *
 * Return: void
 */
void print_binary(unsigned long int n)
{
	unsigned long int divider, checker;
	char flags;

	flags = 0;
	divider = _pew(2, sizeof(unsigned long int) * 8 - 1);
	while (divider != 0)
	{
	checker = n & divider;
	if (checker == divider)
	{
	flags = 1;
	_putchar('1');
	}
	else if (flags == 1 || divider == 1)
	{
	_putchar('0');
	}
	divider >>= 1;
	}
}

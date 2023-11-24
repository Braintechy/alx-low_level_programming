#include "main.h"

/**
 * get_endianness - ...
 *
 * Return: ...
 */
int get_endianness(void)
{
	int c;
	char *b;

	c = 1;
	b = (char *)&c;
	return (*b);
}

#include "lists.h"

/**
 * listint_len - Program that returns the number of elements in a linked lists.
 * @h: ...
 *
 * Return: ...
 */
size_t listint_len(const listint_t *h)
{
	size_t number = 0;

	while (h)
	{
	number++;
	h = h->next;
	}

	return (number);
}

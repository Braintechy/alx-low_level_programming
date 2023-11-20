#include "lists.h"

/**
 * free_listint_safe - ...
 * @h: ...
 *
 * Return: ...
 */
size_t free_listint_safe(listint_t **h)
{
	size_t length = 0;
	int deff;
	listint_t *temp;

	if (!h || !*h)
	return (0);

	while (*h)
	{
	deff = *h - (*h)->next;
	if (deff > 0)
	{
	temp = (*h)->next;
	free(*h);
	*h = temp;
	length++;
	}
	else
	{
	free(*h);
	*h = NULL;
	length++;
	break;
	}
	}

	*h = NULL;

	return (length);
}

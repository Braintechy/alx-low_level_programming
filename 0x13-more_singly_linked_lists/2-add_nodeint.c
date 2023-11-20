#include "lists.h"

/**
 * add_nodeint - ...
 * @head: ...
 * @n: ...
 *
 * Return: ...
 */
listint_t *add_nodeint(listint_t **head, const int n)
{
	listint_t *latest;

	latest = malloc(sizeof(listint_t));
	if (!latest)
	return (NULL);

	latest->n = n;
	latest->next = *head;
	*head = latest;

	return (latest);
}

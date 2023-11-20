#include "lists.h"

/**
 * insert_nodeint_at_index - ...
 * @head: ...
 * @idx: ...
 * @n: ...
 *
 * Return: ...
 */
listint_t *insert_nodeint_at_index(listint_t **head, unsigned int idx, int n)
{
	unsigned int j;
	listint_t *latest;
	listint_t *temp = *head;

	latest = malloc(sizeof(listint_t));
	if (!latest || !head)
	return (NULL);

	latest->n = n;
	latest->next = NULL;

	if (idx == 0)
	{
	latest->next = *head;
	*head = latest;
	return (latest);
	}

	for (j = 0; temp && j < idx; j++)
	{
	if (j == idx - 1)
	{
	latest->next = temp->next;
	temp->next = latest;
	return (latest);
	}
	else
	temp = temp->next;
	}

	return (NULL);
}

#include "lists.h"

/**
 * sum_listint - ...
 * @head: ...
 *
 * Return: ...
 */
int sum_listint(listint_t *head)
{
	int add = 0;
	listint_t *temp = head;

	while (temp)
	{
	add += temp->n;
	temp = temp->next;
	}

	return (add);
}

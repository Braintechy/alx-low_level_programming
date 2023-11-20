#include "lists.h"

/**
 * find_listint_loop - ...
 * @head: ...
 *
 * Return: ...
 */
listint_t *find_listint_loop(listint_t *head)
{
	listint_t *sluggish = head;
	listint_t *speedy = head;

	if (!head)
	return (NULL);

	while (sluggish && speedy && speedy->next)
	{
	speedy = speedy->next->next;
	sluggish = sluggish->next;
	if (speedy == sluggish)
	{
	sluggish = head;
	while (sluggish != speedy)
	{
	sluggish = sluggish->next;
	speedy = speedy->next;
	}
	return (speedy);
	}
	}

	return (NULL);
}

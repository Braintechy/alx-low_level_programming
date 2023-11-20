#include "lists.h"
#include <stdio.h>

size_t looped_listint_len(const listint_t *head);
size_t print_listint_safe(const listint_t *head);

/**
 * looped_listint_len - ...
 * @head: ...
 *
 * Return: ...
 */
size_t looped_listint_len(const listint_t *head)
{
	const listint_t *lion, *mouse;
	size_t node = 1;

	if (head == NULL || head->next == NULL)
	return (0);

	lion = head->next;
	mouse = (head->next)->next;

	while (mouse)
	{
	if (lion == mouse)
	{
	lion = head;
	while (lion != mouse)
	{
	node++;
	lion = lion->next;
	mouse = mouse->next;
	}
	lion = lion->next;
	while (lion != mouse)
	{
	node++;
	lion = lion->next;
	}

	return (node);
	}

	lion = lion->next;
	mouse = (mouse->next)->next;
	}

	return (0);
}

/**
 * print_listint_safe - ...
 * @head: ...
 *
 * Return: ...
 */
size_t print_listint_safe(const listint_t *head)
{
	size_t node, index = 0;

	node = looped_listint_len(head);

	if (node == 0)
	{
	for (; head != NULL; node++)
	{
	printf("[%p] %d\n", (void *)head, head->n);
	head = head->next;
	}
	}

	else
	{
	for (index = 0; index < node; index++)
	{
	printf("[%p] %d\n", (void *)head, head->n);
	head = head->next;
	}

	printf("-> [%p] %d\n", (void *)head, head->n);
	}

	return (node);
}

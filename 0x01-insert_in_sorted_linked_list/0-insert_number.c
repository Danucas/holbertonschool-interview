#include "lists.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * insert_node - Insert a node in a sorted singly linked list
 * @head: the pointer to the head node in the list
 * @number: integer to insert in the list
 * Return: the pointer to the new node or NULL if fails
 */
listint_t *insert_node(listint_t **head, int number)
{
	listint_t *actual = *head;
	listint_t *new;

	while (actual)
	{
		if (
			(actual->next
			 && actual->next->n > number
			 && actual->n < number)
			|| (!actual->next && actual->n < number))
		{
			new = malloc(sizeof(listint_t));
			new->n = number;
			new->next = actual->next;
			actual->next = new;
			return (new);
		}
		actual = actual->next;
	}
	return (NULL);
}

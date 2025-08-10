#include "sort.h"
#include <stdio.h>
/**
 * insertion_sort_list - sort a doubly linked list of
 * integers in ascending order
 * @list: double pointer pointing to the head of the list
 * Return: nothing
 */
void insertion_sort_list(listint_t **list)
{
	/* Pointers for traversal and swapping */
	listint_t *current;
	listint_t *temp;

	/* Check if the list is NULL, empty, has only one node (nothing to sort) */
	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;
	/* Start from the second node */
	current = (*list)->next;
	while (current != NULL)
	{
		temp = current;
		/* Move temp backwards while it's smaller than the previous node */
		while (temp->prev != NULL && temp->n < temp->prev->n)
		{
			/* Swap nodes temp and temp->prev */
			listint_t *prev_node = temp->prev;
			/* Adjust links for node before prev_node */
			if (prev_node->prev != NULL)
				prev_node->prev->next = temp;
			temp->prev = prev_node->prev;

			/* Adjust links for node after temp */
			if (temp->next != NULL)
				temp->next->prev = prev_node;
			prev_node->next = temp->next;

			/* Connect prev_node and temp */
			temp->next = prev_node;
			prev_node->prev = temp;

			/* Update head if needed */
			if (temp->prev == NULL)
				*list = temp;
			/* Print the list after each swap */
			print_list(*list);
		}
	       /* Move to the next node */
	       current = current->next;
	}
}

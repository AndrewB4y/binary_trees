#include "binary_trees.h"

/**
 * binary_tree_is_complete - checks if a binary tree is complete.
 * @tree: pointer to the root node of the tree to traverse.
 *
 * Return: 1 if the tree is a complete one. If tree is NULL return 0.
 */


int binary_tree_is_complete(const binary_tree_t *tree)
{
	queue_t *q_head = NULL, *q_tail = NULL;
	int is_complete = 1, last = 0;

	if (tree == NULL)
		return (0);

	q_head = push_to_q(&q_head, &q_tail, tree);
	while (q_head != NULL)
	{
		if (q_head->node == NULL)
		{
			last = 1;
		}
		else
		{
			if (last == 1)
			{
				is_complete = 0;
				break;
			}
			q_tail = push_to_q(&q_head, &q_tail, q_head->node->left);
			q_tail = push_to_q(&q_head, &q_tail, q_head->node->right);
		}
		q_head = pop_the_q(&q_head, &q_tail);
	}
	while (q_head != NULL)
		pop_the_q(&q_head, &q_tail);

	return (is_complete);
}

/**
 * push_to_q - adds a new element to the queue.
 * @q_head: head of the queue.
 * @q_tail: tail of the queue.
 * @node: a binary_tree_t pointer to be placed in queue.
 *
 * Return: pointer to the newly created node, meaning the tail.
 */

queue_t *push_to_q(queue_t **q_head, queue_t **q_tail,
		   const binary_tree_t *node)
{
	queue_t *q_node = NULL;

	q_node = malloc(sizeof(queue_t));
	if (q_node == NULL)
		return (NULL);
	q_node->node = node;
	q_node->next = NULL;

	if (*q_head == NULL)
	{
		*q_head = q_node;
		*q_tail = q_node;
	}
	else
	{
		(*q_tail)->next = q_node;
		*q_tail = q_node;
	}
	return (q_node);
}


/**
 * pop_the_q - pops the head of the queue.
 * @q_head: head of the queue.
 * @q_tail: tail of the queue.
 *
 * Return: the new head of the queue.
 */

queue_t *pop_the_q(queue_t **q_head, queue_t **q_tail)
{
	queue_t *q_node = NULL;

	if (*q_head == NULL || *q_tail == NULL)
		return (NULL);
	q_node = *q_head;
	*q_head = (*q_head)->next;
	if (*q_head == NULL)
		*q_tail = NULL;
	free(q_node);

	return (*q_head);
}

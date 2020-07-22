#include "binary_trees.h"

/**
 * binary_tree_levelorder - goes through a binary tree using
 *                          level-order traversal
 *                          If tree or func is NULL, do nothing.
 * @tree: pointer to the root node of the tree to traverse.
 * @func: pointer to a function to call for each node. The value
 *        in the node must be passed as a parameter to this function.
 *
 * Return: void.
 */


void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
	queue_t *q_head = NULL, *q_tail = NULL;

	if (tree == NULL || func == NULL)
		return;

	q_head = push_to_q(&q_head, &q_tail, tree);
	while (q_head != NULL)
	{
		q_tail = push_to_q(&q_head, &q_tail, q_head->node->left);
		q_tail = push_to_q(&q_head, &q_tail, q_head->node->right);
		func(q_head->node->n);
		q_head = pop_the_q(&q_head, &q_tail);
	}
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

	/* If node sended is NULL, no new element is added to the queue */
	if (node == NULL)
		return (*q_tail);

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

#include "binary_trees.h"

/**
 * binary_trees_ancestor - finds the lowest common ancestor of two nodes.
 * @first: pointer to the first node.
 * @second: pointer to the second node.
 *
 * Return: pointer to the lowest common ancestor node of the two given nodes.
 *         If no common ancestor was found, NULL is returned.
 */

binary_tree_t *binary_trees_ancestor(const binary_tree_t *first,
				     const binary_tree_t *second)
{
	const binary_tree_t *node_f = first, *node_s = second;

	if (first == NULL || second == NULL)
		return (NULL);

	/* Finding highest common ancestor */
	while (node_f->parent != NULL || node_s->parent != NULL)
	{
		if (node_f->parent != NULL)
			node_f = node_f->parent;
		if (node_s->parent != NULL)
			node_s = node_s->parent;
	}
	/* If no highest common ancestor return NULL */
	if (node_f != node_s)
		return (NULL);
	/* Checking if first or second are the highest ancestor */
	if (node_f == first)
		return ((void *)first);
	else if (node_f == second)
		return ((void *)second);

	return (recursive_ancestor(node_f, first, second));
}

/**
 * recursive_ancestor - checks for lowest common ancestor recursively.
 * @node: node in the tree to be compared aginst first and second.
 * @first: pointer to the first node.
 * @second: pointer to the second node.
 *
 * Return: pointer to lowest common ancestor. NULL otherwise.
 */

binary_tree_t *recursive_ancestor(const binary_tree_t *node,
		   const binary_tree_t *first,
		   const binary_tree_t *second)
{
	const binary_tree_t *l_node = NULL, *r_node = NULL;

	if (node == NULL)
		return (NULL);

	if (node == first || node == second)
		return ((void *)node);

	l_node = recursive_ancestor(node->left, first, second);
	if (l_node != first && l_node != second && l_node != NULL)
		return ((void *)l_node);
	r_node = recursive_ancestor(node->right, first, second);

	/* If the result from left and right are different than NULL */
	/* This is lowest common ancestor */
	if (l_node != NULL && r_node != NULL)
		return ((void *)node);

	if (l_node != NULL)
		return ((void *)l_node);
	if (r_node != NULL)
		return ((void *)r_node);

	return (NULL);
}

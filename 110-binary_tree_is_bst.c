#include "binary_trees.h"

/**
 * binary_tree_is_bst - checks if a binary tree is a valid Binary Search Tree.
 * @tree: pointer to the root node of the tree to check.
 *
 * Return: 1 if tree is a valid BST, and 0 otherwise.
 *         If tree is NULL, return 0
 */


int binary_tree_is_bst(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	if (is_less(tree->left) && is_greater(tree->right))
		return (1);

	return (0);
}

/**
 * is_less - checks if a node is less than its parent.
 * @node: node in the tree to check.
 *
 * Return: 1 if is less, 0 otherwise (>=).
 */

int is_less(const binary_tree_t *node)
{
	if (node == NULL)
		return (1);

	if (node->n >= node->parent->n)
		return (0);

	if (is_less(node->left) && is_greater(node->right))
		return (1);

	return (0);
}


/**
 * is_greater - checks if a node is greater than its parent.
 * @node: node in the tree to check.
 *
 * Return: 1 if is greater, 0 otherwise (<=).
 */

int is_greater(const binary_tree_t *node)
{
	if (node == NULL)
		return (1);

	if (node->n <= node->parent->n)
		return (0);

	if (is_less(node->left) && is_greater(node->right))
		return (1);

	return (0);
}

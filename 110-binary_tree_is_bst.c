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

	if (is_less(tree->left, tree->n, 1) && is_greater(tree->right, tree->n, 0))
		return (1);

	return (0);
}

/**
 * is_less - checks if a node is less than its parent.
 * @node: node in the tree to check.
 * @r_val: value of the root.
 * @side: 1 for left, 0 for right part of the tree.
 *
 * Return: 1 if is less, 0 otherwise (>=).
 */

int is_less(const binary_tree_t *node, int r_val, int side)
{
	if (node == NULL)
		return (1);

	if (node->n >= node->parent->n)
		return (0);

	if (side == 1)
	{
		/* left side, all values should be less than root */
		if (node->n >= r_val)
			return (0);
	}
	else
	{
		/* right side, all values should be greater than root */
		if (node->n <= r_val)
			return (0);
	}

	if (is_less(node->left, r_val, side) && is_greater(node->right, r_val, side))
		return (1);

	return (0);
}


/**
 * is_greater - checks if a node is greater than its parent.
 * @node: node in the tree to check.
 * @r_val: value of the root.
 * @side: 1 for left, 0 for right part of the tree.
 *
 * Return: 1 if is greater, 0 otherwise (<=).
 */

int is_greater(const binary_tree_t *node, int r_val, int side)
{
	if (node == NULL)
		return (1);

	if (node->n <= node->parent->n)
		return (0);
	if (side == 1)
	{
		/* left side, all values should be less than root */
		if (node->n >= r_val)
			return (0);
	}
	else
	{
		/* right side, all values should be greater than root */
		if (node->n <= r_val)
			return (0);
	}
	if (is_less(node->left, r_val, side) && is_greater(node->right, r_val, side))
		return (1);

	return (0);
}

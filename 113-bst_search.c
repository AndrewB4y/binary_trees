#include "binary_trees.h"

/**
 * bst_search - searches for a value in a Binary Search Tree.
 * @tree: pointer to the root node of the BST to search.
 * @value: value to search in the tree.
 *
 * Return: a pointer to the node containing a value equals to value.
 *         If tree is NULL or if nothing is found returns NULL.
 */

bst_t *bst_search(const bst_t *tree, int value)
{
	if (tree == NULL)
		return (NULL);

	while (tree != NULL)
	{
		if (value == tree->n)
			return ((void *)tree);

		if (value > tree->n)
			tree = tree->right;
		else
			tree = tree->left;
	}
	return (NULL);
}

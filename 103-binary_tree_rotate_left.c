#include "binary_trees.h"

/**
 * binary_tree_rotate_left - performs a left-rotation on a binary tree.
 * @tree: pointer to the root node of the tree to rotate.
 *
 * Return: pointer to the new root node of the tree once rotated.
 */


binary_tree_t *binary_tree_rotate_left(binary_tree_t *tree)
{
	binary_tree_t temp;

	if (tree == NULL)
		return (NULL);
	else if (tree->right == NULL)
		return (tree);
	temp = *tree;
	/* changing old root->parent->left/right */
	if (tree->parent != NULL)
	{
		if (tree->parent->right == tree)
			tree->parent->right = tree->right;
		else
			tree->parent->left = tree->right;
	}
	/* changing old root's  parent - right */
	tree->parent = temp.right;
	tree->right = temp.right->left;
	/* changing old root->right  parent- left */
	temp.right->parent = temp.parent;
	/* chaging old root->right->left */
	if (temp.right->left != NULL)
		temp.right->left->parent = tree;
	temp.right->left = tree;
	return (tree->parent);
}

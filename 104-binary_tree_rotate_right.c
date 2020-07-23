#include "binary_trees.h"

/**
 * binary_tree_rotate_right - performs a right-rotation on a binary tree.
 * @tree: pointer to the root node of the tree to rotate.
 *
 * Return: pointer to the new root node of the tree once rotated.
 */


binary_tree_t *binary_tree_rotate_right(binary_tree_t *tree)
{
	binary_tree_t temp;

	if (tree == NULL)
		return (NULL);
	else if (tree->left == NULL)
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
	/* changing old root's  parent - left */
	tree->parent = temp.left;
	tree->left = temp.left->right;
	/* changing old root->left  parent- right */
	temp.left->parent = temp.parent;
	/* chaging old root->left->right */
	if (temp.left->right != NULL)
		temp.left->right->parent = tree;
	temp.left->right = tree;
	return (tree->parent);
}

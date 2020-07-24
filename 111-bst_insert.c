#include "binary_trees.h"

/**
 * bst_insert - inserts a value in a Binary Search Tree.
 * @tree: double pointer to the root node of the BST to insert the value.
 * @value: value to store in the node to be inserted.
 *
 * Return: a pointer to the created node, or NULL on failure.
 *         If the address stored in @tree is NULL, the created node
 *         becomes the root node.
 *         If the value is already present in the tree, it is ignored.
 */

bst_t *bst_insert(bst_t **tree, int value)
{
	bst_t *new_node = NULL;

	if (tree == NULL)
		return (NULL);
	if (*tree == NULL)
	{
		*tree = binary_tree_node(NULL, value);
		return (*tree);
	}

	new_node = *tree;
	while (1)
	{
		if (value == new_node->n)
			return (NULL);

		if (value > new_node->n)
		{
			if (new_node->right != NULL)
				new_node = new_node->right;
			else
			{
				new_node = binary_tree_node(new_node, value);
				new_node->parent->right = new_node;
				break;
			}
		}
		else
		{
			if (new_node->left != NULL)
				new_node = new_node->left;
			else
			{
				new_node = binary_tree_node(new_node, value);
				new_node->parent->left = new_node;
				break;
			}
		}
	}
	return (new_node);
}

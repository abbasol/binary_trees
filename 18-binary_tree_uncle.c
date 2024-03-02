#include <stdlib.h>
#include "binary_trees.h"

/**
 * binary_tree_uncle - finds the uncle of a node
 * @node: pointer to the node to find the uncle
 *
 * Return: pointer to the uncle node, or NULL if no uncle
 */
binary_tree_t *binary_tree_uncle(binary_tree_t *node)
{
	binary_tree_t *granddad, *dad;

	if (node == NULL || node->parent == NULL)
		return (NULL);

	dad = node->parent;
	granddad = dad->parent;

	if (granddad == NULL)
		return (NULL);

	if (granddad->left == dad)
		return (granddad->right);
	else
		return (granddad->left);
}

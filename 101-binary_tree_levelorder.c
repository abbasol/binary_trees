#include "binary_trees.h"
#include <stdio.h>

int get_node_height(const binary_tree_t *);
int get_depth(const binary_tree_t *);
void call_handler(int, const binary_tree_t *, void (*func)(int));
int is_leaf(const binary_tree_t *);

/**
 * binary_tree_levelorder - Goes through a binary tree using level-order
 *
 * @tree: Pointer to the root node of the tree to traverse
 * @func: Pointer to a function to call for each node. The value in the node
 *
 * Return: Nothing
 */
void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
	int i, max_height;

	if (tree == NULL || func == NULL)
		return;

	max_height = get_node_height(tree);

	for (i = 1; i <= max_height; i++)
	{
		call_handler(i, tree, func);
	}
}

/**
 * is_leaf - Checks if a node is a leaf
 * @tree: Pointer to the node to check
 *
 * Return: 1 if node is a leaf, 0 otherwise
 */
int is_leaf(const binary_tree_t *tree)
{
	if (tree->left == NULL && tree->right == NULL)
		return (1);
	else
		return (0);
}

/**
 * get_node_height - Gets the height of a node
 * @tree: Pointer to the node to check
 *
 * Return: Height of the node
 */
int get_node_height(const binary_tree_t *tree)
{
	int l, r;

	if (tree == NULL)
		return (0);

	l = get_node_height(tree->left);
	r = get_node_height(tree->right);

	return (l > r ? l + 1 : r + 1);
}

/**
 * get_depth - Gets the depth of a node
 * @tree: Pointer to the node to check
 *
 * Return: Depth of the node
 */
int get_depth(const binary_tree_t *tree)
{
	int depth;

	if (tree == NULL)
		return (0);

	depth = get_depth(tree->parent);

	return (depth + 1);
}

/**
 * call_handler - Calls the handler function
 *
 * @level: Level of the node
 * @tree: Pointer to the node to check
 * @func: Pointer to the function to call
 *
 * Return: Nothing
 */
void call_handler(int level, const binary_tree_t *tree, void (*func)(int))
{
	if (tree == NULL)
		return;

	if (get_depth(tree) == level)
		func(tree->n);

	call_handler(level, tree->left, func);
	call_handler(level, tree->right, func);
}

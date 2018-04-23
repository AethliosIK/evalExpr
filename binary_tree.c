/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   binary_tree.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchambar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/19 18:35:24 by tchambar          #+#    #+#             */
/*   Updated: 2017/08/20 21:14:05 by tchambar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "binary_tree.h"

t_bt		*bt_create_root(void *data, t_bt *left, t_bt *right)
{
	t_bt	*tree;

	tree = (t_bt *)malloc(sizeof(*tree));
	tree->data = data;
	tree->left = left;
	tree->right = right;
	return (tree);
}

t_bt		*bt_insert_number(t_bt *tree, int *nb)
{
	if (tree == NULL)
		return (bt_create_root(nb, NULL, NULL));
	if (tree->right == NULL && tree->left == NULL)
		return (tree);
	if (tree->right == NULL)
		tree->right = bt_create_root(nb, NULL, NULL);
	else
	{
		tree->left = (bt_insert_number(tree->left, nb));
		tree->right = (bt_insert_number(tree->right, nb));
	}
	return (tree);
}

t_bt		*bt_insert_operand(t_bt *tree, t_op *op)
{
	t_op	*current_op;

	if (tree->left == NULL && tree->right == NULL)
		return (bt_create_root(op, tree, NULL));
	current_op = (t_op *)(tree->data);
	if (current_op->priority >= op->priority)
		tree = bt_create_root(op, tree, NULL);
	else
		tree->right = bt_insert_operand(tree->right, op);
	return (tree);
}

int			bt_calc(t_bt *tree)
{
	t_op	*op;

	if (tree == NULL)
		return (0);
	if (tree->left == NULL && tree->right == NULL)
		return (*((int *)(tree->data)));
	op = (t_op *)(tree->data);
	return ((op->f)(bt_calc(tree->left), bt_calc(tree->right)));
}

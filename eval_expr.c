/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eval_expr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchambar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/19 18:09:00 by tchambar          #+#    #+#             */
/*   Updated: 2017/08/20 21:32:21 by tchambar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "eval_expr.h"

t_op g_operand_tab[] =
{
	{"+", &ft_add, 1},
	{"-", &ft_sub, 1},
	{"*", &ft_mul, 2},
	{"/", &ft_div, 2},
	{"%", &ft_mod, 2}
};

int		is_number(char *str)
{
	int i;

	i = 0;
	if (str == NULL)
		return (0);
	if (str[i] == '-')
	{
		if (str[i + 1] == '\0')
			return (0);
		i++;
	}
	while (str[i] != '\0')
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
		i++;
	}
	return (1);
}

void	search_op(char *str, t_bt **tree, int *bracket)
{
	t_op	*op;
	int		i;

	i = 0;
	while (i < NB_OPERAND)
	{
		if (ft_strcmp(str, g_operand_tab[i].name) == 0)
		{
			op = (t_op *)malloc(sizeof(*op));
			if (op == NULL)
				return ;
			op->name = g_operand_tab[i].name;
			op->f = g_operand_tab[i].f;
			op->priority = g_operand_tab[i].priority + *bracket;
			*tree = bt_insert_operand(*tree, op);
			break ;
		}
		i++;
	}
}

void	search_char(char *str, t_bt **tree, int *bracket)
{
	int		*nb;

	if (is_number(str))
	{
		nb = (int *)malloc(sizeof(*nb));
		*nb = ft_atoi(str);
		*tree = bt_insert_number(*tree, nb);
	}
	else if (str[0] == '(')
		*bracket += 2;
	else if (str[0] == ')')
		*bracket -= 2;
	else
	{
		search_op(str, tree, bracket);
	}
}

int		eval_expr(char *str)
{
	char	**tab;
	t_bt	*tree;
	int		bracket;
	int		result;
	int		j;

	tab = ft_split_whitespaces(str);
	bracket = 0;
	j = 0;
	tree = NULL;
	while (tab[j] != 0)
	{
		search_char(tab[j], &tree, &bracket);
		j++;
	}
	result = (bt_calc(tree));
	return (result);
}

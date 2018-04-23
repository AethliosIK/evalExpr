/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   binary_tree.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchambar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/20 12:48:30 by tchambar          #+#    #+#             */
/*   Updated: 2017/08/20 21:31:33 by tchambar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BINARY_TREE_H
# define BINARY_TREE_H

# include <stdlib.h>
# include "operand.h"

typedef struct		s_bt
{
	void		*data;
	struct s_bt	*left;
	struct s_bt	*right;
}					t_bt;

t_bt				*bt_insert_number(t_bt *tree, int *nb);

t_bt				*bt_insert_operand(t_bt *tree, t_op *op);

int					bt_calc(t_bt *tree);

#endif

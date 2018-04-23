/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eval_expr.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchambar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/20 13:53:55 by tchambar          #+#    #+#             */
/*   Updated: 2017/08/20 21:32:19 by tchambar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EVAL_EXPR_H
# define EVAL_EXPR_H

# include <stdlib.h>
# include "binary_tree.h"
# include "operand.h"
# include "ft_split_whitespaces.h"
# include "util.h"

# define NB_OPERAND 5

int		eval_expr(char *str);

#endif

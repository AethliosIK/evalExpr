/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operand.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchambar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/20 12:52:28 by tchambar          #+#    #+#             */
/*   Updated: 2017/08/20 21:32:45 by tchambar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OPERAND_H
# define OPERAND_H

typedef struct		s_op
{
	char	*name;
	int		(*f)(int, int);
	int		priority;
}					t_op;

int					ft_add(int a, int b);

int					ft_sub(int a, int b);

int					ft_mul(int a, int b);

int					ft_div(int a, int b);

int					ft_mod(int a, int b);

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchambar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/20 14:59:11 by tchambar          #+#    #+#             */
/*   Updated: 2017/08/20 15:08:26 by tchambar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTIL_H
# define UTIL_H

# include <unistd.h>
# include "ft_split_whitespaces.h"

int		ft_putchar(char c);

void	ft_putnbr(int nb);

int		ft_atoi(char *str);

int		ft_strcmp(char *s1, char *s2);

#endif

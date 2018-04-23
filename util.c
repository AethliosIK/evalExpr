/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchambar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/20 14:58:14 by tchambar          #+#    #+#             */
/*   Updated: 2017/08/20 21:33:02 by tchambar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "util.h"

int		ft_putchar(char c)
{
	write(1, &c, 1);
	return (0);
}

void	ft_putnbr_rec(int nb)
{
	if (nb > -10 && nb < 10)
	{
		if (nb < 0)
		{
			nb = -nb;
		}
		ft_putchar(nb + '0');
		return ;
	}
	ft_putnbr_rec(nb / 10);
	nb = (nb % 10);
	if (nb < 0)
	{
		nb = -nb;
	}
	ft_putchar(nb + '0');
}

void	ft_putnbr(int nb)
{
	if (nb < 0)
	{
		ft_putchar('-');
	}
	ft_putnbr_rec(nb);
}

int		ft_atoi(char *str)
{
	int nb;
	int sign;
	int i;

	sign = 1;
	nb = 0;
	i = 0;
	while (str[i] == ' ' || str[i] == '\t')
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	while (str[i] != '\0' && (str[i] >= '0' && str[i] <= '9'))
	{
		nb = nb * 10 + ((int)str[i] - '0');
		i++;
	}
	return (nb * sign);
}

int		ft_strcmp(char *s1, char *s2)
{
	if (*s1 == *s2)
	{
		if (*s1 == '\0')
		{
			return (0);
		}
		return (ft_strcmp((s1 + 1), (s2 + 1)));
	}
	return (*s1 - *s2);
}

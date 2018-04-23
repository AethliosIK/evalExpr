/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_withspaces.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchambar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/08 13:23:04 by tchambar          #+#    #+#             */
/*   Updated: 2017/08/20 21:32:36 by tchambar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		is_sep(char c)
{
	return (c == '\t' || c == '\n' || c == ' ');
}

int		word_len(char *str)
{
	int k;

	k = 0;
	while (str[k] != '\0' && !is_sep(str[k]))
		k++;
	return (k);
}

int		count_word(char *str)
{
	int k;

	k = 0;
	if (*str == '\0')
		return (0);
	while (is_sep(*str))
		str++;
	while (*str != '\0')
	{
		if (is_sep(*str))
		{
			k++;
			while (is_sep(*str))
				str++;
		}
		if (*str != '\0')
			str++;
	}
	return (k + 1);
}

char	*insert_wd_in_tab(char **tab, char *str)
{
	char *begin_wd;
	char *wd;

	begin_wd = (char *)malloc(sizeof(*begin_wd) * (word_len(str) + 1));
	wd = begin_wd;
	while (*str != '\0' && !is_sep(*str))
	{
		*wd = *str;
		wd++;
		str++;
	}
	*wd = '\0';
	*tab = begin_wd;
	return (str);
}

char	**ft_split_whitespaces(char *str)
{
	char **begin_tab;
	char **tab;

	begin_tab = (char **)malloc(sizeof(*begin_tab) * (count_word(str) + 1));
	tab = begin_tab;
	while (*str != '\0')
	{
		if (!is_sep(*str))
		{
			str = insert_wd_in_tab(tab, str);
			tab++;
		}
		if (*str != '\0')
			str++;
	}
	*tab = 0;
	return (begin_tab);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_builtin_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yictseng <yictseng@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/15 11:43:36 by yictseng          #+#    #+#             */
/*   Updated: 2020/10/31 13:19:43 by yictseng         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int		count_tab_str(char **tab)
{
	int i;

	i = 0;
	while (tab[i])
		i++;
	return (i);
}

int		search_char(char *str, char c)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (str[i] == c)
			return (i);
		i++;
	}
	return (-1);
}

int		is_valid_name(char *str, int assign)
{
	int i;

	i = 0;
	if (assign == 0)
		return (0);
	if (str[i] >= '0' && str[i] <= '9')
		return (0);
	while (i < assign && ((str[i] >= 'a' && str[i] <= 'z')
		|| (str[i] >= 'A' && str[i] <= 'Z')
		|| (str[i] >= '0' && str[i] <= '9')
		|| (str[i] == '_')))
		i++;
	if (i != assign)
		return (0);
	return (1);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_write_words.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yictseng <yictseng@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/18 16:44:12 by yictseng          #+#    #+#             */
/*   Updated: 2020/11/18 16:44:13 by yictseng         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	write_words(const char *str, int i, t_struct *box)
{
	write(1, str, i);
	box->value += i;
}

void	write_spaces(int nb, t_struct *box)
{
	int		i;

	i = 0;
	while (i < nb)
	{
		write(1, " ", 1);
		(box->value)++;
		i++;
	}
}

void	write_zeros(int nb, t_struct *box)
{
	int		i;

	i = 0;
	while (i < nb)
	{
		write(1, "0", 1);
		(box->value)++;
		i++;
	}
}

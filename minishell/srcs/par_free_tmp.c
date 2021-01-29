/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   par_free_tmp.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: terry <terry@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/31 19:24:46 by terry             #+#    #+#             */
/*   Updated: 2020/10/31 19:24:46 by terry            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

char		**ft_free_tmp(char **s, int idx)
{
	while (s[idx] != NULL && idx >= 0)
	{
		free(s[idx]);
		s[idx] = NULL;
		idx--;
	}
	free(s);
	s = NULL;
	return (NULL);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   par_get_value.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: terry <terry@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/31 19:24:35 by terry             #+#    #+#             */
/*   Updated: 2020/10/31 19:24:35 by terry            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

char		*ft_get_value(char *tmp, int i, t_node *env_lst)
{
	char	*dash;
	char	*value;

	dash = ft_strndup(tmp, i);
	if (dash)
	{
		value = ft_strdup(get_value_in_node(env_lst, dash));
		free(dash);
		dash = NULL;
		return (value);
	}
	return (NULL);
}

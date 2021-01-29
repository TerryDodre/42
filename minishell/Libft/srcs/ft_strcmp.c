/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yictseng <yictseng@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/18 16:42:38 by yictseng          #+#    #+#             */
/*   Updated: 2020/11/18 16:42:39 by yictseng         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int		ft_strcmp(const char *s1, const char *s2)
{
	size_t i;

	i = 0;
	if (s1 == NULL)
		return (0);
	if (s2 == NULL)
		return (0);
	while (s1[i] && s2[i] && s1[i] == s2[i])
		i++;
	if (s1[i] != s2[i])
		return (((unsigned char*)s1)[i] - ((unsigned char*)s2)[i]);
	return (0);
}

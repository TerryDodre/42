/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdodre <tdodre@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/08 16:36:06 by tdodre            #+#    #+#             */
/*   Updated: 2020/10/08 16:38:34 by tdodre           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*tmp;
	int		i;

	i = 0;
	if (!s || !f)
		return (NULL);
	if (!(tmp = ft_calloc(sizeof(char), (ft_strlen(s) + 1))))
		return (NULL);
	while (s[i])
	{
		tmp[i] = f(i, s[i]);
		++i;
	}
	return (tmp);
}

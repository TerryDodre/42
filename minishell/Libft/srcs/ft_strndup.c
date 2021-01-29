/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yictseng <yictseng@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/18 16:43:24 by yictseng          #+#    #+#             */
/*   Updated: 2020/11/18 16:43:25 by yictseng         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*ft_strndup(const char *s1, int len)
{
	int		i;
	char	*dst;

	i = 0;
	if (!(dst = (char *)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	while (s1[i] && i < len)
	{
		dst[i] = s1[i];
		i++;
	}
	dst[i] = '\0';
	return (dst);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yictseng <yictseng@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/18 16:42:49 by yictseng          #+#    #+#             */
/*   Updated: 2020/11/18 16:42:49 by yictseng         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*ft_strdup(const char *s1)
{
	char	*cpy;
	int		len;

	if (s1 == NULL)
		return (NULL);
	len = ft_strlen(s1) + 1;
	cpy = malloc(sizeof(char) * len);
	if (cpy == NULL)
		return (NULL);
	ft_strcpy(cpy, s1);
	return (cpy);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yictseng <yictseng@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/18 16:43:28 by yictseng          #+#    #+#             */
/*   Updated: 2020/11/18 16:43:29 by yictseng         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t i;
	size_t j;

	i = 0;
	j = 0;
	if (!*needle)
		return ((char *)haystack);
	if (ft_strlen((char *)haystack) < ft_strlen((char *)needle))
		return (0);
	while (haystack[i] && len--)
	{
		while ((haystack[i + j] == needle[j]) && (haystack[i + j] ||
					needle[j]) && (j <= len))
			j++;
		if (needle[j] == '\0')
			return ((char *)&haystack[i]);
		if (needle[j] != haystack[i])
			j = 0;
		i++;
	}
	return (0);
}

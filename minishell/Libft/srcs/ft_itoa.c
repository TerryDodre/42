/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yictseng <yictseng@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/18 16:40:29 by yictseng          #+#    #+#             */
/*   Updated: 2020/11/18 16:40:29 by yictseng         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

static int		len_nb(long n)
{
	int		len;

	len = 0;
	if (n == 0)
		len = 1;
	if (n < 0)
	{
		n = -n;
		len++;
	}
	while (n > 0)
	{
		n /= 10;
		len++;
	}
	return (len);
}

static char		*convert(char *str, long nb, int len)
{
	str[len--] = '\0';
	if (nb == 0)
	{
		str[0] = 48;
		return (str);
	}
	else if (nb < 0)
	{
		str[0] = '-';
		nb *= -1;
		while (len > 0)
		{
			str[len--] = 48 + (nb % 10);
			nb /= 10;
		}
	}
	else
	{
		while (len >= 0)
		{
			str[len--] = 48 + (nb % 10);
			nb /= 10;
		}
	}
	return (str);
}

char			*ft_itoa(int n)
{
	char	*str;
	long	nb;
	int		len;

	nb = n;
	len = len_nb(nb);
	str = malloc(sizeof(char) * (len + 1));
	if (str == NULL)
		return (NULL);
	return (convert(str, nb, len));
}

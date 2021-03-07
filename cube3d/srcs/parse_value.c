/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_value.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdodre <tdodre@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/15 13:19:30 by tdodre            #+#    #+#             */
/*   Updated: 2020/07/17 14:22:44 by tdodre           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cube.h"

char	*ft_dupcolor(char *parse)
{
	int		i;
	int		j;
	char	*dst;

	i = 0;
	j = 0;
	while (parse[i] == ' ' && parse[i])
		i++;
	if (!(dst = malloc(sizeof(char) * (ft_strlen(parse) - i + 1))))
		return (NULL);
	while (parse[i])
	{
		dst[j] = parse[i];
		i++;
		j++;
	}
	dst[j] = '\0';
	return (dst);
}

char	*ft_duptexture(char *parse)
{
	int		i;
	int		j;
	char	*dst;

	i = 0;
	j = 0;
	while (parse[i] == ' ' && parse[i])
		i++;
	if (!(dst = malloc(sizeof(char) * (ft_strlen(parse) - i + 1))))
		return (NULL);
	while (parse[i])
	{
		dst[j] = parse[i];
		i++;
		j++;
	}
	dst[j] = '\0';
	return (dst);
}

int		ft_parse_texture(t_parsing *p, char *parse)
{
	if (!parse)
		return (-1);
	if (parse[0] == 'N' && parse[1] == 'O')
		p->no = ft_duptexture(parse + 2);
	else if (parse[0] == 'S' && parse[1] == 'O')
		p->so = ft_duptexture(parse + 2);
	else if (parse[0] == 'W' && parse[1] == 'E')
		p->we = ft_duptexture(parse + 2);
	else if (parse[0] == 'E' && parse[1] == 'A')
		p->ea = ft_duptexture(parse + 2);
	else if (parse[0] == 'S')
		p->sprite = ft_duptexture(parse + 1);
	else if (parse[0] == 'F')
		p->f = ft_dupcolor(parse + 1);
	else if (parse[0] == 'C')
		p->c = ft_dupcolor(parse + 1);
	else
		return (-1);
	free(parse);
	parse = 0;
	return (0);
}

int		ft_check_end_res(char *parse, int i)
{
	while (parse[i] >= '0' && parse[i] <= '9')
		i++;
	if (parse[i] != '\0')
		return (-1);
	return (0);
}

int		ft_parse_resolution(t_parsing *p, char *parse)
{
	int		i;

	i = 0;
	if (!parse)
		return (-1);
	while (parse[i] == ' ' || parse[i] == 'R')
		i++;
	if (parse[i] >= '0' && parse[i] <= '9')
		p->width = ft_atoi(i, parse);
	else
		return (-1);
	while (parse[i] >= '0' && parse[i] <= '9')
		i++;
	while (parse[i] == ' ')
		i++;
	if (parse[i] >= '0' && parse[i] <= '9')
		p->height = ft_atoi(i, parse);
	else
		return (-1);
	if (ft_check_end_res(parse, i) == -1)
		return (-1);
	free(parse);
	parse = 0;
	return (1);
}

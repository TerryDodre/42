/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_absolute_path.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: terry <terry@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/31 19:25:31 by terry             #+#    #+#             */
/*   Updated: 2020/11/25 15:37:16 by terry            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

char		*tmp_is_path(char **cmd, char **path_split, char *tmp)
{
	int			i;
	struct stat	sb;

	i = 0;
	while (path_split[i])
	{
		tmp = (char *)ft_calloc(sizeof(char), (ft_strlen(path_split[i])
			+ 1 + ft_strlen(cmd[0]) + 1));
		if (tmp == NULL)
			return (tmp);
		ft_strcat(tmp, path_split[i]);
		ft_strcat(tmp, "/");
		ft_strcat(tmp, cmd[0]);
		if (stat(tmp, &sb) == 0)
			return (tmp);
		free(tmp);
		tmp = NULL;
		i++;
	}
	return (tmp);
}

void		get_absolute_path(char **cmd, t_node *env_lst)
{
	char		*path;
	char		*tmp;
	char		**path_split;
	struct stat	sb;

	path = ft_strdup(get_value_in_node(env_lst, "PATH"));
	if (path != NULL)
	{
		if (cmd[0][0] != '/' && ft_strncmp(cmd[0], "./", 2) != 0)
		{
			path_split = ft_split(path, ':');
			tmp = tmp_is_path(cmd, path_split, tmp);
			ft_free_tab(&path_split);
			free(cmd[0]);
			cmd[0] = tmp;
		}
		free(path);
		path = NULL;
	}
	else if (stat(cmd[0], &sb) != 0)
	{
		free(cmd[0]);
		cmd[0] = NULL;
	}
}

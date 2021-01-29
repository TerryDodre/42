/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   launch_pwd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yictseng <yictseng@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/15 11:42:23 by yictseng          #+#    #+#             */
/*   Updated: 2020/10/31 14:01:59 by yictseng         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	launch_pwd(void)
{
	char	*pwd;
	char	buff[4096 + 1];

	pwd = getcwd(buff, 4096);
	ft_putendl_fd(pwd, 1);
}

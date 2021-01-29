/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: terry <terry@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/18 16:37:14 by yictseng          #+#    #+#             */
/*   Updated: 2020/11/27 15:15:08 by terry            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdio.h>
# include <stdlib.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <sys/stat.h>
# include <unistd.h>
# include <fcntl.h>
# include <string.h>
# include <signal.h>
# include <stdbool.h>
# include <limits.h>
# include "../Libft/libft.h"

/*
** ENVIRONMENT VARIABLES
*/
typedef	struct		s_pair
{
	char			*name;
	char			*value;
}					t_pair;

typedef struct		s_node
{
	t_pair			*content;
	struct s_node	*previous;
	struct s_node	*head;
	struct s_node	*next;
}					t_node;

/*
** BUILT-INS
*/
int					is_builtin_exist(char *cmd);
void				exec_builtin(char **cmd, t_node **env_list, int index);
void				launch_env(t_node *env_lst);
void				launch_echo(char **cmd, t_node *env_lst);
void				launch_pwd(void);
void				launch_cd(char **cmd, t_node **env_lst);
void				launch_export(char **cmd, t_node **env_lst);
void				sort_export_env(t_node *env_lst);
void				launch_unset(char **cmd, t_node **env_lst);
void				launch_exit(char **cmd);
int					g_exit_out;
/*
** LINKED LIST UTILS
*/
t_node				*create_env_lst(char **sys_env);
t_node				*ft_new_env_node(char *str);
t_node				*ft_new_node(char *name, char *value);
t_node				*ft_nodelast(t_node *lst);
t_node				*ft_node_find(t_node *env_lst, int order);
int					ft_nodeadd_back(t_node **alst, t_node *new);
void				ft_clear_nodelst(t_node **env_lst);
char				*get_value_in_node(t_node *env_lst, char *str);
int					search_name(t_node *env_lst, char *str);
int					ft_nodesize(t_node *lst);
void				delete_node(t_node **env_lst, int name_order);
void				modify_node_content_value(t_node *env_lst, int order,
												char *value);
void				modify_node_content(t_node *env_lst, int order, char *name,
												char *value);
int					ft_nodeadd_middle(t_node **alst, t_node *new);
int					add_pwd_node(t_node **env_lst);
int					check_env_lst(t_node **env_lst);
char				**put_lst_to_tab(t_node *env_lst);
/*
** STRING UTILS
*/
int					count_tab_str(char **tab);
int					search_char(char *str, char c);
int					is_valid_name(char *str, int assign);
int					get_next_line(int fd, char **line);
/*
** PROMPT
*/
char				*g_path_prompt;
int					g_exit_status;
int					g_signal_status;
void				get_absolute_path(char **cmd, t_node *env_lst);
int					prompt_command_not_found(char *buffer);
void				prompt_wait_command(t_node *env_lst);
/*
**START PARSING
*/
char				**ft_parsing(char *buffer, t_node *env_lst);
char				*ft_get_cmd(char *buffer, t_node *env_lst, int len);
int					ft_size_cmd(char *buffer, t_node *env_lst);
int					jump_quote_dollar(char *s, t_node *env_lst);
int					jump_quote(char *s);
char				*ft_get_value(char *tmp, int i, t_node *env_lst);
int					ft_check_semicolon(char *s);
int					ft_check_redir(char *s);
int					ft_check_pipe(char *s);
char				**ft_free_tmp(char **s, int idx);
char				**cmd_without_quote(char **tmp);
char				**ft_split_cmd(char *s);
void				ft_ini_get_cmd(int *i, int *d_quote, char **buffer);
int					ft_error_quote(char *s);
/*
**START COMMAND
*/
void				exec_command(char **cmd, t_node **env_lst);
void				exec_pipe(char **cmd, int a, t_node **env_lst);
void				exec_redir(char **cmd, int a, t_node **env_lst);
void				check_behind(char **cmd, int a, int fd, t_node **env_lst);
char				**get_cmd_redir(char **cmd, char c);
void				exec_in_redir(char **cmd, int fd, t_node **env_lst,
									pid_t pid);
void				exec_out_redir(char **cmd, int fd, t_node **env_lst,
									pid_t pid);
void				pipe_exit(char **cmd);
/*
**END
*/
void				signal_control(int signo);
void				ft_exit(char *buffer, t_node **env_lst);
#endif

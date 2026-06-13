/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zshkukan <zshkukan@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/09 01:17:50 by issa              #+#    #+#             */
/*   Updated: 2026/04/29 21:24:22 by zshkukan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXECUTION_H
# define EXECUTION_H

char	*get_cmd_path(char **env, char *cmd);
char	**set_env(char **env, char *key, char *val);
char	**add_env(char **env, char *key, char *val);
void	free_env(char **env);
void	reset_shell_signals(void);
void	set_child_exec_signals(void);
void	set_parent_exec_signals(void);
void	print_exp_list(t_shell *data);
void	handle_interrupt_signal(int sig);
void	exec_cmd(t_shell *data, t_cmd *cmd);
void	exec_pipe(t_shell *data, t_cmd *cmd);
void	external_cmd(t_shell *data, t_cmd *cmd);
void	child_status(t_shell *data, int status);
int		ft_echo(char **av);
int		ft_env(t_shell *data);
int		ft_pwd(t_shell *data);
int		ft_cd(t_shell *data, char **av);
int		ft_exit(t_shell *data, char **av);
int		ft_unset(t_shell *data, char **av);
int		ft_export(t_shell *data, char **av);
int		exec_builtin(t_shell *data, char **av);
int		handle_empty_cmd(t_shell *data, t_cmd *cmd);
int		create_next_pipe(t_shell *data, t_cmd *cmd, int *p_pipe, int fd[2]);
int		handle_fork_error(t_shell *data, t_cmd *cmd, int *p_pipe, int fd[2]);
#endif

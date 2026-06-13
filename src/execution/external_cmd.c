/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   external_cmd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: issa <issa@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/14 02:30:00 by  iabiesat         #+#    #+#             */
/*   Updated: 2026/04/29 02:53:37 by issa             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

static int	path_access(char *path, char *cmd)
{
	DIR	*dir;

	dir = opendir(path);
	if (dir)
	{
		closedir(dir);
		ft_putstr_fd(cmd, 2);
		ft_putendl_fd(": Is a directory", 2);
		return (126);
	}
	if (access(path, X_OK) == -1)
	{
		ft_putstr_fd(cmd, 2);
		ft_putendl_fd(": Permission denied", 2);
		return (126);
	}
	return (0);
}

int	handle_empty_cmd(t_shell *data, t_cmd *cmd)
{
	if (cmd->args[0] == NULL)
	{
		data->exit_status = 0;
		return (1);
	}
	if (cmd->args[0][0] == '\0')
	{
		ft_putstr_fd("minishell: : command not found\n", 2);
		data->exit_status = 127;
		return (1);
	}
	return (0);
}

static void	h_child(t_shell *data, t_cmd *cmd, char *path)
{
	set_child_exec_signals();
	if (redirec(cmd->redirs) == 1)
	{
		free(path);
		free_shell(data);
		exit(1);
	}
	if (path_access(path, cmd->args[0]) != 0)
	{
		free(path);
		free_shell(data);
		exit(126);
	}
	if (execve(path, cmd->args, data->envp_shell) == -1)
	{
		perror(cmd->args[0]);
		free(path);
		free_shell(data);
		exit(1);
	}
}

static void	fork_and_execute(t_shell *data, t_cmd *cmd, char *path)
{
	int	pid;
	int	status;

	set_parent_exec_signals();
	pid = fork();
	if (pid == 0)
		h_child(data, cmd, path);
	else if (pid > 0)
	{
		waitpid(pid, &status, 0);
		child_status(data, status);
	}
	else
	{
		perror("fork");
		data->exit_status = 1;
	}
}

void	external_cmd(t_shell *data, t_cmd *cmd)
{
	char	*path;

	if (handle_empty_cmd(data, cmd))
		return ;
	path = get_cmd_path(data->envp_shell, cmd->args[0]);
	if (!path)
	{
		ft_putstr_fd(cmd->args[0], 2);
		if (ft_strchr(cmd->args[0], '/'))
			ft_putendl_fd(": No such file or directory", 2);
		else
			ft_putendl_fd(": command not found", 2);
		data->exit_status = 127;
		return ;
	}
	fork_and_execute(data, cmd, path);
	free(path);
	reset_shell_signals();
}

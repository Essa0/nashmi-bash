/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_pipe.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iabiesat <iabiesat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/19 16:05:12 by  iabiesat         #+#    #+#             */
/*   Updated: 2026/04/30 18:11:44 by iabiesat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

static void	setup_child_pipe(int prev_pipe, int fd[2], t_cmd *cmd)
{
	signal(SIGPIPE, SIG_IGN);
	set_child_exec_signals();
	if (prev_pipe != -1)
	{
		dup2(prev_pipe, STDIN_FILENO);
		close(prev_pipe);
	}
	if (cmd->next)
	{
		dup2(fd[1], STDOUT_FILENO);
		close(fd[1]);
		close(fd[0]);
	}
}

static void	handle_parent_pipe(int *prev_pipe, int fd[2], t_cmd *cmd)
{
	if (*prev_pipe != -1)
	{
		close(*prev_pipe);
		*prev_pipe = -1;
	}
	if (cmd->next)
	{
		close(fd[1]);
		*prev_pipe = fd[0];
	}
	else
		*prev_pipe = -1;
}

static void	exec_pipe_child(t_shell *data, t_cmd *cmd, int prev_pipe, int fd[2])
{
	int	child_status;

	setup_child_pipe(prev_pipe, fd, cmd);
	if (redirec(cmd->redirs) == 1)
	{
		free_shell(data);
		exit(1);
	}
	data->in_pipe = 1;
	exec_cmd(data, cmd);
	child_status = data->exit_status;
	free_shell(data);
	exit(child_status);
}

static pid_t	pipe_loop(t_shell *data, t_cmd *cmd, int *prev_pipe)
{
	pid_t	pid;
	pid_t	last_pid;
	t_cmd	*temp;
	int		fd[2];

	temp = cmd;
	last_pid = -1;
	while (temp)
	{
		if (create_next_pipe(data, temp, prev_pipe, fd) == -1)
			return (-1);
		pid = fork();
		if (pid < 0)
			return (handle_fork_error(data, temp, prev_pipe, fd));
		if (pid == 0)
			exec_pipe_child(data, temp, *prev_pipe, fd);
		last_pid = pid;
		handle_parent_pipe(prev_pipe, fd, temp);
		temp = temp->next;
	}
	return (last_pid);
}

void	exec_pipe(t_shell *data, t_cmd *cmd)
{
	int		prev_pipe;
	int		status;
	pid_t	last_pid;

	prev_pipe = -1;
	set_parent_exec_signals();
	last_pid = pipe_loop(data, cmd, &prev_pipe);
	if (last_pid == -1)
		return ;
	waitpid(last_pid, &status, 0);
	child_status(data, status);
	while (wait(&status) > 0)
		;
	reset_shell_signals();
}

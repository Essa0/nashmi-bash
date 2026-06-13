/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: issa <issa@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/27 17:05:00 by issa              #+#    #+#             */
/*   Updated: 2026/04/27 23:42:46 by issa             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	set_parent_exec_signals(void)
{
	signal(SIGINT, SIG_IGN);
	signal(SIGQUIT, SIG_IGN);
}

void	set_child_exec_signals(void)
{
	signal(SIGINT, SIG_DFL);
	signal(SIGQUIT, SIG_DFL);
}

void	reset_shell_signals(void)
{
	signal(SIGINT, handle_interrupt_signal);
	signal(SIGQUIT, SIG_IGN);
	g_signal = 0;
}

int	handle_fork_error(t_shell *data, t_cmd *cmd, int *p_pipe, int fd[2])
{
	perror("fork");
	if (cmd->next)
	{
		close(fd[0]);
		close(fd[1]);
	}
	if (*p_pipe != -1)
	{
		close(*p_pipe);
		*p_pipe = -1;
	}
	data->exit_status = 1;
	return (-1);
}

int	create_next_pipe(t_shell *data, t_cmd *cmd, int *p_pipe, int fd[2])
{
	if (!cmd->next)
		return (0);
	if (pipe(fd) == -1)
	{
		perror("pipe");
		if (*p_pipe != -1)
		{
			close(*p_pipe);
			*p_pipe = -1;
		}
		data->exit_status = 1;
		return (-1);
	}
	return (0);
}

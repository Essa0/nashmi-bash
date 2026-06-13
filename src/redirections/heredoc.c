/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zshkukan <zshkukan@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/29 21:09:38 by zshkukan          #+#    #+#             */
/*   Updated: 2026/04/30 10:52:02 by zshkukan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

static int	read_loop(char *line, int fd, char *del, int saved_stdin)
{
	while (1)
	{
		line = readline("> ");
		if (g_signal == SIGINT)
		{
			free(line);
			line = NULL;
			write(1, "\n", 1);
			close(fd);
			dup2(saved_stdin, STDIN_FILENO);
			close(saved_stdin);
			g_signal = 130;
			break ;
		}
		if (!line)
			return (1);
		if (ft_strcmp(line, del) == 0)
		{
			free(line);
			break ;
		}
		ft_putendl_fd(line, fd);
	}
	return (0);
}

static int	heredoc(char *del)
{
	char	*line;
	int		fd;
	int		saved_stdin;
	int		error;

	line = NULL;
	saved_stdin = dup(STDIN_FILENO);
	fd = open(".temp_heredoc", O_CREAT | O_WRONLY | O_TRUNC, 0644);
	if (fd == -1)
	{
		close(saved_stdin);
		return (1);
	}
	error = read_loop(line, fd, del, saved_stdin);
	if (error == 1)
		print_error(del);
	close(fd);
	dup2(saved_stdin, STDIN_FILENO);
	close(saved_stdin);
	if (g_signal == 130)
		return (1);
	return (0);
}

static int	single_heredoc(t_redir *red)
{
	int	i;

	if (!red)
		return (0);
	i = 0;
	while (red[i].file)
	{
		if (red[i].type == TOKEN_HEREDOC)
		{
			if (heredoc(red[i].file) == 1)
				return (1);
			red[i].type = TOKEN_REDIR_IN;
			free(red[i].file);
			red[i].file = ft_strdup(".temp_heredoc");
			if (!red[i].file)
				return (1);
		}
		i++;
	}
	return (0);
}

int	handle_heredoc(t_cmd *cmd, t_shell *shell)
{
	t_cmd	*temp_cmd;

	(void)shell;
	if (!cmd)
		return (1);
	g_signal = 0;
	setup_heredoc_signals();
	temp_cmd = cmd;
	while (temp_cmd)
	{
		if (single_heredoc(temp_cmd->redirs) == 1)
		{
			g_signal = 0;
			shell->exit_status = 130;
			setup_interactive_signals();
			return (1);
		}
		temp_cmd = temp_cmd->next;
	}
	setup_interactive_signals();
	return (0);
}

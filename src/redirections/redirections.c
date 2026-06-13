/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirections.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iabiesat <iabiesat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/29 21:09:44 by zshkukan          #+#    #+#             */
/*   Updated: 2026/04/30 18:23:35 by iabiesat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

static int	redir_i(char *file)
{
	int	fd;

	fd = open(file, O_RDONLY);
	if (fd == -1)
	{
		perror("minishell");
		return (1);
	}
	dup2(fd, STDIN_FILENO);
	close(fd);
	return (0);
}

static int	redir_o(char *file)
{
	int	fd;

	fd = open(file, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (fd == -1)
	{
		perror("minishell");
		return (1);
	}
	dup2(fd, STDOUT_FILENO);
	close(fd);
	return (0);
}

static int	redir_a(char *file)
{
	int	fd;

	fd = open(file, O_WRONLY | O_CREAT | O_APPEND, 0644);
	if (fd == -1)
	{
		perror("minishell");
		return (1);
	}
	dup2(fd, STDOUT_FILENO);
	close(fd);
	return (0);
}

int	redirec(t_redir *re)
{
	int	i;

	if (!re)
		return (0);
	i = 0;
	while (re[i].file)
	{
		if (re[i].type == TOKEN_REDIR_IN)
		{
			if (redir_i(re[i].file) == 1)
				return (1);
		}
		else if (re[i].type == TOKEN_REDIR_OUT)
		{
			if (redir_o(re[i].file) == 1)
				return (1);
		}
		else if (re[i].type == TOKEN_REDIR_APPEND)
		{
			if (redir_a(re[i].file) == 1)
				return (1);
		}
		i++;
	}
	return (0);
}

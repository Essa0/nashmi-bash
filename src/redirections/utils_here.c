/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_here.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zshkukan <zshkukan@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/29 20:14:19 by zshkukan          #+#    #+#             */
/*   Updated: 2026/04/29 20:14:23 by zshkukan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	heredoc_sigint(int sig)
{
	(void)sig;
	g_signal = SIGINT;
	close(STDIN_FILENO);
	signal(SIGINT, SIG_DFL);
	rl_on_new_line();
}

void	setup_heredoc_signals(void)
{
	signal(SIGINT, heredoc_sigint);
	signal(SIGQUIT, SIG_IGN);
}

void	print_error(char *del)
{
	ft_printf("minishell: warning: here-document ");
	ft_printf("at line 1 delimited by end-of-file");
	ft_printf("%s%s%s\n", " (wanted `", del, "')");
}

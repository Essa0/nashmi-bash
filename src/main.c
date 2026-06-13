/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iabiesat <iabiesat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/29 20:12:51 by zshkukan          #+#    #+#             */
/*   Updated: 2026/05/10 16:35:04 by iabiesat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void	handle_interrupt_signal(int sigg)
{
	(void)sigg;
	write(1, "\n", 1);
	rl_on_new_line();
	rl_replace_line("", 0);
	rl_redisplay();
	g_signal = 130;
}

void	setup_interactive_signals(void)
{
	signal(SIGINT, handle_interrupt_signal);
	signal(SIGQUIT, SIG_IGN);
}

int	main(int argc, char **argv, char **envp)
{
	int		status;
	t_shell	*shell_m;

	(void)argv;
	if (argc != 1)
		return (1);
	setup_interactive_signals();
	shell_m = init_shell(envp);
	if (!shell_m)
		return (0);
	status = shell(shell_m);
	return (status);
}

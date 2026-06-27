/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: issa <issa@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/29 20:12:51 by zshkukan          #+#    #+#             */
/*   Updated: 2026/06/13 16:10:09 by issa             ###   ########.fr       */
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

void print_welcome_header(void)
{
	ft_putstr_fd("\033[1;36m", 1);
    ft_putendl_fd(" _   _           _ 			  _               _     ", 1);
    ft_putendl_fd("| \\ | | ___  ___| |__  _ __ ___ (_)      | |__   __ _ ___| |__  ", 1);
    ft_putendl_fd("|  \\| |/ _ \\/ __| '_ \\| '_ ` _ \\| |_____ | '_ \\ / _` / __| '_ \\ ", 1);
    ft_putendl_fd("| |\\  | (_| \\__ \\ | | | | | | | | |_____|| |_) | (_| \\__ \\ | | |", 1);
    ft_putendl_fd("|_| \\_|\\__,_|___/_| |_|_| |_| |_|_|      |_.__/ \\__,_|___/_| |_|", 1);
    ft_putstr_fd("\033[0m", 1);

    ft_putstr_fd("\033[1;32m", 1); 
    ft_putendl_fd("        Welcome to Nashmi-bash! Built by iabiesat & zshkuan\n", 1);
    ft_putstr_fd("\033[0m", 1); 
}

int	main(int argc, char **argv, char **envp)
{
	int		status;
	t_shell	*shell_m;

	(void)argv;
	if (argc != 1)
		return (1);
	print_welcome_header();
	setup_interactive_signals();
	shell_m = init_shell(envp);
	if (!shell_m)
		return (0);
	status = shell(shell_m);
	return (status);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iabiesat <iabiesat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/29 20:20:20 by zshkukan          #+#    #+#             */
/*   Updated: 2026/04/30 18:25:46 by iabiesat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

int			g_signal = 0;

static int	is_builtin(char *cmd)
{
	if (!cmd)
		return (0);
	if (ft_strcmp(cmd, "echo") == 0 || ft_strcmp(cmd, "cd") == 0
		|| ft_strcmp(cmd, "pwd") == 0 || ft_strcmp(cmd, "export") == 0
		|| ft_strcmp(cmd, "unset") == 0 || ft_strcmp(cmd, "env") == 0
		|| ft_strcmp(cmd, "exit") == 0)
		return (1);
	return (0);
}

static void	core_layer(t_shell *shell, t_cmd *cmds)
{
	int	saved_out;
	int	saved_in;
	int	check_builtin;

	if (cmds->next)
		exec_pipe(shell, cmds);
	else
	{
		check_builtin = is_builtin(cmds->args[0]);
		if (check_builtin == 1)
		{
			saved_in = dup(STDIN_FILENO);
			saved_out = dup(STDOUT_FILENO);
			if (redirec(cmds->redirs) == 0)
				exec_cmd(shell, cmds);
			else
				shell->exit_status = 1;
			dup2(saved_out, STDOUT_FILENO);
			dup2(saved_in, STDIN_FILENO);
			close(saved_in);
			close(saved_out);
		}
		else
			external_cmd(shell, cmds);
	}
}

static void	command_mod(t_shell *shell)
{
	expand_all(&shell->tokens, shell);
	if (check_syntax(shell->tokens, shell) == 1)
	{
		free_token_list(shell->tokens);
		free_shell_partial(shell);
		return ;
	}
	shell->commands = parsing(shell->tokens);
	if (!shell->commands)
	{
		shell->exit_status = 0;
		free_token_list(shell->tokens);
		return ;
	}
	free_token_list(shell->tokens);
	shell->tokens = NULL;
	if (handle_heredoc(shell->commands, shell) == 0)
		core_layer(shell, shell->commands);
	unlink(".temp_heredoc");
	setup_interactive_signals();
	free_shell_partial(shell);
}

static void	preparing_line(t_shell *shell)
{
	if (history_add(shell->line_input) == 1)
	{
		free_shell_partial(shell);
		return ;
	}
	if (check_required(shell, shell->line_input) == 1)
	{
		free_shell_partial(shell);
		return ;
	}
	shell->tokens = tokenization(shell->line_input);
	if (!shell->tokens)
	{
		free_shell_partial(shell);
		return ;
	}
	if (check_syntax(shell->tokens, shell) == 1)
	{
		free_token_list(shell->tokens);
		free_shell_partial(shell);
		return ;
	}
	command_mod(shell);
}

int	shell(t_shell *shell)
{
	char	*line;
	int		ex;

	while (1)
	{
		line = readline(PROMPT);
		if (g_signal == 130)
		{
			shell->exit_status = 130;
			g_signal = 0;
		}
		if (!line)
			break ;
		shell->line_input = ft_strdup(line);
		free(line);
		preparing_line(shell);
		if (shell->should_exit)
			break ;
	}
	if (!shell->should_exit)
		write(1, "exit\n", 5);
	ex = shell->exit_status;
	free_string_array(shell->envp_shell);
	free(shell);
	return (ex);
}

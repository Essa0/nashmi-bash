/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_minishell.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zshkukan <zshkukan@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/29 20:15:39 by zshkukan          #+#    #+#             */
/*   Updated: 2026/04/29 20:15:41 by zshkukan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	free_string_array(char **arr)
{
	int	i;

	if (!arr)
		return ;
	i = 0;
	while (arr[i])
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}

static void	free_redir_array(t_redir *redirs)
{
	int	i;

	if (!redirs)
		return ;
	i = 0;
	while (redirs[i].file)
	{
		free(redirs[i].file);
		i++;
	}
	free(redirs);
}

static void	free_commands(t_cmd *cmd)
{
	t_cmd	*temp;
	t_cmd	*next;

	if (!cmd)
		return ;
	temp = cmd;
	while (temp)
	{
		next = temp->next;
		if (temp->args)
			free_string_array(temp->args);
		if (temp->types)
			free(temp->types);
		if (temp->redirs)
			free_redir_array(temp->redirs);
		free(temp);
		temp = next;
	}
}

void	free_shell(t_shell *shell)
{
	if (!shell)
		return ;
	if (shell->line_input)
	{
		free(shell->line_input);
		shell->line_input = NULL;
	}
	if (shell->envp_shell)
	{
		free_string_array(shell->envp_shell);
		shell->envp_shell = NULL;
	}
	if (shell->commands)
	{
		free_commands(shell->commands);
		shell->commands = NULL;
	}
	free(shell);
	rl_clear_history();
}

void	free_shell_partial(t_shell *shell)
{
	if (!shell)
		return ;
	if (shell->line_input)
	{
		free(shell->line_input);
		shell->line_input = NULL;
	}
	if (shell->commands)
	{
		free_commands(shell->commands);
		shell->commands = NULL;
	}
}

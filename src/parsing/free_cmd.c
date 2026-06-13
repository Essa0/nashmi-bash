/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_cmd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zshkukan <zshkukan@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/29 20:15:12 by zshkukan          #+#    #+#             */
/*   Updated: 2026/04/29 20:15:14 by zshkukan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	free_args(t_cmd *cmd)
{
	int	i;

	if (!cmd || !cmd->args)
		return ;
	i = 0;
	while (cmd->args[i])
	{
		free(cmd->args[i]);
		i++;
	}
	free(cmd->args);
	cmd->args = NULL;
	if (cmd->types)
	{
		free(cmd->types);
		cmd->types = NULL;
	}
}

static void	free_redirs(t_cmd *cmd)
{
	int	i;

	if (!cmd || !cmd->redirs)
		return ;
	i = 0;
	while (cmd->redirs[i].file)
	{
		free(cmd->redirs[i].file);
		i++;
	}
	free(cmd->redirs);
	cmd->redirs = NULL;
}

void	free_cmd(t_cmd **cmd)
{
	t_cmd	*current;
	t_cmd	*next;

	if (!cmd || !*cmd)
		return ;
	current = *cmd;
	while (current != NULL)
	{
		next = current->next;
		free_args(current);
		free_redirs(current);
		free(current);
		current = next;
	}
	*cmd = NULL;
}

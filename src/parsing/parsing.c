/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zshkukan <zshkukan@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/29 20:15:20 by zshkukan          #+#    #+#             */
/*   Updated: 2026/04/29 20:15:22 by zshkukan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

static void	skip_p(t_nodes **current)
{
	while (*current)
	{
		if ((*current)->data->type == TOKEN_PIPE)
		{
			*current = (*current)->next;
			break ;
		}
		*current = (*current)->next;
	}
}

static t_cmd	*free_parse_cmd(t_cmd *cmd)
{
	if (!cmd)
		return (NULL);
	if (cmd->args)
		free(cmd->args);
	if (cmd->types)
		free(cmd->types);
	if (cmd->redirs)
		free(cmd->redirs);
	free(cmd);
	return (NULL);
}

static t_cmd	*parse_command(t_nodes **start)
{
	t_cmd	*clear_cmd;

	clear_cmd = ft_calloc(1, sizeof(t_cmd));
	if (!clear_cmd)
		return (NULL);
	build_cmd(*start, &clear_cmd);
	if (!clear_cmd->args || !clear_cmd->types)
		return (free_parse_cmd(clear_cmd));
	clear_cmd->next = NULL;
	skip_p(start);
	return (clear_cmd);
}

t_cmd	*parsing(t_nodes *head_t)
{
	t_cmd	*cmd_head;
	t_cmd	*temp;
	t_cmd	*new_cmd;
	t_nodes	*current;

	if (!head_t)
		return (NULL);
	current = head_t;
	cmd_head = NULL;
	temp = NULL;
	while (current)
	{
		new_cmd = parse_command(&current);
		if (!new_cmd)
		{
			free_cmd(&cmd_head);
			return (NULL);
		}
		if (!cmd_head)
			cmd_head = new_cmd;
		else
			temp->next = new_cmd;
		temp = new_cmd;
	}
	return (cmd_head);
}

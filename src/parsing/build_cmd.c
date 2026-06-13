/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_cmd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zshkukan <zshkukan@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/29 21:09:58 by zshkukan          #+#    #+#             */
/*   Updated: 2026/04/30 10:50:18 by zshkukan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

static int	init_cmd(t_nodes *start, t_cmd **cmd)
{
	if (alloc_args_types(start, cmd))
		return (1);
	if (alloc_redirs(start, cmd))
		return (1);
	return (0);
}

static void	set_value(t_nodes *node, int *ai, int *ri, t_cmd **cmd)
{
	t_nodes	*temp;

	temp = NULL;
	if (node->data->type >= 0 && node->data->type <= 2)
	{
		(*cmd)->args[*ai] = ft_strdup(node->data->value);
		(*cmd)->types[*ai] = node->data->type;
		(*ai)++;
	}
	if (node->data->type >= 4 && node->data->type <= 7)
	{
		if (!node->next || node->next->data->type == TOKEN_PIPE)
			return ;
		(*cmd)->redirs[*ri].type = node->data->type;
		temp = node->next;
		(*cmd)->redirs[*ri].file = ft_strdup(temp->data->value);
		(*ri)++;
	}
}

static int	handle_redir_step(t_nodes **temp)
{
	if ((*temp)->data->type < TOKEN_REDIR_IN
		|| (*temp)->data->type > TOKEN_HEREDOC)
		return (0);
	if (!(*temp)->next || (*temp)->next->data->type == TOKEN_PIPE)
		return (1);
	*temp = (*temp)->next->next;
	return (2);
}

void	build_cmd(t_nodes *start, t_cmd **cmd)
{
	t_nodes	*temp;
	int		ai;
	int		ri;
	int		step;

	if (init_cmd(start, cmd) == 1)
		return ;
	temp = start;
	ai = 0;
	ri = 0;
	while (temp != NULL)
	{
		if (temp->data->type == TOKEN_PIPE)
			break ;
		set_value(temp, &ai, &ri, cmd);
		step = handle_redir_step(&temp);
		if (step == 1)
			break ;
		if (step == 2)
			continue ;
		temp = temp->next;
	}
	(*cmd)->args[ai] = NULL;
	(*cmd)->types[ai] = 0;
}

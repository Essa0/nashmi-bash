/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bulid_cmd1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zshkukan <zshkukan@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/30 10:50:40 by zshkukan          #+#    #+#             */
/*   Updated: 2026/04/30 10:59:30 by zshkukan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int	num_args(t_nodes *start)
{
	t_nodes	*temp;
	int		i;

	temp = start;
	i = 0;
	while (temp != NULL)
	{
		if (temp->data->type == TOKEN_PIPE)
			break ;
		if (temp->data->type >= 4 && temp->data->type <= 7)
		{
			if (!temp->next || temp->next->data->type == TOKEN_PIPE)
				break ;
			temp = temp->next->next;
			continue ;
		}
		i++;
		temp = temp->next;
	}
	return (i);
}

int	num_redir(t_nodes *start)
{
	t_nodes	*temp;
	int		i;

	i = 0;
	temp = start;
	while (temp != NULL)
	{
		if (temp->data->type == TOKEN_PIPE)
			break ;
		if (temp->data->type >= 4 && temp->data->type <= 7)
			i++;
		temp = temp->next;
	}
	return (i);
}

int	alloc_args_types(t_nodes *start, t_cmd **cmd)
{
	int	na;

	na = num_args(start);
	(*cmd)->args = ft_calloc(na + 1, sizeof(char *));
	(*cmd)->types = ft_calloc(na + 1, sizeof(int));
	if (!(*cmd)->args || !(*cmd)->types)
	{
		free((*cmd)->args);
		free((*cmd)->types);
		(*cmd)->args = NULL;
		(*cmd)->types = NULL;
		return (1);
	}
	return (0);
}

int	alloc_redirs(t_nodes *start, t_cmd **cmd)
{
	int	nr;

	nr = num_redir(start);
	if (nr <= 0)
		return (0);
	(*cmd)->redirs = ft_calloc(nr + 1, sizeof(t_redir));
	if (!(*cmd)->redirs)
	{
		free((*cmd)->args);
		free((*cmd)->types);
		(*cmd)->args = NULL;
		(*cmd)->types = NULL;
		return (1);
	}
	return (0);
}

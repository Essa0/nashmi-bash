/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   after_expand1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zshkukan <zshkukan@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/30 10:34:11 by zshkukan          #+#    #+#             */
/*   Updated: 2026/04/30 10:35:24 by zshkukan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	replace_node_with_split(t_nodes **head, t_nodes *node)
{
	t_nodes	*first;

	first = NULL;
	if (split_value_to_nodes(node->data->value, &first))
		return ;
	link_replacement(head, node, first);
	free_token(node);
}

void	split_after_exp(t_nodes **head)
{
	t_nodes	*temp;
	t_nodes	*next;

	temp = *head;
	while (temp)
	{
		next = temp->next;
		if (temp->data->type == TOKEN_WORD && ft_strchr(temp->data->value, ' '))
		{
			replace_node_with_split(head, temp);
		}
		temp = next;
	}
}

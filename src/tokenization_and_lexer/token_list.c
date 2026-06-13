/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_list.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zshkukan <zshkukan@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/29 21:08:54 by zshkukan          #+#    #+#             */
/*   Updated: 2026/04/29 21:08:56 by zshkukan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int	add_last(t_nodes **head, t_nodes *next)
{
	t_nodes	*temp;

	if (!next || !head)
		return (1);
	if (!*head)
	{
		*head = next;
		return (0);
	}
	temp = *head;
	while (temp && temp->next != NULL)
		temp = temp->next;
	if (!temp)
		return (1);
	temp->next = next;
	next->prev = temp;
	next->next = NULL;
	return (0);
}

t_nodes	*new_node(t_token *token)
{
	t_nodes	*node;

	node = NULL;
	node = malloc(sizeof(t_nodes));
	if (!node)
		return (NULL);
	node->data = token;
	node->next = NULL;
	node->prev = NULL;
	return (node);
}

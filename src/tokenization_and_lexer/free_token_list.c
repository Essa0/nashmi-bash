/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_token_list.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zshkukan <zshkukan@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/29 20:13:20 by zshkukan          #+#    #+#             */
/*   Updated: 2026/04/29 20:13:22 by zshkukan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	free_token(t_nodes *token)
{
	free(token->data->value);
	free(token->data);
	free(token);
}

void	free_token_list(t_nodes *head)
{
	t_nodes	*temp;
	t_nodes	*next;
	t_token	*tok;

	if (!head)
		return ;
	temp = head;
	next = NULL;
	while (temp)
	{
		next = temp->next;
		tok = temp->data;
		if (tok)
		{
			if (tok->value)
				free(tok->value);
			free(tok);
		}
		free(temp);
		temp = next;
	}
	head = NULL;
}

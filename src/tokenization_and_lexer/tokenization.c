/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenization.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zshkukan <zshkukan@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/29 21:09:03 by zshkukan          #+#    #+#             */
/*   Updated: 2026/04/29 21:20:25 by zshkukan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

static int	build_tok_list(char *line, int *index, t_nodes **head)
{
	t_token	*tok;
	t_nodes	*node;

	if (!line[*index])
		return (0);
	tok = lexer(line, index);
	if (tok == NULL)
	{
		free_token_list(*head);
		return (1);
	}
	node = new_node(tok);
	if (!node)
	{
		free(tok->value);
		free(tok);
		free_token_list(*head);
		return (1);
	}
	add_last(head, node);
	return (0);
}

t_nodes	*tokenization(char *line)
{
	t_nodes	*head;
	int		index;

	if (!line || !*line)
		return (NULL);
	head = NULL;
	index = 0;
	while (line[index])
	{
		if (ft_isspace(line[index]))
			index++;
		else
		{
			if (build_tok_list(line, &index, &head) == 1)
				return (NULL);
			index++;
		}
	}
	if (!head)
		return (NULL);
	return (head);
}

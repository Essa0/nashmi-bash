/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   after_expand.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zshkukan <zshkukan@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/29 20:16:30 by zshkukan          #+#    #+#             */
/*   Updated: 2026/04/30 10:37:34 by zshkukan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

char	*get_word(char *s, int *i)
{
	int	start;
	int	in_sq;
	int	in_dq;

	in_sq = 0;
	in_dq = 0;
	start = *i;
	while (s[*i])
	{
		if (s[*i] == '\'' && !in_dq)
			in_sq = !in_sq;
		else if (s[*i] == '\"' && !in_sq)
			in_dq = !in_dq;
		if (!in_sq && !in_dq && ft_isspace(s[*i]))
			break ;
		(*i)++;
	}
	return (ft_substr(s, start, *i - start));
}

int	append_node(t_nodes **first, t_nodes **last, char *word)
{
	t_nodes	*new;

	if (!word)
		return (1);
	if (!*word)
		return (0);
	new = new_node_from_value(word);
	if (!new)
		return (1);
	if (!*first)
		*first = new;
	if (*last)
		(*last)->next = new;
	new->prev = *last;
	*last = new;
	return (0);
}

int	split_value_to_nodes(char *value, t_nodes **first)
{
	char	*word;
	t_nodes	*last;
	int		i;

	i = 0;
	last = NULL;
	while (value[i])
	{
		while (ft_isspace(value[i]))
			i++;
		if (!value[i])
			break ;
		word = get_word(value, &i);
		if (append_node(first, &last, word))
		{
			free(word);
			free_token_list(*first);
			*first = NULL;
			return (1);
		}
		free(word);
	}
	return (0);
}

t_nodes	*last_node(t_nodes *first)
{
	while (first && first->next)
		first = first->next;
	return (first);
}

void	link_replacement(t_nodes **head, t_nodes *node, t_nodes *first)
{
	t_nodes	*prev;
	t_nodes	*next;
	t_nodes	*last;

	prev = node->prev;
	next = node->next;
	if (!first)
	{
		if (prev)
			prev->next = next;
		if (next)
			next->prev = prev;
		if (*head == node)
			*head = next;
		return ;
	}
	last = last_node(first);
	if (prev)
		prev->next = first;
	first->prev = prev;
	last->next = next;
	if (next)
		next->prev = last;
	if (*head == node)
		*head = first;
}

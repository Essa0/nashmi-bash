/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zshkukan <zshkukan@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/29 20:19:55 by zshkukan          #+#    #+#             */
/*   Updated: 2026/04/30 10:46:36 by zshkukan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

static int	is_tilde_expansion(char *str)
{
	return (str[0] == '~' && (str[1] == '\0' || str[1] == '/'));
}

char	*expand_tilde(char *str, char **envp)
{
	char	*home;
	char	*result;

	if (!is_tilde_expansion(str))
		return (ft_strdup(str));
	home = get_env_val(envp, "HOME");
	if (!home)
		return (ft_strdup(str));
	if (str[1] == '\0')
		return (ft_strdup(home));
	result = ft_strjoin(home, str + 1);
	return (result);
}

void	remove_tokens(t_nodes **head)
{
	t_nodes	*temp;
	t_nodes	*next;
	t_nodes	*pre;

	temp = *head;
	while (temp)
	{
		pre = temp->prev;
		next = temp->next;
		if (is_empty_expanded(temp->data->value) && temp->data->type != 7
			&& temp->data->type != TOKEN_PIPE
			&& temp->data->type != TOKEN_REDIR_APPEND
			&& temp->data->type != TOKEN_REDIR_IN
			&& temp->data->type != TOKEN_REDIR_OUT)
		{
			free_token(temp);
			if (pre)
				pre->next = next;
			else
				*head = next;
			if (next)
				next->prev = pre;
		}
		temp = next;
	}
}

t_nodes	*new_node_from_value(char *val)
{
	t_token	*t;
	t_nodes	*n;

	t = ft_calloc(1, sizeof(t_token));
	if (!t)
		return (NULL);
	t->type = TOKEN_WORD;
	t->value = ft_strdup(val);
	n = new_node(t);
	if (!n)
	{
		free(t->value);
		free(t);
		return (NULL);
	}
	return (n);
}

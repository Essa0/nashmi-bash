/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_exp_token.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zshkukan <zshkukan@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/29 21:10:47 by zshkukan          #+#    #+#             */
/*   Updated: 2026/04/29 21:10:48 by zshkukan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int	is_empty_expanded(char *value)
{
	int	j;
	int	f;

	if (!value)
		return (1);
	f = 0;
	j = 0;
	while (value[j])
	{
		if (ft_isprint(value[j]))
			f += 1;
		j++;
	}
	if (f > 0)
		return (0);
	return (1);
}

static int	expand_value(t_token *token_v, t_shell *shell)
{
	char	*expanded;

	if (ft_strchr(token_v->value, '~'))
	{
		expanded = expand_tilde(token_v->value, shell->envp_shell);
		if (!expanded)
			return (1);
		free(token_v->value);
		token_v->value = expanded;
		return (0);
	}
	if (ft_strchr(token_v->value, '$') == NULL)
		return (3);
	expanded = expand_string(token_v->value, shell);
	if (!expanded)
		return (1);
	free(token_v->value);
	token_v->value = expanded;
	return (4);
}

static void	expand_token(t_nodes *token_e, t_shell *shell)
{
	if (token_e->prev && token_e->prev->data->type == TOKEN_HEREDOC)
	{
		token_e->data->type = FLAG_E;
		return ;
	}
	else
	{
		if (expand_value(token_e->data, shell) == 3)
			token_e->data->type = FLAG_E;
	}
}

static void	remove_quote(t_nodes *token_e)
{
	char	*value;
	t_nodes	*temp;

	temp = token_e;
	while (temp)
	{
		if (temp->data->type == FLAG_E)
		{
			value = remove_quotes(temp->data->value);
			if (value)
			{
				free(temp->data->value);
				temp->data->value = value;
			}
			temp->data->type = TOKEN_WORD;
		}
		temp = temp->next;
	}
}

int	expand_all(t_nodes **head_t, t_shell *shell)
{
	t_nodes	*temp;

	if (!head_t)
		return (0);
	temp = *head_t;
	while (temp)
	{
		if (temp->data->type == TOKEN_WORD || temp->data->type == TOKEN_WORD_DQ
			|| temp->data->type == TOKEN_WORD_SQ)
			expand_token(temp, shell);
		temp = temp->next;
	}
	split_after_exp(head_t);
	remove_tokens(head_t);
	remove_quote((*head_t));
	return (0);
}

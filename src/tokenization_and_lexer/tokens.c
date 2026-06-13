/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokens.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zshkukan <zshkukan@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/29 21:09:13 by zshkukan          #+#    #+#             */
/*   Updated: 2026/04/29 21:09:15 by zshkukan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	tok_word(char *line, int *index, t_token **t)
{
	int	start;
	int	end;

	start = *index;
	while (line[*index] && check_char_t(line[*index]) == 0)
	{
		if (line[*index] == '\"' || line[*index] == '\'')
		{
			if (line[*index] == '\"' && !(*t)->type)
				(*t)->type = TOKEN_WORD_DQ;
			else if (line[*index] == '\'' && !(*t)->type)
				(*t)->type = TOKEN_WORD_SQ;
			skip_inner_quote(line, index);
			if (!line[*index])
				return ;
		}
		(*index)++;
	}
	(*index)--;
	end = *index - start + 1;
	(*t)->value = ft_substr(line, start, end);
	if (!(*t)->type)
		(*t)->type = TOKEN_WORD;
}

static void	tok_pipe(t_token *t)
{
	t->value = NULL;
	t->type = TOKEN_PIPE;
}

static void	tok_redirec(char *line, int *index, t_token **t)
{
	if (line[*index] == '<')
	{
		(*t)->type = TOKEN_REDIR_IN;
		if (line[(*index) + 1] == '<')
		{
			(*t)->type = TOKEN_HEREDOC;
			(*index)++;
		}
	}
	else if (line[*index] == '>')
	{
		(*t)->type = TOKEN_REDIR_OUT;
		if (line[(*index) + 1] == '>')
		{
			(*t)->type = TOKEN_REDIR_APPEND;
			(*index)++;
		}
	}
	else
		return ;
}

t_token	*lexer(char *line, int *index)
{
	t_token	*t;

	if (!line || !line[*index])
		return (NULL);
	t = ft_calloc(1, sizeof(t_token));
	if (!t)
		return (NULL);
	else if (line[*index] == '|')
		tok_pipe(t);
	else if (line[*index] == '<' || line[*index] == '>')
		tok_redirec(line, index, &t);
	else
		tok_word(line, index, &t);
	if (!t)
		return (NULL);
	return (t);
}

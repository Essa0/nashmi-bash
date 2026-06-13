/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zshkukan <zshkukan@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/29 21:10:40 by zshkukan          #+#    #+#             */
/*   Updated: 2026/04/30 10:44:24 by zshkukan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

char	*expand_var(char *s, int *i, t_shell *sh)
{
	char	*key;
	char	*val;
	int		start;

	if (s[*i] == '?')
	{
		(*i)++;
		return (ft_itoa(sh->exit_status));
	}
	start = *i;
	while (s[*i] && (ft_isalnum(s[*i]) || s[*i] == '_') && s[*i] != '$')
		(*i)++;
	if (*i == start)
		return (ft_strdup("$"));
	key = ft_substr(s, start, *i - start);
	if (!key)
		return (NULL);
	val = get_env_val(sh->envp_shell, key);
	free(key);
	if (!val)
		return (ft_strdup(""));
	return (ft_strdup(val));
}

char	*handle_sq(char *s, int *i)
{
	int		start;
	char	*part;

	start = ++(*i);
	while (s[*i] && s[*i] != '\'')
		(*i)++;
	if (!s[*i])
		return (NULL);
	part = ft_substr(s, start, *i - start);
	(*i)++;
	return (part);
}

char	*get_dq_part(char *s, int *i, t_shell *sh)
{
	if (s[*i] == '$')
	{
		(*i)++;
		return (expand_var(s, i, sh));
	}
	return (ft_substr(s, (*i)++, 1));
}

int	append_dq_part(char **res, char *s, int *i, t_shell *sh)
{
	char	*tmp;

	tmp = get_dq_part(s, i, sh);
	if (!tmp)
	{
		free(*res);
		*res = NULL;
		return (1);
	}
	*res = append(*res, tmp);
	if (!*res)
		return (1);
	return (0);
}

char	*handle_dq(char *s, int *i, t_shell *sh)
{
	char	*res;

	res = ft_strdup("");
	if (!res)
		return (NULL);
	(*i)++;
	while (s[*i] && s[*i] != '\"')
	{
		if (append_dq_part(&res, s, i, sh))
			return (NULL);
	}
	if (!s[*i])
	{
		free(res);
		return (NULL);
	}
	(*i)++;
	return (res);
}

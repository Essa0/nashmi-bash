/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zshkukan <zshkukan@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/30 10:39:58 by zshkukan          #+#    #+#             */
/*   Updated: 2026/04/30 10:44:40 by zshkukan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

char	*handle_normal(char *s, int *i, t_shell *sh)
{
	if (s[*i] == '\'')
		return (handle_sq(s, i));
	if (s[*i] == '\"')
		return (handle_dq(s, i, sh));
	if (s[*i] == '$')
	{
		(*i)++;
		return (expand_var(s, i, sh));
	}
	return (ft_substr(s, (*i)++, 1));
}

char	*expand_string(char *str, t_shell *sh)
{
	int		i;
	char	*res;
	char	*part;

	i = 0;
	res = ft_strdup("");
	if (!res)
		return (NULL);
	while (str[i])
	{
		part = handle_normal(str, &i, sh);
		if (!part)
		{
			free(res);
			return (NULL);
		}
		res = append(res, part);
		if (!res)
			return (NULL);
	}
	return (res);
}

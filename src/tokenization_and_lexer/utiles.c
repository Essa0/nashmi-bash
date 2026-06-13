/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utiles.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zshkukan <zshkukan@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/29 21:09:22 by zshkukan          #+#    #+#             */
/*   Updated: 2026/04/29 21:09:24 by zshkukan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int	skip_inner_quote(char *line, int *index)
{
	char	quote;

	quote = line[*index];
	(*index)++;
	while (line[*index] && line[*index] != quote)
		(*index)++;
	if (!line[*index])
		return (1);
	return (0);
}

int	copy_without_quotes(char *src, char *dst)
{
	int		i;
	int		j;
	char	quote;

	i = 0;
	j = 0;
	while (src[i])
	{
		if (src[i] == '"' || src[i] == '\'')
		{
			quote = src[i];
			i++;
			while (src[i] && src[i] != quote)
				dst[j++] = src[i++];
			if (src[i])
				i++;
		}
		else
			dst[j++] = src[i++];
	}
	dst[j] = '\0';
	return (j);
}

char	*remove_quotes(char *str)
{
	char	*result;
	int		len;

	len = ft_strlen(str);
	result = ft_calloc(len + 1, sizeof(char));
	if (!result)
		return (NULL);
	copy_without_quotes(str, result);
	return (result);
}

int	check_char_t(char c)
{
	if (c == '|' || c == ' ' || c == '<' || c == '>')
		return (1);
	return (0);
}

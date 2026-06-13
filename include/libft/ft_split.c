/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zshkukan <zshkukan@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/16 21:43:47 by zshkukan          #+#    #+#             */
/*   Updated: 2025/08/18 14:51:00 by zshkukan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	free_arr(char **arr, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}

static int	next_tok(char const *s, char c, size_t *idx, size_t *len)
{
	size_t	k;

	k = *idx;
	while (s[k] && s[k] == c)
		k++;
	if (!s[k])
		return (0);
	*len = 0;
	while (s[k + *len] && s[k + *len] != c)
		(*len)++;
	*idx = k;
	return (1);
}

static int	num_w(char const *s, char c)
{
	size_t	idx;
	size_t	len;
	int		cnt;

	idx = 0;
	cnt = 0;
	while (next_tok(s, c, &idx, &len))
	{
		cnt++;
		idx += len;
	}
	return (cnt);
}

char	**ft_split(char const *s, char c)
{
	char	**arr;
	size_t	i;
	size_t	idx;
	size_t	len;

	i = 0;
	idx = 0;
	len = 0;
	if (!s)
		return (NULL);
	arr = ft_calloc((size_t)num_w(s, c) + 1, sizeof(char *));
	if (!arr)
		return (NULL);
	while (next_tok(s, c, &idx, &len))
	{
		arr[i] = ft_substr(s, idx, len);
		if (!arr[i++])
		{
			free_arr(arr, i - 1);
			return (NULL);
		}
		idx += len;
	}
	return (arr);
}

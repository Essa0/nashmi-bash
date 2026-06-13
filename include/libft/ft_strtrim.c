/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zshkukan <zshkukan@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/13 20:14:16 by zshkukan          #+#    #+#             */
/*   Updated: 2025/08/18 14:52:34 by zshkukan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_set(char const s, char const *set)
{
	int	i_set;

	i_set = 0;
	while (set[i_set])
	{
		if (s == set[i_set])
		{
			return (1);
		}
		i_set++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		start;
	int		end;
	char	*ptr;

	if (!s1 || !set)
		return (NULL);
	start = 0;
	end = ft_strlen(s1) - 1;
	while (s1[start] && is_set(s1[start], set))
		start++;
	while (end >= start && is_set(s1[end], set))
		end--;
	ptr = ft_calloc((end - start) + 2, sizeof(char));
	if (!ptr)
		return (NULL);
	ft_strlcpy(ptr, &s1[start], (end - start) + 2);
	return (ptr);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zshkukan <zshkukan@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/18 13:49:10 by zshkukan          #+#    #+#             */
/*   Updated: 2025/08/24 10:59:16 by zshkukan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char ( *f)(unsigned int, char))
{
	size_t		i;
	char		*ptr;

	if (!s || !f)
		return (NULL);
	i = 0;
	ptr = ft_calloc(ft_strlen(s) + 1, sizeof(char));
	if (!ptr)
		return (NULL);
	while (i < ft_strlen(s))
	{
		ptr[i] = f(i, s[i]);
		i++;
	}
	return (ptr);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zshkukan <zshkukan@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/09 20:49:57 by zshkukan          #+#    #+#             */
/*   Updated: 2025/08/18 14:51:46 by zshkukan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
// size of dest
size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t		lens;
	size_t		lend;
	size_t		i;

	lend = ft_strlen(dst);
	lens = ft_strlen(src);
	i = 0;
	if (size <= lend)
		return (size + lens);
	while (src[i] && (lend + i) < size - 1)
	{
		dst[lend + i] = src[i];
		i++;
	}
	dst[lend + i] = '\0';
	return (lend + lens);
}

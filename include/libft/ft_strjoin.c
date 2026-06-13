/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zshkukan <zshkukan@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/13 17:37:45 by zshkukan          #+#    #+#             */
/*   Updated: 2025/08/18 14:51:37 by zshkukan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	total_len;
	char	*ptr;

	total_len = ft_strlen(s1) + ft_strlen(s2) + 1;
	ptr = ft_calloc(total_len, sizeof(char));
	if (!ptr)
		return (NULL);
	ft_strlcat(ptr, s1, total_len);
	ft_strlcat(&ptr[ft_strlen(ptr)], s2, total_len);
	return (ptr);
}

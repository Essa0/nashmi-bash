/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zshkukan <zshkukan@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/12 19:30:26 by zshkukan          #+#    #+#             */
/*   Updated: 2025/08/24 10:59:39 by zshkukan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*sub_buff;

	if (!s)
		return (NULL);
	if (start >= ft_strlen(s))
	{
		sub_buff = ft_calloc(1, sizeof(char));
		if (!sub_buff)
			return (NULL);
		return (sub_buff);
	}
	if (len > ft_strlen(s + start))
		len = ft_strlen(s + start);
	sub_buff = ft_calloc(len + 1, sizeof(char));
	if (!sub_buff)
		return (NULL);
	ft_strlcpy(sub_buff, s + start, len + 1);
	return (sub_buff);
}

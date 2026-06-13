/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zshkukan <zshkukan@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/11 16:09:43 by zshkukan          #+#    #+#             */
/*   Updated: 2025/08/24 10:59:26 by zshkukan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	il;

	i = 0;
	il = 0;
	if (*little == '\0')
		return ((char *)big);
	while (i < len && big[i] != '\0')
	{
		il = 0;
		while (little[il] != '\0'
			&& (i + il) < len && big[i + il] == little[il])
		{
			il++;
		}
		if (little[il] == '\0')
			return ((char *)&big[i]);
		i++;
	}
	return (NULL);
}

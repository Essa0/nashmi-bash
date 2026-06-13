/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zshkukan <zshkukan@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/18 14:48:05 by zshkukan          #+#    #+#             */
/*   Updated: 2025/08/24 10:44:17 by zshkukan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	int		value;
	char	*ptr;
	size_t	i;

	value = 0;
	ptr = (char *)s;
	i = 0;
	while (i < n)
	{
		ptr[i] = value;
		i++;
	}
}

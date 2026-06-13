/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zshkukan <zshkukan@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/18 13:48:18 by zshkukan          #+#    #+#             */
/*   Updated: 2025/08/24 10:45:56 by zshkukan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*converter(long n, int len, char sign)
{
	int		i;
	char	*ptr;

	ptr = ft_calloc(len + 1, sizeof(char));
	if (!ptr)
		return (NULL);
	if (sign == '-')
	{
		ptr[0] = '-';
		n *= -1;
	}
	ptr[len] = '\0';
	i = len - 1;
	while (i >= 0 && !(sign == '-' && i == 0))
	{
		ptr[i] = (n % 10) + '0';
		n /= 10;
		i--;
	}
	return (ptr);
}

static char	*allocator(int n)
{
	int		len;
	char	sign;
	long	k;

	len = 0;
	sign = '\0';
	k = n;
	if (n < 0)
	{
		sign = '-';
		k *= -1;
		len++;
	}
	while (k > 0)
	{
		k /= 10;
		len++;
	}
	return (converter(n, len, sign));
}

char	*ft_itoa(int n)
{
	char	*ptr;

	ptr = NULL;
	if (n == 0)
	{
		ptr = ft_calloc(2, sizeof(char));
		if (ptr)
		{
			ptr[0] = '0';
			ptr[1] = '\0';
		}
		return (ptr);
	}
	return (allocator(n));
}

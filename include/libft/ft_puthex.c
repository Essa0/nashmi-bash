/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zshkukan <zshkukan@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/27 16:24:42 by zshkukan          #+#    #+#             */
/*   Updated: 2025/09/27 16:38:04 by zshkukan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	tohex(unsigned int p, char c)
{
	const char	hex[] = "0123456789abcdef";
	const char	uhex[] = "0123456789ABCDEF";
	int			count;

	count = 0;
	if (p >= 16)
		count += tohex(p / 16, c);
	if (c == 'x')
		count += ft_putchar(hex[p % 16]);
	else if (c == 'X')
		count += ft_putchar(uhex[p % 16]);
	return (count);
}

int	ft_puthex(char c, unsigned int p)
{
	int	count;

	count = 0;
	count = tohex(p, c);
	return (count);
}

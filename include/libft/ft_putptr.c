/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zshkukan <zshkukan@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/27 16:38:15 by zshkukan          #+#    #+#             */
/*   Updated: 2025/10/11 14:24:02 by zshkukan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	deal_with_ptr(unsigned long p)
{
	const char	hex[] = "0123456789abcdef";
	int			count;

	count = 0;
	if (p >= 16)
		count += deal_with_ptr(p / 16);
	count += ft_putchar(hex[p % 16]);
	return (count);
}

int	ft_putptr(void *p)
{
	int	count;

	count = 0;
	if (!p)
		return (ft_putstr("(nil)"));
	count += ft_putstr("0x");
	count += deal_with_ptr((unsigned long)p);
	return (count);
}

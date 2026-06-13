/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zshkukan <zshkukan@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/27 16:37:39 by zshkukan          #+#    #+#             */
/*   Updated: 2025/10/11 13:57:59 by zshkukan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	converter(va_list *args, const char *sign, int i)
{
	if (sign[i] == 'c')
		return (ft_putchar(va_arg(*args, int)));
	else if (sign[i] == 's')
		return (ft_putstr(va_arg(*args, char *)));
	else if (sign[i] == 'p')
		return (ft_putptr(va_arg(*args, void *)));
	else if (sign[i] == 'd' || sign[i] == 'i')
		return (ft_putnbr(va_arg(*args, int)));
	else if (sign[i] == 'u')
		return (ft_putunbr(va_arg(*args, unsigned int)));
	else if (sign[i] == 'x' || sign[i] == 'X')
		return (ft_puthex(sign[i], va_arg(*args, unsigned int)));
	else if (sign[i] == '%')
		return (write(1, "%", 1));
	return (0);
}

int	ft_printf(const char *format, ...)
{
	va_list		args;
	int			i;
	int			c;

	if (!format)
		return (-1);
	va_start(args, format);
	c = 0;
	i = 0;
	while (format[i])
	{
		if (format[i] == '%')
		{
			c += converter(&args, format, ++i);
			if (c < 0)
				return (-1);
		}
		else
			c += write(1, &format[i], 1);
		if (c < 0)
			return (-1);
		i++;
	}
	va_end(args);
	return (c);
}

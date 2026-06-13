/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: issa <issa@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/26 22:21:46 by  iabiesat         #+#    #+#             */
/*   Updated: 2026/04/21 23:42:34 by issa             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

/*
	customize echo command
	provide just -n option
*/

static int	flag_checker(char *av)
{
	int	i;

	i = 1;
	if (av[0] == '-' && av[1] == 'n')
	{
		while (av[i])
		{
			if (av[i] != 'n')
				return (1);
			i++;
		}
	}
	else
		return (1);
	return (0);
}

int	ft_echo(char **av)
{
	int	i;
	int	checker;

	i = 1;
	checker = 0;
	while (av[i])
	{
		if (flag_checker(av[i]) == 0)
		{
			checker = 1;
			i++;
			continue ;
		}
		break ;
	}
	while (av[i])
	{
		ft_putstr_fd(av[i], 1);
		if (av[i + 1])
			write(1, " ", 1);
		i++;
	}
	if (checker == 0)
		write(1, "\n", 1);
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: issa <issa@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/20 00:00:00 by issa              #+#    #+#             */
/*   Updated: 2026/04/29 17:21:07 by issa             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

static int	is_numeric(const char *s)
{
	int	i;

	if (!s || !*s)
		return (0);
	i = 0;
	if (s[i] == '+' || s[i] == '-')
		i++;
	if (!s[i])
		return (0);
	while (s[i])
	{
		if (s[i] < '0' || s[i] > '9')
			return (0);
		i++;
	}
	return (1);
}

static int	print_exit_er(char *av, t_shell *shell)
{
	ft_putstr_fd("minishell: exit: ", STDERR_FILENO);
	ft_putstr_fd(av, STDERR_FILENO);
	ft_putendl_fd(": numeric argument required", STDERR_FILENO);
	shell->exit_status = 2;
	shell->should_exit = 1;
	return (2);
}

static int	is_ll_overflow(const char *s)
{
	long long	r;
	int			sign;
	int			i;
	int			d;

	r = 0;
	sign = 1;
	i = 0;
	if (s[i] == '+' || s[i] == '-')
	{
		if (s[i] == '-')
			sign = -1;
		i++;
	}
	while (s[i])
	{
		d = s[i] - '0';
		if ((sign == 1 && r > (LLONG_MAX - d) / 10)
			|| (sign == -1 && (-r) < (LLONG_MIN + d) / 10))
			return (1);
		r = r * 10 + d;
		i++;
	}
	return (0);
}

static long long	ft_atoll(const char *s)
{
	long long	r;
	int			sign;
	int			i;

	r = 0;
	sign = 1;
	i = 0;
	while (s[i] == ' ' || (s[i] >= 9 && s[i] <= 13))
		i++;
	if (s[i] == '+' || s[i] == '-')
	{
		if (s[i] == '-')
			sign = -1;
		i++;
	}
	while (s[i] >= '0' && s[i] <= '9')
	{
		r = r * 10 + (s[i] - '0');
		i++;
	}
	return (r * sign);
}

int	ft_exit(t_shell *data, char **av)
{
	int	code;

	if (!data->in_pipe)
		ft_putendl_fd("exit", STDERR_FILENO);
	if (!av[1])
	{
		data->should_exit = 1;
		return (data->exit_status);
	}
	if (!is_numeric(av[1]) || is_ll_overflow(av[1]))
		return (print_exit_er(av[1], data));
	if (av[2])
	{
		ft_putstr_fd("minishell: exit: too many arguments\n", STDERR_FILENO);
		return (1);
	}
	code = (int)ft_atoll(av[1]);
	code = ((code % 256) + 256) % 256;
	data->should_exit = 1;
	return ((int)code);
}

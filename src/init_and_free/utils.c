/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zshkukan <zshkukan@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/29 20:16:00 by zshkukan          #+#    #+#             */
/*   Updated: 2026/04/29 20:16:03 by zshkukan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

static int	is_valid_shlvl(char *lvl)
{
	int	i;

	i = 0;
	if (!lvl || !*lvl)
		return (0);
	if (lvl[i] == '+' || lvl[i] == '-')
		i++;
	if (!lvl[i])
		return (0);
	while (lvl[i])
	{
		if (!ft_isdigit(lvl[i]))
			return (0);
		i++;
	}
	return (1);
}

static int	is_positive_too_high(char *lvl)
{
	int		i;
	int		len;
	char	*digits;

	i = 0;
	if (lvl[i] == '+')
		i++;
	digits = lvl + i;
	while (*digits == '0')
		digits++;
	if (!*digits)
		return (0);
	len = ft_strlen(digits);
	if (len > 3)
		return (1);
	if (len == 3 && ft_strncmp(digits, "1000", 4) >= 0)
		return (1);
	return (0);
}

int	shlvl_checked_next(char *lvl)
{
	int	value;

	if (!is_valid_shlvl(lvl))
		return (1);
	if (lvl[0] == '-')
		return (0);
	if (is_positive_too_high(lvl))
		return (2);
	value = ft_atoi(lvl);
	if (value < 0)
		return (0);
	return (3);
}

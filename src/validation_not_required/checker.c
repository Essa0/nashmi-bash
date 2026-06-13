/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zshkukan <zshkukan@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/29 21:08:41 by zshkukan          #+#    #+#             */
/*   Updated: 2026/04/29 21:08:43 by zshkukan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

// done zeyad
static int	check_char(char *line)
{
	int	index;

	index = 0;
	while (line[index])
	{
		if (line[index] == 92)
			return (1);
		else if (line[index] == ';')
			return (2);
		else if (line[index] == 34)
		{
			index++;
			while (line[index] && line[index] != 34)
				index++;
		}
		else if (line[index] == 39)
		{
			index++;
			while (line[index] && line[index] != 39)
				index++;
		}
		index++;
	}
	return (0);
}

static int	check_quote(char *line, int c, int *index)
{
	(*index)++;
	while (line[*index])
	{
		if (line[*index] == c)
			return (0);
		(*index)++;
	}
	return (1);
}

static int	check_unclosed(char *line)
{
	int	index;

	index = 0;
	while (line[index])
	{
		if (line[index] == 34)
		{
			if (check_quote(line, 34, &index) == 1)
				return (1);
		}
		else if (line[index] == 39)
		{
			if (check_quote(line, 39, &index) == 1)
				return (1);
		}
		index++;
	}
	return (0);
}

int	check_required(t_shell *shell, char *line)
{
	int	e;

	if (!line)
		return (1);
	if (check_unclosed(line) == 1)
	{
		ft_putstr_fd("minishell: syntax error near unexpected unclosed quote\n",
			2);
		shell->exit_status = 2;
		return (1);
	}
	e = check_char(line);
	if (e == 1 || e == 2)
	{
		if (e == 1)
			ft_putstr_fd("minishell: syntax error near unexpected backslash\n",
				2);
		if (e == 2)
			ft_putstr_fd("minishell: syntax error near unexpected semicolon\n",
				2);
		shell->exit_status = 2;
		return (1);
	}
	return (0);
}

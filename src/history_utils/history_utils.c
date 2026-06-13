/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   history_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zshkukan <zshkukan@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/29 20:16:15 by zshkukan          #+#    #+#             */
/*   Updated: 2026/04/29 20:16:17 by zshkukan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int	history_add(char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if ((unsigned char)line[i] >= 33 && (unsigned char)line[i] < 127)
		{
			add_history(line);
			return (0);
		}
		i++;
	}
	return (1);
}

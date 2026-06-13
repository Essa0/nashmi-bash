/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zshkukan <zshkukan@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/29 20:20:03 by zshkukan          #+#    #+#             */
/*   Updated: 2026/04/29 20:20:06 by zshkukan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

char	*append(char *res, char *add)
{
	char	*tmp;

	if (!add)
	{
		free(res);
		return (NULL);
	}
	if (!res)
		return (add);
	if (ft_strlen(add) == 0)
	{
		free(add);
		return (res);
	}
	tmp = ft_strjoin(res, add);
	free(res);
	free(add);
	if (!tmp)
		return (NULL);
	return (tmp);
}

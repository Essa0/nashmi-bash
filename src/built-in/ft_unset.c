/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unset.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: issa <issa@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/04 23:20:55 by  iabiesat         #+#    #+#             */
/*   Updated: 2026/04/21 23:45:03 by issa             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

static void	remove_env_var(t_shell *data, char *var_name)
{
	int	i;
	int	var_len;

	i = 0;
	var_len = ft_strlen(var_name);
	while (data->envp_shell[i])
	{
		if (ft_strncmp(data->envp_shell[i], var_name, var_len) == 0
			&& data->envp_shell[i][var_len] == '=')
		{
			free(data->envp_shell[i]);
			while (data->envp_shell[i])
			{
				data->envp_shell[i] = data->envp_shell[i + 1];
				i++;
			}
			break ;
		}
		i++;
	}
}

int	ft_unset(t_shell *data, char **av)
{
	int	j;

	if (!av[1])
		return (0);
	j = 1;
	while (av[j])
	{
		remove_env_var(data, av[j]);
		j++;
	}
	return (0);
}

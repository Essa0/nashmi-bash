/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_env_val.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: issa <issa@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/28 02:37:29 by  iabiesat         #+#    #+#             */
/*   Updated: 2026/04/21 23:49:14 by issa             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/minishell.h"

/*
	return pointer to pos next to (=)
	if found the key you search about
*/

char	*get_env_val(char **env, char *key)
{
	int	i;

	i = 0;
	while (env[i])
	{
		if (strncmp(env[i], key, strlen(key)) == 0
			&& env[i][strlen(key)] == '=')
			return ((char *)&env[i][strlen(key) + 1]);
		i++;
	}
	return (NULL);
}

int	ft_env(t_shell *data)
{
	int	i;

	i = 0;
	while (data->envp_shell[i])
	{
		if (ft_strchr(data->envp_shell[i], '='))
			ft_putendl_fd(data->envp_shell[i], 1);
		i++;
	}
	return (0);
}

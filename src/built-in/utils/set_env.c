/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_env.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: issa <issa@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/04 23:35:38 by  iabiesat         #+#    #+#             */
/*   Updated: 2026/04/29 00:35:45 by issa             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/minishell.h"

static char	*build_env_var(char *key, char *val)
{
	char	*temp;
	char	*result;

	temp = ft_strjoin(key, "=");
	if (!temp)
		return (NULL);
	if (val == NULL)
	{
		free(temp);
		return (ft_strdup(key));
	}
	result = ft_strjoin(temp, val);
	free(temp);
	return (result);
}

char	**add_env(char **env, char *key, char *val)
{
	int		i;
	char	**new_env;

	i = 0;
	while (env[i])
		i++;
	new_env = malloc(sizeof(char *) * (i + 2));
	if (!new_env)
		return (env);
	i = 0;
	while (env[i])
	{
		new_env[i] = env[i];
		i++;
	}
	new_env[i] = build_env_var(key, val);
	new_env[i + 1] = NULL;
	free(env);
	return (new_env);
}

char	**set_env(char **env, char *key, char *val)
{
	int		i;
	char	*path;
	char	*new_path;

	i = 0;
	while (env[i])
	{
		if (strncmp(env[i], key, strlen(key)) == 0
			&& env[i][strlen(key)] == '=')
		{
			free(env[i]);
			path = ft_strjoin(key, "=");
			if (!path)
				return (env);
			if (val)
				new_path = ft_strjoin(path, val);
			else
				new_path = ft_strdup(path);
			env[i] = new_path;
			free(path);
			return (env);
		}
		i++;
	}
	return (add_env(env, key, val));
}

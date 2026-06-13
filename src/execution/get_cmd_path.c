/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_cmd_path.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iabiesat <iabiesat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/05 22:01:54 by  iabiesat         #+#    #+#             */
/*   Updated: 2026/04/30 18:30:38 by iabiesat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

static char	*ft_strjoin_with_slash(char const *s1, char const *s2)
{
	size_t	total_len;
	char	*ptr;

	if (!s1 || !s2)
		return (NULL);
	total_len = ft_strlen(s1) + ft_strlen(s2) + 2;
	ptr = ft_calloc(total_len, sizeof(char));
	if (!ptr)
		return (NULL);
	ft_strlcat(ptr, s1, total_len);
	ft_strlcat(ptr, "/", total_len);
	ft_strlcat(ptr, s2, total_len);
	return (ptr);
}

static char	*search_in_path(char **split_path, char *cmd)
{
	int		i;
	char	*path;

	i = 0;
	while (split_path[i])
	{
		path = ft_strjoin_with_slash(split_path[i], cmd);
		if (!path)
			return (NULL);
		if (access(path, F_OK) == 0)
		{
			free_env(split_path);
			return (path);
		}
		free(path);
		i++;
	}
	free_env(split_path);
	return (NULL);
}

char	*get_cmd_path(char **env, char *cmd)
{
	char	**split_path;

	if (ft_strchr(cmd, '/'))
	{
		if (access(cmd, F_OK) == 0)
			return (ft_strdup(cmd));
		return (NULL);
	}
	split_path = ft_split(get_env_val(env, "PATH"), ':');
	if (!split_path)
		return (NULL);
	return (search_in_path(split_path, cmd));
}

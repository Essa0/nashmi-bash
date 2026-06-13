/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: issa <issa@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/05 00:43:04 by  iabiesat         #+#    #+#             */
/*   Updated: 2026/04/29 02:48:48 by issa             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int	is_valid_name(char *str)
{
	int	i;

	i = 0;
	if (!str || !str[0] || (!ft_isalpha(str[0]) && str[0] != '_'))
		return (0);
	while (str[i])
	{
		if (!ft_isalnum(str[i]) && str[i] != '_')
			return (0);
		i++;
	}
	return (1);
}

static void	parse_key_value(char *arg, char **key, char **val)
{
	char	*check_var;

	check_var = ft_strchr(arg, '=');
	if (check_var)
	{
		*key = ft_substr(arg, 0, check_var - arg);
		*val = ft_strdup(check_var + 1);
	}
	else
	{
		*key = ft_strdup(arg);
		*val = NULL;
	}
}

static int	find_and_update_env(t_shell *data, char *key, char *val)
{
	int		i;
	int		key_len;
	char	*path;

	i = 0;
	key_len = ft_strlen(key);
	while (data->envp_shell[i])
	{
		if (ft_strncmp(data->envp_shell[i], key, key_len) == 0
			&& (data->envp_shell[i][key_len] == '='
			|| data->envp_shell[i][key_len] == '\0'))
		{
			if (val != NULL)
			{
				path = ft_strjoin(key, "=");
				free(data->envp_shell[i]);
				data->envp_shell[i] = ft_strjoin(path, val);
				free(path);
			}
			return (1);
		}
		i++;
	}
	return (0);
}

static int	handle_export_var(t_shell *data, char *arg)
{
	char	*key;
	char	*val;

	key = NULL;
	val = NULL;
	parse_key_value(arg, &key, &val);
	if (!key)
	{
		free(val);
		return (1);
	}
	if (!is_valid_name(key))
	{
		ft_putstr_fd("minishell: export: ", 2);
		ft_putstr_fd(arg, 2);
		ft_putendl_fd(": not a valid identifier", 2);
		free(key);
		free(val);
		return (0);
	}
	if (!find_and_update_env(data, key, val))
		data->envp_shell = add_env(data->envp_shell, key, val);
	free(key);
	free(val);
	return (1);
}

int	ft_export(t_shell *data, char **av)
{
	int	k;
	int	state;

	if (!av[1])
	{
		print_exp_list(data);
		return (0);
	}
	k = 1;
	state = 0;
	while (av[k])
	{
		if (!handle_export_var(data, av[k]))
			state = 1;
		k++;
	}
	return (state);
}

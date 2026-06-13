/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: issa <issa@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/28 02:49:21 by  iabiesat         #+#    #+#             */
/*   Updated: 2026/04/29 00:45:09 by issa             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

/*
	customize cd command
*/

static int	validate_args(char **av)
{
	if (av[1] && av[2])
	{
		ft_putendl_fd("minishell: cd: too many arguments", 2);
		return (0);
	}
	return (1);
}

char	*get_target_dir(char **av, t_shell *data, int *allocated)
{
	char	*dir;

	*allocated = 0;
	if (!av[1])
		dir = get_env_val(data->envp_shell, "HOME");
	else if (ft_strcmp(av[1], "-") == 0)
	{
		dir = get_env_val(data->envp_shell, "OLDPWD");
		if (dir)
			printf("%s\n", dir);
	}
	else
	{
		dir = expand_tilde(av[1], data->envp_shell);
		*allocated = 1;
	}
	return (dir);
}

static int	execute_cd(t_shell *data, char *dir, char *cur_dir)
{
	char	*new_pwd;

	if (chdir(dir) != 0)
	{
		perror("minishell: cd");
		return (0);
	}
	data->envp_shell = set_env(data->envp_shell, "OLDPWD", cur_dir);
	new_pwd = getcwd(NULL, 0);
	if (new_pwd)
	{
		data->envp_shell = set_env(data->envp_shell, "PWD", new_pwd);
		free(new_pwd);
	}
	return (1);
}

static int	handle_cd_target(char **av, char *dir, char *cur_dir, int allocated)
{
	if (!dir)
	{
		if (!av[1])
			ft_putendl_fd("minishell: cd: HOME not set", 2);
		else if (ft_strcmp(av[1], "-") == 0)
			ft_putendl_fd("minishell: cd: OLDPWD not set", 2);
		free(cur_dir);
		if (allocated)
			free(dir);
		return (1);
	}
	return (0);
}

int	ft_cd(t_shell *data, char **av)
{
	char	*cur_dir;
	char	*dir;
	int		allocated;

	allocated = 0;
	if (!validate_args(av))
		return (1);
	cur_dir = getcwd(NULL, 0);
	if (!cur_dir)
		cur_dir = ft_strdup(get_env_val(data->envp_shell, "PWD"));
	dir = get_target_dir(av, data, &allocated);
	if (handle_cd_target(av, dir, cur_dir, allocated))
		return (1);
	if (!execute_cd(data, dir, cur_dir))
	{
		free(cur_dir);
		if (allocated)
			free(dir);
		return (1);
	}
	if (allocated)
		free(dir);
	free(cur_dir);
	return (0);
}

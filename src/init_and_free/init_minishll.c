/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_minishll.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zshkukan <zshkukan@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/29 21:10:15 by zshkukan          #+#    #+#             */
/*   Updated: 2026/04/30 10:46:54 by zshkukan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

static void	free_2d(char **arr)
{
	int	i;

	i = 0;
	if (!arr)
		return ;
	while (arr[i])
		free(arr[i++]);
	free(arr);
	arr = NULL;
}

static char	**init_envp(char **e)
{
	int		i;
	char	**envp;

	envp = NULL;
	if (!e)
		return (NULL);
	i = 0;
	while (e[i])
		i++;
	envp = ft_calloc(i + 1, sizeof(char *));
	if (!envp)
		return (NULL);
	i = 0;
	while (e[i])
	{
		envp[i] = ft_strdup(e[i]);
		if (!envp[i])
		{
			free_2d(envp);
			return (NULL);
		}
		i++;
	}
	envp[i] = NULL;
	return (envp);
}

static int	shell_level(t_shell *shell)
{
	char	*lvl;
	int		lvl_int;
	int		stat;

	lvl = get_env_val(shell->envp_shell, "SHLVL");
	if (lvl)
	{
		stat = shlvl_checked_next(lvl);
		if (stat == 1)
			lvl_int = 1;
		else if (stat == 2)
		{
			ft_putstr("minishell: warning: shell level (");
			ft_putstr(lvl);
			ft_putstr(") too high, resetting to 1 \n");
			lvl_int = 1;
		}
		else if (stat == 3)
			lvl_int = ft_atoi(lvl) + 1;
		else
			lvl_int = 0;
		return (lvl_int);
	}
	return (1);
}

static void	set_level(t_shell *shell)
{
	int		lvl;
	char	*new_lvl;
	char	**new_env;

	lvl = shell_level(shell);
	new_lvl = ft_itoa(lvl);
	if (!new_lvl)
		return ;
	new_env = set_env(shell->envp_shell, "SHLVL", new_lvl);
	free(new_lvl);
	if (!new_env)
		return ;
	if (new_env != shell->envp_shell)
		free_2d(shell->envp_shell);
	shell->envp_shell = new_env;
}

t_shell	*init_shell(char **envp_main)
{
	t_shell	*shell;

	if (!envp_main)
		return (NULL);
	shell = ft_calloc(1, sizeof(t_shell));
	if (!shell)
		return (NULL);
	shell->line_input = NULL;
	shell->envp_shell = init_envp(envp_main);
	if (!shell->envp_shell)
	{
		free(shell);
		return (NULL);
	}
	set_level(shell);
	shell->tokens = NULL;
	shell->commands = NULL;
	shell->exit_status = 0;
	return (shell);
}

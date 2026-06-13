/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_builtin.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: issa <issa@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/14 02:33:32 by  iabiesat         #+#    #+#             */
/*   Updated: 2026/04/27 23:40:45 by issa             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int	exec_builtin(t_shell *data, char **av)
{
	if (ft_strcmp(av[0], "echo") == 0)
		return (ft_echo(av));
	else if (ft_strcmp(av[0], "pwd") == 0)
		return (ft_pwd(data));
	else if (ft_strcmp(av[0], "export") == 0)
		return (ft_export(data, av));
	else if (ft_strcmp(av[0], "unset") == 0)
		return (ft_unset(data, av));
	else if (ft_strcmp(av[0], "exit") == 0)
		return (ft_exit(data, av));
	else if (ft_strcmp(av[0], "cd") == 0)
		return (ft_cd(data, av));
	else if (ft_strcmp(av[0], "env") == 0)
		return (ft_env(data));
	return (-1);
}

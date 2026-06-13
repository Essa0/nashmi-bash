/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pwd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: issa <issa@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/27 01:55:45 by  iabiesat         #+#    #+#             */
/*   Updated: 2026/04/21 23:44:33 by issa             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

/*
	customize pwd command
*/

int	ft_pwd(t_shell *data)
{
	char	*cur_path;
	char	*env_path;

	cur_path = getcwd(NULL, 0);
	if (cur_path)
	{
		ft_putendl_fd(cur_path, 1);
		free(cur_path);
		return (0);
	}
	env_path = get_env_val(data->envp_shell, "PWD");
	if (env_path)
		ft_putendl_fd(env_path, 1);
	return (0);
}

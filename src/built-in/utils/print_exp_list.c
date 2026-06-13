/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_exp_list.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: issa <issa@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/21 22:53:32 by issa              #+#    #+#             */
/*   Updated: 2026/04/21 23:41:26 by issa             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/minishell.h"

void	print_exp_list(t_shell *data)
{
	int		i;
	char	*eq;

	i = 0;
	while (data->envp_shell[i])
	{
		ft_putstr_fd("declare -x ", 1);
		eq = ft_strchr(data->envp_shell[i], '=');
		if (eq)
		{
			write(1, data->envp_shell[i], eq - data->envp_shell[i] + 1);
			ft_putstr_fd("\"", 1);
			ft_putstr_fd(eq + 1, 1);
			ft_putendl_fd("\"", 1);
		}
		else
			ft_putendl_fd(data->envp_shell[i], 1);
		i++;
	}
}

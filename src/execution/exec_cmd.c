/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_cmd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: issa <issa@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/15 00:21:05 by  iabiesat         #+#    #+#             */
/*   Updated: 2026/04/27 16:46:47 by issa             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	exec_cmd(t_shell *data, t_cmd *cmd)
{
	int	status;

	if (handle_empty_cmd(data, cmd))
		return ;
	status = exec_builtin(data, cmd->args);
	if (status != -1)
	{
		data->exit_status = status;
		return ;
	}
	external_cmd(data, cmd);
}

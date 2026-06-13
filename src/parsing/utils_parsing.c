/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_parsing.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zshkukan <zshkukan@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/29 20:15:30 by zshkukan          #+#    #+#             */
/*   Updated: 2026/04/29 20:15:32 by zshkukan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int	check_tok_type(t_token *t)
{
	if (t->type != TOKEN_WORD && t->type != TOKEN_WORD_DQ
		&& t->type != TOKEN_WORD_SQ)
		return (1);
	return (0);
}

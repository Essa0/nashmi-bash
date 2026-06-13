/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_list.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zshkukan <zshkukan@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/29 21:11:43 by zshkukan          #+#    #+#             */
/*   Updated: 2026/04/29 21:12:06 by zshkukan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TOKEN_LIST_H
# define TOKEN_LIST_H

# include "structs.h"

int		add_last(t_nodes **head, t_nodes *next);
t_nodes	*new_node(t_token *token);
void	free_token_list(t_nodes *head);
void	free_token(t_nodes *token);

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zshkukan <zshkukan@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/29 21:11:33 by zshkukan          #+#    #+#             */
/*   Updated: 2026/04/30 10:46:10 by zshkukan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

enum	e_tv_type
{
	TOKEN_WORD,
	TOKEN_WORD_SQ,
	TOKEN_WORD_DQ,
	TOKEN_PIPE,
	TOKEN_REDIR_IN,
	TOKEN_REDIR_OUT,
	TOKEN_REDIR_APPEND,
	TOKEN_HEREDOC,
	FLAG_E
};

typedef struct s_token
{
	char			*value;
	enum e_tv_type	type;
}	t_token;

typedef struct s_node
{
	t_token			*data;
	struct s_node	*next;
	struct s_node	*prev;	
}		t_nodes;

typedef struct s_redir
{
	enum e_tv_type	type;
	char			*file;
}		t_redir;

typedef struct s_command_block
{
	char					**args;
	int						*types;
	t_redir					*redirs;
	struct s_command_block	*next;
}				t_cmd;

typedef struct s_minishell
{
	char	*line_input;
	char	**envp_shell;	
	t_nodes	*tokens;
	t_cmd	*commands;
	int		exit_status;
	int		should_exit;
	int		in_pipe;
}				t_shell;

#endif

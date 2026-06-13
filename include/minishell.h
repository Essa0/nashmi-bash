/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iabiesat <iabiesat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/29 21:11:26 by zshkukan          #+#    #+#             */
/*   Updated: 2026/04/30 18:31:54 by iabiesat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# define PROMPT "minishell > "

# include "token_list.h"
# include "libft/libft.h"
# include "libft/ft_printf.h"
# include "structs.h"
# include "execution.h"
# include <sys/param.h>
# include <errno.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <dirent.h>
# include <signal.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <readline/readline.h>
# include <readline/history.h>

extern int	g_signal;
int		shell(t_shell *shell);
t_shell	*init_shell(char **envp_main);
void	free_string_array(char **arr);
int		shlvl_checked_next(char *lvl);
void	free_shell(t_shell *shell);
void	free_shell_partial(t_shell *shell);
int		history_add(char *line);
int		check_required(t_shell *shell, char *line);
t_nodes	*tokenization(char *line);
t_token	*lexer(char *line, int *index);
int		check_char_t(char c);
int		skip_inner_quote(char *line, int *index);
int		copy_without_quotes(char *src, char *dst);
char	*remove_quotes(char *str);
char	*get_env_val(char **env, char *key);
char	*expand_tilde(char *str, char **envp);

char	*handle_dq(char *s, int *i, t_shell *sh);
int		append_dq_part(char **res, char *s, int *i, t_shell *sh);
char	*get_dq_part(char *s, int *i, t_shell *sh);
char	*handle_sq(char *s, int *i);
char	*expand_var(char *s, int *i, t_shell *sh);
char	*handle_normal(char *s, int *i, t_shell *sh);
char	*expand_string(char *str, t_shell *shell);

int		expand_all(t_nodes **head_t, t_shell *shell);
int		is_empty_expanded(char *value);

char	*get_word(char *s, int *i);
int		append_node(t_nodes **first, t_nodes **last, char *word);
int		split_value_to_nodes(char *value, t_nodes **first);
t_nodes	*last_node(t_nodes *first);
void	link_replacement(t_nodes **head, t_nodes *node, t_nodes *first);
void	replace_node_with_split(t_nodes **head, t_nodes *node);
void	split_after_exp(t_nodes **head);

void	remove_tokens(t_nodes **head);
t_nodes	*new_node_from_value(char *val);
char	*append(char *res, char *add);
t_cmd	*parsing(t_nodes *head_t);
int		check_syntax(t_nodes *head, t_shell *shell);
int		check_tok_type(t_token *t);

int		num_args(t_nodes *start);
int		num_redir(t_nodes *start);
int		alloc_args_types(t_nodes *start, t_cmd **cmd);
int		alloc_redirs(t_nodes *start, t_cmd **cmd);

void	build_cmd(t_nodes *start, t_cmd **cmd);
void	free_cmd(t_cmd **cmd);
void	free_args(t_cmd *cmd);
int		redirec(t_redir *re);
int		handle_heredoc(t_cmd *cmd, t_shell *shell);
void	heredoc_sigint(int sig);
void	setup_heredoc_signals(void);
void	print_error(char *del);
void	setup_interactive_signals(void);
#endif

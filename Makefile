# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: iabiesat <iabiesat@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/04/29 21:34:53 by zshkukan          #+#    #+#              #
#    Updated: 2026/04/30 17:21:49 by iabiesat         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minishell

CC = cc
CFLAGS = -Wall -Wextra -Werror -g
RM = rm -rf

LIBFT = $(LIBFT_DIR)/libft.a
LIBFT_DIR = include/libft

INCLUDES = -Iinclude -I$(LIBFT_DIR)

SRC_DIR = src
BUILTIN_DIR = $(SRC_DIR)/built-in
EXEC_DIR = $(SRC_DIR)/execution
EXPAND_DIR = $(SRC_DIR)/expansion
INIT_DIR = $(SRC_DIR)/init_and_free
PARSING_DIR = $(SRC_DIR)/parsing
REDIR_DIR = $(SRC_DIR)/redirections
TOKEN_DIR = $(SRC_DIR)/tokenization_and_lexer
HISTORY_DIR = $(SRC_DIR)/history_utils
VALID_DIR = $(SRC_DIR)/validation_not_required


SRC = \
	$(SRC_DIR)/main.c \
	$(SRC_DIR)/shell.c \
	\
	$(BUILTIN_DIR)/ft_cd.c \
	$(BUILTIN_DIR)/ft_echo.c \
	$(BUILTIN_DIR)/ft_exit.c \
	$(BUILTIN_DIR)/ft_export.c \
	$(BUILTIN_DIR)/ft_pwd.c \
	$(BUILTIN_DIR)/ft_unset.c \
	$(BUILTIN_DIR)/utils/free_env.c \
	$(BUILTIN_DIR)/utils/get_env_val.c \
	$(BUILTIN_DIR)/utils/print_exp_list.c \
	$(BUILTIN_DIR)/utils/set_env.c \
	\
	$(EXEC_DIR)/check_builtin.c \
	$(EXEC_DIR)/child_status.c \
	$(EXEC_DIR)/exec_cmd.c \
	$(EXEC_DIR)/exec_pipe.c \
	$(EXEC_DIR)/exec_utils.c \
	$(EXEC_DIR)/external_cmd.c \
	$(EXEC_DIR)/get_cmd_path.c \
	\
	$(EXPAND_DIR)/after_expand.c \
	$(EXPAND_DIR)/after_expand1.c \
	$(EXPAND_DIR)/expand.c \
	$(EXPAND_DIR)/expand1.c \
	$(EXPAND_DIR)/set_exp_token.c \
	$(EXPAND_DIR)/utils.c \
	$(EXPAND_DIR)/utils2.c \
	\
	$(INIT_DIR)/free_minishell.c \
	$(INIT_DIR)/init_minishll.c \
	$(INIT_DIR)/utils.c \
	\
	$(PARSING_DIR)/bulid_cmd1.c \
	$(PARSING_DIR)/build_cmd.c \
	$(PARSING_DIR)/check_syntax.c \
	$(PARSING_DIR)/free_cmd.c \
	$(PARSING_DIR)/parsing.c \
	$(PARSING_DIR)/utils_parsing.c \
	\
	$(REDIR_DIR)/heredoc.c \
	$(REDIR_DIR)/redirections.c \
	$(REDIR_DIR)/utils_here.c \
	\
	$(TOKEN_DIR)/free_token_list.c \
	$(TOKEN_DIR)/token_list.c \
	$(TOKEN_DIR)/tokenization.c \
	$(TOKEN_DIR)/tokens.c \
	$(TOKEN_DIR)/utiles.c \
	\
	$(HISTORY_DIR)/history_utils.c \
	\
	$(VALID_DIR)/checker.c

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(LIBFT) $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -L ./include/libft -lft -lreadline -o $(NAME)

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	$(RM) $(OBJ)
	$(MAKE) -C $(LIBFT_DIR) clean

fclean: clean
	$(RM) $(NAME)
	$(MAKE) -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re
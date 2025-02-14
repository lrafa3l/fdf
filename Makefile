# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lrafael <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/07/28 13:09:10 by lrafael           #+#    #+#              #
#    Updated: 2024/09/05 14:52:44 by lrafael          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			= fdf
CC				= cc
CFLAGS			= -Wall -Wextra -Werror

# Directories
SRCS_DIR		= srcs
OBJS_DIR		= obj
LIBFT_DIR		= ./libft
MINILIBX_DIR	= ./minilibx-linux
INCLUDE			= -Iincs

# Source and Objects files
SRCS			= $(SRCS_DIR)/fdf_main.c			\
					$(SRCS_DIR)/fdf_extra.c			\
					$(SRCS_DIR)/fdf_map_process.c	\
					$(SRCS_DIR)/fdf_hooks.c			\
					$(SRCS_DIR)/fdf_draw.c			\
					$(SRCS_DIR)/fdf_draw_extra.c	\
					$(SRCS_DIR)/fdf_draw_lines.c	\
					$(SRCS_DIR)/fdf_math.c	\
					$(SRCS_DIR)/fdf_file_check.c\
					$(SRCS_DIR)/fdf_extra_plus.c

OBJS			= $(SRCS:$(SRCS_DIR)/%.c=$(OBJS_DIR)/%.o)

# Libraries
LIBS			= -L$(MINILIBX_DIR) -lmlx_Linux -lXext -lX11 -lm -L$(LIBFT_DIR) -lft

# Colors
RESET			= \033[0m
BOLD			= \033[1m
RED				= \033[31m
GREEN			= \033[32m

# Rules
all: $(NAME)

$(OBJS_DIR)/%.o: $(SRCS_DIR)/%.c
	@mkdir -p $(OBJS_DIR)
	@$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@

$(NAME): $(OBJS)
	@make -s -C $(LIBFT_DIR)
	@make -s -C $(MINILIBX_DIR)
	@$(CC) $(OBJS) $(LIBS) -o $(NAME)
	@echo "\033c"
	@echo "\n\t\t$(GREEN)$(BOLD) ~ Fil de Fer(FDF) Compiled! ~$(RESET) \n"

n:
	@norminette .

clean:
	@make clean -s -C $(LIBFT_DIR)
	@make clean -s -C $(MINILIBX_DIR)
	@rm -rf $(OBJS_DIR)
	@echo "\033c"
	@echo "\n\t\t\$(RED)$(BOLD)Objects Deleted!$(RESET)\n"

fclean: clean
	@make fclean -s -C $(LIBFT_DIR)
	@rm -f $(NAME)
	@echo "\033c"
	@echo "\n\t\t\$(RED)$(BOLD)Everything Deleted!$(RESET)\n"

re: fclean all

.PHONY: all n clean fclean re

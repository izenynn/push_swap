# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dpoveda- <me@izenynn.com>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/09/29 10:15:42 by dpoveda-          #+#    #+#              #
#    Updated: 2021/10/09 21:23:59 by dpoveda-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# NAMES
NAME = push_swap

LIBFT_NAME = libft.a

# MAKE
MAKE = make

# COMPILER
CC = gcc

CFLAGS = -Wall -Wextra -Werror -fsanitize=address -g3

CFLAGS += -I ./$(LIBFT_DIR)/inc -I ./inc

LDFLAGS = -L $(LIBFT_DIR)

LDLIBS = -lft

LIBFT = $(LIBFT_DIR)/$(LIBFT_NAME)

# DIRS
SRCS_DIR = src

OBJS_DIR = obj

LIBFT_DIR = libft

# SOURCES
SRCS_FILES =	push_swap.c		handle_args.c		check_args.c		\
				tab_utils.c		ops_s.c				ops_p.c				\
				ops_r.c			ops_rr.c			handle_sort.c		\
				sort_utils.c	sort_small.c

OBJS_FILES = $(SRCS_FILES:%.c=%.o)

SRCS = $(addprefix $(SRCS_DIR)/, $(SRCS_FILES))

OBJS = $(addprefix $(OBJS_DIR)/, $(OBJS_FILES))

.PHONY: all bonus clean fclean re norm

all: $(NAME)

$(NAME): $(LIBFT) $(OBJS)
	$(CC) $^ -o $@ $(CFLAGS) $(LDFLAGS) $(LDLIBS)

$(LIBFT):
	$(MAKE) all -sC $(LIBFT_DIR)

$(OBJS_DIR)/%.o: $(SRCS_DIR)/%.c | $(OBJS_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJS_DIR):
	mkdir -p $(OBJS_DIR)

clean:
	$(MAKE) clean -sC $(LIBFT_DIR)
	rm -rf $(LIBFT_NAME)
	rm -rf $(OBJS_DIR)

fclean: clean
	$(MAKE) fclean -sC $(LIBFT_DIR)
	rm -rf $(NAME)

re: fclean all

norm:
	@clear
	@echo "===== NORMINETTE ====="
	@norminette .

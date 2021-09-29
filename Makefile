# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dpoveda- <me@izenynn.com>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/09/29 10:15:42 by dpoveda-          #+#    #+#              #
#    Updated: 2021/09/29 10:49:57 by dpoveda-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

LIBFT_NAME = libft.a

MAKE = make

CC = gcc

CFLAGS = -Wall -Wextra -Werror

ARFLAGS = -rcs

H_DIR = inc

LIBFT_DIR = libft

LIBFT_H_DIR = $(LIBFT_DIR)/inc

SRCS_DIR = src

OBJS_DIR = obj

SRC_PUSH_SWAP = push_swap.c

SRCS_FILES =	prueba.c

OBJS_FILES = $(SRCS_FILES:%.c=%.o)

SRCS = $(addprefix $(SRCS_DIR)/, $(SRCS_FILES))

OBJS = $(addprefix $(OBJS_DIR)/, $(OBJS_FILES))

LIBFT = $(addprefix $(LIBFT_DIR)/, $(LIBFT_NAME))

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(LIBFT) $(OBJS) $(SRC_PUSH_SWAP)
	cp $(LIBFT) .
	ar $(ARFLAGS) $(LIBFT_NAME) $(OBJS)
	$(CC) $(CFLAGS) $(SRC_PUSH_SWAP) $(LIBFT) $(OBJS) -o $(NAME) -I $(LIBFT_H_DIR) -I $(H_DIR)

$(LIBFT):
	$(MAKE) all -sC $(LIBFT_DIR)

$(OBJS_DIR)/%.o: $(SRCS_DIR)/%.c | $(OBJS_DIR)
	$(CC) $(CFLAGS) -c $< -o $@ -I $(LIBFT_H_DIR)

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

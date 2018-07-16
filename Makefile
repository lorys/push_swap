# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: llopez <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/05/09 13:36:27 by llopez            #+#    #+#              #
#    Updated: 2018/07/16 11:59:13 by llopez           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

BIN_NAME_1 = push_swap
BIN_NAME_2 = checker

CC = gcc

SRC_GLOBAL = src/p.c \
	  src/r.c \
	  src/s.c \
	  src/utils.c \

SRC_BIN_NAME_1 = main_push_swap.c

SRC_BIN_NAME_2 = main_checker.c

INCLUDES = -I libft/ libft/libft.a -I libft/get_next_line.h -I .

FLAGS = -Wall -Werror -Wextra

all:
	@printf "\033[31;1m Making LIBFT \033[0m\n"
	@make -C ./libft/
	@printf "\033[32;1m LIBFT made \033[0m\n"
	@printf "\033[31;1m Compiling $(BIN_NAME_1) \033[0m\n"
	@$(CC) -o $(BIN_NAME_2) $(FLAGS) $(SRC_GLOBAL) $(SRC_BIN_NAME_2) $(INCLUDES)
	@printf "\033[32;1m Compiled $(BIN_NAME_1) ! \033[0m\n"
	@printf "\033[31;1m Compiling $(BIN_NAME_2) \033[0m\n"
	@$(CC) -o $(BIN_NAME_1) $(FLAGS) $(SRC_GLOBAL) $(SRC_BIN_NAME_1) $(INCLUDES)
	@printf "\033[32;1m Compiled $(BIN_NAME_1) ! \033[0m\n"

clean:
	@printf "\033[41m Cleaned ! \033[0m\n"

fclean:
	@printf "\n\033[41m Cleaning... \033[0m\n"
	@rm -rf push_swap checker
	@printf "\n\033[42m Cleaned ! \033[0m\n"

re: fclean all

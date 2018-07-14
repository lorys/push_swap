# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: llopez <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/05/09 13:36:27 by llopez            #+#    #+#              #
#    Updated: 2018/07/14 19:57:50 by llopez           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

BIN_NAME_1 = push_swap
BIN_NAME_2 = checker

SRC = src/p.c \
	  src/r.c \
	  src/s.c \
	  src/utils.c \

all: libft/libft.a
	gcc -o $(BIN_NAME_1) $(SRC) main_push_swap.c -I libft/ libft/libft.a -I libft/get_next_line.h -I .
	gcc -o $(BIN_NAME_2) $(SRC) main_checker.c -I libft/ libft/libft.a -I libft/get_next_line.h -I .


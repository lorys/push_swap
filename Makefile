# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: llopez <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/05/09 13:36:27 by llopez            #+#    #+#              #
#    Updated: 2018/07/17 01:02:58 by llopez           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

BIN_NAME_1 = push_swap
BIN_NAME_2 = checker

CC = gcc

SRC_GLOBAL = src/p.c \
	  src/r.c \
	  src/s.c \
	  src/a_listlen.c \
	  src/errors.c \
	  src/fill_list.c \
	  src/ft_nbrnbr.c \
	  src/get_maillon.c \
	  src/get_max.c \
	  src/get_minus.c \
	  src/get_mediane.c \
	  src/get_position_int.c \
	  src/good_params.c \
	  src/lastoflist.c \
	  src/prepare_sort.c \
	  src/print_list.c \
	  src/print_multiple_list.c \
	  src/quick_sort.c \
	  src/sort_insert.c \
	  src/sort_list.c \
	  src/sort_logic.c \
	  src/sorted.c \
	  src/valid_int.c \
	  src/valid_op.c \
	  src/free_list.c

SRC_BIN_NAME_1 = main_push_swap.c

SRC_BIN_NAME_2 = main_checker.c

INCLUDES = -Iincludes

FLAGS = -Wall -Werror -Wextra

OBJDIR = obj/

OBJ = $(patsubst %.c, %.o, $(addprefix $(OBJDIR), $(notdir $(SRC_GLOBAL))))

LIBFT = libft/libft.a

all: $(BIN_NAME_1) $(BIN_NAME_2)

$(OBJDIR)%.o: src/%.c includes/push_swap.h
	@mkdir -p $(OBJDIR)
	@printf "\033[33m $@ \033[0m\n"
	@$(CC) -o $@ -c $< $(INCLUDES) $(FLAGS)

$(BIN_NAME_1): $(LIBFT) $(OBJ) $(SRC_BIN_NAME_1)
	@printf "\033[31;1m Compiling $(BIN_NAME_1) \033[0m\n"
	@$(CC) -o $(BIN_NAME_1) $(FLAGS) $(OBJ) $(SRC_BIN_NAME_1) $(INCLUDES) $(LIBFT)
	@printf "\033[32;1m Compiled $(BIN_NAME_1) ! \033[0m\n"

$(BIN_NAME_2): $(LIBFT) $(OBJ) $(SRC_BIN_NAME_2)
	@printf "\033[31;1m Compiling $(BIN_NAME_2) \033[0m\n"
	@$(CC) -o $(BIN_NAME_2) $(FLAGS) $(OBJ) $(SRC_BIN_NAME_2) $(INCLUDES) $(LIBFT)
	@printf "\033[32;1m Compiled $(BIN_NAME_2) ! \033[0m\n"

$(LIBFT):
	@printf "\033[31;1m Making LIBFT \033[0m\n"
	@make -C libft/
	@printf "\033[32;1m LIBFT made \033[0m\n"

clean:
	@printf "\033[41m Cleaned ! \033[0m\n"

fclean:
	make -C libft/ fclean
	@printf "\n\033[41m Cleaning... \033[0m\n"
	@rm -rf obj/ push_swap checker
	@printf "\n\033[42m Cleaned ! \033[0m\n"

re: fclean all

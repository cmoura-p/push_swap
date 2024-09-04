# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cmoura-p <cmoura-p@students.42porto.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/07 16:49:36 by cmoura-p          #+#    #+#              #
#    Updated: 2024/09/04 20:19:51 by cmoura-p         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= push_swap
CC	= gcc
FLAGS	= -Wall -Werror -Wextra -g
RM	= rm -f

LIBFT	= ./libft/libft.a
SRC_DIR	= src/
OBJ_DIR	= obj/

SRCS	=	$(SRC_DIR)main.c \
		$(SRC_DIR)push_swap.c \
		$(SRC_DIR)ft_errors.c \
		$(SRC_DIR)ft_stack.c \
		$(SRC_DIR)ft_split.c\
		$(SRC_DIR)ft_utils.c \
		$(SRC_DIR)op_swap.c \
		$(SRC_DIR)op_push.c \
		$(SRC_DIR)op_rev_rotate.c \
		$(SRC_DIR)op_rotate.c \
		$(SRC_DIR)short_sort.c
#		$(SRC_DIR)real_sort.c\

OBJ	= $(patsubst $(SRC_DIR)%.c,$(OBJ_DIR)%.o,$(SRCS))

start:
	@make all

$(LIBFT):
	@make -C ./libft

all:	$(NAME)

$(NAME):$(OBJ) $(LIBFT)
	@$(CC) $(FLAGS) $(OBJ) $(LIBFT) -o $(NAME)

$(OBJ_DIR)%.o:	$(SRC_DIR)%.c
	@mkdir -p $(@D)
	@$(CC) $(FLAGS) -c $< -o $@

clean:
	@$(RM) -r $(OBJ_DIR)
	@make clean -C ./libft

fclean:	clean
	@$(RM) $(NAME)
	@$(RM) $(LIBFT)

re:	fclean all

.PHONY:	start all clean fclean re

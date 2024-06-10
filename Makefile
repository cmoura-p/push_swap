# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cmoura-p <cmoura-p@students.42porto.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/07 16:49:36 by cmoura-p          #+#    #+#              #
#    Updated: 2024/06/10 18:14:58 by cmoura-p         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Iniciando
NAME		= push_swap

# Compilacao e CFlags
CC			= gcc
CFLAG		= -Wall -Werror -Wextra
RM			= rm -f

# Diretorios
LIBFT		= ./libft/libft.a
SRC_DIR		= src/
OBJ_DIR		= obj/

# Arquivos Fonte

SRCS				=	$(SRC_DIR)push_swap.c \
						$(SRC_DIR)op_push.c \
						$(SRC_DIR)op_rev_rotate.c \
						$(SRC_DIR)op_rotate.c \
						$(SRC_DIR)op_swap.c \
						$(SRC_DIR)ft_stacks.c \
						$(SRC_DIR)ft_errors.c \
						$(SRC_DIR)quick_sort.c \
						$(SRC_DIR)big_sort.c

# Aplicando o padrao de substituicao de cada fonte me SRC e criando uma lista correspondente de objetos
OBJ 				= $(patsubst $(SRC_DIR)%.c,$(OBJ_DIR)%.o,$(SRCS))

# Montando as regras
start:
	@make all

$(LIBFT):
	@make -C ./libft

all: 		$(NAME)

$(NAME):	$(OBJ) $(LIBFT)
			@$(CC) $(CFLAG) $(OBJ) $(LIBFT) -o $(NAME)

# Criando os arquivos objeto a partir dos arquivos fonte
$(OBJ_DIR)%.o:	$(SRC_DIR)%.c
				@mkdir -p $(@D)
				@$(CC) $(CFLAG) -c $< -o $@

clean:
	@$(RM) -r $(OBJ_DIR)
	@make clean -C ./libft

fclean: 	clean
			@$(RM) $(NAME)
#			@$(RM) $(LIBFT)

re: 		fclean all

# Phony representa acao nos arquivos
.PHONY: 	start all clean fclean re

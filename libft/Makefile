# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cmoura-p <cmoura-p@students.42porto.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/05 19:42:04 by cmoura-p          #+#    #+#              #
#    Updated: 2024/06/07 17:24:17 by cmoura-p         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			= libft.a

CC				= cc
CFLAG			= -Wall -Wextra -Werror -I
C_SOURCE 		= ft_atol.c ft_bzero.c ft_calloc.c ft_memcpy.c \
				ft_memset.c ft_split.c ft_strdup.c ft_strlen.c ft_substr.c
OBJ = $(C_SOURCE:.c=.o)

RM				= rm -f
AR				= ar rc

all: 		$(NAME)

$(NAME): 	$(OBJ)
			@$(AR) $(NAME) $(OBJ)

#$(OBJ):	$(C_SOURCE)
#			@$(CC) $(CFLAG) -c $(C_SOURCE)

clean:
				@$(RM) -r $(OBJ)
#				@$(RM) .cache_exists

fclean: 		clean
				@$(RM) $(NAME)

re: 			fclean all

.PHONY: 		all clean fclean re


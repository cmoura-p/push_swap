# Standard
NAME			= libft.a

# Compiling and Flags
CC				= gcc
FLAGS			= -Wall -Wextra -Werror
RM				= rm -f
AR				= ar rcs

# Source Files
C_SOURCE = 	ft_atol.c ft_bzero.c ft_calloc.c ft_memset.c ft_strlen.c \

PF_SOURCE = $(wildcard ./printf/*.c)

OBJ = $(C_SOURCE:.c=.o) $(PF_SOURCE:./printf/%.c=./printf/%.o)

# Build rules
all: 		$(NAME)

$(NAME): 	$(OBJ)
			@$(AR) $(NAME) $(OBJ)

#$(OBJ):	$(C_SOURCE)
#			@$(CC) $(CFLAG) -c $(C_SOURCE)

%.o: %.c
			@$(CC) $(FLAGS) -c $< -o $@

./printf/%.o: ./printf/%.c
			@$(CC) $(FLAGS) -c $< -o $@

clean:
				@$(RM) -r $(OBJ)
				@$(RM) .cache_exists

fclean: 		clean
				@$(RM) $(NAME)

re: 			fclean all

.PHONY: 		all clean fclean re


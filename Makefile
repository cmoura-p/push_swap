# Standard
NAME				= push_swap

# Directories
LIBFT				= ./libft/libft.a
SRC_DIR				= src/
OBJ_DIR				= obj/

# Compiler and CFlags
CC					= gcc
CFLAG				= -Wall -Werror -Wextra -I
RM					= rm -f

# Source Files
PUSH_SWAP_SRC		=	$(SRC_DIR)op_push.c \
						$(SRC_DIR)op_rev_rotate.c \
						$(SRC_DIR)op_rotate.c \
						$(SRC_DIR)op_swap.c \
						$(SRC_DIR)ft_stacks.c \
						$(SRC_DIR)ft_errors.c \
						$(SRC_DIR)quick_sort.c \
						$(SRC_DIR)big_sort.c


# Apply the pattern substitution to each source file in SRC and produce a corresponding list of object files in the OBJ_DIR
OBJ 				= $(PUSH_SWAP_SRC:.c=(OBJ_DIR).o)

# Build rules
start:
					@make all

$(LIBFT):
					@make -C ./libft

all: 				$(NAME)

$(NAME): 			$(OBJ) $(LIBFT)
					@$(CC) $(CFLAGS) $(INC) $(OBJ) $(LIBFT) -o $(NAME)

# Compile object files from source files
$(OBJ_DIR)%.o:		$(SRC_DIR)%.c
					@mkdir -p $(@D)
					@$(CC) $(CFLAGS) $(INC) -c $< -o $@

clean:
					@$(RM) -r $(OBJ_DIR)
					@make clean -C ./libft

fclean: 			clean
					@$(RM) $(NAME)
					@$(RM) $(LIBFT)

re: 				fclean all

# Phony targets represent actions not files
.PHONY: 			start all clean fclean re

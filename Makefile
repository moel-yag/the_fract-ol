# **************************************************************************** #
# Makefile for fract'ol project                                                #
# **************************************************************************** #

# Project name
NAME		= fractol

# Compiler and flags
CC			= cc
CFLAGS		= -Wall -Wextra -Werror
MLX_FLAGS	= -L minilibx-linux -lmlx -lXext -lX11 -lm

# Directories
SRC_DIR		= srcs
OBJ_DIR		= objs
INC_DIR		= includes
LIBFT_DIR	= libft
MLX_DIR		= minilibx-linux

# Source files
SRCS		= main.c init.c render.c events.c string_utils.c math_utils.c
OBJS		= $(addprefix $(OBJ_DIR)/, $(SRCS:.c=.o))

# Includes
INCLUDES	= -I $(INC_DIR) -I $(LIBFT_DIR) -I $(MLX_DIR)

# Colors
GREEN		= \033[0;32m
RED			= \033[0;31m
RESET		= \033[0m

# Rules
all: $(NAME)

$(NAME): $(OBJS)
	@make -C $(LIBFT_DIR)
	@make -C $(MLX_DIR)
	@$(CC) $(CFLAGS) $(OBJS) -L $(LIBFT_DIR) -lft $(MLX_FLAGS) -o $(NAME)
	@echo "$(GREEN)Project $(NAME) compiled successfully!$(RESET)"

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(OBJ_DIR)
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	@make clean -C $(LIBFT_DIR)
	@make clean -C $(MLX_DIR)
	@rm -rf $(OBJ_DIR)
	@echo "$(RED)Object files removed.$(RESET)"

fclean: clean
	@make fclean -C $(LIBFT_DIR)
	@rm -f $(NAME)
	@echo "$(RED)Executable $(NAME) removed.$(RESET)"

re: fclean all

.PHONY: all clean fclean re

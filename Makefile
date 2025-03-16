NAME		= fractol

CC			= cc
CFLAGS		= -Wall -Wextra -Werror
MLX_FLAGS	= -L minilibx-linux -lmlx -lXext -lX11 -lm

SRC_DIR		= srcs
OBJ_DIR		= objs
INC_DIR		= includes
MLX_DIR		= minilibx-linux

SRCS		= main.c init.c render.c events.c string_utils.c math_utils.c
OBJS		= $(addprefix $(OBJ_DIR)/, $(SRCS:.c=.o))

INCLUDES	= -I $(INC_DIR) -I $(MLX_DIR)

all: $(NAME)

$(NAME): $(OBJS)
	@make -C $(MLX_DIR)
	@$(CC) $(CFLAGS) $(OBJS) -lft $(MLX_FLAGS) -o $(NAME)
	@echo "Project $(NAME) compiled successfully!"

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(OBJ_DIR)
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	@make clean -C $(MLX_DIR)
	@rm -rf $(OBJ_DIR)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re

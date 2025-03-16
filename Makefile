NAME		= fractol

CC			= cc
CFLAGS		= -Wall -Wextra -Werror
MLX_FLAGS	= -Lminilibx-linux -lmlx_Linux -lX11 -lXext -lm

SRC_DIR		= srcs
OBJ_DIR		= objs

SRCS		= main.c init.c render.c events.c string_utils.c math_utils.c
OBJS		= $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	@make -C $(MLX_DIR)
	@$(CC) $(CFLAGS) $(OBJS) $(MLX_FLAGS) -o $(NAME)

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

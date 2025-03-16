NAME		= fractol

CC			= cc
CFLAGS		= -Wall -Wextra -Werror
MLX_FLAGS	= -I../minilibx-linux -Lminilibx-linux -lmlx_Linux -lX11 -lXext

SRCS		= main.c init.c render.c events.c string_utils.c math_utils.c
OBJS		= $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	@$(CC) $(CFLAGS) $(OBJS) $(MLX_FLAGS) -o $(NAME)

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@rm -rf $(OBJS)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re

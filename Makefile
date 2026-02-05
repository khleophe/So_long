
SRCS        = ./main.c\
			./parsing.c\

OBJS        = $(SRCS:.c=.o)

CC            = cc
CFLAGS        = -Wall -Wextra -Werror
NAME        = so_long

MLX_DIR        = ./minilibx-linux
MLX_FLAGS    = -L$(MLX_DIR) -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz

RM            = rm -f


all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(MLX_FLAGS) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -I. -I$(MLX_DIR) -c $< -o $@

clean:
	$(RM) $(OBJS)
	make clean

fclean: clean
	$(RM) $(NAME)
	make fclean

re: fclean all

.PHONY: all clean fclean re
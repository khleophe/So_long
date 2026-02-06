
SRCS        =    ./main.c\
                ./init_map.c\

OBJS        = $(SRCS:.c=.o)

CC            = cc
CFLAGS        = -Wall -Wextra -Werror
NAME        = so_long

LIBFT_DIR    = ./libft
LIBFT        = $(LIBFT_DIR)/libft.a

MLX_DIR        = ./minilibx-linux
MLX_FLAGS    = -L$(MLX_DIR) -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz

RM            = rm -f


all: $(NAME)

$(NAME): $(OBJS) $(LIBFT)
    $(CC) $(CFLAGS) $(OBJS) $(LIBFT) $(MLX_FLAGS) -o $(NAME)

%.o: %.c
    $(CC) $(CFLAGS) -I. -I$(LIBFT_DIR) -I$(MLX_DIR) -c $< -o $@

$(LIBFT):
    make -C $(LIBFT_DIR)

clean:
    $(RM) $(OBJS)
    make clean -C $(LIBFT_DIR)

fclean: clean
    $(RM) $(NAME)
    make fclean -C $(LIBFT_DIR)

re: fclean all

.PHONY: all clean fclean re
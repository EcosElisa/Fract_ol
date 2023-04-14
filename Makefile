NAME = fractol
CFLAGS = -Wall -Wextra -Werror -g3
MLX_FLAGS = -lmlx -lX11 -lmlx -lXext

LIBFT = ./libft/libft.a
PATH_SRCS = ./mandatory/sources/
PATH_INCLUDES = ./mandatory/includes/
PATH_OBJS = ./mandatory/objects/

SRCS = $(addprefix $(PATH_SRCS),\
			check_arg.c\
			colors.c\
			fractol.c\
			fractol_utils.c\
			mandelbrot.c)

OBJS = $(patsubst $(PATH_SRCS)%.c, $(PATH_OBJS)%.o, $(SRCS))

INCLUDES = -I $(PATH_INCLUDES)

all: libft $(NAME)

libft:
		make -C ./libft

$(NAME): $(OBJS) $(LIBFT)
		cc $(OBJS) $(LIBFT) $(MLX_FLAGS) -o $(NAME)

$(PATH_OBJS)%.o: $(PATH_SRCS)%.c
	mkdir -p $(PATH_OBJS)
	cc $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
			make clean -C ./libft
			rm -rf $(PATH_OBJS)

fclean:		clean
			make fclean -C ./libft
			rm -rf $(NAME)

re:			fclean all

.PHONY: all clean fclean re libft
NAME = fractol
CFLAGS = -Wall -Wextra -Werror -g3
MLX_FLAGS = -lmlx -lX11 -lmlx -lXext

LIBFT = ./libft/libft.a
PATH_SRCS = ./mandatory/sources/
PATH_INCLUDES = ./includes/
PATH_OBJS = ./mandatory/objects/

BONUS_NAME = ./fractol_bonus
PATH_SRCS_B = ./bonus/sources/
PATH_OBJS_B = ./bonus/objects/

SRCS = $(addprefix $(PATH_SRCS),\
			check_arg.c\
			colors.c\
			fractol.c\
			fractol_utils.c\
			help_msg.c\
			julia.c\
			key_hooks.c\
			mandelbrot.c\
			mouse_hooks.c)

OBJS = $(patsubst $(PATH_SRCS)%.c, $(PATH_OBJS)%.o, $(SRCS))

INCLUDES = -I $(PATH_INCLUDES)

BONUS_SRCS = $(addprefix $(PATH_SRCS_B),\
			check_arg_bonus.c\
			colors_bonus.c\
			fractol_bonus.c\
			fractol_utils_bonus.c\
			help_msg_bonus.c\
			julia_bonus.c\
			keys_hooks_bonus.c\
			mandelbrot_bonus.c\
			mouse_hooks_bonus.c\
			tricorn.c)

BONUS_OBJS = $(patsubst $(PATH_SRCS_B)%.c, $(PATH_OBJS_B)%.o, $(BONUS_SRCS))

INCLUDES_BONUS = -I $(PATH_INCLUDES)

all: libft $(NAME)

libft:
		make -C ./libft

$(NAME): $(OBJS) $(LIBFT)
		cc $(OBJS) $(LIBFT) $(MLX_FLAGS) -o $(NAME)

$(PATH_OBJS)%.o: $(PATH_SRCS)%.c
	mkdir -p $(PATH_OBJS)
	cc $(CFLAGS) $(INCLUDES) -c $< -o $@

bonus: libft $(BONUS_NAME)

$(BONUS_NAME): $(BONUS_OBJS) $(LIBFT)
		cc $(BONUS_OBJS) $(LIBFT) $(MLX_FLAGS) -o $(BONUS_NAME)

$(PATH_OBJS_B)%.o: $(PATH_SRCS_B)%.c
	mkdir -p $(PATH_OBJS_B)
	cc $(CFLAGS) $(INCLUDES_BONUS) -c $< -o $@

clean:
			make clean -C ./libft
			rm -rf $(PATH_OBJS) $(PATH_OBJS_B) $(BONUS_NAME)

fclean:		clean
			make fclean -C ./libft
			rm -rf $(NAME)

re:			fclean all

rebonus: fclean bonus

.PHONY: all clean fclean re bonus rebonus libft
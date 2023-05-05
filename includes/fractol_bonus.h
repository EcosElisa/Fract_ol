/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esobrinh <esobrinh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 14:12:37 by esobrinh          #+#    #+#             */
/*   Updated: 2023/04/26 14:11:22 by esobrinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_BONUS_H
# define FRACTOL_BONUS_H

# include <mlx.h>
# include <stdlib.h>
# include "../libft/libft.h"

# define WIDTH 800
# define HEIGHT 800
# define CX_MAX 2.0
# define CX_MIN -2.0
# define CY_MAX 2.0
# define CY_MIN -2.0
# define ESC 65307
# define KEY_Q 0x0071
# define KEY_R 0x0072
# define KEY_I 0x0069
# define KEY_O 0x006f
# define KEY_A 0x0061
# define KEY_D 0x0064
# define KEY_C 0x0063
# define KEY_SPACE 0x0020
# define ARROW_LEFT 65361
# define ARROW_UP 65362
# define ARROW_RIGHT 65363
# define ARROW_DOWN 65364

typedef struct s_image
{
	void	*new_image;
	char	*addr;
	int		bpp;
	int		size_line;
	int		endian;
	double	x_max;
	double	x_min;
	double	y_max;
	double	y_min;
}	t_image;

typedef struct s_data
{
	void	*mlx_ptr;
	void	*win_ptr;
	t_image	image;
	char	fractal_set;
	int		iteration;
	int		max_iter;
	int		color_set;
	double	x_julia;
	double	y_julia;
	int		julia_set_image;
}	t_data;

void	mandelbrot(t_data *data);
int		check_arg(int argc, char *argv[], t_data *data);
int		start_image(t_data *data);
void	image_pixel_put(t_image *image, int x, int y, int color);
int		get_color(int iteration, int max_iteration, \
			int start_color, int end_color);
int		close_program(t_data *data);
void	first_image(t_data *data);
int		handle_input(int key, t_data *data);
int		mouse_events(int key, int x, int y, t_data *data);
int		mouse_julia(int x, int y, t_data *data);
void	julia(t_data *data);
double	ft_atof(char *str);
int		skip_space_sign_0x(char *hex_string);
int		skip_space_sign(char *str, int *is_neg);
void	help_msg(t_data *data);
void	tricorn(t_data *data);
int		check_tricorn(int argc, char *argv[], t_data *data);

#endif
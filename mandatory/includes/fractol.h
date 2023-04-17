/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esobrinh <esobrinh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 12:26:27 by esobrinh          #+#    #+#             */
/*   Updated: 2023/04/17 15:31:30 by esobrinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <mlx.h>
# include <stdlib.h>
# include <stdio.h>
# include <math.h>
# include "../../libft/libft.h"

# define WIDTH 800
# define HEIGHT 800
# define MAX_ITER 60
# define CX_MAX 2.0
# define CX_MIN -2.0
# define CY_MAX 2.0
# define CY_MIN -2.0

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
	double		color_set;
}	t_data;

void	mandelbrot(t_data *data);
int		check_arg(int argc, char *argv[], t_data *data);
int		start_image(t_data *data);
void	image_pixel_put(t_image *image, int x, int y, int color);
int		get_color(int iteration, int max_iteration, int start_color, int end_color);
#endif
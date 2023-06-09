/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esobrinh <esobrinh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 14:16:03 by esobrinh          #+#    #+#             */
/*   Updated: 2023/04/25 14:18:19 by esobrinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_bonus.h"

static int	set_mandelbrot(double cx, double cy, t_data *data)
{
	double	xz;
	double	yz;
	double	z;

	data->iteration = 0;
	xz = 0;
	yz = 0;
	while (xz * xz + yz * yz < 4 && data->iteration < data->max_iter)
	{
		z = xz * xz - yz * yz + cx;
		yz = 2 * xz * yz + cy;
		xz = z;
		data->iteration++;
	}
	if (data->iteration == data->max_iter)
		return (0x000000);
	else
		return (get_color(data->iteration, data->max_iter, \
				0x080808, data->color_set));
}

void	mandelbrot(t_data *data)
{
	int		x;
	int		y;
	double	cx;
	double	cy;

	y = 0;
	while (y < HEIGHT)
	{
		cy = data->image.y_min + y * (data->image.y_max \
				- data->image.y_min) / HEIGHT;
		x = 0;
		while (x < WIDTH)
		{
			cx = data->image.x_min + x * (data->image.x_max \
					- data->image.x_min) / WIDTH;
			image_pixel_put(&data->image, x, y, set_mandelbrot(cx, cy, data));
			x++;
		}
		y++;
	}
}

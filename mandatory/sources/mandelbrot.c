/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esobrinh <esobrinh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 10:47:42 by esobrinh          #+#    #+#             */
/*   Updated: 2023/04/14 18:31:37 by esobrinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int set_mandelbrot(double cx, double cy, t_data *data)
{
	double xz;
	double yz;
	double z;

	data->iteration = 0;
	xz = 0;
	yz = 0;
	while (xz *xz + yz * yz < 4 && data->iteration < MAX_ITER)
	{
		z = xz * xz - yz * yz + cx;
		yz = 2 * xz * yz + cy;
		xz = z;
		data->iteration++;
	}
	if (data->iteration == MAX_ITER)
		return (0x00000000);
	else
		return (get_color(data->iteration, MAX_ITER, 0x00330000, 0x00FF99FF));
		//return (get_color(data->iteration, MAX_ITER, 0x0f0f0f, 0x00FF99FF/*0Xffffff*/));
		//return (get_color(&data));
}

void	mandelbrot(t_data *data)
{
	int x;
	int y;
	double cx;
	double cy;

	y = 0;
	while (y < HEIGHT)
	{
		cy = data->image.y_min + y * (data->image.y_max - data->image.y_min) / HEIGHT;
		x = 0;
		while (x < WIDTH)
		{
			cx = data->image.x_min + x * (data->image.x_max - data->image.x_min) / WIDTH;
			image_pixel_put(&data->image, x, y, set_mandelbrot(cx, cy, data));
			x++;
		}
		y++;
	}
}

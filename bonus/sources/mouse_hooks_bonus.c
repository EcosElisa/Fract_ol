/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_hooks_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esobrinh <esobrinh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 15:29:31 by esobrinh          #+#    #+#             */
/*   Updated: 2023/04/25 19:34:17 by esobrinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_bonus.h"

static void	follow_mouse(int x, int y, t_data *data)
{
	double	dx;
	double	dy;

	dx = (data->image.x_max - data->image.x_min) / WIDTH *(x - WIDTH / 2);
	dy = (data->image.y_max - data->image.y_min) / HEIGHT *(y - HEIGHT / 2);
	data->image.x_max += dx;
	data->image.x_min += dx;
	data->image.y_max += dy;
	data->image.y_min += dy;
}

int	mouse_events(int key, int x, int y, t_data *data)
{
	double	dx;
	double	dy;

	dx = (data->image.x_max - data->image.x_min) * 0.1;
	dy = (data->image.y_max - data->image.y_min) * 0.1;
	if (key == 4)
	{
		data->image.x_min -= dx;
		data->image.x_max += dx;
		data->image.y_min -= dy;
		data->image.y_max += dy;
		follow_mouse(x, y, data);
	}
	else if (key == 5)
	{
		data->image.x_min += dx;
		data->image.x_max -= dx;
		data->image.y_min += dy;
		data->image.y_max -= dy;
		follow_mouse(x, y, data);
	}
	return (0);
}

int	mouse_julia(int x, int y, t_data *data)
{
	if (data->fractal_set == 'j' && data->julia_set_image == 0)
	{
		data->x_julia = (data->image.x_max - data->image.x_min) \
				/ WIDTH * (x - WIDTH / 2);
		data->y_julia = (data->image.y_max - data->image.y_min) \
				/ HEIGHT * (y - HEIGHT / 2);
	}
	return (0);
}

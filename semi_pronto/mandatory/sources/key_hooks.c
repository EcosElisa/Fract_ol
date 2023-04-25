/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hooks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esobrinh <esobrinh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 19:21:24 by esobrinh          #+#    #+#             */
/*   Updated: 2023/04/20 18:16:02 by esobrinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	new_max_iter(int key, t_data *data)
{
	if (key == KEY_A)
		data->max_iter += 5;
	if (key == KEY_D)
		data->max_iter -= 5;
}

static void	key_zoom(int key, t_data *data)
{
	if (key == KEY_I)
	{
		data->image.x_min -= data->image.x_min * 0.1;
		data->image.x_max -= data->image.x_max * 0.1;
		data->image.y_min -= data->image.y_min * 0.1;
		data->image.y_max -= data->image.y_max * 0.1;
	}
	else if (key == KEY_O)
	{
		data->image.x_min += data->image.x_min * 0.1;
		data->image.x_max += data->image.x_max * 0.1;
		data->image.y_min += data->image.y_min * 0.1;
		data->image.y_max += data->image.y_max * 0.1;
	}
}

int	handle_input(int key, t_data *data)
{
	if (key == ESC || key == KEY_Q)
		close_program(data);
	else if (key == KEY_R)
		first_image(data);
	else if (key == KEY_I || key == KEY_O)
		key_zoom(key, data);
	else if (key == KEY_A || key == KEY_D)
		new_max_iter(key, data);
	else if (key == KEY_SPACE && data->fractal_set == 'j')
		data->julia_set_image = 1;
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys_hooks_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esobrinh <esobrinh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 14:38:31 by esobrinh          #+#    #+#             */
/*   Updated: 2023/04/25 19:46:09 by esobrinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_bonus.h"

static void	new_max_iter(int key, t_data *data)
{
	if (key == KEY_A)
		data->max_iter += 5;
	if (key == KEY_D)
		data->max_iter -= 5;
}

static void	change_color(t_data *data)
{
	if (data->color_set == 0xff5e00)
		data->color_set = 0xfff01f;
	else if (data->color_set == 0xfff01f)
		data->color_set = 0xff3131;
	else if (data->color_set == 0xff3131)
		data->color_set = 0xff1493;
	else if (data->color_set == 0xff1493)
		data->color_set = 0xea00ff;
	else if (data->color_set == 0xea00ff)
		data->color_set = 0xbc13fe;
	else if (data->color_set == 0xbc13fe)
		data->color_set = 0x1f51ff;
	else if (data->color_set == 0x1f51ff)
		data->color_set = 0x8a2be2;
	else if (data->color_set == 0x8a2be2)
		data->color_set = 0xccff00;
}

static void	move_arrow(int key, t_data *data)
{
	double	dx;
	double	dy;

	dx = (data->image.x_max - data->image.x_min) / 10;
	dy = (data->image.y_max - data->image.y_min) / 10;
	if (key == ARROW_LEFT)
	{
		data->image.x_max -= dx;
		data->image.x_min -= dx;
	}
	else if (key == ARROW_RIGHT)
	{
		data->image.x_max += dx;
		data->image.x_min += dx;
	}
	else if (key == ARROW_UP)
	{
		data->image.y_max -= dy;
		data->image.y_min -= dy;
	}
	else
	{
		data->image.y_max += dy;
		data->image.y_min += dy;
	}
}

int	handle_input(int key, t_data *data)
{
	if (key == ESC || key == KEY_Q)
		close_program(data);
	else if (key == KEY_R)
		first_image(data);
	else if (key == KEY_C)
		change_color(data);
	else if (key == ARROW_LEFT || key == ARROW_RIGHT
		|| key == ARROW_UP || key == ARROW_DOWN)
		move_arrow(key, data);
	else if (key == KEY_A || key == KEY_D)
		new_max_iter(key, data);
	else if (key == KEY_SPACE && data->fractal_set == 'j')
		data->julia_set_image = 1;
	return (0);
}

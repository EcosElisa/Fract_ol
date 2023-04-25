/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_hooks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esobrinh <esobrinh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 13:09:54 by esobrinh          #+#    #+#             */
/*   Updated: 2023/04/20 15:47:13 by esobrinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	mouse_events(int key, int x, int y, t_data *data)
{
	x = 1;
	y = 1;
	if (key == 4 && x)
	{
		data->image.x_min -= data->image.x_min * 0.1;
		data->image.x_max -= data->image.x_max * 0.1;
		data->image.y_min -= data->image.y_min * 0.1;
		data->image.y_max -= data->image.y_max * 0.1;
	}
	else if (key == 5 && y)
	{
		data->image.x_min += data->image.x_min * 0.1;
		data->image.x_max += data->image.x_max * 0.1;
		data->image.y_min += data->image.y_min * 0.1;
		data->image.y_max += data->image.y_max * 0.1;
	}
	return (0);
}

//A transformação nessa função é necessaria para mapear as coordenadas
//do mouse para o plano complexo usado para gerar o conjunto de Julia.
int	mouse_julia(int x, int y, t_data *data)
{
	if (data->fractal_set == 'j' && data->julia_set_image == 0)
	{
		data->x_julia = (data->image.x_max - data->image.x_min)\
				/ WIDTH * (x - WIDTH / 2);
		data->y_julia = (data->image.y_max - data->image.y_min)\
				/ HEIGHT * (y - HEIGHT / 2);
	}
	return (0);
}

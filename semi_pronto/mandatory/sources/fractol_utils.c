/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esobrinh <esobrinh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 16:32:33 by esobrinh          #+#    #+#             */
/*   Updated: 2023/04/20 16:53:09 by esobrinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	image_pixel_put(t_image *image, int x, int y, int color)
{
	char	*pixel;

	pixel = (image)->addr +((image)->size_line * y + ((image)->bpp / 8) * x);
	*(int *)pixel = color;
}

int	close_program(t_data *data)
{
	mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	mlx_destroy_display(data->mlx_ptr);
	free(data->mlx_ptr);
	free(data);
	exit(0);
	return (0);
}

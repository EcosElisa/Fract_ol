/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esobrinh <esobrinh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 15:11:04 by esobrinh          #+#    #+#             */
/*   Updated: 2023/04/25 19:03:30 by esobrinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_bonus.h"

int	start_image(t_data *data)
{
	data->image.new_image = mlx_new_image(data->mlx_ptr, WIDTH, HEIGHT);
	data->image.addr = mlx_get_data_addr(data->image.new_image, \
			&data->image.bpp, &data->image.size_line, &data->image.endian);
	if (data->fractal_set == 'm')
		mandelbrot(data);
	else if (data->fractal_set == 't')
		tricorn(data);
	else if (data->fractal_set == 'j')
		julia(data);
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, \
			data->image.new_image, 0, 0);
	mlx_destroy_image(data->mlx_ptr, data->image.new_image);
	return (0);
}

void	first_image(t_data *data)
{
	data->image.x_max = CX_MAX;
	data->image.x_min = CX_MIN;
	data->image.y_max = CY_MAX;
	data->image.y_min = CY_MIN;
	data->max_iter = 100;
	data->julia_set_image = 0;
	start_image(data);
}

static int	start_window(t_data *data)
{
	data->mlx_ptr = mlx_init();
	if (!data->mlx_ptr)
		return (free(data), 1);
	data->win_ptr = mlx_new_window(data->mlx_ptr, \
			WIDTH, HEIGHT, "fractol");
	if (!data->win_ptr)
	{
		mlx_destroy_display(data->mlx_ptr);
		free(data->mlx_ptr);
		free(data);
		return (1);
	}
	first_image(data);
	mlx_hook(data->win_ptr, 2, 1L << 0, handle_input, data);
	mlx_hook(data->win_ptr, 17, 1L << 0, close_program, data);
	mlx_hook(data->win_ptr, 4, 1L << 2, mouse_events, data);
	mlx_hook(data->win_ptr, 6, 1l << 6, mouse_julia, data);
	mlx_loop_hook(data->mlx_ptr, start_image, data);
	mlx_loop(data->mlx_ptr);
	return (0);
}

int	main(int argc, char *argv[])
{
	t_data	*data;

	data = (t_data *)malloc(sizeof(t_data) * 2);
	if (!data)
		return (1);
	if (check_arg(argc, argv, data))
		start_window(data);
	else
		free(data);
	return (0);
}

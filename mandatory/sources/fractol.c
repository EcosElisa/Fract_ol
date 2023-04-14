/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esobrinh <esobrinh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 16:19:33 by esobrinh          #+#    #+#             */
/*   Updated: 2023/04/14 17:45:16 by esobrinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	start_image(t_data *data)
{
	data->image.new_image = mlx_new_image(data->mlx_ptr, WIDTH, HEIGHT);
	data->image.addr = mlx_get_data_addr(data->image.new_image,
		&data->image.bpp, &data->image.size_line, &data->image.endian);
	if (data->fractal_set == 'm')
		mandelbrot(data);
	// else if (data->fractal_set == 'j')
	// 	julia(data);
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->image.new_image, 0, 0);
	mlx_destroy_image(data->mlx_ptr, data->image.new_image);
	return (0);
}

//Serve para setar a imagem nos parametros iniciais depois q da zoom
void	first_image(t_data *data)
{
	data->image.x_max = CX_MAX;
	data->image.x_min = CX_MIN;
	data->image.y_max = CY_MAX;
	data->image.y_min = CY_MIN;
	start_image(data);
}

static int	start_window(t_data *data)
{
	data->mlx_ptr = mlx_init();
	if (!data->mlx_ptr)
		return (free(data), 1);
	data->win_ptr = mlx_new_window(data->mlx_ptr, WIDTH, HEIGHT, "test_mandelbrot");
	if (!data->win_ptr)
	{
		mlx_destroy_display(data->mlx_ptr);
		free(data->mlx_ptr);
		free(data);
		return (1);
	}
	first_image(data);
	mlx_loop(data->mlx_ptr);
	return (0);
}

int main(int argc, char *argv[])
{
	t_data  *data;

	data = (t_data *)malloc(sizeof(t_data) * 2);
	if (!data)
		return (1);
	if (check_arg(argc, argv, data))
		start_window(data);
	else
		free(data);
	return (0);
}
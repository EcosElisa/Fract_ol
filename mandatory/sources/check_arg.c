/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esobrinh <esobrinh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 16:31:03 by esobrinh          #+#    #+#             */
/*   Updated: 2023/04/17 15:31:16 by esobrinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int check_arg(int argc, char *argv[], t_data *data)
{
	if (argc == 2 && ft_strncmp("Mandelbrot", argv[1], 10) == 0)
	{
		data->fractal_set = 'm';
		data->color_set = 0x00FF6666;
		return (1);
	}
	if (argc == 3 && ft_strncmp("Mandelbrot", argv[1], 10) == 0)
	{
		data->fractal_set = 'm';
		data->color_set = ft_atoi(argv[2]);
		printf("%f", data->color_set);
		return (1);
	}
	return (0);
}


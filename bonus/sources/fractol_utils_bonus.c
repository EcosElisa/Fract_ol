/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_utils_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esobrinh <esobrinh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 14:20:34 by esobrinh          #+#    #+#             */
/*   Updated: 2023/04/25 14:21:51 by esobrinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_bonus.h"

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

int	skip_space_sign_0x(char *hex_string)
{
	int	i;

	i = 0;
	while (ft_isspace(hex_string[i]))
		i++;
	if (hex_string[i] == '+')
		i++;
	if (hex_string[i] == '0' && (hex_string[i + 1] \
		&& (hex_string[i + 1] == 'x' || hex_string[i] == 'X')))
			i = i + 2;
	return (i);
}

int	skip_space_sign(char *str, int *is_neg)
{
	int	i;

	i = 0;
	while (ft_isspace(str[i]))
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			*is_neg *= -1;
		i++;
	}
	return (i);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esobrinh <esobrinh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 16:31:03 by esobrinh          #+#    #+#             */
/*   Updated: 2023/05/04 16:32:42 by esobrinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int	hex_to_dec(char *hex_string, t_data *data)
{
	int	i;
	int	current_digit;
	int	x;

	x = 0;
	i = 0;
	current_digit = 0;
	i = skip_space_sign_0x(hex_string);
	while (hex_string[i] && ft_ishexdigit(hex_string[i]))
	{
		if (ft_isdigit(hex_string[i]))
			current_digit = (current_digit * 16) + (hex_string[i] - 48);
		else
			current_digit = (current_digit * 16) \
					+ ft_toupper(*hex_string) - 'A' + 10;
		i++;
		x++;
	}
	if (x == 6 && !hex_string[i])
		return (current_digit);
	else
		help_msg(data);
	return (0);
}

double	ft_atof(char *str)
{
	int		i;
	int		is_neg;
	double	nb;
	double	div;

	nb = 0;
	div = 0.1;
	is_neg = 1;
	i = skip_space_sign(str, &is_neg);
	while (str[i] && ft_isdigit(str[i]) && str[i] != '.')
	{
		nb = (nb * 10.0) + (str[i] - 48);
		i++;
	}
	if (str[i] == '.')
		i++;
	while (str[i] && ft_isdigit(str[i]))
	{
		nb = nb + ((str[i] - 48) * div);
		div *= 0.1;
		i++;
	}
	if (str[i] && !ft_isdigit(str[i]))
		return (-42);
	return (nb * is_neg);
}

int	check_arg(int argc, char *argv[], t_data *data)
{
	if (argc == 2 && ft_strcmp("Mandelbrot", argv[1]) == 0)
	{
		data->fractal_set = 'm';
		data->color_set = 0x0ff0fc;
		return (1);
	}
	if (argc == 3 && ft_strcmp("Mandelbrot", argv[1]) == 0)
	{
		data->fractal_set = 'm';
		data->color_set = hex_to_dec(argv[2], data);
		return (1);
	}
	if (argc == 4 && ft_strcmp("Julia", argv[1]) == 0 \
			&& ft_atof(argv[2]) >= -2.0 && ft_atof(argv[2]) <= 2.0 \
			&& ft_atof(argv[3]) >= -2.0 && ft_atof(argv[3]) <= 2.0)
	{
		data->fractal_set = 'j';
		data->x_julia = ft_atof(argv[2]);
		data->y_julia = ft_atof(argv[3]);
		data->color_set = 0xff5e00;
		return (1);
	}
	help_msg(data);
	return (0);
}

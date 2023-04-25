/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esobrinh <esobrinh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 15:03:22 by esobrinh          #+#    #+#             */
/*   Updated: 2023/04/25 15:04:32 by esobrinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_bonus.h"

int	get_color(int iteration, int max_iteration, int start_color, int end_color)
{
	int		start_rgb[3];
	int		end_rgb[3];
	double	t;

	t = (double)iteration / max_iteration;
	start_rgb[0] = ((start_color >> 16) & 0xFF);
	start_rgb[1] = ((start_color >> 8) & 0xFF);
	start_rgb[2] = ((start_color >> 0) & 0xFF);
	end_rgb[0] = ((end_color >> 16) & 0xFF);
	end_rgb[1] = ((end_color >> 8) & 0xFF);
	end_rgb[2] = ((end_color >> 0) & 0xFF);
	start_rgb[0] = (end_rgb[0] - start_rgb[0]) * t + start_rgb[0];
	start_rgb[1] = (end_rgb[1] - start_rgb[1]) * t + start_rgb[1];
	start_rgb[2] = (end_rgb[2] - start_rgb[2]) * t + start_rgb[2];
	return ((start_rgb[0] << 16) | (start_rgb[1] << 8) | start_rgb[2]);
}

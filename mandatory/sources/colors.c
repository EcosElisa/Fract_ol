/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esobrinh <esobrinh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 13:24:35 by esobrinh          #+#    #+#             */
/*   Updated: 2023/04/14 18:16:13 by esobrinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

// static int get_color(int iteration)
// {
// 	double t = (double)iteration / (double)MAX_ITER;
// 	int r = (int)(9 * (1 - t) * t * t * t * 255);
// 	int g = (int)(15 * (1 - t) * (1 - t) * t * t * 255);
// 	int b = (int)(8.5 * (1 - t) * (1 - t) * (1 - t) * t * 255);
// 	return (r << 16 | g << 8 | b);
// }

// static int get_color(int iteration)
// {
//     if (iteration == MAX_ITER)
//         return 0x00000000;
    
//     int r = 0, g = 0, b = 0;
    
//     if (iteration < MAX_ITER / 3) {
//         r = (int)(255.0 * iteration / (MAX_ITER / 3));
//         g = 0;
//         b = 0;
//     } else if (iteration < 2 * MAX_ITER / 3) {
//         r = 255;
//         g = (int)(255.0 * (iteration - MAX_ITER / 3) / (MAX_ITER / 3));
//         b = 0;
//     } else {
//         r = 255;
//         g = 255;
//         b = (int)(255.0 * (iteration - 2 * MAX_ITER / 3) / (MAX_ITER / 3));
//     }
    
//     return (r << 16) | (g << 8) | b;
// }

// static int get_color(int iteration)
// {
//     if (iteration == MAX_ITER)
//         return 0x00000000;
    
//     int r = 0, g = 0, b = 0;
    
//     if (iteration < MAX_ITER / 2) {
//         r = (int)(255.0 * iteration / (MAX_ITER / 2));
//         g = 0;
//         b = (int)(255.0 * iteration / (MAX_ITER / 2));
//     } else {
//         r = 255;
//         g = (int)(255.0 * (iteration - MAX_ITER / 2) / (MAX_ITER / 2));
//         b = 255;
//     }
    
//     return (r << 16) | (g << 8) | b;
// }

// int	get_color(t_data *data)
// {
// 	int	r;
// 	int	g;
// 	int	b;

// 	r = 0;
// 	g = 0;
// 	b = 0;

// 	if (data->interation < MAX_ITER / 2)
// 	{
// 		r = (int)(255.0 * data->interation / (MAX_ITER / 2));
// 		g = 0;
// 		b = (int)(255.0 * data->interation / (MAX_ITER / 2));
// 	}
// 	else
// 	{
// 		r = 255;
// 		g = (int)(255.0 * (data->interation - MAX_ITER / 2) / (MAX_ITER / 2));
// 		b = 255;
// 	}

// 	return (r << 16) | (g << 8) | b;
// }

// int get_color(t_data **data)
// {
// 	double	t;
// 	int	start_color

// 	(*data)->color.r = 90;
// 	(*data)->color.g = 255;
// 	(*data)->color.b = 0;
	
// 	t = (double)(*data)->iteration / MAX_ITER;
// 	(*data)->color.start_color = ((*data)->color.start_color >> 16) & 0xFF;
// 	(*data)->color.start_g = ((*data)->color.start_color >> 8) & 0xFF;
// 	(*data)->color.start_b = (*data)->color.start_color & 0xFF;
// 	(*data)->color.end_r = ((*data)->color.end_color >> 16) & 0xFF;
// 	(*data)->color.end_g = ((*data)->color.end_color >> 8) & 0xFF;
// 	(*data)->color.end_b = (*data)->color.end_color & 0xFF;

// 	(*data)->color.r = (int)((*data)->color.start_r + ((*data)->color.end_r - (*data)->color.start_r) * t);
// 	(*data)->color.g = (int)((*data)->color.start_g + ((*data)->color.end_g - (*data)->color.start_g) * t);
// 	(*data)->color.b = (int)((*data)->color.start_b + ((*data)->color.end_b - (*data)->color.start_b) * t);

// 	return ((*data)->color.r << 16) | ((*data)->color.g << 8) | (*data)->color.b;
// }

// int get_color(int iteration, int max_iteration, int start_color, int end_color)
// {
//     if (iteration == max_iteration)
//         return 0x00000000;
    
//     int r = 0, g = 0, b = 0;
    
//     double t = (double)iteration / max_iteration;
//     int start_r = (start_color >> 16) & 0xFF;
//     int start_g = (start_color >> 8) & 0xFF;
//     int start_b = start_color & 0xFF;
//     int end_r = (end_color >> 16) & 0xFF;
//     int end_g = (end_color >> 8) & 0xFF;
//     int end_b = end_color & 0xFF;
    
//     r = (int)(start_r + (end_r - start_r) * t);
//     g = (int)(start_g + (end_g - start_g) * t);
//     b = (int)(start_b + (end_b - start_b) * t);
    
//     return (r << 16) | (g << 8) | b;
// }

int get_color(int iteration, int max_iteration, int start_color, int end_color)
{
	int	start_rgb[3];
	int	end_rgb[3];
	double t = (double)iteration / max_iteration;

	start_rgb[0] = ((start_color >> 16) & 0xFF);
	start_rgb[1] = ((start_color >> 8) & 0xFF);
	start_rgb[2] = ((start_color >> 0) & 0xFF);
	end_rgb[0] = ((end_color >> 16) & 0xFF);
	end_rgb[1] = ((end_color >> 8) & 0xFF);
	end_rgb[2] = ((end_color >> 0) & 0xFF);
	start_rgb[0] = (end_rgb[0] - start_rgb[0]) * t + start_rgb[0];
	start_rgb[1] = (end_rgb[1] - start_rgb[1]) * t + start_rgb[1];
	start_rgb[2] = (end_rgb[2] - start_rgb[2]) * t + start_rgb[2];


	return (start_rgb[0] << 16) | (start_rgb[1] << 8) | start_rgb[2];
}
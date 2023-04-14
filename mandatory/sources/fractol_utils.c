/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esobrinh <esobrinh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 16:32:33 by esobrinh          #+#    #+#             */
/*   Updated: 2023/04/14 16:46:11 by esobrinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	image_pixel_put(t_image *image, int x, int y, int color)
{
	char	*pixel;
	
	pixel = (image)->addr +((image)->size_line * y + ((image)->bpp / 8) * x);
	*(int *)pixel = color;
}

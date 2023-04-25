/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help_msg_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esobrinh <esobrinh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 15:13:37 by esobrinh          #+#    #+#             */
/*   Updated: 2023/04/25 19:56:07 by esobrinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_bonus.h"

static void	print_fractal_options(void)
{
	ft_putendl_fd("+===============  Available Fractals  ===============+", 1);
	ft_putendl_fd("Which fractal would you like to view?", 1);
	ft_putendl_fd("\tMandelbrot", 1);
	ft_putendl_fd("\tJulia", 1);
	ft_putendl_fd("\tTricorn", 1);
	ft_putendl_fd("\e[36mUsage example:\t./fractol <type>\n \
		./fractol Mandelbrot\n\t\t./fractol Tricorn\e[0m", 1);
	ft_putstr_fd("\nFor Julia, you may specify starting values for the\n", 1);
	ft_putstr_fd("initial fractal shape. Values must be between\n", 1);
	ft_putendl_fd("-2.0 and 2.0 and must contain a decimal point.", 1);
	ft_putendl_fd("\e[36mUsage example:\t", 1);
	ft_putendl_fd("\t\t./fractol Julia\n\t\t./fractol Julia 0.285 0.01\e[0m", 1);
}

static void	print_color_options(void)
{
	ft_putendl_fd("\n+===============  Color Display  ====================+", 1);
	ft_putendl_fd("Pick a display color by providing a hexadecimal code.", 1);
	ft_putendl_fd("(Ps: Works for Mandelbrot and Tricorn.)", 1);
	ft_putendl_fd("The hex color code must be formatted as RRGGBB:", 1);
	ft_putendl_fd("\tWhite:\tFFFFFF\t\tBlack:\t000000", 1);
	ft_putendl_fd("\tRed:\tFF0000\t\tGreen:\t00FF00", 1);
	ft_putendl_fd("\tBlue:\t0000FF\t\tYellow:\tFFFF00", 1);
	ft_putendl_fd("Other interesting colors:", 1);
	ft_putendl_fd("\tPurple:\t9933FF\t\tOrange:\tCC6600", 1);
	ft_putendl_fd("\tPink:\tFF3399\t\tTurquoise: 00FF80\t", 1);
	ft_putstr_fd("\e[36mUsage example:\t", 1);
	ft_putendl_fd("./fractol <type> <color>", 1);
	ft_putendl_fd("\t\t./fractol Mandelbrot 0066FF\n \
		./fractol Tricorn 0066FF\e[0m", 1);
}

static void	print_controls(void)
{
	ft_putendl_fd("\n+===============  Controls  =========================+", 1);
	ft_putendl_fd("Key_R:\t\tReset the image.", 1);
	ft_putendl_fd("Keys A/D:\tDefine the number of iteration(a: increases", 1);
	ft_putendl_fd("\t\t\td: decreases).", 1);
	ft_putendl_fd("Scroll wheel:\tZoom in and out.", 1);
	ft_putendl_fd("Arrows Up, Down, Left or Right: Moving the view.\t", 1);
	ft_putendl_fd("ESC, key_Q or close window:\tQuit fract'ol.", 1);
	ft_putendl_fd("JULIA - Space:\tTo freeze the image.", 1);
	ft_putendl_fd("JULIA - Key_C:\tChange the color.", 1);
	ft_putendl_fd("JULIA - Mouse moves:\tChanges the values of the ", 1);
	ft_putendl_fd("\t\t\tcomplex numbers.", 1);
	ft_putendl_fd("+====================================================+\n", 1);
}

void	help_msg(t_data *data)
{
	ft_putendl_fd("\n+====================================================+", 1);
	ft_putendl_fd("|                     FRACT'OL                       |", 1);
	ft_putendl_fd("+====================================================+\n", 1);
	print_fractal_options();
	print_color_options();
	print_controls();
	free(data);
	exit(0);
}

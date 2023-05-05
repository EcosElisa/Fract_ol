// int	check_arg(int argc, char *argv[], t_data *data)
// {
// 	if (argc == 2 && ft_strncmp("Mandelbrot", argv[1], 10) == 0)
// 	{
// 		data->fractal_set = 'm';
// 		data->start_color = 
// 		data->end_color = 0x4fdee0;
// 		return (1);
// 	}
// 	if (argc == 3 && ft_strncmp("Mandelbrot", argv[1], 10) == 0)
// 	{
// 		data->fractal_set = 'm';
// 		data->end_color = hex_to_dec(argv[2], data);
// 		return (1);
// 	}
// 	if (argc == 4 && ft_strncmp("Julia", argv[1], 5) == 0 \
// 			&& ft_atof(argv[2]) >= -2.0 && ft_atof(argv[2]) <= 2.0 \
// 			&& ft_atof(argv[3]) >= -2.0 && ft_atof(argv[3]) <= 2.0)
// 	{
// 		data->fractal_set = 'j';
// 		data->x_julia = ft_atof(argv[2]);
// 		data->y_julia = ft_atof(argv[3]);
// 		data->start_color = 0xf7f4d4;
// 		data->end_color = 0x01afda;
// 		return (1);
// 	}
// 	help_msg(data);
// 	return (0);
	//0xFFC0CB - rosinha claro
	//0x6e3a9e - roxo
	//0xf28f1c - laranja
	//0xffcbad - laranja claro
	//0xe2f5bb - verde claro

// int	check_args_julia(int argc, char *argv[], t_data *data)
// {
// 	if (argc == 4 && ft_strncmp("Julia", argv[1], 5) == 0 \
// 			&& ft_atof(argv[2]) >= -2.0 && ft_atof(argv[2]) <= 2.0 \
// 			&& ft_atof(argv[3]) >= -2.0 && ft_atof(argv[3]) <= 2.0)
// 	{
// 		data->fractal_set = 'j';
// 		data->x_julia = ft_atof(argv[2]);
// 		data->y_julia = ft_atof(argv[3]);
// 		data->start_color = 0x0000FF;
// 		data->end_color = 0xFF00FF;
// 		return (1);
// 	}
// 	help_msg(data);
// 	return (0);
// }

azul celeste - 0x4fdee0(nao é neon)

CORES NEON

Amarelo - 0xfff01f
Verdes - 0xccff00(lime) | 0x7fff00 | 0x39ff14 (esses dois ultimos sao bem parecidos)
Azul - 0x1f51ff(escuro)
Vermelho - 0xff3131
Laranja - 0xff5e00
Rosa - 0xff44cc(pink) | 0xff1493(rosa) | 0xea00ff(magenta)
Roxo - 0xbc13fe | 0x8a2be2(roxo escuro)

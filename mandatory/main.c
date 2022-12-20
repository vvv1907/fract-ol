/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcolumbu <hcolumbu@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 10:17:29 by hcolumbu          #+#    #+#             */
/*   Updated: 2022/04/09 19:02:04 by hcolumbu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	init_fractol(t_fractol *fr, int type, double first, double second)
{
	fr->fractol_type = type;
	fr->julia_c.re = first;
	fr->julia_c.im = second;
	fr->mouse.re = 0;
	fr->mouse.im = 0;
	fr->zoom = 1;
	fr->max_iteration = 100;
	fr->color.red = 0;
	fr->color.green = 0;
	fr->color.blue = 0;
}

void	fractol(int type, double first, double second)
{
	t_fractol	*fr;

	fr = (t_fractol *)malloc(sizeof(t_fractol));
	if (!fr)
	{
		perror("fractol_malloc error");
		exit(1);
	}
	init_fractol(fr, type, first, second);
	fr->mlx = mlx_init();
	if (!fr->mlx)
		ft_error(fr, "mlx_init error");
	fr->win = mlx_new_window(fr->mlx, WIDTH, HEIGHT, "fractol");
	if (!fr->win)
		ft_error(fr, "mlx_new_window error");
	draw_fractol(fr);
	mlx_hook(fr->win, 2, 1L << 3, key_hook, fr);
	mlx_hook(fr->win, 4, 1L << 3, mouse_hook, fr);
	mlx_hook(fr->win, 17, 0L, red_cross_hook, NULL);
	mlx_loop(fr->mlx);
	free(fr);
}

static int	validation(int argc, char **argv, double *first, double *second)
{
	if (argc == 2 && ft_strequ(argv[1], "Mandelbrot"))
		return (1);
	if (argc == 2 && ft_strequ(argv[1], "Julia"))
		return (2);
	if (argc == 4 && ft_strequ(argv[1], "Julia"))
	{
		*first = ft_atoi_double(argv[2]);
		*second = ft_atoi_double(argv[3]);
		return (4);
	}
	return (0);
}

static void	incorrect_arguments(void)
{
	ft_putstr_fd("*******************************************************\n", 1);
	ft_putstr_fd("Usage: ./fractol <name of fractal> \n", 1);
	ft_putstr_fd("\nYou can choose one of the following: \n", 1);
	ft_putstr_fd("\nMandelbrot \nJulia \n", 1);
	ft_putstr_fd("*******************************************************\n", 1);
	ft_putstr_fd("OR \n**************************************************\n", 1);
	ft_putstr_fd("Usage: ./fractol Julia <real part> <imaginary part>\n", 1);
	ft_putstr_fd("real part and imaginary part must be 'double' format\n", 1);
	ft_putstr_fd("*******************************************************\n", 1);
}

int	main(int argc, char **argv)
{
	int		fractal_type;
	double	first_param;
	double	second_param;

	first_param = -0.4;
	second_param = 0.6;
	if (argc == 2 || argc == 4)
	{
		fractal_type = validation(argc, argv, &first_param, &second_param);
		if (fractal_type)
		{
			fractol(fractal_type, first_param, second_param);
			return (0);
		}
	}
	incorrect_arguments();
	return (0);
}

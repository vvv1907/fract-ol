/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcolumbu <hcolumbu@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 10:17:29 by hcolumbu          #+#    #+#             */
/*   Updated: 2022/03/14 10:51:03 by hcolumbu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_bonus.h"

void	ft_error(t_fractol *fr, char *str)
{
	free(fr);
	perror(str);
	exit(1);
}

static void	put_pixel(t_fractol *fr, int x, int y)
{
	int	pos;

	fr->image.data_addr = mlx_get_data_addr(fr->image.image, &fr->image.bpp, \
							&fr->image.size_line, &fr->image.endian);
	pos = x * 4 + y * fr->image.size_line;
	fr->image.data_addr[pos] = fr->color.blue;
	fr->image.data_addr[pos + 1] = fr->color.green;
	fr->image.data_addr[pos + 2] = fr->color.red;
}

static void	get_color(t_fractol *fr, double t)
{
	int		first_color;
	int		second_color;
	int		third_color;

	first_color = (int)(9 * (1 - t) * (t * t * t) * 255);
	second_color = (int)(15 * ((1 - t) * (1 - t)) * (t * t) * 255);
	third_color = (int)(8.5 * ((1 - t) * (1 - t) * (1 - t)) * t * 255);
	if (fr->shift_color == 0)
	{
		fr->color.red = first_color;
		fr->color.green = second_color;
		fr->color.blue = third_color;
	}
	if (fr->shift_color == 1)
	{
		fr->color.red = second_color;
		fr->color.green = third_color;
		fr->color.blue = first_color;
	}
	if (fr->shift_color == 2)
	{
		fr->color.red = third_color;
		fr->color.green = first_color;
		fr->color.blue = second_color;
	}
}

void	draw_fractol(t_fractol *fr)
{
	int		iteration;
	int		x;
	int		y;
	double	t;

	fr->image.image = mlx_new_image(fr->mlx, WIDTH, HEIGHT);
	if (!(fr->image.image))
		ft_error(fr, "mlx_new_image error");
	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		iteration = 0;
		while (x < WIDTH)
		{
			iteration = fractol_type_iteration(fr, x, y);
			t = (double)iteration / (double)fr->max_iteration;
			get_color(fr, t);
			if (t != 1)
				put_pixel(fr, x, y);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(fr->mlx, fr->win, fr->image.image, 0, 0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcolumbu <hcolumbu@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 10:17:29 by hcolumbu          #+#    #+#             */
/*   Updated: 2022/03/13 17:40:50 by hcolumbu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

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

static void	get_color(t_fractol *fr, int iteration)
{
	double	t;

	t = (double)iteration / (double)fr->max_iteration;
	fr->color.red = (int)(9 * (1 - t) * (t * t * t) * 255);
	fr->color.green = (int)(15 * ((1 - t) * (1 - t)) * (t * t) * 255);
	fr->color.blue = (int)(8.5 * ((1 - t) * (1 - t) * (1 - t)) * t * 255);
}

void	draw_fractol(t_fractol *fr)
{
	int	iteration;
	int	x;
	int	y;

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
			get_color(fr, iteration);
			if (iteration != fr->max_iteration)
				put_pixel(fr, x, y);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(fr->mlx, fr->win, fr->image.image, 0, 0);
}

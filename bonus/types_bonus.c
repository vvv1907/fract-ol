/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   types_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcolumbu <hcolumbu@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 10:17:29 by hcolumbu          #+#    #+#             */
/*   Updated: 2022/03/13 17:40:06 by hcolumbu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_bonus.h"

static t_complex	init_complex(t_fractol *fr, int x, int y)
{
	t_complex	c;

	c.re = 1.6 * (x - WIDTH / 2) \
		/ (0.5 * fr->zoom * WIDTH) + (fr->mouse.re / WIDTH) - 0.7;
	c.im = 1.6 * (y - HEIGHT / 2) \
		/ (0.5 * fr->zoom * HEIGHT) - fr->mouse.im / HEIGHT;
	return (c);
}

static int	iteration_mandelbrot(t_fractol *fr, t_complex z, t_complex c)
{
	int		iteration;
	double	tmp;

	tmp = 0;
	iteration = 0;
	while (z.re * z.re + z.im * z.im <= 4 && iteration < fr->max_iteration)
	{
		tmp = z.re;
		z.re = tmp * tmp - z.im * z.im + c.re;
		z.im = 2.0 * tmp * z.im + c.im;
		iteration++;
	}
	return (iteration);
}

static int	iteration_julia(t_fractol *fr, t_complex z)
{
	int		iteration;
	double	tmp;

	tmp = 0;
	iteration = 0;
	while (z.re * z.re + z.im * z.im <= 4 && iteration < fr->max_iteration)
	{
		tmp = z.re;
		z.re = tmp * tmp - z.im * z.im + fr->julia_c.re;
		z.im = 2.0 * tmp * z.im + fr->julia_c.im;
		iteration++;
	}
	return (iteration);
}

static int	iteration_burning_ship(t_fractol *fr, t_complex z, t_complex c)
{
	int		iteration;
	double	tmp;
	double	abs;

	iteration = 0;
	while (z.re * z.re + z.im * z.im <= 4 && iteration < fr->max_iteration)
	{
		tmp = z.re;
		z.re = tmp * tmp - z.im * z.im + c.re;
		abs = tmp * z.im;
		if (abs < 0)
			abs *= -1;
		z.im = 2.0 * abs + c.im;
		iteration++;
	}
	return (iteration);
}

int	fractol_type_iteration(t_fractol *fr, int x, int y)
{
	t_complex	c;
	t_complex	z;

	z.re = 0;
	z.im = 0;
	c = init_complex(fr, x, y);
	if (fr->fractol_type == 2 || fr->fractol_type == 4)
		return (iteration_julia(fr, c));
	else if (fr->fractol_type == 3)
		return (iteration_burning_ship(fr, z, c));
	else
		return (iteration_mandelbrot(fr, z, c));
}

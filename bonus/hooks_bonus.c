/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcolumbu <hcolumbu@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 10:17:29 by hcolumbu          #+#    #+#             */
/*   Updated: 2022/03/14 10:31:29 by hcolumbu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_bonus.h"

static void	key_iteration(int keycode, t_fractol *fr)
{
	if (keycode == PLUS_ITER)
	{
		if (fr->max_iteration < 50)
			fr->max_iteration += 1;
		else if (fr->max_iteration < 1000000000)
			fr->max_iteration = (int)(fr->max_iteration * 1.05);
	}
	if (keycode == MINUS_ITER)
	{
		if (fr->max_iteration > 50)
			fr->max_iteration = (int)(fr->max_iteration * 0.95);
		else if (fr->max_iteration > 1)
			fr->max_iteration -= 1;
	}
}

static void	key_move(int keycode, t_fractol *fr)
{
	if (keycode == CURSOR_UP || keycode == W)
		fr->mouse.im += 20;
	if (keycode == CURSOR_DOWN || keycode == S)
		fr->mouse.im -= 20;
	if (keycode == CURSOR_LEFT || keycode == A)
		fr->mouse.re -= 20;
	if (keycode == CURSOR_RIGHT || keycode == D)
		fr->mouse.re += 20;
}

int	key_hook(int keycode, t_fractol *fr)
{
	if (keycode == ESC)
	{
		mlx_destroy_window(fr->mlx, fr->win);
		free(fr);
		exit(0);
	}
	if (keycode == ZOOM_IN)
		fr->zoom *= 1.1;
	if (keycode == ZOOM_OUT)
		fr->zoom /= 1.1;
	if (keycode == CHANGE_COLOR)
		fr->shift_color = (fr->shift_color + 1) % 3;
	key_move(keycode, fr);
	key_iteration(keycode, fr);
	draw_fractol(fr);
	return (0);
}

int	mouse_hook(int keycode, int x, int y, t_fractol *fr)
{
	x -= WIDTH / 2;
	y -= HEIGHT / 2;
	if (keycode == SCROLL_UP)
	{
		fr->zoom *= 1.1;
		fr->mouse.re += x / fr->zoom / 2.5;
		fr->mouse.im -= y / fr->zoom / 2.5;
	}
	if (keycode == SCROLL_DOWN)
	{
		fr->zoom /= 1.1;
		fr->mouse.re += x / fr->zoom / 2.5;
		fr->mouse.im -= y / fr->zoom / 2.5;
	}
	draw_fractol(fr);
	return (0);
}

int	red_cross_hook(t_fractol *fr)
{
	free(fr);
	exit(0);
	return (0);
}

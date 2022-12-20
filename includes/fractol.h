/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcolumbu <hcolumbu@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 10:17:29 by hcolumbu          #+#    #+#             */
/*   Updated: 2022/03/14 10:20:45 by hcolumbu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H
# include "../libft/libft.h"
# include <stdio.h>

# define WIDTH 1000
# define HEIGHT 1000
# define ESC 53
# define SCROLL_UP 4
# define SCROLL_DOWN 5
# define ZOOM_IN 24
# define ZOOM_OUT 27
# define PLUS_ITER 19
# define MINUS_ITER 18

typedef struct s_color
{
	int			red;
	int			green;
	int			blue;
}				t_color;

typedef struct s_complex
{
	double		re;
	double		im;
}				t_complex;

typedef struct s_image
{
	void		*image;
	char		*data_addr;
	int			size_line;
	int			endian;
	int			bpp;
}				t_image;

typedef struct s_fractol
{
	void		*mlx;
	void		*win;
	t_image		image;
	t_color		color;
	int			max_iteration;
	int			fractol_type;
	double		zoom;
	t_complex	mouse;
	t_complex	julia_c;
}				t_fractol;

void	ft_error(t_fractol *fr, char *str);
void	fractol(int type, double first, double second);
void	draw_fractol(t_fractol *fr);
int		fractol_type_iteration(t_fractol *fr, int x, int y);
int		key_hook(int keycode, t_fractol *fr);
int		mouse_hook(int keycode, int x, int y, t_fractol *fr);
int		red_cross_hook(t_fractol *fr);

#endif

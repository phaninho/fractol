/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractinc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stmartin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/19 10:27:15 by stmartin          #+#    #+#             */
/*   Updated: 2016/05/06 22:15:24 by stmartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTINC_H
# define FRACTINC_H

# include "libft.h"
# include <math.h>
# include <fcntl.h>
# include <mlx.h>
# include <stdlib.h>

# define WIN_X 1000
# define WIN_Y 1000 / 16 * 9

typedef struct			s_image
{
	void		*i;
	int			bpp;
	int			szline;
	int			endian;
	char		*data;
}						t_image;

typedef struct			s_co
{
	int			it_max;
	double		zoom;
	int			x;
	int			y;
	double		x1;
	double		x2;
	double		y1;
	double		y2;
	double		c_r;
	double		c_i;
	double		z_r;
	double		z_i;
}						t_co;

typedef struct			s_tmp
{
	double		tx1;
	double		tx2;
	double		ty1;
	double		ty2;
}						t_tmp;

typedef struct			s_env
{
	double		zx;
	double		zy;
	int			ehk;
	int			ret;
	double		mx;
	double		my;
	void		*mlx;
	void		*win;
	t_image		img;
	t_co		v;
	int			color;
	double		msx;
	double		msy;
	double		tx;
	double		ty;
}						t_env;

int				mouse_hook(int button, int x, int y, t_env *param);
int				mouse_motion(int x, int y, t_env *param);
unsigned long	colorrgb(int r, int g, int b);
int				key_hook(int keycode, t_env *env);
int				expose_hook(t_env *e);
void			image_put_pixel(t_image *i, int x, int y, unsigned long color);
void			julia(t_env *e);
void			mandelbrot(t_env *e);
void			myfractal(t_env *e);
void			init_fractal(t_env *e);
void			change_fractal(int keycode, t_env *e);

#endif

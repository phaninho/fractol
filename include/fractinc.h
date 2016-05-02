/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractinc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stmartin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/19 10:27:15 by stmartin          #+#    #+#             */
/*   Updated: 2016/05/02 19:10:14 by stmartin         ###   ########.fr       */
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
	float		zoom;
	int			x;
	int			y;
	float		x1;
	float		x2;
	float		y1;
	float		y2;
	float		c_r;
	float		c_i;
	float		z_r;
	float		z_i;
	float		c_c;
}						t_co;

typedef struct			s_tmp
{
	float		tx1;
	float		tx2;
	float		ty1;
	float		ty2;
}						t_tmp;

typedef struct			s_env
{
	int			ret;
	int			ctx;
	int			cty;
	float		mx;
	float		my;
	void		*mlx;
	void		*win;
	t_image		img;
	t_co		v;
	int			color;
	double		msx;
	double		msy;
}						t_env;

int				mouse_hook(int button, int x, int y, t_env *param);
int				mouse_motion(int x, int y, t_env *param);
unsigned long	colorrgb(int r, int g, int b);
int				key_hook(int keycode, void *env);
int				expose_hook(t_env *e);
void			image_put_pixel(t_image *i, int x, int y, unsigned long color);
void			julia(t_env *e);
void			mandelbrot(t_env *e);

#endif

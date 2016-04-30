/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_tools.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stmartin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/19 13:16:50 by stmartin          #+#    #+#             */
/*   Updated: 2016/04/30 13:34:38 by stmartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "fractinc.h"



void			fractal(t_env *e, int i)
{
	float	tmp;

	printf("retour x1: %f x2: %f\ny1: %f y2: %f\n", e->v.x1, e->v.x2, e->v.y1, e->v.y2);
	e->v.y = 0;
	while (e->v.y < WIN_Y)
	{
		e->v.x = 0;
		while(e->v.x < WIN_X)
		{
			e->v.z_r = e->v.x / e->v.zoom + e->v.x1 + e->mx;
			e->v.z_i = e->v.y / e->v.zoom + e->v.y1 + e->my;
			i = 0;
			while (e->v.z_r * e->v.z_r + e->v.z_i * e->v.z_i < 4 && i < e->v.it_max)
			{
				e->ret == 2 ? mandelbrot(e) : 1;
				tmp = e->v.z_r;
				e->v.z_r = e->v.z_r * e->v.z_r  - e->v.z_i * e->v.z_i + e->v.c_r;
				e->v.z_i = 2 * e->v.z_i * tmp + e->v.c_i;
				i++;
			}
			if (i == e->v.it_max)
				image_put_pixel(&(e->img), e->v.x, e->v.y, 0);
			else
				image_put_pixel(&(e->img), e->v.x, e->v.y, colorrgb(i * 255 /
				e->v.it_max, i * 255 / e->v.it_max, i * 255 / e->v.it_max));
			e->v.x++;
		}
		e->v.y++;
	}
}

void			move_map(int keycode, t_env *e)
{
	if (keycode == 91)
		e->my -= 100 / e->v.zoom;
	if (keycode == 84)
		e->my += 100 / e->v.zoom;
	if (keycode == 88)
		e->mx += 100 / e->v.zoom;
	if (keycode == 86)
		e->mx -= 100 / e->v.zoom;
}

float			xinit(t_env *e, int x)
{
	float		newx;

	newx = (((e->v.x2 - e->v.x1) * x) / WIN_X) + e->v.x1;
	return (newx);
}

float			yinit(t_env *e, int y)
{
	float		newy;

	newy = (((e->v.y2 - e->v.y1) * y) / WIN_Y) + e->v.y1;
	return (newy);
}

int				mouse_hook(int button, int x, int y, t_env *e)
{
	float		x1;
	float		y1;
	t_tmp		t;

	t.tx1 = e->v.x1;
	t.tx2 = e->v.x2;
	t.ty1 = e->v.y1;
	t.ty2 = e->v.y2;
	x1 = xinit(e, x);
	y1 = yinit(e, y);
	printf("bt %d x: %d y: %d\n", button, x, y);
	if (button == 5 && e->v.zoom < 30000000)
	{
		e->v.zoom *= 1.1;
		//e->ctx = x / 2;
		//e->cty = y / 2;
		e->v.x1 = x1 - ((t.tx2 - t.tx1) / 4);
		e->v.x2 = x1 + ((t.tx2 - t.tx1) / 4);
		e->v.y1 = y1 - ((t.ty2 - t.ty1) / 4);
		e->v.y2 = y1 + ((t.ty2 - t.ty1) / 4);
		printf("test x1: %f x2: %f\ny1: %f y2: %f\n", e->v.x1, e->v.x2, e->v.y1, e->v.y2);
		//e->v.x += 100; /*e->v.x / e->v.zoom / 2.51*/
		//e->v.y += 100; /*e->v.y / e->v.zoom / 2.51*/
	}
	if (button == 4 && e->v.zoom > 50)
		e->v.zoom /= 1.1;
	(void)x;
	(void)y;
	expose_hook(e);
	return (0);
}


int				mouse_motion(int x, int y, int ad, t_env *e)
{
	(void)e;
	if (x > 0 && x < WIN_X && y > 0 && y < WIN_Y)
	{
		//if (x > WIN_X / 2 && y > WIN_Y / 2)
		//	e->v.c_c = (x + y) * 0.001;
	//	if (x > WIN_X / 2)
	//		e->v.c_r += x / 100;
		printf("bt %d bt2 %d bt3 %d\n", x, y, ad);
	}
	
	//expose_hook(e);
	return (0);
}

int				key_hook(int keycode, void *env)
{
	t_env	*e;
	e = (t_env *)env;

	if (keycode == 53)
		exit(1);
	if (keycode == 67)
		e->v.it_max += 10;
	if (e->v.it_max > 11 && keycode == 75)
		e->v.it_max -= 10;
	move_map(keycode, e);
	expose_hook(e);
	return (0);
}


static void		clear_image(t_env *e)
{
	int		y;

	y = 0;
	while(y <= e->img.szline * WIN_Y)
	{
		e->img.data[y] = 0;
		y++;
	}
}

int				expose_hook(t_env *e)
{
	clear_image(e);
	fractal(e, 0);
	mlx_clear_window(e->mlx, e->win);
	mlx_put_image_to_window(e->mlx, e->win, e->img.i, 0, 0);
	return (0);
}

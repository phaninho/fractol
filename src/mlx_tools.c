/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_tools.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stmartin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/19 13:16:50 by stmartin          #+#    #+#             */
/*   Updated: 2016/04/19 23:33:11 by stmartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "fractinc.h"

unsigned long	colorrgb(int r, int g, int b)
{
	return ((r & 0xff) << 16 ) + ((g & 0xff) << 8) + (b & 0xff);
}

void			fractal(t_env *e, int i)
{
	float	tmp;
	//int		zoom_x;
	//int		zoom_y;
	float	c_r;
	float	c_i;
	float	z_r;
	float	z_i;
	float	zoom;
	e->x1 = -1.6;
	e->x2 = 1;
	e->y1 = -0.95;
	e->y2 = 1.4;
	zoom = 320;
	//zoom_x = WIN_X / (e->x2 - e->x1);
	//zoom_y = WIN_Y / (e->y2 - e->y1);
	e->y = 0;
	while (e->y < WIN_Y)
	{
		e->x = 0;
		while(e->x < WIN_X)
		{
			z_r = e->x / zoom + e->x1;
			z_i = e->y / zoom + e->y1;
			c_r = -0.7;
			c_i = 0.27015;
			i = 0;
			while (z_r * z_r + z_i * z_i < 4 && i < ITER_MAX)
			{
				tmp = z_r;
				z_r = z_r * z_r - z_i * z_i + c_r;
				z_i = 2 * z_i * tmp + c_i;
				//image_put_pixel(e->img.i, x, y, e->color);
				i++;
			}
			if (i == ITER_MAX)
			{
				printf("in %d %d\n", e->x, e->y);
				mlx_pixel_put(e->mlx, e->win, e->x, e->y, colorrgb(0, (i * 255) / ITER_MAX, 0));
				//image_put_pixel(e->img.i, x, y, colorrgb(i * 255 / ITER_MAX, 0, 0));
			}
			else
			{
				printf("%d %d\n", e->x, e->y);
			//	e->color = colorrgb(i * 255 / ITER_MAX, 0, 0);
			//	mlx_pixel_put(e->mlx, e->win, e->x, e->y, 0x00FF);
			}
			e->x++;
		}
		e->y++;
	}
	//mlx_put_image_to_window(e->mlx, e->win, e->img.i, 0, 0);
}

int				key_hook(int keycode, void *env)
{
	t_env *e;
	e = (t_env *)env;
	(void)e;
	if (keycode == 53)
		exit(1);
	expose_hook(e);
	return (0);
}

/*
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
*/
int				expose_hook(t_env *e)
{
	//clear_image(e);
	fractal(e, 0);
	printf("%f\n", e->x1);
	mlx_clear_window(e->mlx, e->win);
	//mlx_put_image_to_window(e->mlx, e->win, e->img.i, 0, 0);
	return (0);
}

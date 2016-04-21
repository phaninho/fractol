/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_tools.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stmartin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/19 13:16:50 by stmartin          #+#    #+#             */
/*   Updated: 2016/04/21 16:39:53 by stmartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "fractinc.h"



void			fractal(t_env *e, int i)
{
	t_co	al;
	float	tmp;
	e->v.x1 = -1.6;
	e->v.x2 = 1;
	e->v.y1 = -0.95;
	e->v.y2 = 1.4;
	e->v.y = 0;
	while (e->v.y < WIN_Y)
	{
		e->v.x = 0;
		while(e->v.x < WIN_X)
		{
			al.z_r = e->v.x / e->v.zoom + e->v.x1 + e->mx;
			al.z_i = e->v.y / e->v.zoom + e->v.y1 + e->my;
			al.c_r = -0.7;
			al.c_i = 0.27015;
			i = 0;
			while (al.z_r * al.z_r + al.z_i * al.z_i < 4 && i < ITER_MAX)
			{
				tmp = al.z_r;
				al.z_r = al.z_r * al.z_r  - al.z_i * al.z_i + al.c_r;
				al.z_i = 2 * al.z_i * tmp + al.c_i;
				i++;
			}
			if (i == ITER_MAX)
			{
//				printf("in %d %d\n", e->v.x, e->v.y);
				mlx_pixel_put(e->mlx, e->win, e->v.x, e->v.y, 0);
				//image_put_pixel(e->img.i, e->v.x, e->v.y, 0xff);
			}
			else
				mlx_pixel_put(e->mlx, e->win, e->v.x, e->v.y, colorrgb(i * 255
				/ ITER_MAX, i * 255 / ITER_MAX, i * 255 / ITER_MAX));
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

int				key_hook(int keycode, void *env)
{
	t_env *e;
	e = (t_env *)env;
	(void)e;
	if (keycode == 53)
		exit(1);
	if (keycode == 69)
		e->v.zoom *= 2;
	if (keycode == 78 && e->v.zoom > 100)
		e->v.zoom /= 2;
	move_map(keycode, e);
	printf("kc %d zm %f\n", keycode,e->v.zoom);
	expose_hook(e);
	return (0);
}


/*static void		clear_image(t_env *e)
{
	int		y;

	y = 0;
	while(y <= e->img.szline * WIN_Y)
	{
		e->img.data[y] = 0;
		y++;
	}
}*/

int				expose_hook(t_env *e)
{
//	clear_image(e);
	fractal(e, 0);
//	printf("%f\n", e->v.x1);
//	mlx_clear_window(e->mlx, e->win);
//	mlx_put_image_to_window(e->mlx, e->win, e->img.i, 0, 0);
	return (0);
}
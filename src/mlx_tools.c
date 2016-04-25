/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_tools.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stmartin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/19 13:16:50 by stmartin          #+#    #+#             */
/*   Updated: 2016/04/25 15:28:26 by stmartin         ###   ########.fr       */
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
			while (al.z_r * al.z_r + al.z_i * al.z_i < 4 && i < e->v.it_max)
			{
				tmp = al.z_r;
				al.z_r = al.z_r * al.z_r  - al.z_i * al.z_i + al.c_r;
				al.z_i = 2 * al.z_i * tmp + al.c_i;
				i++;
			}
			if (i == e->v.it_max)
				image_put_pixel(&(e->img), e->v.x, e->v.y, 0);
			else
				image_put_pixel(&(e->img), e->v.x, e->v.y, colorrgb(i * 255 /  e->v.it_max, i * 255 / e->v.it_max, i * 255 / e->v.it_max));
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

int				mouse_hook(int button, int x, int y, void *env)
{
	t_env	*e;
	e = (t_env *)env;
	(void)e;
	printf("bt %d\n", button);
	if (button == 5)
		e->v.zoom *= 2;
	if (button == 4 && e->v.zoom > 50)
		e->v.zoom /= 2;
	(void)x;
	(void)y;
	return (0);
}


int				mouse_motion(int x, int y, int bpp, void *env)
{
	t_env	*e;
	e = (t_env *)env;
	printf("bt %d bt2 %d bt3 %d\n", x, y, bpp);
	
	(void)x;
	(void)y;
	return (0);
}

int				key_hook(int keycode, void *env)
{
	t_env	*e;
	e = (t_env *)env;
	(void)e;
	

	if (keycode == 53)
		exit(1);
	if (keycode == 67)
		e->v.it_max += 10;
	printf("%d\n", e->v.it_max);
	if (e->v.it_max > 11 && keycode == 75)
		e->v.it_max -= 10;
	move_map(keycode, e);
	printf("kc %d zm %f\n", keycode,e->v.zoom);
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
//	printf("%f\n", e->v.x1);
	//mlx_clear_window(e->mlx, e->win);
	mlx_put_image_to_window(e->mlx, e->win, e->img.i, 0, 0);
	return (0);
}

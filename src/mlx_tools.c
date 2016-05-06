/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_tools.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stmartin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/19 13:16:50 by stmartin          #+#    #+#             */
/*   Updated: 2016/05/06 22:54:51 by stmartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "fractinc.h"



void			fractal(t_env *e, int i)
{
	double	tmp;

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
				if (e->ret == 1 || e->ret == 2)
					e->ret == 2 ? mandelbrot(e) : julia(e);
				else
					myfractal(e);
				tmp = e->v.z_r;
				e->v.z_r = e->v.z_r * e->v.z_r  - e->v.z_i * e->v.z_i + e->v.c_r;
				e->v.z_i = 2 * e->v.z_i * tmp + e->v.c_i;
				i++;
			}
			if (i == e->v.it_max)
				image_put_pixel(&(e->img), e->v.x, e->v.y, 0);
			else
				image_put_pixel(&(e->img), e->v.x, e->v.y, colrgb(e->col, i *
			255 / e->v.it_max, i * 255 / e->v.it_max, i * 255 / e->v.it_max));
			e->v.x++;
		}
		e->v.y++;
	}
}

void			move_map(int keycode, t_env *e)
{
	if (keycode == 126)
		e->my -= 100 / e->v.zoom;
	if (keycode == 125)
		e->my += 100 / e->v.zoom;
	if (keycode == 124)
		e->mx += 100 / e->v.zoom;
	if (keycode == 123)
		e->mx -= 100 / e->v.zoom;
}

int				mouse_hook(int button, int x, int y, t_env *e)
{
	double	lax;
	double	lay;

	if (button == 5)
	{
		lax = (x / e->v.zoom) + e->v.x1;
		lay = (y / e->v.zoom) + e->v.y1;
		e->v.zoom *= 1.1;
		e->v.x1 = lax - (x / e->v.zoom);
		e->v.y1 = lay - (y / e->v.zoom);
	}
	if (button == 4 && e->v.zoom > 50)
	{
		lax = (x / e->v.zoom) + e->v.x1;
		lay = (y / e->v.zoom) + e->v.y1;
		e->v.zoom /= 1.1;
		e->v.x1 = lax - (x / e->v.zoom);
		e->v.y1 = lay - (y / e->v.zoom);
	}
	expose_hook(e);
	return (0);
}

int				mouse_motion(int x, int y, t_env *e)
{
	if (e->ehk == 1)
	{
		if (x > 0 && x < WIN_X && y > 0 && y < WIN_Y)
		{
			e->msx = x - (WIN_X / 2);
			e->msy = y - (WIN_Y / 2);
		}
		expose_hook(e);
	}
	return (0);
}

int				key_hook(int keycode, t_env *e)
{
	printf("%d\n", keycode);
	if (keycode == 12)
		e->col++;
	else if (keycode == 0)
		e->col--;
	else if (keycode == 35)
		e->ehk = 0;
	else if (keycode == 31)
		e->ehk = 1;
	else if (keycode == 53)
		exit(1);
	else if (keycode == 24)
		e->v.it_max += 10;
	else if (e->v.it_max > 11 && keycode == 27)
		e->v.it_max -= 10;
	move_map(keycode, e);
	change_fractal(keycode, e);
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

void			put_instruction(t_env *e)
{

	mlx_string_put(e->mlx, e->win, 5, 5, 0xffffff, "+ | -  : change iteration");
	mlx_string_put(e->mlx, e->win, 5, 20, 0xffffff, "p | o : pause / unpause");
	mlx_string_put(e->mlx, e->win, 5, 35, 0xffffff, "scroll: zoom");
	mlx_string_put(e->mlx, e->win, 5, 50, 0xffffff, "arrow : move");
	mlx_string_put(e->mlx, e->win, 5, 65, 0xffffff, "q | a : change color");
}

int				expose_hook(t_env *e)
{
	clear_image(e);
	fractal(e, 0);
	mlx_clear_window(e->mlx, e->win);
	mlx_put_image_to_window(e->mlx, e->win, e->img.i, 0, 0);
	put_instruction(e);
	return (0);
}

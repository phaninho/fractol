/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_tools.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stmartin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/19 13:16:50 by stmartin          #+#    #+#             */
/*   Updated: 2016/05/09 14:46:47 by stmartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "fractinc.h"

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
	mlx_string_put(e->mlx, e->win, 5, 5, 0xffffff, "+ | - : change iteration");
	mlx_string_put(e->mlx, e->win, 5, 23, 0xffffff, "p | o : pause on / off");
	mlx_string_put(e->mlx, e->win, 5, 41, 0xffffff, "scroll: zoom");
	mlx_string_put(e->mlx, e->win, 5, 59, 0xffffff, "arrow : move");
	mlx_string_put(e->mlx, e->win, 5, 77, 0xffffff, "q | a : change color");
	mlx_string_put(e->mlx, e->win, 5, 95, 0xffffff, "1 to 5 : change map");
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

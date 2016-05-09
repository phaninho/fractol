/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stmartin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/06 22:02:48 by stmartin          #+#    #+#             */
/*   Updated: 2016/05/09 14:58:53 by stmartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractinc.h"

void		change_fractal(int keycode, t_env *e)
{
	if (keycode == 18)
	{
		e->msx = 0;
		e->msy = 0;
		e->ret = 1;
	}
	else if (keycode == 19)
	{
		e->msx = 0;
		e->msy = 0;
		e->ret = 2;
	}
	else if (keycode == 20)
		e->ret = 3;
	else if (keycode == 21)
		e->ret = 4;
	else if (keycode == 23)
		e->ret = 5;
}

void		init_xy1(t_env *e)
{
	if (e->ret == 1)
	{
		e->v.x1 = -1.6;
		e->v.y1 = -0.95;
	}
	else if (e->ret == 3)
	{
		e->v.x1 = -2.8;
		e->v.y1 = -2;
	}
	else if (e->ret == 2 || e->ret == 4)
	{
		e->v.x1 = -2.2;
		e->v.y1 = -0.95;
	}
	else if ( e->ret == 5)
	{
		e->v.x1 = -1.6;
		e->v.y1 = -0.75;
	}
}

void		init_fractal(t_env *e)
{
	if (e->ret == 1)
		julia(e);
	else if (e->ret == 2)
		mandelbrot(e);
	else if (e->ret == 3)
		burning_ship(e);
	else if (e->ret == 4)
		tricorn(e);
	else if (e->ret == 5)
		uter(e);
	init_xy1(e);
}

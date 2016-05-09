/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calcul_fractal.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stmartin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/07 14:26:13 by stmartin          #+#    #+#             */
/*   Updated: 2016/05/09 17:37:08 by stmartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractinc.h"

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

void			wich_fractal(t_env *e)
{
	if (e->ret >= 1 && e->ret <= 6)
		e->ret == 1 ? julia(e) : uter(e);
	else
		julia(e);
}

void			fractal(t_env *e, int i)
{
	double	tmp;

	e->v.y = 0;
	while (e->v.y < WIN_Y)
	{
		e->v.x = 0;
		while(e->v.x < WIN_X)
		{
			z_out_init(e);
			i = 0;
			while (e->v.z_r * e->v.z_r + e->v.z_i * e->v.z_i < 4 &&
					i < e->v.it_max)
			{
				wich_fractal(e);
				tmp = e->v.z_r;
				z_in_init(e, tmp);
				i++;
			}
			choose_color(i, e);
			e->v.x++;
		}
		e->v.y++;
	}
}

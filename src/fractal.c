/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stmartin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/29 16:34:37 by stmartin          #+#    #+#             */
/*   Updated: 2016/05/04 17:56:02 by stmartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractinc.h"

void		julia(t_env *e)
{
	e->v.x1 = -1.6;
	e->v.x2 = 1;
	e->v.y1 = -0.95;
	e->v.y2 = 1.4;
	e->v.c_r = -0.7 + (e->msx / 100);
	e->v.c_i = 0.27015 + (e->msy / 100);
}

void		myfractal(t_env *e)
{
	e->v.x1 = -1.6;
	e->v.y1 = -0.95;
	e->v.c_r = e->v.x + e->v.it_max * (e->msx / 100);
	e->v.c_i = e->v.y + e->v.it_max * (e->msx / 100);
}

void		mandelbrot(t_env *e)
{
	e->v.x1 = -1.6;
	e->v.x2 = 1;
	e->v.y1 = -0.95;
	e->v.y2 = 1.4;
	e->v.c_r = e->v.x / e->v.zoom + e->v.x1 + e->mx + (e->msx / 100);
	e->v.c_i = e->v.y / e->v.zoom + e->v.y1 + e->my + (e->msx / 100);
}

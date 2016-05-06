/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stmartin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/29 16:34:37 by stmartin          #+#    #+#             */
/*   Updated: 2016/05/06 21:37:26 by stmartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>
#include "fractinc.h"

void		julia(t_env *e)
{
	e->v.c_r = -0.7 + (e->msx / 100);
	e->v.c_i = 0.27015 + (e->msy / 100);
}

void		myfractal(t_env *e)
{
	e->v.c_r = 0.325123 + (e->msx / 100);
	e->v.c_i = 0.004879 + (e->msy / 100);
}

void		mandelbrot(t_env *e)
{
	e->v.c_r = e->v.x / e->v.zoom + e->v.x1 + e->mx + (e->msx / 100);
	e->v.c_i = e->v.y / e->v.zoom + e->v.y1 + e->my + (e->msx / 100);
}

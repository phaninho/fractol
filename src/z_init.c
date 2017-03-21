/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   z_init.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stmartin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/08 18:54:20 by stmartin          #+#    #+#             */
/*   Updated: 2016/05/10 16:51:39 by stmartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractinc.h"

void			z_out_init(t_env *e)
{
	if (e->ret == 1 || e->ret == 2 || e->ret == 7 || e->ret == 8)
	{
		e->v.z_r = e->v.x / e->v.zoom + e->v.x1 + e->mx;
		e->v.z_i = e->v.y / e->v.zoom + e->v.y1 + e->my;
	}
	else if (e->ret == 3 || e->ret == 5 || e->ret == 4 || e->ret == 6)
	{
		e->v.z_r = 0;
		e->v.z_i = 0;
	}
}

void			z_in_init2(t_env *e, double tmp)
{
	if (e->ret == 5)
	{
		e->v.z_r = fabs(((e->v.z_r * e->v.z_r) * e->v.z_r) - 3 * ((e->v.z_i *
						e->v.z_i) * e->v.z_r) - e->v.c_i);
		e->v.z_i = 3 * ((tmp * tmp) * e->v.z_i) - ((e->v.z_i * e->v.z_i) *
				e->v.z_i) - e->v.c_r;
	}
	else if (e->ret == 6)
	{
		e->v.z_r = ((e->v.z_r * e->v.z_r) - (e->v.z_i * e->v.z_i) * 3) *
			fabs(e->v.z_r) + e->v.c_r;
		e->v.z_i = (((tmp * tmp) * 3) - (e->v.z_i * e->v.z_i)) * fabs(e->v.z_i)
			+ e->v.c_i;
	}
	else if (e->ret == 7)
	{
		e->v.z_r = ((e->v.z_r * e->v.z_r) - (e->v.z_i * e->v.z_i) * 3) *
			fabs(e->v.z_r) + e->v.c_r;
		e->v.z_i = (((tmp * tmp) * 3) - (e->v.z_i * e->v.z_i)) * fabs(e->v.z_i)
			+ e->v.c_i;
	}
}

void			z_in_init(t_env *e, double tmp)
{
	if (e->ret == 1 || e->ret == 2)
	{
		e->v.z_r = e->v.z_r * e->v.z_r - e->v.z_i * e->v.z_i + e->v.c_r;
		e->v.z_i = 2 * e->v.z_i * tmp + e->v.c_i;
	}
	else if (e->ret == 3)
	{
		e->v.z_r = fabs((e->v.z_r * e->v.z_r) - (e->v.z_i * e->v.z_i) +
				e->v.c_r);
		e->v.z_i = fabs(2 * e->v.z_i * tmp + e->v.c_i);
	}
	else if (e->ret == 4)
	{
		e->v.z_r = e->v.z_r * e->v.z_r - e->v.z_i * e->v.z_i + e->v.c_r;
		e->v.z_i = -(2 * e->v.z_i * tmp + e->v.c_i);
	}
	else if (e->ret == 8)
	{
		e->v.z_r = ((e->v.z_r * e->v.z_r) - (e->v.z_i * e->v.z_i) +
				e->v.c_r);
		e->v.z_i = fabs(2 * e->v.z_i * tmp + e->v.c_i);
	}
	else if (e->ret >= 5)
		z_in_init2(e, tmp);
}

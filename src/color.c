/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stmartin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/08 19:12:33 by stmartin          #+#    #+#             */
/*   Updated: 2016/05/08 19:16:07 by stmartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractinc.h"

void		choose_color(int i, t_env *e)
{
	if (i == e->v.it_max)
		image_put_pixel(&(e->img), e->v.x, e->v.y, 0);
	else
		image_put_pixel(&(e->img), e->v.x, e->v.y, colrgb(e->col, i *
			255 / e->v.it_max, i * 255 / e->v.it_max, i * 255 / e->v.it_max));
}

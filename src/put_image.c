/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_image.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stmartin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/19 13:33:34 by stmartin          #+#    #+#             */
/*   Updated: 2016/05/10 16:51:27 by stmartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractinc.h"

unsigned long	colrgb(int c, int r, int g, int b)
{
	return ((r & 0xff) << (2 + c)) + ((g & 0xff) <<
			(8 + c)) + ((b & 0xff) << (20 + c));
}

void			image_put_pixel(t_image *i, int x, int y, unsigned long color)
{
	if (i->endian)
	{
		i->data[(x * i->bpp / 8) + (y * i->szline)] = color / 65536 % 256;
		i->data[(x * i->bpp / 8) + 1 + (y * i->szline)] = color / 256 % 256;
		i->data[(x * i->bpp / 8) + 2 + (y * i->szline)] = color % 256;
	}
	else
	{
		i->data[(x * i->bpp / 8) + 2 + (y * i->szline)] = color / 65536 % 256;
		i->data[(x * i->bpp / 8) + 1 + (y * i->szline)] = color / 256 % 256;
		i->data[(x * i->bpp / 8) + (y * i->szline)] = color % 256;
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractinc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stmartin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/19 10:27:15 by stmartin          #+#    #+#             */
/*   Updated: 2016/04/19 23:31:14 by stmartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTINC_H
# define FRACTINC_H

# include "libft.h"
# include <math.h>
# include <fcntl.h>
# include <mlx.h>
# include <stdlib.h>

# define WIN_X 1000
# define WIN_Y 1100 / 16 * 9
# define ITER_MAX 75

typedef struct			s_image
{
	void		*i;
	int			bpp;
	int			szline;
	int			endian;
	char		*data;
}						t_image;

typedef struct			s_env
{
	int			x;
	int			y;
	float		x1;
	float		x2;
	float		y1;
	float		y2;
	void		*mlx;
	void		*win;
	t_image		img;
	int			color;
}						t_env;

int				key_hook(int keycode, void *env);
int				expose_hook(t_env *e);
void			image_put_pixel(t_image *i, int x, int y, int color);

#endif

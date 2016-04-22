/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stmartin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/19 10:37:15 by stmartin          #+#    #+#             */
/*   Updated: 2016/04/22 15:38:43 by stmartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractinc.h"

void		call_fonction(t_env e)
{
	e.mlx = mlx_init();
	e.win = mlx_new_window(e.mlx, WIN_X, WIN_Y, "Fractal");
	mlx_expose_hook(e.win, expose_hook, &e);
	mlx_mouse_hook(e.win, mouse_hook, &e);
	mlx_hook(e.win, 6, 1 << 6, mouse_motion, &e);
	mlx_hook(e.win, 2, 1L << 0, key_hook, &e);
	e.img.i = mlx_new_image(e.mlx, WIN_X, WIN_Y);
	e.img.data = mlx_get_data_addr(e.img.i, &(e.img.bpp), &(e.img.szline), 
			&(e.img.endian));
	mlx_loop(e.mlx);
}

int			main(int ac, char **av)
{
	static t_env	e;

	e.v.zoom = 320;
	e.v.it_max = 51;
	e.mx = 0;
	e.my = 0;
	e.color = 0x00FF;
	if (ac != 2)
	{
		ft_putendl("Usage : ./fractol [julia, mendel, ...]");
		return (0);
	}
	if (!(ft_strcmp(av[1], "julia")))
		call_fonction(e);
	return (0);
}

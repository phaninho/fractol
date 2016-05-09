/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stmartin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/19 10:37:15 by stmartin          #+#    #+#             */
/*   Updated: 2016/05/09 15:28:44 by stmartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractinc.h"

void		call_fonction(t_env e)
{
	e.mlx = mlx_init();
	e.win = mlx_new_window(e.mlx, WIN_X, WIN_Y, "Fractal");
	e.img.i = mlx_new_image(e.mlx, WIN_X, WIN_Y);
	mlx_expose_hook(e.win, expose_hook, &e);
	mlx_mouse_hook(e.win, mouse_hook, &e);
	mlx_hook(e.win, 6, 1L << 6, mouse_motion, &e);
	mlx_hook(e.win, 2, 1L << 0, key_hook, &e);
	e.img.data = mlx_get_data_addr(e.img.i, &(e.img.bpp), &(e.img.szline), 
			&(e.img.endian));
	mlx_loop(e.mlx);
}


int			check_arg(char **av)
{
	int				ret;

	ret = 0;
	if (!ft_strcmp(av[1], "julia"))
		ret = 1;
	else if (!ft_strcmp(av[1], "mandel"))
		ret = 2;
	else if (!ft_strcmp(av[1], "burn"))
		ret = 3;
	else if (!ft_strcmp(av[1], "tricorn"))
		ret = 4;
	else if (!ft_strcmp(av[1], "uter"))
		ret = 5;
	else if (!ft_strcmp(av[1], "bird"))
		ret = 6;
	return (ret);
}

int			main(int ac, char **av)
{
	static t_env	e;

	e.v.zoom = 220;
	e.v.it_max = 51;
	if (ac == 2 && (e.ret = check_arg(av)))
	{
		init_fractal(&e);
		call_fonction(e);
	}
	else
	{
		ft_putendl("Usage : ./fractol [julia, mandel, burn, tricorn, uter, bird]");
		return (0);
	}
	return (0);
}

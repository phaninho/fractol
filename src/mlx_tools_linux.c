#include <stdio.h>
#include "fractinc.h"

int				mouse_motion(int x, int y, t_env *e)
{
	if (e->ehk == 1)
	{
		if (x > 0 && x < WIN_X && y > 0 && y < WIN_Y)
		{
			e->msx = x - (WIN_X / 2);
			e->msy = y - (WIN_Y / 2);
		}
		expose_hook(e);
	}
	return (0);
}

int				key_hook(int keycode, t_env *e)
{
	if (keycode == 97)
		e->col++;
	else if (keycode == 113)
		e->col--;
	else if (keycode == 111)
		e->ehk = 0;
	else if (keycode == 112)
		e->ehk = 1;
	else if (keycode == 65307)
		exit(1);
	else if (keycode == 61)
		e->v.it_max += 10;
	else if (e->v.it_max > 11 && keycode == 41)
		e->v.it_max -= 10;
	move_map(keycode, e);
	change_fractal(keycode, e);
	expose_hook(e);
	return (0);
}


static void		clear_image(t_env *e)
{
	int		y;

	y = 0;
	while(y <= e->img.szline * WIN_Y)
	{
		e->img.data[y] = 0;
		y++;
	}
}

void			put_instruction(t_env *e)
{
	mlx_string_put(e->mlx, e->win, 5, 5, 0xffffff, "+ | -  : change iteration");
	mlx_string_put(e->mlx, e->win, 5, 21, 0xffffff, "p | o : pause on / off");
	mlx_string_put(e->mlx, e->win, 5, 37, 0xffffff, "scroll: zoom");
	mlx_string_put(e->mlx, e->win, 5, 53, 0xffffff, "arrow : move");
	mlx_string_put(e->mlx, e->win, 5, 69, 0xffffff, "q | a : change color");
	mlx_string_put(e->mlx, e->win, 5, 85, 0xffffff, "1 | 2 | 3 : change map");
}

int				expose_hook(t_env *e)
{
	clear_image(e);
	fractal(e, 0);
	mlx_clear_window(e->mlx, e->win);
	mlx_put_image_to_window(e->mlx, e->win, e->img.i, 0, 0);
	put_instruction(e);
	return (0);
}

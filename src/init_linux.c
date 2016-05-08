#include "fractinc.h"

void		change_fractal(int keycode, t_env *e)
{
	if (keycode == 38)
		e->ret = 1;
	else if (keycode == 233)
		e->ret = 2;
	else if (keycode == 34)
		e->ret = 3;
}

void		init_xy1(t_env *e)
{
	if (e->ret == 1 || e->ret == 3)
	{
		e->v.x1 = -1.6;
		e->v.y1 = -0.95;
	}
	else if (e->ret == 2)
	{
		e->v.x1 = -2.2;
		e->v.y1 = -0.95;
	}
}

void		init_fractal(t_env *e)
{
	if (e->ret == 1)
		julia(e);
	if (e->ret == 2)
		mandelbrot(e);
	if (e->ret == 3)
		myfractal(e);
	init_xy1(e);
}

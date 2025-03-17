/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moel-yag <moel-yag@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/15 02:41:04 by moel-yag          #+#    #+#             */
/*   Updated: 2025/03/17 14:18:19 by moel-yag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "minilibx-linux/mlx.h"
#include <X11/X.h>

int	close_handler(t_fractal *fractal)
{
	mlx_destroy_image(fractal->mlx_connection, fractal->img.img_ptr);
	mlx_destroy_window(fractal->mlx_connection, fractal->mlx_window);
	mlx_destroy_display(fractal->mlx_connection);
	free(fractal->mlx_connection);
	exit(EXIT_SUCCESS);
}

int	key_handler(int keysym, t_fractal *fractal)
{
	if (keysym == XK_Escape)
		close_handler(fractal);
	else if (keysym == XK_Right)
		fractal->shift_x += (0.5 * fractal->zoom);
	else if (keysym == XK_Left)
		fractal->shift_x -= (0.5 * fractal->zoom);
	else if (keysym == XK_Down)
		fractal->shift_y -= (0.5 * fractal->zoom);
	else if (keysym == XK_Up)
		fractal->shift_y += (0.5 * fractal->zoom);
	else if (keysym == XK_equal)
		fractal->iterations_definition += 10;
	else if (keysym == XK_minus)
		fractal->iterations_definition -= 10;
	fractal_render(fractal);
	return (0);
}

int	mouse_handler(int button, int x, int y, t_fractal *f)
{
	double	old_zoom;
	double	ms_r;
	double	ms_i;

	old_zoom = f->zoom;
	if (button == Button5)
		f->zoom *= 0.9;
	else if (button == Button4)
		f->zoom /= 0.9;
	ms_r = (x - WIDTH / 2.0) * (old_zoom / WIDTH) + f->center.x;
	ms_i = (y - WIDTH / 2.0) * (old_zoom / WIDTH) + f->center.y;
	fractal_render(f);
	return (0);
}

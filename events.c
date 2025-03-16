/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moel-yag <moel-yag@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/15 02:41:04 by moel-yag          #+#    #+#             */
/*   Updated: 2025/03/16 12:17:16 by moel-yag         ###   ########.fr       */
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
	else if (keysym == XK_Left)
		fractal->shift_x += (0.5 * fractal->zoom);
	else if (keysym == XK_Right)
		fractal->shift_x -= (0.5 * fractal->zoom);
	else if (keysym == XK_Up)
		fractal->shift_y -= (0.5 * fractal->zoom);
	else if (keysym == XK_Down)
		fractal->shift_y += (0.5 * fractal->zoom);
	else if (keysym == XK_equal)
		fractal->iterations_definition += 10;
	else if (keysym == XK_minus)
		fractal->iterations_definition -= 10;
	fractal_render(fractal);
	return (0);
}

int	mouse_handler(int button, t_fractal *fractal)
{
	if (button == Button5)
		fractal->zoom *= 0.95;
	else if (button == Button4)
		fractal->zoom *= 1.05;
	fractal_render(fractal);
	return (0);
}

// int julia_track(int x, int y, t_fractal *fractal)
// {
//     if (!ft_strncmp(fractal->name, "julia", 5))
//     {
//         fractal->julia_x = (map(x, -2, 2, WIDTH) * fractal->zoom)
//             + fractal->shift_x;
//         fractal->julia_y = (map(y, -2, 2, HEIGHT) * fractal->zoom)
//             + fractal->shift_y;
//     }
//     fractal_render(fractal);
//     return (0);
// }

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moel-yag <moel-yag@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 17:49:33 by moel-yag          #+#    #+#             */
/*   Updated: 2025/03/16 15:21:37 by moel-yag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "minilibx-linux/mlx.h"

static int	valid_julia_params(char **av, double x, double y)
{
	return (av[2][0] && av[3][0] && (x != 0 || y != 0));
}

int	main(int ac, char **av)
{
	t_fractal	f;

	if (ac == 2 && !ft_strncmp(av[1], "mandelbrot", 11))
	{
		f.name = av[1];
		fractal_init(&f);
		fractal_render(&f);
		mlx_loop(f.mlx_connection);
	}
	else if (ac == 4 && !ft_strncmp(av[1], "julia", 5)
		&& valid_julia_params(av, atodbl(av[2]), atodbl(av[3])))
	{
		f.name = av[1];
		f.julia_x = atodbl(av[2]);
		f.julia_y = atodbl(av[3]);
		fractal_init(&f);
		fractal_render(&f);
		mlx_loop(f.mlx_connection);
	}
	else
	{
		ft_putstr_fd(ERROR_MESSAGE, 2);
		ft_putstr_fd(ERROR_MESSAGE2, 2);
		exit(1);
	}
}

// int	main(int ac, char **av)
// {
// 	t_fractal	fractal;

// 	if ((ac == 2 && !ft_strncmp(av[1], "mandelbrot", 11))
// 		|| ((ac == 4 && !ft_strncmp(av[1], "julia", 5))
// 		&& av[2][0] != '\0' && av[3][0] != '\0'))
// 	{
// 		fractal.name = av[1];
// 		if (!ft_strncmp(fractal.name, "julia", 5))
// 		{
// 			fractal.julia_x = atodbl(av[2]);
// 			fractal.julia_y = atodbl(av[3]);
// 		}
// 		fractal_init(&fractal);
// 		fractal_render(&fractal);
// 		mlx_loop(fractal.mlx_connection);
// 	}
// 	else
// 	{
// 		ft_putstr_fd(ERROR_MESSAGE, STDERR_FILENO);
// 		ft_putstr_fd(ERROR_MESSAGE2, STDERR_FILENO);
// 		exit(EXIT_FAILURE);
// 	}
// }

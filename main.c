/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moel-yag <moel-yag@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 17:49:33 by moel-yag          #+#    #+#             */
/*   Updated: 2025/03/17 12:27:16 by moel-yag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "minilibx-linux/mlx.h"

static int	valid_julia_params(char **av)
{
	return (is_valid_number(av[2]) && is_valid_number(av[3]));
}

void	ft_putstr_fd(char *s, int fd)
{
	if (!s)
		return ;
	while (*s)
		write(fd, s++, 1);
}

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	while ((s1[i] || s2[i]) && i < n)
	{
		if (s1[i] != s2[i])
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		i++;
	}
	return (0);
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
		&& av[2][0] && av[3][0] && valid_julia_params(av))
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

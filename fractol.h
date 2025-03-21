/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moel-yag <moel-yag@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 17:50:54 by moel-yag          #+#    #+#             */
/*   Updated: 2025/03/17 12:26:37 by moel-yag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <unistd.h>
# include <math.h>
# include "minilibx-linux/mlx.h"
# include <X11/X.h>
# include <X11/keysym.h>
# include <X11/keysymdef.h>
# include <stdlib.h>
# include <stdio.h>

# define ERROR_MESSAGE "Please enter:\n\t'./fractol mandelbrot'\n"
# define ERROR_MESSAGE2 "\t'./fractol julia <value_1> <value_2>'\n"

# define WIDTH	800
# define HEIGHT	800

# define BLACK				0x000000
# define WHITE				0xFFFFFF
# define RED				0xFF0000
# define GREEN				0x00FF00
# define BLUE				0x0000FF
# define ELECTRIC_BLUE		0x0066FF
# define PSYCHEDELIC_PURPLE	0x660066

typedef struct s_complex
{
	double	x;
	double	y;
}				t_complex;

typedef struct s_img
{
	void	*img_ptr;
	char	*pixels_ptr;
	int		bpp;
	int		endian;
	int		line_len;
}				t_img;

typedef struct s_fractal
{
	char		*name;
	void		*mlx_connection;
	void		*mlx_window;
	t_img		img;
	double		escape_value;
	double		shift_x;
	double		shift_y;
	t_complex	julia_c;
	t_complex	center;
	double		zoom;
	double		iterations_definition;
	double		julia_x;
	double		julia_y;
	double		mouse_x;
	double		mouse_y;
}				t_fractal;

int			ft_strncmp(const char *s1, const char *s2, size_t n);
void		ft_putstr_fd(char *s, int fd);
void		fractal_init(t_fractal *fractal);
void		fractal_render(t_fractal *fractal);
double		map(double unscaled_nb, double new_min, double new_max,
				double old_max);
t_complex	sum_complex(t_complex z1, t_complex z2);
t_complex	square_complex(t_complex z);
int			close_handler(t_fractal *fractal);
int			key_handler(int keysym, t_fractal *fractal);
int			mouse_handler(int button, int x, int y, t_fractal *fractal);
double		atodbl(char *s);
int			is_valid_number(char *s);

#endif

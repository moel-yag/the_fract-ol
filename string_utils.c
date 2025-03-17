/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moel-yag <moel-yag@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 17:20:07 by moel-yag          #+#    #+#             */
/*   Updated: 2025/03/17 15:17:19 by moel-yag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "minilibx-linux/mlx.h"

int	is_valid_number(char *str)
{
	int i;

	i = 0;
	if (str[i] == '+' || str[i] == '-')
		i++;
	while (str[i] && (str[i] >= '0' && str[i] <= '9'))
		i++;
	if (!str[i] && i > 0 && (str[i - 1] >= '0' && str[i - 1] <= '9'))
		return (1);
	else if (str[i] != '.')
		return (0);
	i++;
	while (str[i] && (str[i] >= '0' && str[i] <= '9'))
		i++;
	if (!str[i] && i > 0 && (str[i - 1] >= '0' && str[i - 1] <= '9'))
		return (1);
	else
		return (0);
	return(0);
}

static int	helper_func2(char *s, double *pow, double *fractional_part)
{
	if (*s == '.')
	{
		s++;
		while (*s)
		{
			if (!(*s >= '0' && *s <= '9'))
				return (0);
			*pow /= 10;
			*fractional_part += (*s++ - 48) * (*pow);
		}
	}
	return (0);
}

double	atodbl(char *s)
{
	long	integer_part;
	double	fractional_part;
	double	pow;
	int		sign;

	integer_part = 0;
	fractional_part = 0;
	pow = 1;
	sign = 1;
	while ((*s >= 9 && *s <= 13) || *s == 32)
		++s;
	if (*s == '+' || *s == '-')
	{
		if (*s == '-')
			sign = -1;
		s++;
	}
	while (*s && *s != '.' && (*s >= '0' && *s <= '9'))
		integer_part = integer_part * 10 + (*s++ - 48);
	if (*s && *s != '.' && (*s < '0' || *s > '9'))
		return (0);
	helper_func2(s, &pow, &fractional_part);
	while ((*s >= 9 && *s <= 13) || *s == 32)
		s++;
	return ((integer_part + fractional_part) * sign);
}

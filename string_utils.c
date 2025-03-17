/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moel-yag <moel-yag@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 17:20:07 by moel-yag          #+#    #+#             */
/*   Updated: 2025/03/17 14:06:10 by moel-yag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "minilibx-linux/mlx.h"

static void	skip_whitespace(char **s)
{
	while ((**s >= 9 && **s <= 13) || **s == ' ')
		(*s)++;
}

static int	check_digits_and_dots(char **s, int *has_dot)
{
	int	has_digit;

	has_digit = 0;
	while (**s)
	{
		if (**s == '.')
		{
			if (*has_dot || !has_digit)
				return (0);
			*has_dot = 1;
		}
		else if (**s >= '0' && **s <= '9')
			has_digit = 1;
		else
			break ;
		(*s)++;
	}
	return (has_digit);
}

int	is_valid_number(char *s)
{
	int		has_digit;
	int		has_dot;
	char	*ptr;

	ptr = s;
	has_digit = 0;
	has_dot = 0;
	skip_whitespace(&ptr);
	if (*ptr == '+' || *ptr == '-')
		ptr++;
	skip_whitespace(&ptr);
	has_digit = check_digits_and_dots(&ptr, &has_dot);
	skip_whitespace(&ptr);
	return (*ptr == '\0' && has_digit);
}

static int	helper_func2(char **s, double *pow, double *fractional_part)
{
	if (**s == '.')
	{
		(*s)++;
		while (**s)
		{
			if (!(**s >= '0' && **s <= '9'))
				return (0);
			*pow /= 10;
			*fractional_part += (**s++ - 48) * (*pow);
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
	helper_func2(&s, &pow, &fractional_part);
	while ((*s >= 9 && *s <= 13) || *s == 32)
		s++;
	return ((integer_part + fractional_part) * sign);
}

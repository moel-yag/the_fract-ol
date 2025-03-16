/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moel-yag <moel-yag@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 17:20:07 by moel-yag          #+#    #+#             */
/*   Updated: 2025/03/16 15:19:09 by moel-yag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "minilibx-linux/mlx.h"

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

void	ft_putstr_fd(char *s, int fd)
{
	if (!s)
		return ;
	while (*s)
		write(fd, s++, 1);
}

double	atodbl(char *s)
{
	long	integer_part = 0;
	double	fractional_part = 0;
	double	pow = 1;
	int		sign = 1;

	while ((*s >= 9 && *s <= 13) || *s == 32)
		++s;
	if ((*s == '+' || *s == '-') && (*s++ == '-'))
		sign = -1;
	while (*s && *s != '.' && (*s >= '0' && *s <= '9'))
		integer_part = integer_part * 10 + (*s++ - 48);
	if (*s && *s != '.' && (*s < '0' || *s > '9'))
		return (0);
	if (*s == '.')
	{
		s++;
		while (*s)
		{
			if (!(*s >= '0' && *s <= '9'))
				return (0);
			pow /= 10;
			fractional_part += (*s++ - 48) * pow;
		}
	}
	return ((integer_part + fractional_part) * sign);
}

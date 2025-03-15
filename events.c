/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moel-yag <moel-yag@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/15 02:41:04 by moel-yag          #+#    #+#             */
/*   Updated: 2025/03/15 03:00:27 by moel-yag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int key_handler(int keysym, t_fractal *fractal)
{
    if (keysym == XK_Left)
        fractal->shift_x += 0.5;
    else if (keysym == XK_Right)
        fractal->shift_x -= 0.5;
    else if (keysym == XK_Up)
        fractal->shift_y -= 0.5;
    else if (keysym == XK_Down)
        fractal->shift_y += 0.5;
    else if (keysym == XK_plus)
        fractal->iterations_definition += 10;
    else if (keysym == XK_minus)
        fractal->iterations_definition -= 10;
    return (0);
}

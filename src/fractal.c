/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agondan- <agondan-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 12:00:43 by adair             #+#    #+#             */
/*   Updated: 2024/01/24 13:11:12 by agondan-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"

unsigned int	mandlebrot(t_fractal *frac, double x, double y)
{
	double				temp_x;
	unsigned int		i;
	double				zx;
	double				zy;

	i = 0;
	zx = 0.0;
	zy = 0.0;
	x = x / frac->zoom + frac->x_offset;
	y = y / frac->zoom + frac->y_offset;
	while (i < MAX_ITER)
	{
		temp_x = zx * zx - zy * zy + x;
		zy = 2. * zx * zy + y;
		zx = temp_x;
		i++;
		if (zx * zx + zy * zy > 200)
			break ;
	}
	return (i);
}

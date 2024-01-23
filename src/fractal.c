/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adair <adair@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 12:00:43 by adair             #+#    #+#             */
/*   Updated: 2024/01/23 23:56:18 by adair            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"

unsigned int	mandlebrot(double x, double y)
{
	double				temp_x;
	unsigned int		i;
	double				zx;
	double				zy;

	i = 0;
	zx = 0.0;
	zy = 0.0;
	x = x / 333 - 2.3;
	y = y / 333 - 1.11;
	while (i < MAX_ITER)
	{
		temp_x = zx * zx - zy * zy + x;
		zy = 2. * zx * zy + y;
		zx = temp_x;
		i++;
		if (zx * zx + zy* zy > (5))
			break;
	}
	return (i);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agondan- <agondan-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 17:23:32 by agondan-          #+#    #+#             */
/*   Updated: 2024/01/25 18:10:51 by agondan-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"

void	julia_reset(t_fractal *frac)
{
	frac->name = JULIA;
	frac->zoom = 300;
	frac->x_offset = -2.0;
	frac->y_offset = -1.2;
}

void	julia_init(t_fractal *frac, char *cx, char *cy)
{
	frac->name = JULIA;
	frac->zoom = 300;
	frac->x_offset = -2.0;
	frac->y_offset = -1.2;
	frac->cx = ft_atoi(cx) / pow(10.0, ft_strlen(cx));
	frac->cy = ft_atoi(cy) / pow(10.0, ft_strlen(cy));
}

unsigned int	julia(t_fractal *frac, double x, double y)
{
	double				temp;
	unsigned int		i;
	double				zx;
	double				zy;

	i = 0;
	zx = x / frac->zoom + frac->x_offset;
	zy = y / frac->zoom + frac->y_offset;
	x = frac->cx;
	y = frac->cy;
	while (i < MAX_ITER)
	{
		temp = zx;
		zx = zx * zx - zy * zy + x;
		zy = 2. * temp * zy + y;
		i++;
		if (zx * zx + zy * zy > 5)
			break ;
	}
	return (i);
}

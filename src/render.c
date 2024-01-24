/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agondan- <agondan-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 23:01:51 by adair             #+#    #+#             */
/*   Updated: 2024/01/24 16:12:11 by agondan-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"
#include <stdio.h>

void	ft_pixel_put(t_fractal *frac, int x, int y, int color)
{
	unsigned int	new_color;
	int				*pointer;

	new_color = mlx_get_color_value(frac->mlx, color);
	pointer = (int *)(frac->img_addr + (frac->line_size * y));
	pointer += x;
	*pointer = new_color;
}

unsigned int	mandlebrot(t_fractal *frac, double x, double y);

int	select_draw(t_fractal *frac, double x, double y)
{
	if (frac->name == MANDLEBROT)
	{
		return (mandlebrot(frac, x, y));
	}
}

void	render(t_fractal *frac)
{
	double			x;
	double			y;
	unsigned int	iter_count;

	x = 0.;
	y = 0.;
	while (y < Y_SIZE)
	{
		while (x < X_SIZE)
		{
			iter_count = select_draw(frac, x, y);
			if (iter_count == MAX_ITER)
				ft_pixel_put(frac, x, y, 0x000000);
			else
				ft_pixel_put(frac, x, y, ((0xABCDEF * iter_count) % 0xFFFFFF));
			x++;
		}
		x = 0;
		y++;
	}
	mlx_put_image_to_window(frac->mlx, frac->win, frac->img, 0, 0);
}

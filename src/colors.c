/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adair <adair@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 21:15:52 by adair             #+#    #+#             */
/*   Updated: 2024/01/24 22:30:27 by adair            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"

void	next_color(t_fractal *frac)
{
	int	red;
	int	green;
	int	blue;

	red = (frac->color >> 16) & 0xFF;
	green = (frac->color >> 8) & 0xFF;
	blue = (frac->color) & 0xFF;
	if (frac->fase == 0)
	{
		red -= 1;
		blue += 1;
	}
	if (frac->fase == 1)
	{
		blue -= 1;
		green += 1;
	}
	if (frac->fase == 2)
	{
		green -= 1;
		red += 1;
	}
	if (red == 255 || blue == 255 || green == 255)
		frac->fase = (frac->fase + 1) % 3;
	frac->color = red << 16 | green << 8 | blue;
}

int	get_color(t_fractal *frac, int iterations)
{
	double	intensidad;
	int		red;
	int		green;
	int		blue;

	intensidad = iterations / (MAX_ITER + 0.0);
	red = ((frac->color >> 16) & 0xFF) * (intensidad);
	green = ((frac->color >> 8) & 0xFF) * (intensidad);
	blue = ((frac->color) & 0xFF) * (intensidad);
	return (iterations << 24 | red << 16 | green << 8 | blue);
}

void	ft_pixel_update(t_fractal *frac, int x, int y)
{
	int	*pointer;
	int	new_color;

	pointer = (int *)(frac->img_addr + (frac->line_size * y));
	pointer += x;
	new_color = get_color(frac, (*pointer >> 24) & 0xFF);
	*pointer = new_color;
}

int	update_colors(t_fractal *frac)
{
	int x;
	int y;

	x = 0;
	y = 0;
	next_color(frac);
	while (y < Y_SIZE)
	{
		while (x < X_SIZE)
		{
			ft_pixel_update(frac, x, y);
			x++;
		}
		x = 0;
		y++;
	}
	mlx_put_image_to_window(frac->mlx, frac->win, frac->img, 0, 0);
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adair <adair@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 12:24:30 by adair             #+#    #+#             */
/*   Updated: 2024/01/23 15:46:03 by adair            ###   ########.fr       */
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
	*pointer = color;
}

int	close(int _keycode, t_fractal *frac)
{
	mlx_destroy_window(frac->mlx, frac->win);
	return (0);
}

int	main(void)
{
	t_fractal	frac;

	frac.mlx = mlx_init();
	frac.win = mlx_new_window(frac.mlx, X_SIZE, Y_SIZE, "Hello world!");
	frac.img = mlx_new_image(frac.mlx, X_SIZE, Y_SIZE);
	mlx_hook(frac.win, 17, 0, close, &frac);
	frac.img_addr = mlx_get_data_addr(frac.img, &frac.bpp, &frac.line_size,
			&frac.endian);
	mlx_put_image_to_window(frac.mlx, frac.win, frac.img, 0, 0);
	mlx_loop(frac.mlx);
}

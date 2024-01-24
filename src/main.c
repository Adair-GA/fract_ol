/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adair <adair@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 12:24:30 by adair             #+#    #+#             */
/*   Updated: 2024/01/24 23:45:10 by adair            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"
#include <stdio.h>

void	render(t_fractal *frac);
int		update_colors(t_fractal *frac);

int	close_win(t_fractal *frac)
{
	mlx_destroy_window(frac->mlx, frac->win);
	exit(0);
	return (0);
}

int	key(int key, t_fractal *frac)
{
	int	zoom_count;

	if (key == ESC)
		return (close_win(frac));
	zoom_count = (abs(frac->zoom - 333) / 50) + 1;
	if (key == LEFT_ARR)
		frac->x_offset -= 0.5 / zoom_count;
	if (key == RIGHT_ARR)
		frac->x_offset += 0.5 / zoom_count;
	if (key == DOWN_ARR)
		frac->y_offset += 0.5 / zoom_count;
	if (key == UP_ARR)
		frac->y_offset -= 0.5 / zoom_count;
	render(frac);
	return (0);
}

int	mouse(int bt, int _x, int _y, t_fractal *frac)
{
	int	zoom_count;

	_x = _x + _y;
	zoom_count = (abs(frac->zoom - 333) / 50) + 1;
	if (bt == 4 || bt == 5)
	{
		if (bt == 4 && (frac->zoom + 40 * (zoom_count * .2) + 40) < __INT32_MAX__)
		{
			frac->zoom += 40 * (zoom_count * .2) + 40;
		}
		else if (bt == 5)
		{
			frac->zoom -= 40 * (zoom_count * .2) + 40;
		}
		render(frac);
	}
	return (0);
}

void	setup_mlx(t_fractal *frac)
{
	frac->mlx = mlx_init();
	frac->win = mlx_new_window(frac->mlx, X_SIZE, Y_SIZE, "Hello world!");
	frac->img = mlx_new_image(frac->mlx, X_SIZE, Y_SIZE);
	frac->img_addr = mlx_get_data_addr(frac->img, &frac->bpp, &frac->line_size,
			&frac->endian);
	mlx_hook(frac->win, 17, 0, close_win, frac);
	mlx_key_hook(frac->win, key, frac);
	mlx_mouse_hook(frac->win, mouse, frac);
	mlx_do_key_autorepeaton(frac->mlx);
	mlx_loop_hook(frac->mlx, update_colors, frac);
}

int	main(void)
{
	t_fractal	frac;

	setup_mlx(&frac);
	frac.name = MANDLEBROT;
	frac.zoom = 333;
	frac.x_offset = -2.3;
	frac.y_offset = -1.11;
	frac.color = 255 << 16;
	render(&frac);
	mlx_loop(frac.mlx);
}

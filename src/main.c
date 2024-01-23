/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adair <adair@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 12:24:30 by adair             #+#    #+#             */
/*   Updated: 2024/01/23 23:08:02 by adair            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"
#include <stdio.h>

void	render(t_fractal *frac);

int	close_win(t_fractal *frac)
{
	mlx_destroy_window(frac->mlx, frac->win);
	mlx_loop_end(frac->mlx);
	return (0);
}

int	close_key(int key, t_fractal *frac)
{
	if (key == 0xFF1B)
		close_win(frac);
	return (0);
}

int	main(void)
{
	t_fractal	frac;

	frac.mlx = mlx_init();
	frac.win = mlx_new_window(frac.mlx, X_SIZE, Y_SIZE, "Hello world!");
	frac.img = mlx_new_image(frac.mlx, X_SIZE, Y_SIZE);
	frac.img_addr = mlx_get_data_addr(frac.img, &frac.bpp, &frac.line_size,
			&frac.endian);
	render(&frac);
	mlx_put_image_to_window(frac.mlx, frac.win, frac.img, 0, 0);
	mlx_hook(frac.win, 17, 0, close_win, &frac);
	mlx_key_hook(frac.win, close_key, &frac);
	mlx_loop(frac.mlx);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adair <adair@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 12:24:30 by adair             #+#    #+#             */
/*   Updated: 2024/01/25 12:09:10 by adair            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"
#include <stdio.h>

int		update_colors(t_fractal *frac);

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
	mandlebrot_init(&frac);
	frac.color = 255 << 16;
	frac.fase = 0;
	render(&frac);
	mlx_loop(frac.mlx);
}

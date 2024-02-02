/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agondan- <agondan-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 12:24:30 by adair             #+#    #+#             */
/*   Updated: 2024/02/02 11:30:43 by agondan-         ###   ########.fr       */
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

int	main(int argc, char **argv)
{
	t_fractal	frac;

	if (argc == 2 && ft_strncmp(argv[1], "mandl", 5) == 0)
		mandlebrot_init(&frac);
	else if (argc == 4 && ft_strncmp(argv[1], "julia", 5) == 0)
		julia_init(&frac, argv[2], argv[3]);
	else if (argc == 2 && ft_strncmp(argv[1], "ship", 4) == 0)
		ship_init(&frac);
	else
	{
		ft_putendl_fd("Usage: fractol <type> [cx cy]", 1);
		ft_putendl_fd("\ttype: mandl, julia, ship", 1);
		ft_putendl_fd("\tcx, cy: parameters for julia", 1);
		return (0);
	}
	setup_mlx(&frac);
	frac.color = 255 << 16;
	frac.fase = 0;
	render(&frac);
	mlx_loop(frac.mlx);
}

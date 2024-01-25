/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agondan- <agondan-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 11:35:29 by adair             #+#    #+#             */
/*   Updated: 2024/01/25 18:07:51 by agondan-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"

int	close_win(t_fractal *frac)
{
	mlx_destroy_window(frac->mlx, frac->win);
	exit(0);
	return (0);
}

void	reset(t_fractal *frac)
{
	if (frac->name == MANDLEBROT)
		return (mandlebrot_init(frac));
	else if (frac->name == SHIP)
		return (ship_init(frac));
	else
		return (julia_reset(frac));
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
	if (key == LOW_R || key == UPP_R)
		reset(frac);
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
		if (bt == 4 && (frac->zoom + 40 * (zoom_count * .2) + 40) < 2147483647)
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

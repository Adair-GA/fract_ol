/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fract_ol.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agondan- <agondan-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 12:25:19 by adair             #+#    #+#             */
/*   Updated: 2024/01/25 18:08:16 by agondan-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACT_OL_H
# define FRACT_OL_H
# define X_SIZE 1280
# define Y_SIZE 720
# ifndef MAX_ITER
#  define MAX_ITER 50
# endif

# include "mlx.h"
# include <stdlib.h>
# include "libft.h"
# include "keys.h"
# include <math.h>

enum e_fractal
{
	MANDLEBROT,
	JULIA,
	SHIP
};

typedef struct s_fractal
{
	void			*mlx;
	void			*win;
	void			*img;
	char			*img_addr;
	int				bpp;
	int				line_size;
	int				endian;
	int				zoom;
	double			x_offset;
	double			y_offset;
	enum e_fractal	name;
	int				color;
	int				fase;
	double			cx;
	double			cy;
}				t_fractal;

int		close_win(t_fractal *frac);
int		key(int key, t_fractal *frac);
int		mouse(int bt, int _x, int _y, t_fractal *frac);
void	render(t_fractal *frac);
void	mandlebrot_init(t_fractal *frac);
void	julia_init(t_fractal *frac, char *cx, char *cy);
void	ship_init(t_fractal *frac);
void	julia_reset(t_fractal *frac);

#endif

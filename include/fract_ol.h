/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fract_ol.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adair <adair@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 12:25:19 by adair             #+#    #+#             */
/*   Updated: 2024/01/24 16:39:07 by adair            ###   ########.fr       */
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
}				t_fractal;

#endif

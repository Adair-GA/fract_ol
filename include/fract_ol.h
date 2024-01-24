/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fract_ol.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adair <adair@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 12:25:19 by adair             #+#    #+#             */
/*   Updated: 2024/01/24 00:09:11 by adair            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACT_OL_H
# define FRACT_OL_H
# define X_SIZE 1280
# define Y_SIZE 720
# ifndef MAX_ITER
#  define MAX_ITER 150
# endif

# include "mlx.h"

typedef struct s_fractal
{
	void	*mlx;
	void	*win;
	void	*img;
	char	*img_addr;
	int		bpp;
	int		line_size;
	int		endian;
}				t_fractal;


#endif

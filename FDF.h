/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FDF.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jterrell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/29 13:48:06 by jterrell          #+#    #+#             */
/*   Updated: 2020/01/29 13:48:08 by jterrell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef FDF_H
# define FDF_H

#include <math.h>

# define ABS(x) (x >= 0) ? x : x * -1

# define WIN_WID 1000
# define WIN_HEI 1000
# define MAX(x, y) (x > y) ? x : y

#include "libft.h"
#include "mlx.h"

typedef struct	s_point
{
	int		x1;
	int		x2;
	int		y1;
	int		y2;
	float	x;
	float	y;
}			t_point;

typedef struct	s_map
{
	int		*img;
	int		*data;
	int		size_l;
	int		bpp;
	int		endian;
}			t_map;

typedef struct	s_mlx
{
	int		*mlx;
	int		*window;
	t_map	image;
}			t_mlx;

#endif
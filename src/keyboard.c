/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: whool199 <whool199@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/11 16:43:06 by whool199          #+#    #+#             */
/*   Updated: 2020/08/12 15:31:02 by whool199         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdlib.h>

int		hook_keydown(int key, t_mlx *mlx)
{
	(void)mlx;
	if (key == 53)
		exit(EXIT_SUCCESS);
	if (key == ARROW_UP)
		projection_1(1, mlx);
	return (0);
}

int		projection_1(int var, t_mlx *mlx)
{
	if (var)
	{
		mlx->cam->x = 0;
		mlx->cam->y = 0;
		render(mlx);
	}
	return (0);
}

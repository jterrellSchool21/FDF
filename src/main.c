/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: whool199 <whool199@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/11 16:43:18 by whool199          #+#    #+#             */
/*   Updated: 2020/08/11 22:55:11 by whool199         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "libft.h"
#include "mlx.h"
#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>

int		die(char *reason)
{
	ft_putendl(reason);
	return (1);
}

int		main(int argc, char **argv)
{
	t_map	*map;
	t_mlx	*mlx;
	int		fd;

	if (argc < 2)
		return (die("error: not enough arguments"));
	fd = open(argv[1], O_RDONLY);
	printf("%d\n", fd);
	if (fd < 0 || !read_file(fd, &map))
		return (die("error: invalid file"));
	if ((mlx = init(ft_strjoin("FdF - ", argv[1]))) == NULL)
		return (die("error: mlx couldn't init"));
	mlx->map = map;
	render(mlx);
	mlx_hook(mlx->window, 4, 0, hook_mousedown, mlx);
	mlx_hook(mlx->window, 5, 0, hook_mouseup, mlx);
	mlx_hook(mlx->window, 6, 0, hook_mousemove, mlx);
	mlx_key_hook(mlx->window, hook_keydown, mlx);
	mlx_loop(mlx->mlx);
	return (0);
}

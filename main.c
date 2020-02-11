/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jterrell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/29 13:48:16 by jterrell          #+#    #+#             */
/*   Updated: 2020/01/29 13:48:18 by jterrell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FDF.h"
#include "mlx.h"
#include <stdio.h>

float	ft_round(float x)
{
	int		left;
	float	tmp;

	left = (int)x;
	tmp = x - left + 0.5f;
	if (tmp > 1)
		return (left + 1);
	return (left);
}

/*void	off(char *s)
{
	write(1, s, ft_strlen(s));
	exit(1);
}*/

void	line(t_mlx *fdf, t_point *p)
{
    int		dx;
    int		dy;
	int		len;

	dx = abs(p->x2 - p->x1);
	dy = abs(p->y2 - p->y1);
	len = MAX(dx, dy);
    if (len == 0)
    {
		fdf->image.data[(int)(p->y * 1000 + p->x)] = 0x00FF00;
    }
    if (dy <= dx)
    {
		p->x = p->x1;
		p->y = p->y1;
		len++;
		while(len--)
		{
			fdf->image.data[(int)(ft_round(p->y) * 1000 + p->x)] = 0x00FF00;
			p->x++;
			p->y += (float)dy / (float)dx;
		}
	}
	else
	{
		p->x = p->x1;
		p->y = p->y1;
		len++;
		while(len--)
		{
			fdf->image.data[(int)(p->y * 1000 + ft_round(p->x))] = 0x00FF00;
			p->x += (float)dx / (float)dy;
			p->y++;
		}
	}
} 

int		main(void)
{
	t_mlx	*fdf;
	t_point	*p;
	int		count_h;
	int		count_w;

	count_h = -1;
	p = (t_point*)malloc(sizeof(t_point));
	p->x1 = 1;
	p->x2 = 990;
	p->y1 = 1;
	p->y2 = 990;
	fdf = (t_mlx*)malloc(sizeof(t_mlx));
	/*if (argc != 2)
		off("kek");*/
	fdf->mlx = mlx_init();
	fdf->window = mlx_new_window(fdf->mlx, 1000, 1000, "FDF");
	fdf->image.img = mlx_new_image(fdf->mlx, 1000, 1000);
	fdf->image.data = (int *)mlx_get_data_addr(fdf->image.img, &fdf->image.bpp, &fdf->image.size_l, &fdf->image.endian);
	printf("\n%d\n", ABS(-54));
	while (++count_h < 1000)
	{
		count_w = -1;
		while (++count_w < 1000)
		{
			if (count_w % 2)
				fdf->image.data[count_h * 1000 + count_w] = 0xFF0000;
			else
				fdf->image.data[count_h * 1000 + count_w] = 0xFFFFFF;
		}
	}
	line(fdf, p);
	mlx_put_image_to_window(fdf->mlx, fdf->window, fdf->image.img, 0, 0);
	mlx_loop(fdf->mlx);
	return (0);
}
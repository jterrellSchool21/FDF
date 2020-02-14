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

void	draw_main(t_fmap *fmap, t_mlx *fdf, t_point *p)
{
	int		x;
	int		y;
	int		mass[11][19] = {{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, {0, 0, 10, 10, 0, 0, 10, 10, 0, 0, 0, 10, 10, 10, 10, 10, 0, 0, 0}, {0, 0, 10, 10, 0, 0, 10, 10, 0, 0, 0, 0, 0, 0, 0, 10, 10, 0, 0} ,{0, 0, 10, 10, 0, 0, 10, 10, 0, 0, 0, 0, 0, 0, 0, 10, 10, 0, 0}, {0, 0, 10, 10, 10, 10, 10, 10, 0, 0, 0, 0, 10, 10, 10, 10, 0, 0, 0}, {0, 0, 0, 10, 10, 10, 10, 10, 0, 0, 0, 10, 10, 0, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0, 10, 10, 0, 0, 0, 10, 10, 0, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0, 10, 10, 0, 0, 0, 10, 10, 10, 10, 10, 10, 0, 0}, {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}};

	y = 0;
	p->x2 = 0;
	p->y2 = 0;
	p->y1 = 100;
	while (y < fmap->len - 1)
	{
		x = 0;
		p->x1 = 100;
		while (x < fmap->width - 1)
		{
			p->x2 = p->x1 + DX;
			p->y1 = 100;
			p->y2 = mass[y][x + 1];
			line(fdf, p);
			p->x2 = p->x1;
			p->y2 = mass[y + 1][x];
			line(fdf, p);
			printf("\np->x1 = %d, p->x2 = %d, p->y1 = %d, p->y2 = %d, mass[%d][%d] = %d\n", p->x1, p->x2, p->y1, p->y2, y, x, mass[y][x]);
			x++;
		}
		p->y1 += DY;
		y++;
	}
}

/*void	off(char *s)
{
	write(1, s, ft_strlen(s));
	exit(1);
}*/


t_fmap	*fmap_init()
{
	t_fmap	*fmap;

	fmap = (t_fmap*)malloc(sizeof(t_fmap));
	fmap->color = 0xFFFFFF;
	fmap->width = 19;
	fmap->len = 11;
	/*while (j < 11)
	{
		fmap->map[j] = (int*)malloc(sizeof(int*));
		while (i < 19)
		{
			fmap->map[j][i] = (int)malloc(sizeof(int));
			i++;
		}
		j++;
	}
	fmap->map = {{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, {0, 0, 10, 10, 0, 0, 10, 10, 0, 0, 0, 10, 10, 10, 10, 10, 0, 0, 0}, {0, 0, 10, 10, 0, 0, 10, 10, 0, 0, 0, 0, 0, 0, 0, 10, 10, 0, 0} ,{0, 0, 10, 10, 0, 0, 10, 10, 0, 0, 0, 0, 0, 0, 0, 10, 10, 0, 0}, {0, 0, 10, 10, 10, 10, 10, 10, 0, 0, 0, 0, 10, 10, 10, 10, 0, 0, 0}, {0, 0, 0, 10, 10, 10, 10, 10, 0, 0, 0, 10, 10, 0, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0, 10, 10, 0, 0, 0, 10, 10, 0, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0, 10, 10, 0, 0, 0, 10, 10, 10, 10, 10, 10, 0, 0}, {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}};
	*/
	//fmap->map[11][19] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 10, 10, 0, 0, 10, 10, 0, 0, 0, 10, 10, 10, 10, 10, 0, 0, 0, 0, 0, 10, 10, 0, 0, 10, 10, 0, 0, 0, 0, 0, 0, 0, 10, 10, 0, 0} ,{0, 0, 10, 10, 0, 0, 10, 10, 0, 0, 0, 0, 0, 0, 0, 10, 10, 0, 0, 0, 0, 10, 10, 10, 10, 10, 10, 0, 0, 0, 0, 10, 10, 10, 10, 0, 0, 0, 0, 0, 0, 10, 10, 10, 10, 10, 0, 0, 0, 10, 10, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 10, 10, 0, 0, 0, 10, 10, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 10, 10, 0, 0, 0, 10, 10, 10, 10, 10, 10, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
	return (fmap);
}

int		main(void)
{
	t_mlx	*fdf;
	t_point	*p;
	int		count_h;
	int		count_w;
	t_fmap	*fmap;

	count_h = -1;
	p = (t_point*)malloc(sizeof(t_point));

	fdf = (t_mlx*)malloc(sizeof(t_mlx));
	/*if (argc != 2)
		off("kek");*/
	fdf->mlx = mlx_init();
	fdf->window = mlx_new_window(fdf->mlx, 1000, 1000, "FDF");
	fdf->image.img = mlx_new_image(fdf->mlx, 1000, 1000);
	fdf->image.data = (int *)mlx_get_data_addr(fdf->image.img, &fdf->image.bpp, &fdf->image.size_l, &fdf->image.endian);
	fmap = fmap_init();
	//printf("\n%d\n", ABS(-54));
	while (++count_h < 1000)
	{
		count_w = -1;
		while (++count_w < 1000)
		{
			if (count_w % 2)
				fdf->image.data[count_h * 1000 + count_w] = 0x00000;
			else
				fdf->image.data[count_h * 1000 + count_w] = 0x000000;
		}
	}
	draw_main(fmap, fdf, p);
	p->x1 = 1;
	p->x2 = 999;
	p->y1 = 1;
	p->y2 = 999;
	//line(fdf, p);
	mlx_put_image_to_window(fdf->mlx, fdf->window, fdf->image.img, 0, 0);
	mlx_loop(fdf->mlx);
	return (0);
}

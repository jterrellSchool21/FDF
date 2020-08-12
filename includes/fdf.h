/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: whool199 <whool199@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/11 16:42:44 by whool199          #+#    #+#             */
/*   Updated: 2020/08/12 15:24:23 by whool199         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include "libft.h"
# define WIN_WIDTH			1280
# define WIN_HEIGHT			720
# define ARROW_UP			126
# define ARROW_DOWN			125

typedef struct		s_cam
{
	double		offsetx;
	double		offsety;
	double		x;
	double		y;
	int			scale;
	double		**matrix;
}					t_cam;
typedef struct		s_vector
{
	double		x;
	double		y;
	double		z;
	int			color;
}					t_vector;
typedef struct		s_map
{
	int			width;
	int			height;
	int			depth_min;
	int			depth_max;
	t_vector	**vectors;
}					t_map;
typedef struct		s_mouse
{
	char		isdown;
	int			x;
	int			y;
	int			lastx;
	int			lasty;
}					t_mouse;
typedef struct		s_image
{
	void		*image;
	char		*ptr;
	int			bpp;
	int			stride;
	int			endian;
}					t_image;
typedef struct		s_mlx
{
	void		*mlx;
	void		*window;
	t_image		*image;
	t_map		*map;
	t_cam		*cam;
	t_mouse		*mouse;
	double		**zbuf;
}					t_mlx;
typedef struct		s_line
{
	t_vector	start;
	t_vector	stop;
	int			dx;
	int			dy;
	int			sx;
	int			sy;
	int			err;
	int			err2;
}					t_line;
int					read_file(int fd, t_map **map);
t_vector			*get_vector(int x, int y, char *str);
t_map				*get_map(int width, int height);
t_mlx				*init(char *title);
void				render(t_mlx *mlx);
t_vector			rotate(t_vector p, t_cam *r);
t_vector			vector_at(t_map *map, int x, int y);
t_vector			project_vector(t_vector p, t_mlx *mlx);
int					hook_mousemove(int x, int y, t_mlx *mlx);
int					hook_mousedown(int button, int x, int y, t_mlx *mlx);
int					hook_mouseup(int button, int x, int y, t_mlx *mlx);
int					hook_keydown(int key, t_mlx *mlx);
void				image_set_pixel(t_image *image, int x, int y, int color);
void				clear_image(t_image *image);
int					lineclip(t_vector *p1, t_vector *p2);
t_image				*new_image(t_mlx *mlx);
t_image				*del_image(t_mlx *mlx, t_image *img);
void				fill_colors(t_map *m);
int					clerp(int c1, int c2, double p);
size_t				ft_countwords(char *str, char sep);
void				ft_lstrev(t_list **alst);
int					ft_splitdel(char ***split);
size_t				ft_lstcount(t_list *lst);
double				ft_ilerp(double val, double first, double second);
int					ft_lerpi(int first, int second, double p);
int					ft_abs(int i);
int					projection_1(int var, t_mlx *mlx);
#endif

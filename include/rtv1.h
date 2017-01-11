/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rtv1.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jplevy <jplevy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/05 03:21:25 by jplevy            #+#    #+#             */
/*   Updated: 2016/12/07 02:35:21 by aviau            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RVT1_H
# define RVT1_H

# define USAGE "./rtv1 file\n"
# define C_MLX ((t_mlx*)(param))

# include <libft.h>
# include <matrix.h>
# include <mlx.h>
# include <stdlib.h>
# include <float.h>
# include <math.h>
# include <pthread.h>

typedef struct		s_mlx
{
	void			*mlx;
	void			*win;
	void			*img;
	char			*p;
	int				bp;
	int				sl;
	int				endian;
}					t_mlx;

typedef struct		s_point
{
	float			x;
	float			y;
	float			z;
}					t_point;

typedef struct		s_cam
{
	int				width;
	int				height;
	int				fov;
	t_point			rot;
	t_point			pos;
}					t_cam;

typedef struct		s_plane
{
	t_point			pos;
	t_point			n;
	float			d;
	int				col;
}					t_plane;

typedef struct		s_square
{
	t_point			pos;
	t_point			n;
	float			d;
	float			size;
	int				col;
}					t_square;

typedef struct		s_sphere
{
	t_point			center;
	float			r;
	int				col;
}					t_sphere;

typedef struct		s_cyl
{
	t_point			center;
	float			size;
	float			r;
	int				col;
}					t_cyl;

typedef struct		s_triangle
{
	float			d;
	t_point			pos;
	t_point			n;
	t_point			p1;
	t_point			p2;
	t_point			p3;
	int				col;
}					t_triangle;

typedef struct		s_cube
{
	float			d;
	float			size;
	t_point			pos;
	t_point			n;
	int				col;
}					t_cube;

typedef struct		s_scene
{
	t_sphere		light;
	t_cam			cam;
	t_point			ori;
	t_mlx			mlx;
	int				key;
	int				det;
}					t_scene;

typedef struct		s_threads
{
	int				i;
	pthread_t		thds;
	t_scene			*s;
}					t_threads;

int					keypress(int, t_scene *);
int					keyrel(int, t_scene *);
int					mouse(int, int, t_scene *);
float				sphere(t_scene s, t_sphere sp, t_point ray, float *t_last);
float				cylinder(t_scene s, t_cyl cy, t_point ray, float *t_last);
float				plane(t_scene s, t_plane pl, t_point ray, float *t_last);
float				square(t_scene s, t_square sq, t_point ray, float *t_last);
float				triangle(t_scene s, t_triangle tr, t_point ray, float *t_last);
float				cube(t_scene s, t_cyl cy, t_point ray, float *t_last);
float				sq(float num);
float				vec_dot(t_point v, t_point v2);
void				keyapply(t_scene *s);
t_point				vec_norm(t_point vec);

#endif

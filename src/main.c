/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jplevy <jplevy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/27 19:04:59 by jplevy            #+#    #+#             */
/*   Updated: 2016/12/07 02:43:37 by aviau            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rtv1.h>
#include <key.h>
#include <stdio.h>

#define		W_PL 20.0
#define		H_PL 20.0
#define		N_THD 8

int			ft_get_light(int y, int x, t_scene s)
{
	t_point	ray; //vecteur or(igine) normalisé (fonction vec_norm)
	t_sphere	sp;  //sphere
	t_sphere	sp2;  //sphere
	t_sphere	sp3;  //sphere
	t_sphere	sp4;  //sphere
	t_plane		pl;
	t_square	sq;
	t_cyl		cy;
	float	ratio; // ratio width/height
	float	t; // oui ou non dans la sphere (l.64-73).

	int		col;
	int		tmpcol;
//	int		R; // les couleurs en RGB pour pseudo simuler une lumiere
//	int		G;  // venant de la camera, c'est du fake mais ca rend pas
//	int		B;  // trop mal, mais pas a garder ou pas dans cet etat.

	ratio = (float)s.cam.height / (float)s.cam.width; //le fameux ratio
	s.ori.x = (float)x * (W_PL / (float)s.cam.width) - 10.0; //point X dans plan X (-10, 10)
	s.ori.y = (float)y * (H_PL * ratio / (float)s.cam.height) - 10.0 * ratio; //point Y dans plan Y (-10*ratio, 10*ratio)
	s.ori.z = W_PL / (2.0 * 0.27); //point Z correspondant a (width plan / (2 * (angle FOV / 2) en radian))
	//	if (s.ori.x == 0 || s.ori.y == 0)
	//		return (0xFF0000);
	ray = vec_norm(s.ori); // normalization du vecteur

	sp.center.x = 4;  // pos sphere X
	sp.center.y = -3;  // pos sphere Y
	sp.center.z = 60; // pos sphere Z
	sp.r = 3.0;
	sp.col = 0xFF0000;
	sp2.center.x = 2;
	sp2.center.y = 0;
	sp2.center.z = 40;
	sp2.r = 2.0;
	sp2.col = 0x00FF00;
	sp3.center.x = 0;
	sp3.center.y = 0;
	sp3.center.z = 60;
	sp3.r = 2.0;
	sp3.col = 0x0000FF;
	sp4.center.x = -6;
	sp4.center.y = -6;
	sp4.center.z = 70;
	sp4.r = 3.0;
	sp4.col = 0x888888;
	cy.center.x = -4;
	cy.center.y = -3;
	cy.center.z = 100;
	cy.size = 0.2;
	cy.r = 20;
	cy.col = 0x31ECEF;
	pl.pos.x = 0;
	pl.pos.y = 0;
	pl.pos.z = 40;
	pl.n.x = 0;
	pl.n.y = 1;
	pl.n.z = 0;
	pl.col = 0x666666;
	sq.pos.x = -5.5;
	sq.pos.y = -5.5;
	sq.pos.z = 70;
	sq.n.x = 1;
	sq.n.y = 1;
	sq.n.z = 0;
	sq.size = 3.0;
	sq.col = 0xFF00FF;
	s.light.center.x = -6;
	s.light.center.y = -6;
	s.light.center.z = 50;

	t = 0;
	tmpcol = sphere(s, sp, ray, &t);
	if (tmpcol >= 0)
		col = tmpcol;
	tmpcol = sphere(s, sp2, ray, &t);
	if (tmpcol >= 0)
		col = tmpcol;
	tmpcol = sphere(s, sp3, ray, &t);
	if (tmpcol >= 0)
		col = tmpcol;
	tmpcol = sphere(s, sp4, ray, &t);
	if (tmpcol >= 0)
		col = tmpcol;
	tmpcol = cylinder(s, cy, ray, &t);
	if (tmpcol >= 0)
		col = tmpcol;
	tmpcol = plane(s, pl, ray, &t);
	if (tmpcol >= 0)
		col = tmpcol;
	tmpcol = square(s, sq, ray, &t);
	if (tmpcol >= 0)
		col = tmpcol;
	if (t <= 0)
		return (0);
//	if (t > 255)
//		t = 255;
//	R = (col & 0xFF0000) / 0x010000 - (int)(t / 1.3);
//	G = (col & 0xFF00) / 0x0100 - (int)(t / 1.3);
//	B = (col & 0xFF) - (int)(t / 1.3);
//	R = R < 0 ? 0 : R;
//	G = G < 0 ? 0 : G;
//	B = B < 0 ? 0 : B;
//	return (R * 0x10000 + G * 0x100 + B);
	return (col);
}

void	call_pix(t_threads *t, int col)
{
	(t->s->mlx.p)[t->i * 4] = (col & 0xFF);
	(t->s->mlx.p)[t->i * 4 + 1] = (col & 0xFF00) >> 8;
	(t->s->mlx.p)[t->i * 4 + 2] = (col & 0xFF0000) >> 16;
	(t->s->mlx.p)[t->i * 4 + 3] = 0;
}

int		moy(int *nums, int range)
{
	int	i;
	int total;

	i = 0;
	total = 0;
	while (i < range)
	{
		total += nums[i];
		i++;
	}
	return (total / range);
}

void	antialiasing(t_scene *s)
{
//	int	pix;
//
//	pix = t[0].s->cam.width + 1;
//	while (pix < t[0].s->cam.width * t[0].s->cam.height)
//	{
//		i = -1;
//		col = ft_get_light(t->i / t->s->cam.width, t->i % t->s->cam.width, *(t->s));
//		while (++i < t[0].s->det + 1)
//		{
//			t[i].i = pix + i;
//			call_pix(&t[i], col);
//		}
//		pix += t[0].s->det + 1;
//	}
//	
	mlx_put_image_to_window(s->mlx.mlx, s->mlx.win, s->mlx.img, 0, 0);
}

int		ft_get_map(t_threads *t)
{
	int			i;
	int			pix;
	int			col;

	if (!(t[0].s->key & REDRAW))
	{
		mlx_put_image_to_window(t[0].s->mlx.mlx, t[0].s->mlx.win, t[0].s->mlx.img, 0, 0);
		return (0);
	}
	t[0].s->key -= REDRAW;
	keyapply(t[0].s);
	pix = 0;
	while (pix < t[0].s->cam.width * t[0].s->cam.height)
	{
		i = -1;
		col = ft_get_light(t->i / t->s->cam.width, t->i % t->s->cam.width, *(t->s));
		while (++i < t[0].s->det + 1)
		{
			t[i].i = pix + i;
			call_pix(&t[i], col);
		}
		pix += t[0].s->det + 1;
	}
	antialiasing(t[0].s);
	return (0);
}

int		rt_quit(void)
{
	exit(0);
	return (666);
}

int		main(int ac, char **av)
{
	t_threads	t[N_THD];
	t_scene		s;
	int 		i;

	if (ac >= 2 || !(*av))
		ft_putstr(USAGE);
	else
	{
		s.mlx.mlx = mlx_init();
		s.cam.height = 1000;
		s.cam.width = 1200;
		s.cam.pos.x = 0;
		s.cam.pos.y = -3;
		s.cam.pos.z = 0;
		s.cam.rot.x = 1;
		s.cam.rot.y = 1;
		s.cam.rot.z = 0;
		s.key = REDRAW;
		s.det = 0;
		s.mlx.win = mlx_new_window(s.mlx.mlx, s.cam.width, s.cam.height, "rtv1");
		s.mlx.img = mlx_new_image(s.mlx.mlx, s.cam.width, s.cam.height);
		s.mlx.p = mlx_get_data_addr(s.mlx.img, &(s.mlx.bp), &(s.mlx.sl), &(s.mlx.endian));
		i = -1;
		while (++i < N_THD)
			t[i].s = &s;
		mlx_hook(s.mlx.win, 2, (1L << 0), &keypress, &s);
		mlx_hook(s.mlx.win, 3, (1L << 1), &keyrel, &s);
		mlx_hook(s.mlx.win, 6, (1L << 13), &mouse, &s);
		mlx_hook(s.mlx.win, 17, (1L << 17), &rt_quit, NULL);
		mlx_loop_hook(s.mlx.mlx, &ft_get_map, &t);
		mlx_loop(s.mlx.mlx);
	}
	return (0);
}

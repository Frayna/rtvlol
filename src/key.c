/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aviau <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/05 06:49:25 by aviau             #+#    #+#             */
/*   Updated: 2016/12/05 07:45:28 by aviau            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rtv1.h>
#include <key.h>

void	keyapply(t_scene *s)
{
	if (s->key & POS_XP)
		s->cam.pos.x += 0.1;
	if (s->key & POS_XM)
		s->cam.pos.x -= 0.1;
	if (s->key & POS_YP)
		s->cam.pos.y += 0.1;
	if (s->key & POS_YM)
		s->cam.pos.y -= 0.1;
	if (s->key & POS_ZP)
		s->cam.pos.z -= 1;
	if (s->key & POS_ZM)
		s->cam.pos.z += 1;
}

int		keypress(int key, t_scene *s)
{
	if (ESC)
		exit (0);
	if (!(s->key & POS_XM) && LEFT)
		s->key += POS_XM;
	if (!(s->key & POS_XP) && RIGHT)
		s->key += POS_XP;
	if (!(s->key & POS_YM) && P_UP)
		s->key += POS_YM;
	if (!(s->key & POS_YP) && P_DOWN)
		s->key += POS_YP;
	if (!(s->key & POS_ZM) && UP)
		s->key += POS_ZM;
	if (!(s->key & POS_ZP) && DOWN)
		s->key += POS_ZP;
	if (!(s->key & REDRAW))
		s->key += REDRAW;
	return (0);
}

int		keyrel(int key, t_scene *s)
{
	if ((s->key & POS_XM) && LEFT)
		s->key -= POS_XM;
	if ((s->key & POS_XP) && RIGHT)
		s->key -= POS_XP;
	if ((s->key & POS_YM) && P_UP)
		s->key -= POS_YM;
	if ((s->key & POS_YP) && P_DOWN)
		s->key -= POS_YP;
	if ((s->key & POS_ZM) && UP)
		s->key -= POS_ZM;
	if ((s->key & POS_ZP) && DOWN)
		s->key -= POS_ZP;
	if (KP_1 && s->det < 5)
		s->det++;
	if (KP_2 && s->det > 0)
		s->det--;
	if (!(s->key & REDRAW))
		s->key += REDRAW;
	return (0);
}

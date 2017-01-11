#include <rtv1.h>
#include <stdio.h>

float		dif_sphere(t_scene s, t_sphere sp, t_point ray, t_sphere light, float t)
{
	t_point		hit;
	t_point		norm;
	t_point		vlight;
	float		dot;

	hit = (t_point){.x = ray.x * t + s.cam.pos.x, .y = ray.y * t + s.cam.pos.y, .z = ray.z * t + s.cam.pos.z};
	norm = (t_point){.x = hit.x - sp.center.x,
		.y = hit.y - sp.center.y, .z = hit.z - sp.center.z};
	vlight = (t_point){.x = light.center.x - hit.x,
		.y = light.center.y - hit.y, .z = light.center.z - hit.z};
	vlight = vec_norm(vlight);
	norm = vec_norm(norm);
	dot = norm.x * vlight.x + norm.y * vlight.y + norm.z * vlight.z;
	return(acos(dot));
}

float		dif_cyl(t_scene s, t_cyl cy, t_point ray, t_sphere light, float t)
{
	t_point		hit;
	t_point		norm;
	t_point		vlight;
	float		dot;

	hit = (t_point){.x = ray.x * t + s.cam.pos.x, .y = ray.y * t + s.cam.pos.y, .z = ray.z * t + s.cam.pos.z};
	norm = (t_point){.x = hit.x - cy.center.x,
		.y = 1, .z = hit.z - cy.center.z};
	vlight = (t_point){.x = light.center.x - hit.x,
		.y = light.center.y - hit.y, .z = light.center.z - hit.z};
	vlight = vec_norm(vlight);
	norm = vec_norm(norm);
	dot = vec_dot(norm, vlight);
	return(acos(dot));
}

float		dif_pl(t_scene s, t_plane pl, t_point ray, t_sphere light, float t)
{
	t_point		hit;
	t_point		norm;
	t_point		vlight;
	float		dot;

	hit = (t_point){.x = ray.x * t + s.cam.pos.x, .y = ray.y * t + s.cam.pos.y, .z = ray.z * t + s.cam.pos.z};
	norm = (t_point){.x = hit.x - pl.pos.x,
		.y = hit.y - pl.pos.y, .z = hit.z - pl.pos.z};
	vlight = (t_point){.x = light.center.x - hit.x,
		.y = light.center.y - hit.y, .z = light.center.z - hit.z};
	vlight = vec_norm(vlight);
	norm = vec_norm(norm);
	dot = vec_dot(norm, vlight);
	return(acos(dot));
}

int			colorize_light(int col, float angle)
{
	float	p;
	int		r;
	int		g;
	int		b;

	p = angle / (M_PI / 2);
	r = (col & 0xFF0000) / 0x10000;
	g = (col & 0xFF00) / 0x100;
	b = (col & 0xFF);
	r = r - r * p;
	g = g - g * p;
	b = b - b * p;
	r = r < 0 ? 0 : r;
	g = g < 0 ? 0 : g;
	b = b < 0 ? 0 : b;
	return (r * 0x10000 + g * 0x100 + b);
}

float		sphere(t_scene s, t_sphere sp, t_point ray, float *t_last)
{
	float	t;
	float	delta;
	float	a;
	float	b;
	float	c;

	a = sq(ray.x) + sq(ray.y) + sq(ray.z);
	b = 2 * ((s.cam.pos.x - sp.center.x) * ray.x + (s.cam.pos.y - sp.center.y) * ray.y + (s.cam.pos.z - sp.center.z) * ray.z);
	c = sq(s.cam.pos.x - sp.center.x) + sq(s.cam.pos.y - sp.center.y) + sq(s.cam.pos.z - sp.center.z) - sq(sp.r);
	delta = sq(b) - 4.0 * a * c;
	if (delta > 0)
	{
		t = (-b + sqrtf(delta)) / (2.0 * a);
		t = t > ((-b - sqrtf(delta)) / (2.0 * a)) ? ((-b - sqrtf(delta)) / (2.0 * a)) : t;
	}
	else
		t = 0;
	if (t > 0 && (t < *t_last || *t_last <= 0))
	{
		*t_last = t;
		return (colorize_light(sp.col, dif_sphere(s, sp, ray, s.light, *t_last)));
//		return (sp.col);
	}
	return (-1);
}

int			cyl_cap(t_scene s, t_cyl cy, t_point ray, float *t_last)
{
	float	t;
	float	dot;
	t_point	hit;
	t_point	v;

	t = -(s.cam.pos.y - cy.center.y + cy.size) / ray.y;
	hit = (t_point){.x = ray.x * t + s.cam.pos.x, .y = ray.y * t + s.cam.pos.y, .z = ray.z * t + s.cam.pos.z};
	v = (t_point){.x = hit.x - cy.center.x, .y = hit.y - cy.center.y + cy.size, .z = hit.z - cy.center.z};
	dot = vec_dot(v, v);
	if (t > 0 && (t < *t_last || *t_last <= 0) && sqrtf(dot) <= cy.r)// && s.cam.pos.z + t * ray.z > 30)
	{
		*t_last = t;
		return(cy.col);
	}
	return (-1);
}

float		cylinder(t_scene s, t_cyl cy, t_point ray, float *t_last)
{
	float	t;
	float	t2;
	float	delta;
	float	a;
	float	b;
	float	c;
	int		out;

	a = sq(ray.x) + sq(ray.z);
	b = 2.0 * (ray.x * (s.cam.pos.x - cy.center.x) + ray.z * (s.cam.pos.z - cy.center.z));
	c = sq(s.cam.pos.x - cy.center.x) + sq(s.cam.pos.z - cy.center.z) - (cy.r * cy.r);
	delta = sq(b) - 4.0 * a * c;
	if (delta > 0)
	{
		t = (-b + sqrtf(delta)) / (2.0 * a);
		if (t > (-b - sqrtf(delta)) / (2.0 * a))
		{
			t2 = t;
			t = (-b - sqrtf(delta)) / (2.0 * a);
		}
	}
	else
		t = 0;
	if (t > 0 && (t < *t_last || *t_last <= 0) &&
		s.cam.pos.y + t * ray.y < cy.center.y &&
		s.cam.pos.y + t * ray.y > cy.center.y - cy.size)
	{
		*t_last = t;
		return (colorize_light(cy.col, dif_cyl(s, cy, ray, s.light, *t_last)));
//		return (cy.col);
	}
	out = cyl_cap(s, cy, ray, t_last);
	if (out >= 0)
		return (out);
	if (t2 > 0 && (t2 < *t_last || *t_last <= 0) &&
		s.cam.pos.y + t2 * ray.y < cy.center.y &&
		s.cam.pos.y + t2 * ray.y > cy.center.y - cy.size)
	{
		*t_last = t2;
//		return (colorize_light(cy.col, dif_cyl(s, cy, ray, s.light, *t_last)));
		return (0x808080);
	}
	return (-1);
}

float		plane(t_scene s, t_plane pl, t_point ray, float *t_last)
{
	float	t;

	pl.d = -pl.pos.x * pl.n.x - pl.pos.y * pl.n.y - pl.pos.z * pl.n.z;
	t = -(pl.n.x * s.cam.pos.x + pl.n.y * s.cam.pos.y + pl.n.z * s.cam.pos.z + pl.d) \
		/ (pl.n.x * ray.x + pl.n.y * ray.y + pl.n.z * ray.z);

	if (t > 0 && (t < *t_last || *t_last <= 0))// && s.cam.pos.z + t * ray.z > 30)
	{
		*t_last = t;
		return(((int)(fabs(s.cam.pos.x + t * ray.x - 0.5) + 0.5) % 2 ^ (int)(fabs(s.cam.pos.z / 3 + t * ray.z / 3) + 0.5) % 2) ? 0x000F00 : 0x00CC00);
	}
	return (-1);
}

float		square(t_scene s, t_square sq, t_point ray, float *t_last)
{
	float	t;
	float	dot;
	t_point	hit;
	t_point	v;

	sq.d = -sq.pos.x * sq.n.x - sq.pos.y * sq.n.y - sq.pos.z * sq.n.z;
	t = -(sq.n.x * s.cam.pos.x + sq.n.y * s.cam.pos.y + sq.n.z * s.cam.pos.z + sq.d) \
		/ (sq.n.x * ray.x + sq.n.y * ray.y + sq.n.z * ray.z);
	hit = (t_point){.x = ray.x * t + s.cam.pos.x, .y = ray.y * t + s.cam.pos.y, .z = ray.z * t + s.cam.pos.z};
	v = (t_point){.x = hit.x - sq.pos.x, .y = hit.y - sq.pos.y, .z = hit.z - sq.pos.z};
	dot = v.x * v.x + v.y * v.y + v.z * v.z;
	if (t > 0 && (t < *t_last || *t_last <= 0) && sqrtf(dot) <= sq.size)// && s.cam.pos.z + t * ray.z > 30)
	{
		*t_last = t;
		return(sq.col);
	}
	return (-1);
}

float		triangle(t_scene s, t_triangle tr, t_point ray, float *t_last)
{
	float	t;
	t_point	hit;

	tr.d = -tr.pos.x * tr.n.x - tr.pos.y * tr.n.y - tr.pos.z * tr.n.z;
	t = -(tr.n.x * s.cam.pos.x + tr.n.y * s.cam.pos.y + tr.n.z * s.cam.pos.z + tr.d) \
		/ (tr.n.x * ray.x + tr.n.y * ray.y + tr.n.z * ray.z);
	hit.x = ray.x * t;
	hit.y = ray.y * t;
	hit.z = ray.z * t;
	if(!(((hit.x > tr.p1.x && hit.x < tr.p2.x && hit.x > tr.p3.x)
		|| (hit.x > tr.p2.x && hit.x < tr.p3.x && hit.x > tr.p1.x)
		|| (hit.y > tr.p3.y && hit.y < tr.p1.y && hit.y > tr.p2.y)) &&
		((hit.y > tr.p1.y && hit.y < tr.p2.y && hit.y > tr.p3.y)
		|| (hit.y > tr.p2.y && hit.y < tr.p3.y && hit.y > tr.p1.y)
		|| (hit.y > tr.p3.y && hit.y < tr.p1.y && hit.y > tr.p2.y)) &&
		((hit.z > tr.p1.z && hit.z < tr.p2.z && hit.z > tr.p3.z)
		|| (hit.z > tr.p2.z && hit.z < tr.p3.z && hit.z > tr.p1.z)
		|| (hit.z > tr.p3.z && hit.z < tr.p1.z && hit.z > tr.p2.z))))
		return(-1);
	if (t > 0 && (t < *t_last || *t_last <= 0))
	{
		*t_last = t;
		return (tr.col);
	}
	return (-1);
}

float		cube(t_scene s, t_cyl cy, t_point ray, float *t_last)
{
	float	t;
	float	delta;
	float	a;
	float	b;
	float	c;

	a = sq(ray.x) + sq(ray.z) ; // les fameuses putain de fat equation qu'on va se retaper
	b = 2.0 * (ray.x * (s.cam.pos.x - cy.center.x) + ray.z * (s.cam.pos.z - cy.center.z));
	c = sq(s.cam.pos.x - cy.center.x) + sq(s.cam.pos.z - cy.center.z) - (cy.r * cy.r);
	delta = sq(b) - 4.0 * a * c; // le delta grace â a, b, et c.
	if (delta > 0)  // si delta negatif alors
	{
		t = (-b + sqrtf(delta)) / (2.0 * a); // la calcul de t avec (-b + racine(delta))
		// en dessous, le meme calcul avec (-b - racine(delta)) et ternaire pour definir le plus petit
		t = t > ((-b - sqrtf(delta)) / (2.0 * a))? ((-b - sqrtf(delta)) / (2.0 * a)) : t;
		// definir le plus petit si le rayon touche deux fois la sphere, et prendre le point touché
	}
	else
		t = 0;
	if (t > 0 && (t < *t_last || *t_last <= 0))// && s.cam.pos.y + t * ray.y > cy.center.y && s.cam.pos.y + t * ray.y < cy.center.y + cy.size)
	{
		*t_last = t;
		// printf("cy = %f\n", t);
		return (cy.col);
	}
	return (-1);
}

#include <rtv1.h>
#include <stdio.h>

float		vec_dot(t_point v, t_point v2)
{
	return (v.x * v2.x + v.y * v2.y + v.z * v2.z);
}

t_point		vec_norm(t_point vec)
{
	// Tout est dans ce lien
	// http://www.fundza.com/vectors/normalize/
	t_point	norm;
	float	lenght;

	lenght = sqrt((vec.x * vec.x) + (vec.y * vec.y) + (vec.z * vec.z));
	norm.x = vec.x / lenght;
	norm.y = vec.y / lenght;
	norm.z = vec.z / lenght;
	return (norm);
}

float		sq(float num)
{
	return (num * num);
}

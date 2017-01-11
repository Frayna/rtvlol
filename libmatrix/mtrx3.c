#include "matrix.h"

t_vec3		m_rot3_x(t_vec3 m, float ang)
{
	t_vec3	out;

	out.x = m.x;
	out.y = m.y * cos(ang) - m.z * sin(ang);
	out.z = m.y * sin(ang) + m.z * cos(ang);
	return (out);
}

t_vec3		m_rot3_y(t_vec3 m, float ang)
{
	t_vec3	out;

	out.x = m.x * cos(ang) + m.z * sin(ang);
	out.y = m.y;
	out.z = -m.x * sin(ang) + m.z * cos(ang);
	return (out);
}

t_vec3		m_rot3_z(t_vec3 m, float ang)
{
	t_vec3	out;

	out.x = m.x * cos(ang) - m.y * sin(ang);
	out.y = m.x * sin(ang) + m.y * cos(ang);
	out.z = m.z;
	return (out);
}

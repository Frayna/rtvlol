#include "matrix.h"

t_vec2		m_rot2(t_vec2 m, float ang)
{
	t_vec2	out;

	out.x = m.x * cos(ang) - m.y * sin(ang);
	out.y = m.x * sin(ang) + m.y * cos(ang);
	return (out);
}

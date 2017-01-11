#ifndef	MATRIX_H
# define MATRIX_H

# include <math.h>

typedef	struct	s_vec2
{
	float		x;
	float		y;
}				t_vec2;

typedef	struct	s_vec3
{
	float		x;
	float		y;
	float		z;
}				t_vec3;

typedef	struct	s_vec4
{
	float		i;
	float		j;
	float		k;
	float		r;
}				t_vec4;

typedef struct	s_mtrx2
{
	t_vec2		x;
	t_vec2		y;
}				t_mtrx2;

typedef struct	s_mtrx3
{
	t_vec3		x;
	t_vec3		y;
	t_vec3		z;
}				t_mtrx3;

#endif

float	rad(float deg);
float	deg(float rad);
t_vec2	m_rot2(t_vec2 m, float ang);
t_vec3	m_rot3_x(t_vec3 m, float ang);
t_vec3	m_rot3_y(t_vec3 m, float ang);
t_vec3	m_rot3_z(t_vec3 m, float ang);

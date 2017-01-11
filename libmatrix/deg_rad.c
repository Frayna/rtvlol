#include "matrix.h"

float	rad(float deg)
{
	return (deg * (2.0f * M_PI) / 360.0f);
}

float	deg(float rad)
{
	return (rad * 360.0f / (2.0f * M_PI));
}

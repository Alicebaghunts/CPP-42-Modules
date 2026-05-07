#include "Point.hpp"
#include <cmath>

static float area(Point const a, Point const b, Point const c)
{
	float ax = a.getX().toFloat();
	float ay = a.getY().toFloat();
	float bx = b.getX().toFloat();
	float by = b.getY().toFloat();
	float cx = c.getX().toFloat();
	float cy = c.getY().toFloat();
	return std::fabs((bx - ax) * (cy - ay) - (by - ay) * (cx - ax)) / 2.0f;
}

bool bsp(Point const a, Point const b, Point const c, Point const point)
{
	float A = area(a, b, c);
	float A1 = area(point, b, c);
	float A2 = area(a, point, c);
	float A3 = area(a, b, point);

	if (A1 == 0 || A2 == 0 || A3 == 0)
		return false;

	return (std::fabs(A - (A1 + A2 + A3)) <= 1e-6f);
}

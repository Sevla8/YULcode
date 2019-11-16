#include <assert.h>
#include <math.h>
#include "point.h"

Point::Point(const Point& point) : x(point.x), y(point.y) {}

Point::Point(double _x, double _y)  : x(_x), y(_y) {}

bool Point::isNeighbour(const Point& point) const {
	if (this->x + 1 == point.x && this->y == point.y)
		return true;
	if (this->x - 1 == point.x && this->y == point.y)
		return true;
	if (this->x == point.x && this->y + 1 == point.y)
		return true;
	if (this->x == point.x && this->y - 1 == point.y)
		return true;
	return false;
}

#include "Transform.h"

Transform Transform::fromTo(double startX, double startY, double endX, double endY) const
{
	Transform t;

	t.x = (startX + endX) / 2;
	t.y = (startY + endY) / 2;
	double length = sqrt(pow((startX - endX), 2) + pow((startY - endY), 2));
	t.sx = length / 2;
	t.sy = 1;
	t.r = atan2((endY - startY), (endX - startX));

	return t;
}
#pragma once
#include <iostream>
#include <string>
#include <cmath>

using namespace std;

class Transform
{
public:

	double x = 0;
	double y = 0;
	double sx = 0;
	double sy = 0;
	double r = 0;
	string name = "Transform";

	Transform fromTo(double startX, double startY, double endX, double endY) const;

};

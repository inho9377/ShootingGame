#include "Point.h"



Point::Point()
{
}


Point::~Point()
{
}

double Point::GetDistanceTwoPoint(Point p1, Point p2)
{
	return sqrt(pow(p1.GetX() - p2.GetX(), 2) + pow(p1.GetY() - p2.GetY(), 2));
}

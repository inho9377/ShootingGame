#pragma once
#include <math.h>
//2D�����̹Ƿ� ���ǻ� ���� ��(x,y)Ŭ����
class Point
{
public:
	Point();
	~Point();

	double GetX() { return x; }
	double GetY() { return y; }
	void SetX(float putx) { x = putx; }
	void SetY(float puty) { y = puty; }

	double GetDistanceTwoPoint(Point p1, Point p2);
private:
	float x, y;
};


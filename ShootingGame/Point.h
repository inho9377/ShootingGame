#pragma once
class Point
{
public:
	Point();
	~Point();

	double GetX() { return x; }
	double GetY() { return y; }
	void SetX(double putx) { x = putx; }
	void SetY(double puty) { y = puty; }

private:
	float x, y;
};


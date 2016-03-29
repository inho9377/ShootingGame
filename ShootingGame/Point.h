#pragma once

//2D게임이므로 편의상 만든 점(x,y)클래스
class Point
{
public:
	Point();
	~Point();

	double GetX() { return x; }
	double GetY() { return y; }
	void SetX(float putx) { x = putx; }
	void SetY(float puty) { y = puty; }

private:
	float x, y;
};


#pragma once

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

private:
	float x, y;
};


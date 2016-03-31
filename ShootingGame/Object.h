#pragma once
#include <windows.h>
#include <atlimage.h>
#include "Point.h"
#include <memory>

//���� �׷����� ����� Ŭ����
//Flight, Bullet, Background���� base
class Object
{
public:
	Object();
	Object(WCHAR path[], double currentPosX, double currentPosY);
	~Object();

	//�̹����� ȭ���� ����� �� ��� ����
	enum class info_out_of_screen {
		LEFT_OVER,
		RIGHT_OVER,
		UP_OVER,
		DOWN_OVER,
		IN_SCREEN
	};

	//ȭ�鿡 �׷���
	void draw(HDC hdc);


	void SetCurrentPosition(Point point)
	{
		CurrentPosition.SetX(point.GetX());
		CurrentPosition.SetY(point.GetY());
	}
	void SetCurrentPosition(double x, double y){ CurrentPosition.SetX(x), CurrentPosition.SetY(y); }

	Point GetCurrentPosition() { return CurrentPosition; }
	void SetFileLocation(WCHAR loc[]) { wcscpy_s(fileLocation, loc);}

	std::shared_ptr<CImage> GetDrawImage() { return DrawImage; }

	void SetCimage(std::shared_ptr<CImage> c){ DrawImage = c; }
	
	//�̹����� �ش� ��ġ '��ŭ'�̵���Ų��.
	virtual void move(double x, double y);
	//roll-over�� ǥ������ ����

	//�̹����� ȭ���� ����°�
	bool IsOutOfScreen();

	//�̹����� ȭ���� ������� ��� �������� ����°�
	info_out_of_screen InfoOutOfScreen();
	

	const double winSizeX = 800.0;
	const double winSizeY = 600.0;
	bool IsCollision(Object &obj);


	double GetRadian() { return radian; }
	void SetRadian(double set) { radian = set; }

	Point GetCenter() { return center; }
	void Setcenter(Point set) { center = set; }

private:
	//������Ʈ�� ���� ��ġ
	Point CurrentPosition;

	//������Ʈ�� ������ �̹����� ���� ��ġ
	WCHAR fileLocation[256];
	std::shared_ptr<CImage> DrawImage;

	//�浹üũ�� ���� ������(������ ����)
	Point center;
	double radian;
	
};
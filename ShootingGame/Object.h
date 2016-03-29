#pragma once
#include <windows.h>
#include <atlimage.h>
#include "Point.h"

//무언가 그려지는 대상의 클래스
//Flight, Bullet, Background등의 base
class Object
{
public:
	Object();
	Object(WCHAR path[], double currentPosX, double currentPosY);
	~Object();

	//이미지가 화면을 벗어났을 때 벗어난 방향
	enum class info_out_of_screen {
		LEFT_OVER,
		RIGHT_OVER,
		UP_OVER,
		DOWN_OVER,
		IN_SCREEN
	};

	//화면에 그려냄
	void draw(HDC hdc);


	void SetCurrentPosition(Point point)
	{
		CurrentPosition.SetX(point.GetX());
		CurrentPosition.SetY(point.GetY());
	}
	void SetCurrentPosition(double x, double y){ CurrentPosition.SetX(x), CurrentPosition.SetY(y); }

	Point GetCurrentPosition() { return CurrentPosition; }
	void SetFileLocation(WCHAR loc[]) { wcscpy_s(fileLocation, loc);}

	CImage* GetCimage() { return Cimage; }

	void SetCimage(CImage* c){ Cimage = c; }
	
	//이미지를 해당 위치 '만큼'이동시킨다.
	void move(double x, double y);

	//이미지가 화면을 벗어났는가
	bool IsOutOfScreen();

	//이미지가 화면을 벗어났을때 어느 방향으로 벗어났는가
	info_out_of_screen InfoOutOfScreen();


	const double winSizeX = 800.0;
	const double winSizeY = 600.0;

private:
	//오브젝트의 현재 위치
	Point CurrentPosition;

	//오브젝트가 가지는 이미지의 파일 위치
	WCHAR fileLocation[256];
	CImage *Cimage;
	
	
};
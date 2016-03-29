#pragma once
#include <windows.h>
#include <atlimage.h>
#include "Point.h"

class Object
{
public:
	Object();
	Object(WCHAR path[], double currentPosX, double currentPosY);
	~Object();


	enum class info_out_of_screen {
		LEFT_OVER,
		RIGHT_OVER,
		UP_OVER,
		DOWN_OVER,
		IN_SCREEN
	};


	void draw(HDC hdc);


	void SetCurrentPosition(Point point)
	{
		CurrentPosition.SetX(point.GetX());
		CurrentPosition.SetY(point.GetY());
	}
	void SetCurrentPosition(double x, double y)
	{
		CurrentPosition.SetX(x), CurrentPosition.SetY(y);
	}

	Point GetCurrentPosition()
	{
		return CurrentPosition;
	}
	void SetFileLocation(WCHAR loc[])
	{
		wcscpy_s(fileLocation, loc);
	}

	CImage* GetCimage() { return Cimage; }
	void SetCimage(CImage* c)
	{
		Cimage = c;
	}
	
	void move(double x, double y);

	bool IsOutOfScreen();
	info_out_of_screen InfoOutOfScreen();


	const double winSizeX = 800.0;
	const double winSizeY = 600.0;

private:
	Point CurrentPosition;
	WCHAR fileLocation[256];
	CImage *Cimage;
	
	
};
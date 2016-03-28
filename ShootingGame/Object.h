#pragma once
#include <windows.h>
#include <atlimage.h>
#include "Point.h"
class Object
{
public:
	Object();
	~Object();

	void draw(HDC hdc);
	void SetCurrentPosition(double x, double y)
	{
		CurrentPosition.SetX(x), CurrentPosition.SetY(y);
	}
	void SetFileLocation(WCHAR* loc)
	{
		fileLocation = loc;
	}

	
private:
	Point CurrentPosition;
	WCHAR *fileLocation;
	CImage Cimage;
	
};


#pragma once
#include <windows.h>
#include "Point.h"
class Object
{
public:
	Object();
	~Object();

	void draw(HDC hdc);
	
private:
	Point CurrentPosition;
	
};


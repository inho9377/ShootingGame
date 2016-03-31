#include "Object.h"


Object::Object()
{
	
}



Object::Object(WCHAR re[], double currentPosX=0.0, double currentPosY=0.0)
{
	DrawImage = std::make_shared<CImage>();
	WCHAR path[256];
	GetCurrentDirectory(sizeof(path), path);
	WCHAR backGroundPath[256];
	wcscpy_s(backGroundPath, path);
	wcscat_s(backGroundPath, re);
	wcscpy_s(fileLocation, backGroundPath);
	DrawImage->Load(backGroundPath);
}


Object::~Object()
{
	GetDrawImage()->Destroy();
}

void Object::draw(HDC hdc)
{
	DrawImage->BitBlt(hdc, this->CurrentPosition.GetX(), this->CurrentPosition.GetY(), SRCCOPY);
}


void Object::move(double x, double y)
{
	this->SetCurrentPosition(this->GetCurrentPosition().GetX() + x,
		this->GetCurrentPosition().GetY() + y);
}


//��ü�� ȭ�� �ٱ����� �������� ����
bool Object::IsOutOfScreen()
{
	if (GetCurrentPosition().GetX() > winSizeX)
		return true;
	
	if (GetCurrentPosition().GetX() < 0.0)
		return true;

	if (GetCurrentPosition().GetY() > winSizeY)
		return true;

	if (GetCurrentPosition().GetY() < 0.0)
		return true;

	return false;


}


	
//��ü�� ȭ�� �ٱ��� �ִٸ�, ��� �ִ��� ����
Object::info_out_of_screen Object::InfoOutOfScreen()
{
	if (GetCurrentPosition().GetX() > winSizeX-150)
		return info_out_of_screen::RIGHT_OVER;

	if (GetCurrentPosition().GetX() < 0.0)
		return info_out_of_screen::LEFT_OVER;

	if (GetCurrentPosition().GetY() > winSizeY-150)
		return info_out_of_screen::DOWN_OVER;

	if (GetCurrentPosition().GetY() < 0.0)
		return info_out_of_screen::UP_OVER;

	return info_out_of_screen::IN_SCREEN;
}

//Ư�� object�� �浹���� ����
bool Object::IsCollision(Object &obj)
{
	double distance = this->GetCenter().GetDistanceTwoPoint(this->GetCenter(), obj.GetCenter());

	if (distance < (this->GetRadian() + obj.GetRadian()))
		return true;

	return false;
}


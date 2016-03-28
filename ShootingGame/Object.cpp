#include "Object.h"



Object::Object()
{
}


Object::~Object()
{
}

void Object::draw(HDC hdc)
{

	Cimage.BitBlt(hdc, this->CurrentPosition.GetX(), this->CurrentPosition.GetY(), SRCCOPY);

}

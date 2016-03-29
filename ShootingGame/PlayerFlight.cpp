#include "PlayerFlight.h"


CPlayerFlight::CPlayerFlight()
{
	SetCimage(new CImage);
	WCHAR path[256];
	GetCurrentDirectory(sizeof(path), path);
	WCHAR backGroundPath[256];
	wcscpy_s(backGroundPath, path);
	wcscat_s(backGroundPath, L"/Image/playerflight.bmp");
	SetCurrentDirectory(backGroundPath);


	SetCurrentPosition(0.0, 0.0);

	SetFileLocation(backGroundPath);

	GetCimage()->Load(backGroundPath);

	for (int tmp = 0; tmp < num_bullet; tmp++)
	{
		BulletList.push(new CBullet);
	}
}

CPlayerFlight::~CPlayerFlight()
{

}

void CPlayerFlight::SetPositionWithSpeed(int myinput)
{
	if (!IsOutOfScreen())
	{
		switch (myinput)
		{
		case VK_UP:
			move(0, -speed);
			break;

		case VK_DOWN:
			move(0, speed);
			break;

		case VK_LEFT:
			move(-speed, 0);
			break;

		case VK_RIGHT:
			move(speed, 0);
			break;
		default:
			break;
		}
	}

	else
	{
		switch (InfoOutOfScreen())
		{
		case Object::info_out_of_screen::LEFT_OVER:
			move(1, 0);
			break;
		case Object::info_out_of_screen::RIGHT_OVER:
			move(-1, 0);
			break;
		case Object::info_out_of_screen::UP_OVER:
			move(0, 1);
			break;
		case Object::info_out_of_screen::DOWN_OVER:
			move(0, -1);
			break;
		default:
			break;
		}
		

		
	}
}


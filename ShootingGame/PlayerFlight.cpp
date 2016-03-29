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
			move(0, speed);
			break;

		case VK_DOWN:
		case VK_LEFT:
		case VK_RIGHT:


		default:
			break;
		}
	}
}


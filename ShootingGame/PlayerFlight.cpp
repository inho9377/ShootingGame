#include "PlayerFlight.h"


CPlayerFlight::CPlayerFlight()
{
	//파일 이름 설정
	SetCimage(new CImage);
	WCHAR path[256];
	GetCurrentDirectory(sizeof(path), path);
	WCHAR backGroundPath[256];
	wcscpy_s(backGroundPath, path);
	wcscat_s(backGroundPath, L"/Image/playerflight.bmp");
	SetCurrentDirectory(backGroundPath);


	SetCurrentPosition(0.0, 0.0);

	SetFileLocation(backGroundPath);

	GetDrawImage()->Load(backGroundPath);

	for (int tmp = 0; tmp < num_bullet; tmp++)
	{
		//BulletSprite 제작 까지 잠시..
		//BulletList.push(new CBullet);
	}
}

CPlayerFlight::~CPlayerFlight()
{

}

void CPlayerFlight::SetPositionWithSpeed(int myinput)
{
	//플레이어의 비행기가 화면 안쪽에 있으면
	if (!IsOutOfScreen())
	{
		//키보드 입력에 따라 움직임
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
	//화면 바깥에 있으면
	else
	{
		//조작에도 움직이지 않도록 위치를 돌려놓음
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


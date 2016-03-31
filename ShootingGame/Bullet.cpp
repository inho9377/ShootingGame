#include "Bullet.h"



CBullet::CBullet()
{
	//파일 위치 지정
	SetCimage(std::make_shared<CImage>());
	WCHAR path[256];
	GetCurrentDirectory(sizeof(path), path);
	WCHAR Bulletpath[256];
	wcscpy_s(Bulletpath, path);
	wcscat_s(Bulletpath, L"/Image/bullet.bmp");
	SetCurrentDirectory(Bulletpath);


	SetCurrentPosition(0.0, 0.0);

	SetFileLocation(Bulletpath);

	GetDrawImage()->Load(Bulletpath);
}


CBullet::CBullet(Point bulletPoint)
{
	//파일 위치 지정
	SetCimage(std::make_shared<CImage>());
	WCHAR path[256];
	GetCurrentDirectory(sizeof(path), path);
	WCHAR Bulletpath[256];
	wcscpy_s(Bulletpath, path);
	wcscat_s(Bulletpath, L"/Image/bullet.bmp");
	SetCurrentDirectory(Bulletpath);


	SetCurrentPosition(0.0, 0.0);

	SetFileLocation(Bulletpath);

	GetDrawImage()->Load(Bulletpath);
	SetCurrentPosition(bulletPoint);
}

CBullet::~CBullet()
{
}

void CBullet::ShotTo()
{
	//총탄이 화면 바깥으로 나갈때까지 일직선으로 움직임
	if (!IsOutOfScreen())
		move(0, shot_speed);
	else;
		//delete this; //너무 느려지지 않을까..?
}

void CBullet::ShotToDirection(Point goal)
{

	if (IsOutOfScreen() || IsCrashTarget())
	{
		//delete this;
		return;
	}

	double distance = this->GetCenter().GetDistanceTwoPoint(GetCenter(), goal);

	double bullet_setting_x = (goal.GetX() - GetCenter().GetX()) / distance * shot_speed;
	double bullet_setting_y = (goal.GetY() - GetCenter().GetY()) / distance * shot_speed;

	this->SetCurrentPosition(bullet_setting_x, bullet_setting_y);

}


//총탄이 적에게 맞았는가.
bool CBullet::IsCrashTarget()
{
	return false;
}

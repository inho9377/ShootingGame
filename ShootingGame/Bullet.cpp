#include "Bullet.h"



CBullet::CBullet()
{
}


CBullet::CBullet(Point bulletPoint)
{
	SetCurrentPosition(bulletPoint);
}

CBullet::~CBullet()
{
}

void CBullet::ShotTo()
{
	if (!IsOutOfScreen())
		move(0, shot_speed);
	else
		delete this;
}

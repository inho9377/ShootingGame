#pragma once
#include "Object.h"
#include "Point.h"
class CBullet :
	public Object
{
public:
	CBullet();
	CBullet(Point bulletPoint);
	~CBullet();

	//해당하는 방향으로 발사된다.
	void ShotTo();

	double GetShotSpeed(){return shot_speed;}
	void SetShotSpeed(double set) { shot_speed = set; }
private:

	//Bullet이 날아가는 속력. 기체마다 다름
	double shot_speed = 1.0;
};


#pragma once
#include "Object.h"
#include "Point.h"


enum class BulletType
{
	NORMAL
};

class CBullet :
	public Object
{
public:
	CBullet();
	CBullet(Point bulletPoint);
	~CBullet();

	//해당하는 방향으로 발사된다.
	void ShotTo();

	//해당 점으로 향함
	void ShotToDirection(Point goal);
	
	double GetShotSpeed(){return shot_speed;}
	void SetShotSpeed(double set) { shot_speed = set; }
	
	bool IsCrashTarget();

	BulletType GetBulletType() { return bulletType; }
	void SetBulletType(BulletType set) { bulletType = set; }

	Point GetGoalPosition() { return Goal_Position; }
	void SetGoalPosition(Point set) { Goal_Position = set; }


private:

	//Bullet이 날아가는 속력. 기체마다 다름
	double shot_speed = 1.0;
	//날아가는 방향
	Point Goal_Position;
	//탄환의 속성(일반적인 탄, 유도탄등)
	BulletType bulletType;
};


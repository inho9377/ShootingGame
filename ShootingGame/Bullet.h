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

	//�ش��ϴ� �������� �߻�ȴ�.
	void ShotTo();

	double GetShotSpeed(){return shot_speed;}
	void SetShotSpeed(double set) { shot_speed = set; }
private:

	//Bullet�� ���ư��� �ӷ�. ��ü���� �ٸ�
	double shot_speed = 1.0;
};


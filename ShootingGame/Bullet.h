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

	//�ش��ϴ� �������� �߻�ȴ�.
	void ShotTo();

	//�ش� ������ ����
	void ShotToDirection(Point goal);
	
	double GetShotSpeed(){return shot_speed;}
	void SetShotSpeed(double set) { shot_speed = set; }
	
	bool IsCrashTarget();

	BulletType GetBulletType() { return bulletType; }
	void SetBulletType(BulletType set) { bulletType = set; }

	Point GetGoalPosition() { return Goal_Position; }
	void SetGoalPosition(Point set) { Goal_Position = set; }


private:

	//Bullet�� ���ư��� �ӷ�. ��ü���� �ٸ�
	double shot_speed = 1.0;
	//���ư��� ����
	Point Goal_Position;
	//źȯ�� �Ӽ�(�Ϲ����� ź, ����ź��)
	BulletType bulletType;
};


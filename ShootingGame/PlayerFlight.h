#pragma once
#include "Flight.h"
#include "MyInput.h"
class CPlayerFlight :
	public CFlight
{
public:
	CPlayerFlight();
	~CPlayerFlight();

	void SetPositionWithSpeed(int myinput);

private:
	//�÷��̾�� Bullet���� ����������.
	int num_bullet = 50;
	CImage *roll_over;
	CImage *roll_down;
};


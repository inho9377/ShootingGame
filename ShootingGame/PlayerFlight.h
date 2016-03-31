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
	//플레이어는 Bullet수에 제한이있음.
	int num_bullet = 50;
	std::shared_ptr<CImage> roll_over;
	std::shared_ptr<CImage> roll_down;
};


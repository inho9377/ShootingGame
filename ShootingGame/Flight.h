
#include "Object.h"
#include "Bullet.h"
#include <stack>
#pragma once
class CFlight : public Object
{
public:
	CFlight();
	~CFlight();

	void Shot();

	
	double speed = 1.0;
};
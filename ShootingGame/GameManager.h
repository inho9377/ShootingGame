#pragma once
#include"MyInput.h"
#include "PlayerFlight.h"


class CGameManager
{
public:
	CGameManager();
	~CGameManager();

	void Init();
	void SettleDirectory();
	void SetCurrentKey();
	void PlayerAct();
	CMyInput myInput;
	void SetPlayerFlight(CPlayerFlight *r)
	{this->player = r;}


private:
	int currentKey;
	CPlayerFlight *player;
};


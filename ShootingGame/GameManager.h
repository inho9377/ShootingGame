#pragma once
#include"MyInput.h"
#include "PlayerFlight.h"

//Game�� ������ ��Ʈ���� ����ϴ� Ŭ����
//Object���� ��ġ����, �浹üũ���� �ٷ�⿡ ��� ������Ʈ���� �����־�ߵǴµ�..
class CGameManager
{
public:
	CGameManager();
	~CGameManager();

	void Init();
	void SettleDirectory();

	//Ű������ �Է� ���¸� ����
	void SetCurrentKey();

	//Ű������ �Է� ���¿� ���� Player�� ��ü�� ������Ŵ
	void PlayerAct();

	//Ű���� �Է� ����
	CMyInput myInput;
	void SetPlayerFlight(CPlayerFlight *r)
	{this->player = r;}


private:
	int currentKey;
	CPlayerFlight *player;
};


#pragma once
#include"MyInput.h"
#include <list>
#include "PlayerFlight.h"
#include "Bullet.h"

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
	void SetPlayerFlight(std::shared_ptr<CPlayerFlight>r) {this->player = r;}
	void ShotFromPlayer();
	void ShotToPlayer();
	void ProcedeBullet();

private:
	int currentKey;
	std::shared_ptr<CPlayerFlight> player;
	std::list<std::shared_ptr<CBullet>> bullet_list;
};


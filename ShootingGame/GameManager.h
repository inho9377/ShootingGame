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
	void SetPlayerFlight(CPlayerFlight *r) {this->player = r;}
	void ShotFromPlayer();
	void ShotToPlayer();
	void ProcedeBullet();

private:
	int currentKey;
	CPlayerFlight *player;
	std::list<CBullet*> bullet_list;


};


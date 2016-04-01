#pragma once
#include"MyInput.h"
#include <list>
#include "PlayerFlight.h"
#include "Bullet.h"
#include "BackGround.h"
#include "SceneManager.h"

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
	auto GetPlayerFlight() { return player; }
	void ShotFromPlayer();
	void ShotToPlayer();
	void ProcedeBullet();

	const int winsizeX = 800;
	const int winsizeY = 600;

private:
	int currentKey;
	std::shared_ptr<CPlayerFlight> player;
	std::list<std::shared_ptr<CBullet>> bullet_list;
};


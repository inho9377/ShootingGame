#pragma once
#include"MyInput.h"
#include <list>
#include "PlayerFlight.h"
#include "Bullet.h"

//Game의 로직과 컨트롤을 담당하는 클래스
//Object들의 위치정보, 충돌체크등을 다루기에 모든 오브젝트들을 갖고있어야되는데..
class CGameManager
{
public:
	CGameManager();
	~CGameManager();

	void Init();
	void SettleDirectory();

	//키보드의 입력 상태를 설정
	void SetCurrentKey();

	//키보드의 입력 상태에 대해 Player의 기체를 반응시킴
	void PlayerAct();

	//키보드 입력 상태
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


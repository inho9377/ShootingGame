#include "GameManager.h"



CGameManager::CGameManager()
{
}


CGameManager::~CGameManager()
{
}

//�ʱ�ȭ
void CGameManager::Init()
{


}

void CGameManager::SettleDirectory()
{
	WCHAR path[256];
	GetCurrentDirectory(sizeof(path), path);

	WCHAR backGroundPath[256];
	WCHAR playerFlightPath[256];
	

	wcscpy_s(backGroundPath, path);
	wcscat_s(backGroundPath, L"/Image/sky.bmp");
	

}


void CGameManager::SetCurrentKey()
{
	myInput.KeyboardProcess();

	currentKey = NULL;

	if (myInput.GetKey(VK_UP))
		currentKey = VK_UP;

	if (myInput.GetKey(VK_DOWN))
		currentKey = VK_DOWN;

	if (myInput.GetKey(VK_LEFT))
		currentKey = VK_LEFT;

	if (myInput.GetKey(VK_RIGHT))
		currentKey = VK_RIGHT;

	if (myInput.GetKey(VK_SPACE))
		currentKey = VK_SPACE;

}

void CGameManager::PlayerAct()
{
	if (currentKey == VK_SPACE)
	{
		ShotFromPlayer();
		return;
	}


	if(currentKey)
		player->SetPositionWithSpeed(currentKey);


	for each (std::shared_ptr<CBullet> bullet in bullet_list)
	{
		bullet->ShotTo();
		//bullet->ShotToDirection(bullet->GetGoalPosition());

	}


}

void CGameManager::ShotFromPlayer()
{
	auto bullet = std::make_shared<CBullet>(player->GetCurrentPosition());
	Point Goal;
	Goal.SetX(winsizeX);
	Goal.SetY(GetPlayerFlight()->GetCurrentPosition().GetY());
	bullet->SetGoalPosition(Goal);
	bullet_list.emplace_back(bullet);
	CSceneManagerSingleton::GetInstance()->AddObjectToGameScene(bullet);


}

void CGameManager::ShotToPlayer()
{

}


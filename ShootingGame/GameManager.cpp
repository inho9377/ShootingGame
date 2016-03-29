#include "GameManager.h"
#include "BackGround.h"


CGameManager::CGameManager()
{
}


CGameManager::~CGameManager()
{
}

//ÃÊ±âÈ­
void CGameManager::Init()
{
	CBackGround *background = new CBackGround();
	


	SettleDirectory();
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
	if(currentKey)
		player->SetPositionWithSpeed(currentKey);
}

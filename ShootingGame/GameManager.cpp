#include "GameManager.h"
#include "BackGround.h"


CGameManager::CGameManager()
{
}


CGameManager::~CGameManager()
{
}

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

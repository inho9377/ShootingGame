#include "SceneManager.h"



CSceneManager::CSceneManager()
{
}


CSceneManager::~CSceneManager()
{
}

void CSceneManager::drawScene(HDC hdc)
{
	//Scene�� �����ϴ� ��� Object���� �׷��ش�.
	for (SCENE::iterator iter = CurrentScene.begin();
	iter != CurrentScene.end(); 
		++iter)
	{
		iter->draw(hdc);
	}

}

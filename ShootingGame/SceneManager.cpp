#include "SceneManager.h"



CSceneManager::CSceneManager()
{
}


CSceneManager::~CSceneManager()
{
}

void CSceneManager::drawScene(HDC hdc)
{

	for (SCENE::iterator iter = CurrentScene.begin();
	iter != CurrentScene.end();
	iter++)
	{
		(*iter)->draw(hdc);
	}

	//Scene에 존재하는 모든 Object들을 그려준다.
	/*for (SCENE::iterator iter = CurrentScene.begin();
	iter != CurrentScene.end();
		iter++)
	{
		iter->draw(hdc);
	}
*/
}

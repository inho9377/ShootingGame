#include "SceneManager.h"

CSceneManager* CSceneManager::instace = nullptr;

CSceneManager::CSceneManager()
{
	GameScene = new SCENE;
	StartScene = new SCENE;
	ScoreScene = new SCENE;

	//AddObjectToStartScene(new Object);
	CurrentScene = GameScene;

}


CSceneManager* CSceneManager::GetInstance()
{
	if (instace == nullptr)
		instace = new CSceneManager();

	return instace;
}

void CSceneManager::drawScene(HDC hdc)
{

	for (SCENE::iterator iter = CurrentScene->begin();
	iter != CurrentScene->end();
	iter++)
	{
		(*iter)->draw(hdc);
	}

	//Scene�� �����ϴ� ��� Object���� �׷��ش�.
	
}

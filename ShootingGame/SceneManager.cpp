#include "SceneManager.h"

CSceneManager* CSceneManager::instace = nullptr;

CSceneManager::CSceneManager()
{
	GameScene = std::make_shared<SCENE>(new SCENE);
	StartScene = std::make_shared<SCENE>(new SCENE);
	ScoreScene = std::make_shared<SCENE>(new SCENE);

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

	//Scene에 존재하는 모든 Object들을 그려준다.
	
}


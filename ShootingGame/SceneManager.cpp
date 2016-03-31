#include "SceneManager.h"

CSceneManagerSingleton* CSceneManagerSingleton::instace = nullptr;

CSceneManagerSingleton::CSceneManagerSingleton()
{
	GameScene = std::make_shared<SCENE>(new SCENE());
	StartScene = std::make_shared<SCENE>(new SCENE());
	ScoreScene = std::make_shared<SCENE>(new SCENE());

	//AddObjectToStartScene(new Object);
	CurrentScene = GameScene;

}


CSceneManagerSingleton* CSceneManagerSingleton::GetInstance()
{
	if (instace == nullptr)
		instace = new CSceneManagerSingleton();

	return instace;
}

void CSceneManagerSingleton::drawScene(HDC hdc)
{

	for (SCENE::iterator iter = CurrentScene->begin();
	iter != CurrentScene->end();
	iter++)
	{
		
		(*iter)->draw(hdc);
	}

	//Scene�� �����ϴ� ��� Object���� �׷��ش�.
	
}


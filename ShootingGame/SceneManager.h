#pragma once
#include <windows.h>
#include<list>
#include "Object.h"

//�׷����ϴ� Object���� List�� Scene���� ����
typedef std::list<Object*> SCENE;


//SingleTon Class.

//View�� �����ϴ� Ŭ����. �׷����ϴ� Object���� ���鼭 ȭ�鿡 ���� �׷���
//�׷��� Object���� list�� �����־���ϴµ�..
class CSceneManager
{

private:
	CSceneManager();
	CSceneManager(const CSceneManager& other);
	//~CSceneManager();
	static CSceneManager* instace;


public:
	static CSceneManager* GetInstance();

	void drawScene(HDC hdc);
	SCENE* GetGameScene() { return GameScene; }

	//�׷����ϴ� Object���� Scene�� �߰��Ѵ�.
	//�ݵ�� BackGround�� ���� �߰��Ǿ���!
	void AddObjectToGameScene(Object *object) { GameScene->push_back(object); }
	void AddObjectToStartScene(Object *object) { StartScene->push_back(object); }
	void AddObjectToScoreScene(Object *object) { ScoreScene->push_back(object); }


	void SceneChange(SCENE* goal) { CurrentScene = goal; }
	
	//static CSceneManager& GetInstance() {
	//	return instance;
	//}

private:
	//���� �׷������� Scene
	SCENE *CurrentScene;

	SCENE *GameScene;
	SCENE *StartScene;
	SCENE *ScoreScene;

	
};




//CSceneManager* CSceneManager::instance = nullptr;
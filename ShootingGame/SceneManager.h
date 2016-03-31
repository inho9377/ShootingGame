#pragma once
#include <windows.h>
#include<list>
#include "Object.h"
#include <memory>

//�׷����ϴ� Object���� List�� Scene���� ����
typedef std::list<std::shared_ptr<Object>> SCENE;


//SingleTon Class.

//View�� �����ϴ� Ŭ����. �׷����ϴ� Object���� ���鼭 ȭ�鿡 ���� �׷���
//�׷��� Object���� list�� �����־���ϴµ�..
class CSceneManagerSingleton
{

private:
	CSceneManagerSingleton();
	CSceneManagerSingleton(const CSceneManagerSingleton& other);
	//~CSceneManager();
	static CSceneManagerSingleton* instace;


public:
	static CSceneManagerSingleton* GetInstance();

	void drawScene(HDC hdc);
	std::shared_ptr<SCENE> GetGameScene() { return GameScene; }

	//�׷����ϴ� Object���� Scene�� �߰��Ѵ�.
	//�ݵ�� BackGround�� ���� �߰��Ǿ���!
	void AddObjectToGameScene(std::shared_ptr<Object> object) { GameScene->emplace_back(object); }
	void AddObjectToStartScene(std::shared_ptr<Object> object) { StartScene->emplace_back(object); }
	void AddObjectToScoreScene(std::shared_ptr<Object> object) { ScoreScene->emplace_back(object); }


	void SceneChange(std::shared_ptr<SCENE> goal) { CurrentScene = goal; }
	
	//static CSceneManager& GetInstance() {
	//	return instance;
	//}

private:
	//���� �׷������� Scene
	std::shared_ptr<SCENE> CurrentScene;
	std::shared_ptr<SCENE> GameScene;
	std::shared_ptr<SCENE> StartScene;
	std::shared_ptr<SCENE> ScoreScene;

	
};




#pragma once
#include <windows.h>
#include<list>
#include "Object.h"

//그려야하는 Object들의 List를 Scene으로 정의
typedef std::list<Object*> SCENE;


//SingleTon Class.

//View를 조작하는 클래스. 그려야하는 Object들을 돌면서 화면에 각각 그려냄
//그래서 Object들의 list를 갖고있어야하는데..
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

	//그려야하는 Object들을 Scene에 추가한다.
	//반드시 BackGround가 먼저 추가되야함!
	void AddObjectToGameScene(Object *object) { GameScene->push_back(object); }
	void AddObjectToStartScene(Object *object) { StartScene->push_back(object); }
	void AddObjectToScoreScene(Object *object) { ScoreScene->push_back(object); }


	void SceneChange(SCENE* goal) { CurrentScene = goal; }
	
	//static CSceneManager& GetInstance() {
	//	return instance;
	//}

private:
	//현재 그려져야할 Scene
	SCENE *CurrentScene;

	SCENE *GameScene;
	SCENE *StartScene;
	SCENE *ScoreScene;

	
};




//CSceneManager* CSceneManager::instance = nullptr;
#pragma once
#include <windows.h>
#include<list>
#include "Object.h"
#include <memory>

//그려야하는 Object들의 List를 Scene으로 정의
typedef std::list<std::shared_ptr<Object>> SCENE;


//SingleTon Class.

//View를 조작하는 클래스. 그려야하는 Object들을 돌면서 화면에 각각 그려냄
//그래서 Object들의 list를 갖고있어야하는데..
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

	//그려야하는 Object들을 Scene에 추가한다.
	//반드시 BackGround가 먼저 추가되야함!
	void AddObjectToGameScene(std::shared_ptr<Object> object) { GameScene->emplace_back(object); }
	void AddObjectToStartScene(std::shared_ptr<Object> object) { StartScene->emplace_back(object); }
	void AddObjectToScoreScene(std::shared_ptr<Object> object) { ScoreScene->emplace_back(object); }


	void SceneChange(std::shared_ptr<SCENE> goal) { CurrentScene = goal; }
	
	//static CSceneManager& GetInstance() {
	//	return instance;
	//}

private:
	//현재 그려져야할 Scene
	std::shared_ptr<SCENE> CurrentScene;
	std::shared_ptr<SCENE> GameScene;
	std::shared_ptr<SCENE> StartScene;
	std::shared_ptr<SCENE> ScoreScene;

	
};




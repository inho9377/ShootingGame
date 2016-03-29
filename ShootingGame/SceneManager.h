#pragma once
#include <windows.h>
#include<list>
#include "Object.h"

//그려야하는 Object들의 List를 Scene으로 정의
typedef std::list<Object*> SCENE;

//View를 조작하는 클래스. 그려야하는 Object들을 돌면서 화면에 각각 그려냄
//그래서 Object들의 list를 갖고있어야하는데..
class CSceneManager
{
public:
	CSceneManager();
	~CSceneManager();

	
	void drawScene(HDC hdc);
	SCENE GetCurrentScene() { return CurrentScene; }

	//그려야하는 Object들을 Scene에 추가한다.
	//반드시 BackGround가 먼저 추가되야함!
	void AddObjectToScene(Object *object) { CurrentScene.push_back(object); }

private:
	//현재 그려져야할 Scene
	SCENE CurrentScene;

};


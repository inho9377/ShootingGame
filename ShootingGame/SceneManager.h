#pragma once
#include <windows.h>
#include<list>
#include "Object.h"

//그려야하는 Object들의 List를 Scene으로 정의
typedef std::list<Object*> SCENE;

class CSceneManager
{
public:
	CSceneManager();
	~CSceneManager();

	
	void drawScene(HDC hdc);
	SCENE GetCurrentScene() { return CurrentScene; }
	void AddObjectToScene(Object *object) { CurrentScene.push_back(object); }

private:
	SCENE CurrentScene;

};


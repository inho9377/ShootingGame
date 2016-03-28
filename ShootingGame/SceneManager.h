#pragma once
#include <windows.h>
#include<vector>
#include "Object.h"
typedef std::vector<Object> SCENE;

class CSceneManager
{
public:
	CSceneManager();
	~CSceneManager();

	
	void drawScene(HDC hdc);
	SCENE GetCurrentScene() { return CurrentScene; }
	void AddObjectToScene(const Object &object) { CurrentScene.push_back(object); }

private:
	SCENE CurrentScene;

};


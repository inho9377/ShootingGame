#pragma once
#include <windows.h>
#include<list>
#include "Object.h"

//�׷����ϴ� Object���� List�� Scene���� ����
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


#pragma once
#include <windows.h>
#include<list>
#include "Object.h"

//�׷����ϴ� Object���� List�� Scene���� ����
typedef std::list<Object*> SCENE;

//View�� �����ϴ� Ŭ����. �׷����ϴ� Object���� ���鼭 ȭ�鿡 ���� �׷���
//�׷��� Object���� list�� �����־���ϴµ�..
class CSceneManager
{
public:
	CSceneManager();
	~CSceneManager();

	
	void drawScene(HDC hdc);
	SCENE GetCurrentScene() { return CurrentScene; }

	//�׷����ϴ� Object���� Scene�� �߰��Ѵ�.
	//�ݵ�� BackGround�� ���� �߰��Ǿ���!
	void AddObjectToScene(Object *object) { CurrentScene.push_back(object); }

private:
	//���� �׷������� Scene
	SCENE CurrentScene;

};


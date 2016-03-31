#include <windows.h>
#include <time.h>
#include "SceneManager.h"
#include "GameManager.h"
#include <atlimage.h>
#include "BackGround.h"
#include "PlayerFlight.h"

#define szWindowClass	TEXT("First")
#define szTitle			TEXT("First App")

//전역변수를 줄이는 방법이 없을까..
std::shared_ptr<CPlayerFlight> player;
std::shared_ptr<CGameManager> GM;
std::shared_ptr<CBackGround> background;

LRESULT CALLBACK WndProc( HWND hWnd
						 , UINT message
						 , WPARAM wParam
						 , LPARAM lParam );

int APIENTRY WinMain( HINSTANCE hInstance,
					  HINSTANCE hPrevInstance,
					  LPSTR lpszCmdParam,
					  int nCmdShow)
{
	WNDCLASSEX wcex;

	wcex.cbSize		= sizeof(WNDCLASSEX);
	wcex.style		= CS_HREDRAW | CS_VREDRAW;
	wcex.lpfnWndProc	= (WNDPROC)WndProc;
	wcex.cbClsExtra		= 0;
	wcex.cbWndExtra		= 0;
	wcex.hInstance		= hInstance;
	wcex.hIcon	= LoadIcon(hInstance, IDI_APPLICATION);
	wcex.hIconSm= LoadIcon(hInstance, IDI_APPLICATION);
	wcex.hCursor= LoadCursor(NULL, IDC_ARROW);
	wcex.hbrBackground	= (HBRUSH)GetStockObject(WHITE_BRUSH);
	wcex.lpszMenuName	= NULL;
	wcex.lpszClassName	= szWindowClass;

	if( !RegisterClassEx(&wcex) )
		return 0;

	HWND	hWnd = CreateWindowEx( WS_EX_APPWINDOW
		, szWindowClass
		, szTitle
		, WS_OVERLAPPEDWINDOW
		, CW_USEDEFAULT
		, CW_USEDEFAULT
		, 800
		, 600
		, NULL
		, NULL
		, hInstance
		, NULL );

	if( !hWnd )
		return 0;

	ShowWindow(hWnd, nCmdShow);

	MSG			msg;
	while (true)
	{
		if (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE))
		{
			if (msg.message == WM_QUIT)
				break;
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
		else
		{
			HDC hdc = GetDC(hWnd);

			//더블 버퍼링을 위한 메모리 버퍼
			HDC      memoryDC = CreateCompatibleDC(hdc);
			HBITMAP memoryBitmap = CreateCompatibleBitmap(hdc, 800, 600);
			SelectObject(memoryDC, memoryBitmap);


			//background->draw(memoryDC);
			//player->draw(memoryDC);

			CSceneManagerSingleton::GetInstance()->drawScene(memoryDC);
			GM->SetCurrentKey();
			GM->PlayerAct();
			
			BitBlt(hdc, 0, 0, 800, 600, memoryDC, 0, 0, SRCCOPY);

			DeleteObject(memoryBitmap);
			DeleteDC(memoryDC);

			ReleaseDC(hWnd, hdc);
		}
	}

	return (int)msg.wParam;
}

// 메시지 처리 함수
LRESULT CALLBACK WndProc( HWND hWnd
						 , UINT message
						 , WPARAM wParam
						 , LPARAM lParam )
{
	HDC	hdc;
	PAINTSTRUCT	ps;

	switch(message)
	{
	case WM_CREATE:
	{
		GM = std::make_shared<CGameManager>(new CGameManager());
		


		background = std::make_shared<CBackGround>(new CBackGround());
		CSceneManagerSingleton::GetInstance()->AddObjectToGameScene(background);
		player = std::make_shared<CPlayerFlight>(new CPlayerFlight());
		CSceneManagerSingleton::GetInstance()->AddObjectToGameScene(player);
		GM->SetPlayerFlight(player);
		
	}
		break;
	case WM_PAINT:
		{
			hdc = BeginPaint( hWnd, &ps );

			EndPaint( hWnd, &ps );
		}
		break;
	case WM_DESTROY:
		PostQuitMessage(0);
		//delete GM;
		//delete SM;
		//delete background;
		return 0;
	}

	return DefWindowProc(hWnd, message, wParam, lParam);
}
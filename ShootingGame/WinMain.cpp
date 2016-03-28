#include <windows.h>
#include <time.h>

#define szWindowClass	TEXT("First")
#define szTitle			TEXT("First App")

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

			//메모리 버퍼 생성
			HDC      memoryDC = CreateCompatibleDC(hdc);
			HBITMAP memoryBitmap = CreateCompatibleBitmap(hdc, 800, 600);
			SelectObject(memoryDC, memoryBitmap);

			//Manager들의 logic
			//SceneStackManager->GetCurrentScene()->DrawScene(memoryDC);
			//GameRuleManager->GetKeyInput();
			//GameRuleManager->DoCharacterAction();

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

		break;
	case WM_PAINT:
		{
			hdc = BeginPaint( hWnd, &ps );

			EndPaint( hWnd, &ps );
		}
		break;
	case WM_DESTROY:
		PostQuitMessage(0);
		return 0;
	}

	return DefWindowProc(hWnd, message, wParam, lParam);
}
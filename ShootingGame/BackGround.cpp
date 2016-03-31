#include "BackGround.h"



CBackGround::CBackGround()
{

	//파일 위치 지정
	SetCimage(std::make_shared<CImage>());
	WCHAR path[256];
	GetCurrentDirectory(sizeof(path), path);
	WCHAR backGroundPath[256];
	wcscpy_s(backGroundPath, path);
	wcscat_s(backGroundPath, L"/Image/sky.bmp");
	SetCurrentDirectory(backGroundPath);


	SetCurrentPosition(0.0, 0.0);
	
	SetFileLocation(backGroundPath);

	GetDrawImage()->Load(backGroundPath);
	
	
}


CBackGround::~CBackGround()
{
	//GetCimage().Destroy();
}

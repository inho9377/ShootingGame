#include "Bullet.h"



CBullet::CBullet()
{
	//���� ��ġ ����
	SetCimage(new CImage);
	WCHAR path[256];
	GetCurrentDirectory(sizeof(path), path);
	WCHAR Bulletpath[256];
	wcscpy_s(Bulletpath, path);
	wcscat_s(Bulletpath, L"/Image/bullet.bmp");
	SetCurrentDirectory(Bulletpath);


	SetCurrentPosition(0.0, 0.0);

	SetFileLocation(Bulletpath);

	GetCimage()->Load(Bulletpath);
}


CBullet::CBullet(Point bulletPoint)
{
	//���� ��ġ ����
	SetCimage(new CImage);
	WCHAR path[256];
	GetCurrentDirectory(sizeof(path), path);
	WCHAR Bulletpath[256];
	wcscpy_s(Bulletpath, path);
	wcscat_s(Bulletpath, L"/Image/bullet.bmp");
	SetCurrentDirectory(Bulletpath);


	SetCurrentPosition(0.0, 0.0);

	SetFileLocation(Bulletpath);

	GetCimage()->Load(Bulletpath);
	SetCurrentPosition(bulletPoint);
}

CBullet::~CBullet()
{
}

void CBullet::ShotTo()
{
	//��ź�� ȭ�� �ٱ����� ���������� ���������� ������
	if (!IsOutOfScreen())
		move(0, shot_speed);
	else
		delete this; //�ʹ� �������� ������..?
}
